#pragma once
#include<iostream>
using namespace std;
class Number
{
	//判断是否为数字
	bool isNumeber;
	//分子
	int numerator;
	//分母
	int denominator;
	//运算符
	char operation;
public:
	//重构运算符
	Number operator+(Number& a);
	Number operator-(Number& a);
	Number operator*(Number& a);
	Number operator/(Number& a);
	
	bool getIs();
	char getOperation();
	pair<int, int> getNum();
	//构造函数
	Number(bool isNumber, int numerator, int denominator);
	Number(bool isNumber, int numerator);
	Number(bool isNumber, char operation);
	Number();
	~Number();
};

