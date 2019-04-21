#ifndef MainMenu_h
#define MainMenu_h
class Person;
class Casino;
class BlackJack;
class Roulette;
class Hangman;
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <io.h>

class MainMenu {
public:
	MainMenu();
	void MMenu();
	virtual void ViewB();
	void Work(int& balances);
	int TotalE, counterD, bonuss, offday;
	static bool job;
	char Todo;
	std::string response;
	Person* per1;
	Casino* gam1;
	static BlackJack* num1;
	static Roulette* num2;
	static Hangman* num3;

protected:
	static int balance;
};
//Person
#endif
