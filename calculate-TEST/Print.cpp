#include "stdafx.h"
#include "Print.h"


char* Print::scan(int n)
{
	cout << s[n];
	return s[n];
}

Print::Print(FILE * f)
{
}

void Print::init(char *lan)
{
	file = fopen(lan, "r");
	fgets(s[1], 1000, file);
	s[1][strlen(s[1]) - 1] = '\0';
	fgets(s[2], 1000, file);
	s[2][strlen(s[2]) - 1] = '\0';
	fgets(s[3], 1000, file);
	s[3][strlen(s[3]) - 1] = '\0';
	fgets(s[4], 1000, file);
	s[4][strlen(s[4]) - 1] = '\0';
	fgets(s[5], 1000, file);
	s[5][strlen(s[5]) - 1] = '\0';
	fgets(s[6], 1000, file);
	s[6][strlen(s[6]) - 1] = '\0';
	fgets(s[7], 1000, file);
	s[7][strlen(s[7]) - 1] = '\0';
	fgets(s[8], 1000, file);
	s[8][strlen(s[8]) - 1] = '\0';
	fgets(s[9], 1000, file);
	s[9][strlen(s[9]) - 1] = '\0';
}

Print::Print()
{
}


Print::~Print()
{
}
