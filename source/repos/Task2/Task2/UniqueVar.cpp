#include "UniqueVar.h"
#include "BadType.h"


UniqueVar::UniqueVar()
{
	data_type = Type::NONE;
	data.int_type = 0;
}

UniqueVar::~UniqueVar()
{
	Destroy();
}

UniqueVar::UniqueVar(bool value)
{
	data_type = Type::BOOL;
	data.bool_type = value;
}

UniqueVar::UniqueVar(char value)
{
	data_type = Type::CHAR;
	data.signed_char_type = value;
}

UniqueVar::UniqueVar(unsigned char value)
{
	data_type = Type::UCHAR;
	data.unsigned_char_type = value;
}

UniqueVar::UniqueVar(wchar_t value)
{
	data_type = Type::WCHAR_T;
	data.wchar_t_type = value;
}

UniqueVar::UniqueVar(short value)
{
	data_type = Type::SHORT;
	data.short_int_type = value;
}

UniqueVar::UniqueVar(unsigned short value)
{
	data_type = Type::USHORT;
	data.unsigned_short_int_type = value;
}

UniqueVar::UniqueVar(int value)
{
	data_type = Type::INT;
	data.int_type = value;
}

UniqueVar::UniqueVar(unsigned int value)
{
	data_type = Type::UINT;
	data.unsigned_int_type = value;
}

UniqueVar::UniqueVar(long int value)
{
	data_type = Type::LONG;
	data.long_int_type;
}

UniqueVar::UniqueVar(unsigned long int value)
{
	data_type = Type::ULONG;
	data.unsigned_long_int_type = value;
}

UniqueVar::UniqueVar(long long int value)
{
	data_type = Type::LONG_LONG;
	data.long_long_int_type = value;
}

UniqueVar::UniqueVar(unsigned long long int value)
{
	data_type = Type::ULONG_LONG;
	data.unsigned_long_int_type = value;
}

UniqueVar::UniqueVar(float value)
{
	data_type = Type::FLOAT;
	data.float_type = value;
}

UniqueVar::UniqueVar(double value)
{
	data_type = Type::DOUBLE;
	data.double_type = value;
}

UniqueVar::UniqueVar(long double value)
{
	data_type = Type::LONG_DOUBLE;
	data.long_double_type = value;
}

UniqueVar::UniqueVar(const UniqueVar & another)
{
	data_type = another.data_type;
	data = another.data;
}

UniqueVar::UniqueVar(UniqueVar && another)
{
	data = std::move(another.data);
	data_type = std::move(another.data_type);
}

UniqueVar & UniqueVar::operator=(const UniqueVar & right)
{
	if (&right == this)
		return *this;

	data_type = right.data_type;
	data = right.data;
	
	return *this;
}

UniqueVar & UniqueVar::operator=(UniqueVar && right)
{
	data = std::move(right.data);
	data_type = std::move(right.data_type);
	return *this;
}

void UniqueVar::getType()
{
	switch (data_type)
	{
	case Type::NONE:
	{
		std::cout << "Variable don't have a type(" << std::endl;
		break;
	}
	case Type::BOOL:
	{
		std::cout << "bool"<< std::endl;
		break;
	}
	case Type::INT:
	{
		std::cout << "int" << std::endl;
		break;
	}
	case Type::CHAR:
	{
		std::cout << "char" << std::endl;
		break;
	}
	case Type::DOUBLE:
	{
		std::cout << "double" << std::endl;
		break;
	}
	case Type::FLOAT:
	{
		std::cout << "float" << std::endl;
		break;
	}
	case Type::LONG:
	{
		std::cout << "long int" << std::endl;
		break;
	}
	case Type::LONG_DOUBLE:
	{
		std::cout << "long double" << std::endl;
		break;
	}
	case Type::LONG_LONG:
	{
		std::cout << "long long int" << std::endl;
		break;
	}
	case Type::SHORT:
	{
		std::cout << "short int" << std::endl;
		break;
	}
	case Type::UCHAR:
	{
		std::cout << "unsigned char" << std::endl;
		break;
	}
	case Type::UINT:
	{
		std::cout << "unsigned int" << std::endl;
		break;
	}
	case Type::ULONG:
	{
		std::cout << "unsigned long" << std::endl;
		break;
	}
	case Type::ULONG_LONG:
	{
		std::cout << "unsigned long long" << std::endl;
		break;
	}
	case Type::USHORT:
	{
		std::cout << "unsigned short int" << std::endl;
		break;
	}
	case Type::WCHAR_T:
	{
		std::cout << "wchar_t" << std::endl;
		break;
	}
	default:
		break;
	}
}

void UniqueVar::swap(UniqueVar & other)
{
	using std::swap;
	swap(data, other.data);
	swap(data_type, other.data_type);
}

void UniqueVar::Destroy()
{
	data_type = Type::NONE;
	data.int_type = 0;
}

int UniqueVar::ToInt() const
{
		if (data_type == Type::INT)
			return data.int_type;
		else
			throw BadType();
}

bool UniqueVar::ToBool() const
{
	if (data_type == Type::BOOL)
		return data.bool_type;
	else
		throw BadType();
}

signed char UniqueVar::ToSignedChar() const
{
	if (data_type == Type::CHAR)
		return data.signed_char_type;
	else
		throw BadType();
}

unsigned char UniqueVar::ToUnsignedChar() const
{
	if (data_type == Type::UCHAR)
		return data.unsigned_short_int_type;
	else
		throw BadType();
}

wchar_t UniqueVar::To_Wchar_t() const
{
	if (data_type == Type::WCHAR_T)
		return data.wchar_t_type;
	else
		throw BadType();
}

short int UniqueVar::ToShortInt() const
{
	if (data_type == Type::SHORT)
		return data.short_int_type;
	else
		throw BadType();
}

unsigned short int UniqueVar::ToUnsignedShortInt() const
{
	if (data_type == Type::USHORT)
		return data.unsigned_short_int_type;
	else
		throw BadType();
}

unsigned int UniqueVar::ToUnsignedInt() const
{
	if (data_type == Type::UINT)
		return data.unsigned_int_type;
	else
		throw BadType();
}

long int UniqueVar::ToLongInt() const
{
	if (data_type == Type::LONG)
		return data.long_int_type;
	else
		throw BadType();
}

unsigned long int UniqueVar::ToUnsignedLongInt() const
{
	if (data_type == Type::ULONG)
		return data.unsigned_long_int_type;
	else
		throw BadType();
}

long long int UniqueVar::ToLongLongInt() const
{
	if (data_type == Type::LONG_LONG)
		return data.long_long_int_type;
	else
		throw BadType();
}

unsigned long long int UniqueVar::ToUnsignedLongLongInt() const
{
	if (data_type == Type::ULONG_LONG)
		return data.unsigned_long_long_int_type;
	else
		throw BadType();
}

float UniqueVar::ToFloat() const
{
	if (data_type == Type::FLOAT)
		return data.float_type;
	else
		throw BadType();
}

double UniqueVar::ToDouble() const
{
	if (data_type == Type::DOUBLE)
		return data.double_type;
	else
		throw BadType();
}

long double UniqueVar::ToLongDouble() const
{
	if (data_type == Type::LONG_DOUBLE)
		return data.long_double_type;
	else
		throw BadType();
}





/*UniqueVar::Holder UniqueVar::GetValue()
{
	switch (GetDataType())
	{
	case Type::NONE:
	{
		std::cout << "Variable don't have a type(" << std::endl;
	}
	case Type::BOOL:
		/
	case Type::INT:
	
	case Type::CHAR:
		
	case Type::DOUBLE:
		
	case Type::FLOAT:
		
	case Type::LONG:
		
	case Type::LONG_DOUBLE:
		
	case Type::LONG_LONG:
		
	case Type::SHORT:
		
	case Type::UCHAR:
		
	case Type::UINT:
		
	case Type::ULONG:
		
	case Type::ULONG_LONG:
		
	case Type::USHORT:
		
	case Type::WCHAR_T:
		
	default:
		break;
	}
}*/


