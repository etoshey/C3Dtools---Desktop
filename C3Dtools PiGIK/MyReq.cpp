
#include "MyReq.h"

#include <Poco/StreamCopier.h>
#include <Poco/InflatingStream.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <iostream>
#include <string>

using namespace Poco;
using namespace Poco::Net;

MyReq::MyReq()
{
}

std::string MyReq::SendReq(std::string url, std::map<std::string, std::string> * parameters)
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

	// Create a session
	HTTPClientSession session(uri.getHost(), uri.getPort());

	// Set connection to keepalive
	session.setKeepAlive(true);

	// Choose the http request method
	HTTPRequest request(HTTPRequest::HTTP_POST, uri.getPath(), HTTPMessage::HTTP_1_1);

	// Add headers
	request.setContentType("application/json");

	request.setContentLength(body.length());

	// send request
	session.sendRequest(request) << body;


	HTTPResponse response;

	// this line is where you get your response
	std::istream& s = session.receiveResponse(response);

	std::ostringstream outStringStream;
	outStringStream << s.rdbuf();
	std::string res_txt = outStringStream.str();
	Poco::JSON::Parser parser;
	auto result = parser.parse(res_txt);
	Poco::JSON::Object obj = *result.extract<Poco::JSON::Object::Ptr>();
	std::string status = obj.get("status");
	if (status == "OK") {
		return obj.get("user_name");
	}
	else {
		return obj.get("error_msg");
	}


	
}