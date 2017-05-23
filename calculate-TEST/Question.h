#pragma once
#include<string>
#include"Number.h"
using namespace std;
class Question
{
	string question;
	string answer;
	int randomNumber(int begin, int end);
	string randomOperation();
public:
	void setQuestion(string s);
	string getAnswer();
	string generateExpression();
	Question();
	~Question();
};

