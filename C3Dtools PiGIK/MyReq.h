#pragma once
#include <string>
#include <map>



class MyReq
{
public:
	MyReq();
	std::string SendReq(std::string url, std::string body, std::map<std::string, std::string> headers);

private:
	
};


