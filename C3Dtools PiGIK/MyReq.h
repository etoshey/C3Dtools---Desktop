#pragma once
#include <string>
#include <map>



class MyReq
{
public:
	MyReq();
	std::string SendReq(std::string url, std::map<std::string, std::string>* parameter);
	std::string upload(std::string url, std::map<std::string, bool>* parameter, std::string file_path);





private:
	
};


