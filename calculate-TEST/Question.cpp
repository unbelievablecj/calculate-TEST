#include "stdafx.h"
#include "Question.h"
#include<math.h>
#include<ctime>
#include<sstream>
#include<stdlib.h>
#include<string>
#include"Number.h"
#include<stack>
using namespace std;

int Question::randomNumber(int start, int end)
{
	
	return start + (end - start)*rand() / (RAND_MAX + 1.0);
}

string Question::randomOperation()
{
	
	int n;
	n = randomNumber(1, 5);
	string aa;
	if (n == 1)
		aa = '+';
	if (n == 2)
		aa = '-';
	if (n == 3)
		aa = '*';
	if (n == 4)
		aa = '/';
	return aa;
}

string Question::getQuestion()
{
	return question;
}

void Question::setQuestion(string s)
{
	question = s;
}

string Question::getAnswer()
{
	//�沨��ջ
	stack<Number> n;
	//������ջ
	stack<Number> o;
	//����ȡ�����ַ�����
	stringstream ss;
	ss << question;

	int i;
	//�жϽ���
	char eof;
	//������
	char op;
	//����
	int nu;
	eof = ss.peek();
	//ʹ���沨��ʽ
//�����ʽ����ȷʱ�������ֲ������
	while (eof != EOF) {
		if (eof >= '0'&&eof <= '9') {
			ss >> nu;
			n.push(Number(true, nu));
		}
		if (eof == '(') {
			ss >> op;
			o.push(Number(false, '('));
		}
		if (eof == '-' || eof == '+') {
			ss >> op;
			while (!o.empty()&&o.top().getOperation()!='(')
			{
				char c = o.top().getOperation();

				Number n1;
				n1 = n.top();
				n.pop();
				switch (c)
				{
				case('-'):
				{
					n1 = n.top() - n1;
					break;
				}
				case('+'):
				{
					n1 = n1 + n.top();
					break;
				}
				case('*'):
				{
					n1 = n1*n.top();
					break;
				}
				case('/'):
				{
					n1 = n.top() / n1;
					break;
				}
				break;
				default:
					break;
				}
				
				n.pop();
				n.push(n1);
				o.pop();
				
			}
			o.push(Number(false, eof));
		}
		if (eof == '*' || eof == '/')
		{
			ss >> op;
			while (!o.empty()&&(o.top().getOperation()=='*'||o.top().getOperation()=='/'))
			{
				op = o.top().getOperation();
				Number n1;
				n1 = n.top();
				n.pop();
				if (op == '*') {
					n1 = n1*n.top();
				}
				if (op == '/') {
					n1 = n.top() / n1;
				}
				n.pop();
				n.push(n1);
				o.pop();
			}
			o.push(Number(false, eof));
		}
		if (eof==')') {
			ss >> op;
			while (!o.empty() && o.top().getOperation() != '(')
			{
				char c = o.top().getOperation();

				Number n1;
				n1 = n.top();
				n.pop();
				switch (c)
				{
				case('-'):
				{
					n1 = n.top() - n1;
					break;
				}
				case('+'):
				{
					n1 = n1 + n.top();
					break;
				}
				case('*'):
				{
					n1 = n1*n.top();
					break;
				}
				case('/'):
				{
					n1 = n.top() / n1;
					break;
				}
				break;
				default:
					break;
				}

				n.pop();
				n.push(n1);
				o.pop();

			
			}
			o.pop();
			
		}
		
		eof = ss.peek();
	}
	//��ʱo�п��ܻ����������
	
	while (!o.empty())
	{
		char c = o.top().getOperation();

		Number n1;
		n1 = n.top();
		n.pop();
		switch (c)
		{
		case('-'):
		{
			n1 = n.top() - n1;
			break;
		}
		case('+'):
		{
			n1 = n1 + n.top();
			break;
		}
		case('*'):
		{
			n1 = n1*n.top();
			break;
		}
		case('/'):
		{
			n1 = n.top() / n1;
			break;
		}
		break;
		default:
			break;
		}

		n.pop();
		n.push(n1);
		o.pop();


	}
	Number n1 = n.top();
	ss.str("");
	pair<int, int> nn;
	nn= n1.getNum();
	//��nn����Լ��
	for (i = 2; i <= nn.second; i++) {
		if (nn.first%i == 0 && nn.second%i == 0) {
			nn.first = nn.first / i;
			nn.second = nn.second / i;
			i--;
		}
	}
	
	ostringstream sss;
	sss << nn.first;
	if (nn.second != 1) {
		sss << '/' << nn.second;
	}
	answer = sss.str();
	return answer;
}

string Question::generateExpression()
{
	//srand(unsigned(time(0)));
	string theQuestion;
	int num[5];
	string a_1[5];
	int i, t, k;

	for (i = 1; i <= 4; i++)
	{
		num[i] = randomNumber(1, 11);
	}

	for (i = 1; i<4; i++)
	{
		a_1[i] = randomOperation();



	}
	for (i = 1; i <= 3; i++)
	{
		if (a_1[i] == "-")
		{
			for (; num[i] <= num[i + 1];)
			{
				num[i + 1] = randomNumber(0, 10);/*�������Ū������0-9�������������Ū��  (number[t]<number[t+1])  �Ƿ�ֹ����1-1��10-10���ȵȵ���� */
				if (num[i] == 0)
				{
					num[i] = randomNumber(1, 11);/*���if�������ǵ�number[t]=0ʱ��number[t+1]��СҲֻ��0����������ѭ�������ԣ���ֹnumber[t]=0.*/
				}
			}
		}
	}

	for (i = 1; i <= 3; i++)
	{
		if (a_1[i] == "/")
		{
			double theMiddle, a, b;//���theMiddle�������жϳ����᲻�����С������֮��ġ�
			int theMiddle_1;
			a = (double)(num[i]);
			b = (double)(num[i + 1]);
			theMiddle = a / b;
			theMiddle_1 = (int)(theMiddle);
			for (; theMiddle != theMiddle_1;)
			{
				num[i + 1] = randomNumber(1, 11);
				b = (double)(num[i + 1]);
				theMiddle = a / b;
				theMiddle_1 = (int)(theMiddle);
			}
		}
	}

	a_1[4] = '=';

	string theNumber[5];
	for (int m = 1; m <= 4; m++)
	{
		for (int n = 0; n <= 10; n++)
		{
			if (num[m] == n)
			{
				ostringstream oss;
				oss << n;
				theNumber[m] = oss.str();
			}
		}
	}//���õ���int����ת��Ϊstring�͡� 

	int brackets;//brackets�����ŵ���˼������һ��ͨ���������ȷ�����š� 
	brackets = randomNumber(1, 20);/*���brackets==1����ǰ�����������ţ��Դ����Ƶõ�������������š�Ϊ�������ų��ֵĸ��ʽ��Ͱ�������ķ�Χ�����ˡ�*/
	if (brackets == 1)
//��Ҫ�Ⱥ�
		theQuestion = "(" + theNumber[1] + a_1[1] + theNumber[2] + ")" + a_1[2] + theNumber[3] + a_1[3] + theNumber[4];// +a_1[4];
	else if (brackets == 2)
		theQuestion = theNumber[1] + a_1[1] + "(" + theNumber[2] + a_1[2] + theNumber[3] + ")" + a_1[3] + theNumber[4];// +a_1[4];
	else if (brackets == 3)
		theQuestion = theNumber[1] + a_1[1] + theNumber[2] + a_1[2] + "(" + theNumber[3] + a_1[3] + theNumber[4] + ")";// +a_1[4];
	else if (brackets == 4)
		theQuestion = "(" + theNumber[1] + a_1[1] + theNumber[2] + a_1[2] + theNumber[3] + ")" + a_1[3] + theNumber[4];// +a_1[4];
	else if (brackets == 5)
		theQuestion = theNumber[1] + a_1[1] + "(" + theNumber[2] + a_1[2] + theNumber[3] + a_1[3] + theNumber[4] + ")";// +a_1[4];
	else
		theQuestion = theNumber[1] + a_1[1] + theNumber[2] + a_1[2] + theNumber[3] + a_1[3] + theNumber[4];// +a_1[4];
	question = theQuestion;
	return theQuestion;
}

Question::Question()
{
}


Question::~Question()
{
}
