#include "stdafx.h"
#include "Controller.h"
#include"Question.h"

char * Controller::getLanuage()
{
	FILE* f;
	f = fopen("language", "r");
	char l[1000];
	fgets(l,1000,f);
	cout << l;
	fgets(l, 1000, f);
	cout << l;
	static char lan[1000];
	char *a = lan;
	cin >> lan;
	fclose(f);
	f = fopen(lan, "r");
	while (f == NULL) {
		printf("目前不支持此语言，请重新输入:");
		scanf("%s", lan);
		f = fopen(lan, "r");
	}
	return a;
}

int Controller::getTotal()
{
	int n=-1;
	if (argc == 1)
	{
		cout << "n=";
		cin >> n;
		total = n;
		return n;
	}
	if (argc == 3)
	{
		FILE* f;
		f = fopen(*(argv + 1), "r");
		char c[1000];
		fgets(c, 1000, f);
		n = atoi(c);
		total = n;
		return n;
	}
	
	return -1;
}

void Controller::run()
{
	string question;
	string answer;
	string re;
	string exit("exit");
	int right = 0;
	int wrong = 0;
	out.scan(1);
	cout << endl;
	bool t=false;
	if (argc == 3)t = true;
	getTotal();
	FILE *f;
	//如果有参数，对文件指针进行设置
	if (t)
	{
		f = fopen(*(argv + 2), "w");
		char num[10]; itoa(total, num, 10);
		if (f != NULL) {
			fputs("n=", f);
			fputs(num, f);
			fputs("\n", f);
		}
	}
	Question q;
	for (int i = 1; i <= total; i++) {
		question=q.generateExpression();
		
		out.scan(2);
		cout << i << endl;
		cout << question<<"=";
		cin >> re;
		if (re == exit)
		{
			break;
		}
		answer = q.getAnswer();
		if (re == answer) {
			right++;
			out.scan(5);
			cout << answer<<endl;
			out.scan(6);
		}
		else
		{
			wrong++;
			out.scan(5);
			cout << answer << endl;
			out.scan(7);
		}
		cout << endl;
		if (t)
		{
			fputs(question.c_str(), f);
			fputs("=", f);
			fputs(answer.c_str(), f);
			fputs("\n", f);
			fputs(re.c_str(), f);
			fputs("\n", f);
		}
	}
	out.scan(8);
	cout << right << endl;
	out.scan(9);
	cout << wrong << endl;
}

void Controller::start()
{
	char *ch=getLanuage();
	out.init(ch);
	run();
}

Controller::Controller(int argc, char * argv[])
{
	this->argc = argc;
	this->argv = argv;
}


Controller::Controller()
{
	argc = 1;
	argv = NULL;
}


Controller::~Controller()
{
}
