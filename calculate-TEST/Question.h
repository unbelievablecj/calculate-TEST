#pragma once
#include<string>
#include"Number.h"
using namespace std;
class Question
{
	//问题
	string question;
	//答案
	string answer;
	// 得到随机数字
	int randomNumber(int begin, int end);
	//得到随机操作符
	string randomOperation();
public:
	string getQuestion();
	//设置问题
	void setQuestion(string s);
	//根据question得到答案，设置answer
	string getAnswer();
	//随机设置question
	string generateExpression();
	Question();
	~Question();
};

