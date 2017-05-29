#pragma once
#include<iostream>
using namespace std;
class Number
{
	//�ж��Ƿ�Ϊ����
	bool isNumeber;
	//����
	int numerator;
	//��ĸ
	int denominator;
	//�����
	char operation;
public:
	//�ع������
	Number operator+(Number& a);
	Number operator-(Number& a);
	Number operator*(Number& a);
	Number operator/(Number& a);
	
	bool getIs();
	char getOperation();
	pair<int, int> getNum();
	//���캯��
	Number(bool isNumber, int numerator, int denominator);
	Number(bool isNumber, int numerator);
	Number(bool isNumber, char operation);
	Number();
	~Number();
};

