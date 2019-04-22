#ifndef Casino_h
#define Casino_h
#include "MainMenu.h"
#include <string>
#include <iostream>
#include <vector>




class Casino : public MainMenu{
public:
	Casino();
	void Bet(int, unsigned int& x);
	void Ccontinue();
	void ViewB();
	virtual void GameMenu();
	virtual void Help();
	int* cont;
	int pcont, hange;
	char q[1];
	std::string Cresponse;
	struct argm {
		int resultado;
		unsigned int apuesta;
	};
	/*BlackJack* num1;
	Roulette* num2;
	Hangman* num3;*/
	argm outcome;
	std::vector<argm> outco;
	std::vector<argm>::iterator it;
	static unsigned int Cbalance;
};
#endif