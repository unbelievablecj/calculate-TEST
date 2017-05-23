#pragma once
#include<iostream>
using namespace std;
class Print
{
	static string s[10];
	FILE* file;
public:
	string scan(int n);
	Print(FILE* f);
	void init();
	Print();
	~Print();
};

