#pragma once
#include"Print.h"
class Controller
{
	int argc;
	char** argv;
	char* language;
	int total;
	Print out;
	char* getLanuage();
	int getTotal();
	void run();
public:
	void start();
	Controller(int argc, char* argv[]);
	Controller();
	~Controller();
};

