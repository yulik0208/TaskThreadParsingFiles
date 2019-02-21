#pragma once


class BadType : public std::exception
{
public:
	virtual const char* what() const throw() { return "Bad types!"; }
};