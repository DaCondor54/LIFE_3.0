# include "MainMenu.h"
#include "Person.h"
#include "Casino.h"
#include "BlackJack.h"
#include "Roulette.h"
#include "Hangman.h"
//#include <iostream>

using namespace std;

bool MainMenu::job = 1;
unsigned int MainMenu::balance = 0;
BlackJack *(MainMenu::num1) = new BlackJack;
Roulette* (MainMenu::num2) = new Roulette;
Hangman* (MainMenu::num3) = new Hangman;
MainMenu::MainMenu()
	/*:num1(NULL), num2(NULL), num3(NULL)*/
{
	job = 1;
	num1 = NULL;
	num2 = NULL;
	num3 = NULL;
	gam1 = NULL;
	per1 = NULL;
	response = "\0";
	srand((unsigned int)time(NULL));
	balance = rand() % 1000 + 100;
	Todo[0] = '\0';
	TotalE = 0;
	counterD = 0; bonuss = 0; offday = 0;

}

void MainMenu::MMenu() {
	BlackJack b1;
    Roulette  r1;
    Hangman h1;
	Person p1;
	Casino g1;
	gam1 = &g1;
	per1 = &p1;
	num1 = &b1;
	num2 = &r1;
	num3 = &h1;
	cout << "**********WELCOME TO LIFE**********\n";
	cout << "************VERSION 3.2************\n";
	cout << "would you like to play: ";
	cin >> response;
	if (response == "yes") {
		per1->Name();
		job = 1;
		cout << "You have: " << balance << "$\n";
		do {
			if (job == 0) {
				cout << "\nWhat would you like to do?\nGo to the Casino(c), Check balance(v), Search for a job(f), Info(i): ";
			}
			else {
				cout << "\nWhat would you like to do?\nGo to the Casino(c), Check balance(v), Go to work(p), Info(i) : ";
			}
			cin >> Todo[0];
			switch (Todo[0]) {
				case 'v': {	cin.clear();cin.ignore(256, '\n'); this->ViewB(); break; }
				case 'c': {cin.clear(); cin.ignore(256, '\n'); gam1->GameMenu(); break; }
				case 'p': {cin.clear(); cin.ignore(256, '\n'); if (job == 1) { per1->Salary(); } else { cout << "You don't have a job\n"; }break; }
				case 'f': {cin.clear(); cin.ignore(256, '\n'); if (job == 0) { per1->newjob(); } else { cout << "You have a job\n"; }; break; }
				case 'i': {cin.clear(); cin.ignore(256, '\n');this ->info(); break; }
			}
			if (Todo[0] != 'v' && Todo[0] != 'c' && Todo[0] != 'p' && Todo[0] != 'f' && Todo[0] != 'e' && Todo[0] != 'i') {
				cout << "That isn't an option\n\n";
			}
		} while (Todo[0] != 'e');
		cout << "Goodbye\n";
	}
	else {
		cout << "Goodbye Have a nice day\n";
	}
}

void MainMenu::Work(unsigned int& balances) {
	balances += TotalE;
			string arrwork = "Working...";
			for (int x = 0; x < 11; x++) {
				cout << arrwork[x] << flush;
				this_thread::sleep_for(chrono::milliseconds(500));
			}
			counterD++;
			cout << "\n\n\nDay " << counterD << "\n";
			if (bonuss > 0) {
				cout << "Your boss was feeling generous, he gave you a bonus of " << bonuss << "$\n";
			}
			cout << "You Gained! " << TotalE << "$\n";
			
}
void MainMenu::ViewB() {
	cout << "\nYou have: " << balance << "$ in your bank account\n\n";
}

void MainMenu::info() {
	this_thread::sleep_for(chrono::seconds(1));
	cout << "This is some basic info\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "This is a little game where you can go at the casino, work, check your balance and if you loose your job you can search for a new one \n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "The goal of the game is to become a sort of life simulator\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "It tries at least\n";
	this_thread::sleep_for(chrono::seconds(1));
}
