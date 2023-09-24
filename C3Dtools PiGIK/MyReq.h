#pragma once
#include <string>
#include <map>
#include <vector>




class MyReq
{
public:
	MyReq();
	void SendReq(std::string url, std::map<std::string, std::string>* parameter, std::vector<std::string>* output);
	std::string upload(std::string url, std::map<std::string, std::string>* parameter, std::string file_path, std::vector<std::string>* log);
	bool write_token(std::string _key);
	std::string MyReq::read_token();
	//---------------------------------------------------
	bool login(std::string url, std::map<std::string, std::string>* parameter, std::vector<std::string>* output);




private:
	bool WriteFile(std::string path, std::vector<std::string>* data, bool append);
	void ExtractTrc(std::string* trc_data, std::vector<std::string>* output, std::vector<std::string>* log);
	void ExtractMot(std::string* mot_data, std::vector<std::string>* output, std::vector<std::string>* log);
	void ExtractAscii(std::string* mot_data, std::vector<std::string>* output, std::vector<std::string>* log);
	bool MakeDir(std::string path);


	
};


