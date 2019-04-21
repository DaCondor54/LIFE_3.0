#ifndef Person_h
#define Person_h

#include "MainMenu.h"
#include "Casino.h"
#include<iostream>
#include <string>
#include <time.h>
class Person : public MainMenu {
public:
	Person();
	int totalm, chanceN, ites, ite, hours, odes, possibility;
	static int salaryp;
	std::string namez;
	void Name();
	void Salary();
	//void Age();
	//void Day();
	void Fired();
	void newjob();

};

#endif