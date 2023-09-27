
#include "MyReq.h"


#include <Poco/StreamCopier.h>
#include <Poco/InflatingStream.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/Net/FilePartSource.h>
#include <Poco/JSON/Parser.h>

#include <Poco/Net/HTTPSClientSession.h>




#include <Poco/Path.h>
#include <Poco/URI.h>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

using namespace Poco;
using namespace Poco::Net;


MyReq::MyReq()
{
}



void MyReq::SendReq(std::string url, std::map<std::string, std::string> * parameters, std::vector<std::string>* output)
{

	//TODO : Why??!!




	try
	{
		JSON::Object bodyObj;
		std::map<std::string, std::string>::iterator it = parameters->begin();

		while (it != parameters->end())
		{
			bodyObj.set(it->first, it->second);
			++it;
		}

		std::ostringstream ss;
		bodyObj.stringify(ss);

		std::string body;
		body = ss.str();

		// Create a URI
		URI uri(url);


		//Getting Response
		std::ostringstream outStringStream;

	
		if (uri.getScheme() == "http") {
			// Create a session
			HTTPClientSession session(uri.getHost(), uri.getPort());

			// Set connection to keepalive
			session.setKeepAlive(true);

			// Choose the http request method
			HTTPRequest request(HTTPRequest::HTTP_POST, uri.getPath(), HTTPMessage::HTTP_1_0);


			// Add headers
			request.setContentType("application/json");
			//request.setContentType("application/form-data");

			request.setContentLength(body.length());

			// send request
			session.sendRequest(request) << body;


			HTTPResponse response;

			// this line is where you get your response
			std::istream& s = session.receiveResponse(response);

			outStringStream << s.rdbuf();
		}
		else {
			// HTTPS
			const Poco::Net::Context::Ptr context = new Poco::Net::Context(
				Poco::Net::Context::CLIENT_USE, "", "", "",
				Poco::Net::Context::VERIFY_NONE, 9, false,
				"ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
			HTTPSClientSession session(uri.getHost(), uri.getPort(), context);

			// Set connection to keepalive
			session.setKeepAlive(true);

			// Choose the http request method
			HTTPRequest request(HTTPRequest::HTTP_POST, uri.getPath(), HTTPMessage::HTTP_1_0);


			// Add headers
			request.setContentType("application/json");
			//request.setContentType("application/form-data");

			request.setContentLength(body.length());

			// send request
			session.sendRequest(request) << body;


			HTTPResponse response;

			// this line is where you get your response
			std::istream& s = session.receiveResponse(response);

			outStringStream << s.rdbuf();
		}


		
		
		std::string res_txt = outStringStream.str();
		Poco::JSON::Parser parser;
		auto result = parser.parse(res_txt);
		Poco::JSON::Object obj = *result.extract<Poco::JSON::Object::Ptr>();
		std::string status = obj.get("status");



		if (status == "OK") {

			output->push_back("OK");
			output->push_back(obj.get("user_name").toString());

		}
		else {
			output->push_back("ERROR");
			output->push_back(obj.get("error_msg").toString());
		}
	}
	catch (const std::exception& ex)
	{
		output->push_back("ERROR");
		output->push_back(ex.what());
		
	}

	


	
}

std::string MyReq::upload(std::string url, std::map<std::string, std::string>* parameter , std::string file_path, std::vector<std::vector<std::string>> * log)
{

	try
	{		
		

		std::filesystem::path p(file_path);
		std::filesystem::path dir = p.parent_path();
		std::filesystem::path file_name = p.filename();

		//Response
		std::ostringstream outStringStream;

		// Create a URI
		URI uri(url);

		HTTPRequest request(HTTPRequest::HTTP_POST, uri.getPath(), HTTPMessage::HTTP_1_1);
		HTMLForm form;
		form.setEncoding(HTMLForm::ENCODING_MULTIPART);
		std::map<std::string, std::string>::iterator it = parameter->begin();
		while (it != parameter->end())
		{			
			form.set(it->first, it->second);
			++it;
		}
		form.addPart("file", new FilePartSource(file_path));
		form.prepareSubmit(request);


		if (uri.getScheme() == "http") {


			// Create a session
			HTTPClientSession httpSession(uri.getHost(), uri.getPort());

			httpSession.setTimeout(Poco::Timespan(60, 0));
			form.write(httpSession.sendRequest(request));

			Poco::Net::HTTPResponse res;
			std::istream& s = httpSession.receiveResponse(res);

			outStringStream << s.rdbuf();
		}
		else {

			// HTTPS
			const Poco::Net::Context::Ptr context = new Poco::Net::Context(
				Poco::Net::Context::CLIENT_USE, "", "", "",
				Poco::Net::Context::VERIFY_NONE, 9, false,
				"ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");

			HTTPSClientSession* httpSession = new HTTPSClientSession(uri.getHost(), uri.getPort(), context);
			httpSession->setTimeout(Poco::Timespan(60, 0));
			form.write(httpSession->sendRequest(request));



			Poco::Net::HTTPResponse res;
			std::istream& s = httpSession->receiveResponse(res);
			
			outStringStream << s.rdbuf();

		}


		std::string res_txt = outStringStream.str();
		Poco::JSON::Parser parser;
		auto result = parser.parse(res_txt);
		Poco::JSON::Object obj = *result.extract<Poco::JSON::Object::Ptr>();
		std::string status = obj.get("status");
		if (status == "OK") {
			std::string data = obj.get("results");
			auto main_results = parser.parse(data);
			Poco::JSON::Object Main_data = *main_results.extract<Poco::JSON::Object::Ptr>();

			//-------------------- TRC  --------------------------//
			std::map<std::string, std::string>::iterator check_trc = parameter->find("TRC");
			if (check_trc->second == "TRUE") {
				log->push_back(std::vector < std::string>{"--------------- TRC ------------- ", "T"});
				std::string trc_data = Main_data.get("trc_result");
				std::vector<std::string> trc_output;
				ExtractTrc(&trc_data, &trc_output, log);
				if (trc_output.size() > 0) {
					MakeDir(dir.string() + "\\C3Dtools");
					if (WriteFile(dir.string() + "\\C3Dtools\\" + file_name.string() + ".trc", &trc_output, false)) {
						//file is generated succssfully
						log->push_back(std::vector < std::string> {"Exporting TRC is done.", "T"});
					}
					else {
						log->push_back(std::vector < std::string> {"Exporting TRC Failed.", "F"});
					}
				}
				else {
					log->push_back(std::vector < std::string> {"TRC Data Not Found.", "F"});
				}

			}
			//-------------------- MOT  --------------------------//
			std::map<std::string, std::string>::iterator check_mot = parameter->find("MOT");
			if (check_mot->second == "TRUE") {
				log->push_back(std::vector < std::string>{"--------------- MOT ------------- ", "T"});
				std::string mot_data = Main_data.get("mot_result");
				std::vector<std::string> mot_output;
				ExtractMot(&mot_data, &mot_output,log);
				if (mot_output.size() > 0) {
					MakeDir(dir.string() + "\\C3Dtools");
					if (WriteFile(dir.string() + "\\C3Dtools\\" + file_name.string() + ".mot", &mot_output, false)) {
						//file is generated succssfully
						log->push_back(std::vector < std::string>{"Exporting MOT is done.", "T"});
					}
					else {
						log->push_back(std::vector < std::string> {"Exporting MOT Failed.", "F"});
					}
				}
				else {
					log->push_back(std::vector < std::string> {"MOT: Data Not Found.", "F"});
				}
			}
			//-------------------- ASCII POINT  --------------------------//
			std::map<std::string, std::string>::iterator check_ascii_point = parameter->find("ASCII_Points");
			if (check_ascii_point->second == "TRUE") {
				log->push_back(std::vector < std::string>{"--------------- ASCII - Points ------------- ", "T"});
				std::string ascii_point_data = Main_data.get("ascii_point_result");
				std::vector<std::string> ascii_points_output;
				ExtractAscii(&ascii_point_data, &ascii_points_output, log);
				if (ascii_points_output.size() > 0) {
					MakeDir(dir.string() + "\\C3Dtools");
					if (WriteFile(dir.string() + "\\C3Dtools\\" + file_name.string() + ".txt", &ascii_points_output, false)) {
						//file is generated succssfully
						log->push_back(std::vector < std::string>{"Exporting ASCII - Points is done.", "T"});
					}
					else {
						log->push_back(std::vector < std::string>{"Exporting ASCII - Points Failed.", "F"});
					}
				}
				else {
					log->push_back(std::vector < std::string>{"Exporting ASCII - Data Not Found.", "F"});
				}
			}
			//-------------------- ASCII Analog  --------------------------//
			std::map<std::string, std::string>::iterator check_ascii_analog = parameter->find("ASCII_Analog");
			if (check_ascii_analog->second == "TRUE") {
				log->push_back(std::vector < std::string>{"--------------- ASCII - Analog ------------- ", "T"});
				std::string ascii_analog_data = Main_data.get("ascii_analog_result");
				std::vector<std::string> ascii_analoge_output;
				ExtractAscii_analog(&ascii_analog_data, &ascii_analoge_output, log);
				if (ascii_analoge_output.size() > 0) {
					MakeDir(dir.string() + "\\C3Dtools");
					if (WriteFile(dir.string() + "\\C3Dtools\\" + file_name.string() + "_Analog.txt", &ascii_analoge_output, false)) {
						//file is generated succssfully
						log->push_back(std::vector < std::string>{"Exporting ASCII - Analog is done.", "T"});
					}
					else {
						log->push_back(std::vector < std::string>{"Exporting ASCII - Analog Failed.", "F"});
					}
				}
				else {
					log->push_back(std::vector < std::string>{"Exporting Analoge - Data Not Found.", "F"});
				}
			}


		}
		else {
			return obj.get("error_msg");
		}

		return std::string();
	}
	catch (const std::exception& ex)
	{
		log->push_back(std::vector < std::string>{" FAILED !!", "F"});
		log->push_back(std::vector < std::string>{ex.what(), "F"});
	}
}

bool MyReq::write_token(std::string _key)
{
	Poco::JSON::Object key;
	key.set("KEY", _key);
	std::ostringstream oss;
	Poco::JSON::Stringifier::stringify(key, oss);
	std::vector<std::string> vec_key;
	vec_key.push_back(oss.str());
	return WriteFile("key.txt", &vec_key, false);

}

std::string MyReq::read_token()
{
	std::fstream file;

	//if exist 
	if (std::filesystem::exists("key.txt")) {

		try
		{
			std::fstream newfile;
			newfile.open("key.txt", std::ios::in);
			std::string Fline;
			if (newfile.is_open()) {
				std::string tp;
				while (std::getline(newfile, tp)) {
					Fline = tp;
				}
				newfile.close();
			}

			Poco::JSON::Parser parser;
			auto json = parser.parse(Fline);
			Poco::JSON::Object key = *json.extract<Poco::JSON::Object::Ptr>();
			return key.get("KEY");
		}
		catch (const std::exception&)
		{
			return "Failed to load key file.";
		}

	}
	else {
		return "";
	}

}

bool MyReq::login(std::string url, std::map<std::string, std::string>* parameters, std::vector<std::string>* output)
{

	return false;

}

bool MyReq::WriteFile(std::string path, std::vector<std::string>* data, bool append)
{
	std::fstream file;

	//if exist 
	if (std::filesystem::exists(path)) {

		// remove file
		std::filesystem::remove(path);
	}

	file.open(path, std::ios_base::out);
	if (!file.is_open())
	{
		return false;
	}
	
	for (auto i = data->begin(); i != data->end(); i++)
	{
		file << *i;
	}
	file.close();

	return true;
}

void MyReq::ExtractTrc(std::string* trc_data, std::vector<std::string>* output, std::vector<std::vector<std::string>>* log)
{
	Poco::JSON::Parser parser;
	auto trc_results = parser.parse(*trc_data);
	Poco::JSON::Object trc_obj = *trc_results.extract<Poco::JSON::Object::Ptr>();
	try
	{
		std::string trc_success_msg = trc_obj.get("success_msg");
		std::string _trc_json = trc_obj.get("json");
		auto trc = parser.parse(_trc_json);
		Poco::JSON::Object trc_main = *trc.extract<Poco::JSON::Object::Ptr>();
		std::string _trc_h1 = trc_main.get("h1");
		std::string _trc_h2 = trc_main.get("h2");
		std::string _trc_h3 = trc_main.get("h3");
		std::string _trc_h4 = trc_main.get("h4");
		std::string _trc_h5 = trc_main.get("h5");
		output->push_back(_trc_h1);
		output->push_back(_trc_h2);
		output->push_back(_trc_h3);
		output->push_back(_trc_h4);
		output->push_back(_trc_h5);

		Poco::JSON::Array::Ptr _trc_array = trc_main.getArray("data");
		Poco::Dynamic::Array da = *_trc_array;
		for (int i = 0; i < da.size(); i++)
		{
			output->push_back(da[i]);
		}
	}
	catch (const std::exception&)
	{
		std::string mot_error_msg = trc_obj.get("error_msg");
		log->push_back(std::vector < std::string>{"Failed to extract TRC data *", "F"});

	}

}

void MyReq::ExtractMot(std::string* mot_data, std::vector<std::string>* output , std::vector<std::vector<std::string>>* log)
{
	Poco::JSON::Parser parser;
	auto mot_results = parser.parse(*mot_data);
	Poco::JSON::Object mot_obj = *mot_results.extract<Poco::JSON::Object::Ptr>();
	// Success || Failed
	try
	{
		std::string mot_success_msg = mot_obj.get("success_msg");
		std::string _mot_json = mot_obj.get("json");
		auto mot = parser.parse(_mot_json);
		Poco::JSON::Object mot_main = *mot.extract<Poco::JSON::Object::Ptr>();
		std::string _mot_h1 = mot_main.get("h1");
		std::string _mot_h2 = mot_main.get("h2");
		output->push_back(_mot_h1);
		output->push_back(_mot_h2);

		Poco::JSON::Array::Ptr _mot_array = mot_main.getArray("data");
		Poco::Dynamic::Array da = *_mot_array;
		for (int i = 0; i < da.size(); i++)
		{
			output->push_back(da[i]);
		}
	}
	catch (const std::exception&)
	{
		std::string mot_error_msg = mot_obj.get("error_msg");
		log->push_back(std::vector < std::string>{"Failed to extract Mot data *","F"});
		
	}

}

void MyReq::ExtractAscii(std::string* _data, std::vector<std::string>* output, std::vector<std::vector<std::string>>* log)
{
	Poco::JSON::Parser parser;
	auto _results = parser.parse(*_data);
	Poco::JSON::Object _obj = *_results.extract<Poco::JSON::Object::Ptr>();
	try
	{

		std::string _success_msg = _obj.get("success_msg");
		std::string _json = _obj.get("json");
		auto ascii = parser.parse(_json);
		Poco::JSON::Object ascii_main = *ascii.extract<Poco::JSON::Object::Ptr>();
		std::string _ascii_h1 = ascii_main.get("h1");
		std::string _ascii_h2 = ascii_main.get("h2");
		output->push_back(_ascii_h1);
		output->push_back(_ascii_h2);

		Poco::JSON::Array::Ptr _ascii_array = ascii_main.getArray("data");
		Poco::Dynamic::Array da = *_ascii_array;
		for (int i = 0; i < da.size(); i++)
		{
			output->push_back(da[i]);
		}
	}
	catch (const std::exception&)
	{
		std::string mot_error_msg = _obj.get("error_msg");
		log->push_back(std::vector < std::string>{"Failed to extract ASCII data *","F"});
	}
}


void MyReq::ExtractAscii_analog(std::string* _data, std::vector<std::string>* output, std::vector<std::vector<std::string>>* log)
{
	Poco::JSON::Parser parser;
	auto _results = parser.parse(*_data);
	Poco::JSON::Object _obj = *_results.extract<Poco::JSON::Object::Ptr>();
	try
	{

		std::string _success_msg = _obj.get("success_msg");
		std::string _json = _obj.get("json");
		auto ascii = parser.parse(_json);
		Poco::JSON::Object ascii_main = *ascii.extract<Poco::JSON::Object::Ptr>();
		std::string _ascii_h1 = ascii_main.get("h1");
		output->push_back(_ascii_h1);

		Poco::JSON::Array::Ptr _ascii_array = ascii_main.getArray("data");
		Poco::Dynamic::Array da = *_ascii_array;
		for (int i = 0; i < da.size(); i++)
		{
			output->push_back(da[i]);
		}
	}
	catch (const std::exception&)
	{
		std::string mot_error_msg = _obj.get("error_msg");
		log->push_back(std::vector < std::string>{"Failed to extract ASCII data *", "F"});
	}
}


bool MyReq::MakeDir(std::string path)
{
	const char* _path = path.c_str();
	std::filesystem::path dir(_path);
	if (std::filesystem::create_directory(dir))
	{
		return true;
	}
	else {
		return false;
	}
}



