#pragma once
#include<iostream>
using namespace std;
class Number
{
	bool isNumeber;
	int numerator;
	int denominator;
	char operation;
public:
	Number operator+(Number& a);
	Number operator-(Number& a);
	Number operator*(Number& a);
	Number operator/(Number& a);
	bool getIs();
	char getOperation();
	pair<int, int> getNum();
	Number(bool isNumber, int numerator);
	Number(bool isNumber, char operation);
	Number();
	~Number();
};

