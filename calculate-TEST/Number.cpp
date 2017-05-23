#include "stdafx.h"
#include "Number.h"


Number Number::operator+(Number & a)
{
	return Number();
}

Number Number::operator-(Number & a)
{
	return Number();
}

Number Number::operator*(Number & a)
{
	return Number();
}

Number Number::operator/(Number & a)
{
	return Number();
}

bool Number::getIs()
{
	return false;
}

char Number::getOperation()
{
	return 0;
}

pair<int, int> Number::getNum()
{
	return pair<int, int>();
}

Number::Number(bool isNumber, int numerator)
{
}

Number::Number(bool isNumber, char operation)
{
}

Number::Number()
{
}


Number::~Number()
{
}
