#pragma once
#include <string>
#include <map>
#include <vector>




class MyReq
{
public:
	MyReq();
	std::string SendReq(std::string url, std::map<std::string, std::string>* parameter);
	std::string upload(std::string url, std::map<std::string, std::string>* parameter, std::string file_path, std::vector<std::string>* log);




private:
	bool WriteFile(std::string path, std::vector<std::string>* data, bool append);
	void ExtractTrc(std::string* trc_data, std::vector<std::string>* output, std::vector<std::string>* log);
	void ExtractMot(std::string* mot_data, std::vector<std::string>* output, std::vector<std::string>* log);
	void ExtractAscii(std::string* mot_data, std::vector<std::string>* output, std::vector<std::string>* log);
	bool MakeDir(std::string path);


	
};


