#ifndef Hangman_h
#define Hangman_h

#include "Casino.h"
#include <vector>
#include <iostream>
#include <string>

//extern std::string arrname[27];

class Hangman : public Casino {
public:
	Hangman();
	void GameMenu();
	void set();
	void stage();
	void check();
	void findme();
	void printme();
	void superprint();
	int rep, error, choice, i, sup, death;
	std::size_t gro, counter;
	bool isit, decision, isit2;
	char x;
	std::size_t a, com;
	std::vector<char> v;
	std::vector<char>::iterator itera;
	std::vector<char> wrong;
	std::vector<char>::iterator itero;
	std::string special;
	std::vector<std::string> supa;
	std::vector<std::string>::iterator its;
	//std::string arrname[27];




};

#endif
