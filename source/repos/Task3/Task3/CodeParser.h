#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include<string>

enum {
	e_codeLines,
	e_emptyLines,
	e_comentLines,
	e_sumLines,
	e_count
};
class CodeParser
{
public:
	CodeParser();
	~CodeParser();
	void DivideOnLines(std::string path);
	void PrintFile();
private:
	std::vector<std::string> m_code;
	unsigned int m_codeInfo[4];
};

