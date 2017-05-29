#include"stdafx.h"
#include<iostream>
#include"Controller.h"
using namespace std;
int main(int argc,char*argv[]) {
	if (argc == 1) {
		Controller c;
		c.start();
	}
	else {
		Controller c = Controller(argc, argv);
		c.start();
	}
	
	system("pause");
	return 0;
}
	
