#include "CodeParser.h"



CodeParser::CodeParser()
{
	for (size_t i = 0; i < e_count; i++)
	{
		m_codeInfo[i] = 0;
	}
}


CodeParser::~CodeParser()
{
	m_code.clear();
}

void CodeParser::DivideOnLines(std::string path)
{
	std::ifstream infile;
	std::string str;
	infile.open(path);
	while (!infile.eof())
	{
		std::getline(infile, str);
		m_code.push_back(str);
	}
}

void CodeParser::PrintFile()
{
	for (auto a : m_code)
	{
		std::cout << a << std::endl;
	}
}
