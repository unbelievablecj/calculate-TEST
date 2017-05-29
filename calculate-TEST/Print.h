#pragma once
#include<iostream>
using namespace std;
class Print
{
	char s[10][1000];
	FILE* file;
public:
	char* scan(int n);
	Print(FILE* f);
	void init(char *lan);
	Print();
	~Print();
};

