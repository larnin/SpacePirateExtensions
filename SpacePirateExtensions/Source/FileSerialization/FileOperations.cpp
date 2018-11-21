#include "FileSerialization/FileOperations.hpp"

#include <fstream>
#include <streambuf>

void writeFile(const std::string & filename, const std::string & data)
{
	std::ofstream out(filename);
	out << data;
	out.close();
}

std::string readFile(const std::string & filename)
{
	std::ifstream stream(filename);
	std::string str;

	stream.seekg(0, std::ios::end);
	str.reserve(stream.tellg());
	stream.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

	return str;
}