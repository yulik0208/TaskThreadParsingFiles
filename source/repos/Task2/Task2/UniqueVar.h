#pragma once
#include <iostream>
#include "BadType.h"
enum Type
{
	NONE,
	BOOL,
	CHAR,
	UCHAR,
	WCHAR_T,
	SHORT,
	USHORT,
	INT,
	UINT,
	LONG,
	ULONG,
	LONG_LONG,
	ULONG_LONG,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE
};

class UniqueVar
{
public:
	
	UniqueVar();
	~UniqueVar();
	UniqueVar(bool value);
	UniqueVar(char value);
	UniqueVar(unsigned char value);
	UniqueVar(wchar_t value);
	UniqueVar(short value);
	UniqueVar(unsigned short value);
	UniqueVar(int value);
	UniqueVar(unsigned int value);
	UniqueVar(long int value);
	UniqueVar(unsigned long int value);
	UniqueVar(long long int value);
	UniqueVar(unsigned long long int value);
	UniqueVar(float value);
	UniqueVar(double value);
	UniqueVar(long double value);

	UniqueVar(const UniqueVar& another);
	UniqueVar(UniqueVar&& another);

	UniqueVar& operator=(const UniqueVar& right);
	UniqueVar& operator=(UniqueVar&& right);

	void getType();
    void swap(UniqueVar& other);

	void Destroy();

	int ToInt() const;
	bool ToBool() const;
	signed char ToSignedChar() const;
	unsigned char ToUnsignedChar() const;
	wchar_t To_Wchar_t() const;
	short int ToShortInt() const;
	unsigned short int ToUnsignedShortInt() const;
	unsigned int ToUnsignedInt() const;
	long int ToLongInt() const;
	unsigned long int ToUnsignedLongInt() const;
	long long int ToLongLongInt() const;
	unsigned long long int ToUnsignedLongLongInt() const;
	float ToFloat() const;
	double ToDouble() const;
	long double ToLongDouble() const;

private:
	union Holder
	{

		bool bool_type;
		signed char signed_char_type;
		unsigned char unsigned_char_type;
		wchar_t	wchar_t_type;
		short int short_int_type;
		unsigned short int unsigned_short_int_type;
		int int_type;
		unsigned int unsigned_int_type;
		long int long_int_type;
		unsigned long int unsigned_long_int_type;
		long long int long_long_int_type;
		unsigned long long int unsigned_long_long_int_type;
		float float_type;
		double double_type;
		long double long_double_type;

	} data;
	Holder GetValue();
	Type data_type;
	Type GetDataType()const { return data_type; }
};

