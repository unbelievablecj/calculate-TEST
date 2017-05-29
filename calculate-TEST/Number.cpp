#include "stdafx.h"
#include "Number.h"


Number Number::operator+(Number & a)
{
	int d = this->denominator*a.denominator;
	int n = this->denominator*a.numerator + this->numerator*a.denominator;
	return Number(true,n,d);
}

Number Number::operator-(Number & a)
{
	int d = this->denominator*a.denominator;
	int n = this->numerator*a.denominator - this->denominator*a.numerator;
	return Number(true,n,d);
}

Number Number::operator*(Number & a)
{
	int d = this->denominator*a.denominator;
	int n = this->numerator*a.numerator;
	return Number(true,n,d);
}

Number Number::operator/(Number & a)
{
	int d = this->denominator*a.numerator;
	int n = this->numerator*a.denominator;
	return Number(true,n,d);
}

bool Number::getIs()
{
	return isNumeber;
}

char Number::getOperation()
{
	return operation;
}

pair<int, int> Number::getNum()
{
	return pair<int, int>(numerator,denominator);
}

Number::Number(bool isNumber, int numerator, int denominator)
{
	this->isNumeber = isNumber;
	this->numerator = numerator;
	this->denominator = denominator;
	operation = '0';
}

Number::Number(bool isNumber, int numerator)
{
	this->isNumeber = isNumber;
	this->numerator = numerator;
	this->denominator = 1;
	this->operation = '0';
}

Number::Number(bool isNumber, char operation)
{
	this->isNumeber = isNumber;
	this->operation = operation;
}

Number::Number()
{
}


Number::~Number()
{
}
