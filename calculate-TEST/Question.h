#pragma once
#include<string>
#include"Number.h"
using namespace std;
class Question
{
	//����
	string question;
	//��
	string answer;
	// �õ��������
	int randomNumber(int begin, int end);
	//�õ����������
	string randomOperation();
public:
	string getQuestion();
	//��������
	void setQuestion(string s);
	//����question�õ��𰸣�����answer
	string getAnswer();
	//�������question
	string generateExpression();
	Question();
	~Question();
};

