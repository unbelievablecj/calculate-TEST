#pragma once
#include"Print.h"
class Controller
{
	int argc;
	char** argv;
	char* language;
	int total;
	Print out;
	//得到语言种类
	char* getLanuage();
	int getTotal();
	void run();
public:
	void start();
	Controller(int argc, char* argv[]);
	Controller();
	~Controller();
};

