#include "Casino.h"
#include "BlackJack.h"
#include "Roulette.h"
#include "Hangman.h"

using namespace std;
unsigned int Casino::Cbalance = 0;
Casino::Casino()
{
	hange = 0;
	pcont = 0;
	cont = &pcont;
	q = '\0';
	outcome.apuesta = 0;
	outcome.resultado = 0;
}

//**********This is beginning to Cmenu func********** 
void Casino::GameMenu() {
	/*num1 = &b1;
	num2 = &r1;
	num3 = &h1;*/
	cout << "would you like to enter the Casino: : ";
	cin >> Cresponse;
	if (Cresponse == "yes") {
		cout << "\n\n********WELCOME TO THE CASINO********\n";
		Cbalance = balance;
		do {
			hange = rand() % 5 + 1;
			if (hange == 1) {
				cout << "\nWhat would you like to do?\nRoulette(r), BlackJack(b), Check balance(b), to exit(e), HangueMan(h) : ";
			}
			else {
				cout << "\nWhat would you like to do?\nRoulette(r), BlackJack(b), Check balance(b), to exit(e): ";
			}
			cin >> q;
			switch (q) {
			case 'r': {  num2->GameMenu();	break; }
			case 'b': { num1->GameMenu();	break; }
			case 'v': { this -> ViewB(); 	break; }
			case 'h': {if (hange == 1) { num3->GameMenu();} break; }
			}
			if (q != 'r' && q != 'b' && q != 'v' && q != 'h' && q != 'e') {
				cout << "That isn't an option\n\n";
			}
		} while (Cbalance > 0 && q != 'e');

		if (Cbalance <= 0) {
			this_thread::sleep_for(chrono::seconds(2));
			cout << "YOU'RE BROKE!\n";
		}
		balance = Cbalance;
		cout << "Goodbye\n";
		this_thread::sleep_for(chrono::seconds(1));
	}
	else {
		cout << "Goodbye\n\n";
	}
}

//**********This is beginning to Bet func**********
void Casino::Bet(int bob,unsigned int& x) {

	switch (bob) {
	case 1: { do {
		cout << "How much would you like to bet?: ";
		cin >> outcome.apuesta;
		while (cin.fail()) {
			cout << "\n\n*****INVALID BET*****\n";
			cin.clear();
			cin.ignore(256, '\n');
			cout << "How much would you like to bet?: ";
			cin >> outcome.apuesta;
		}
		if (outcome.apuesta > x) {
			cout << "\n\nYOU DON'T HAVE ENOUGH MONEY\n";
		}
		else if (outcome.apuesta == 0) {
			cout << "\n\nYOU NEED TO AT LEAST BET SOMETHING\n";
		}
	} while (outcome.apuesta > x || outcome.apuesta <= 0);
	break; }
	case 2: {  x += it->apuesta;
		cout << "*****YOU WON*****\n       " << it->apuesta << "$\n\n";
		break; }
	case 3: {x -= it->apuesta;
		this_thread::sleep_for(chrono::seconds(2));
		cout << "*****YOU LOST***** \n       " << it->apuesta << "$\n\n";
		break; }
	case 4: {this_thread::sleep_for(chrono::seconds(2)); cout << "\n*****NO WINNER*****\n\n"; break; }
	}
}
void Casino::Ccontinue() {
	if (Cbalance > 0) {
		cout << "Would you like to continue?(0), any other key to exit: ";
		outco.clear();
		cin >> *cont;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			*cont = 1;
		}
	}
	else {
		*cont = 1;
	}
}
void Casino::ViewB() {
	cout << "\nYou have: " << Cbalance << "$ in your bank account\n\n";
}