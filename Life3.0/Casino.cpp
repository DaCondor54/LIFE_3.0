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
	q[0] = '\0';
	outcome.apuesta = 0;
	outcome.resultado = 0;
}

//**********This is beginning to Cmenu func********** 
void Casino::GameMenu() {
	cout << "would you like to enter the Casino: : ";
	cin >> Cresponse;
	if (Cresponse == "yes") {
		cout << "\n\n********WELCOME TO THE CASINO********\n";
		Cbalance = balance;
		do {
			hange = rand() % 5 + 1;
			if (hange == 1) {
				cout << "\nWhat would you like to do?\nRoulette(r), BlackJack(b), Check balance(b), to exit(e), HangueMan(h), Info(i) : ";
			}
			else {
				cout << "\nWhat would you like to do?\nRoulette(r), BlackJack(b), Check balance(b), to exit(e), Info(i): ";
			}
			cin >> q[0];
			switch (q[0]) {
			case 'r': {cin.clear(); cin.ignore(256, '\n');  num2->GameMenu();	break; }
			case 'b': {cin.clear(); cin.ignore(256, '\n'); num1->GameMenu();	break; }
			case 'v': {cin.clear(); cin.ignore(256, '\n'); this -> ViewB(); 	break; }
			case 'h': {cin.clear(); cin.ignore(256, '\n'); if (hange == 1) { num3->GameMenu();} break; }
			case 'i': {cin.clear(); cin.ignore(256, '\n'); Help(); }
			}
			if (q[0] != 'r' && q[0] != 'b' && q[0] != 'v' && q[0] != 'h' && q[0]!= 'e' && q[0] != 'i') {
				cout << "That isn't an option\n\n";
			}
		} while (Cbalance > 0 && q[0] != 'e');

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

void Casino::Help() {
	cout << "This is the Casino!!!\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Here you caan play several different games\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "you can play BlackJack, Roulette and slot\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "In those games you can win lots of money!!!\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "There's another game too Hangman!\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "where you can win a lot more but it's dangerouse be careful\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Would you like to know more on one particular game\n";
	cout << "roulette , blackjack or hangman :";
	this_thread::sleep_for(chrono::seconds(2));
	cin >> q[0];
	switch (q[0]) {
	case 'b': {
		cin.clear(); cin.ignore(256, '\n');
		cout << "\n\nBlackJack\n\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "BlackJack is a game where it's player vs delear\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "Both player and dealer receive two cards\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout <<	"the player's card are face up and one of the dealer's cards is face down\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "the goal of the game is to have more than the dealer\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "if you have 21 then it's a black jack and you get paid 2:3\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout <<	"if you more than 21  it's a bust and you loose the game\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "every card is face value except for the king, queen and jack that are 10 and As is 1 or 11\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "you can hit cards to get more cards\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "the dealer always needs to have at least 17 but he can sometimes get more than 21 and you win\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "you can also split if you have 2 cards of the same value and your bet doubles too\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << " you can double down, your bet doubles and you can only get 1 more card\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "that's it now good luck\n\n"; break;
	}
	case 'r': {
		cout << "Roulette\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "In roulette you have to put your chips in the betting field\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "when all bet's are placed the dealer spins the roulette and releases the ball\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "You'll win if the ball lands on a number that correspond to the bet you made\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "in roulette there are several bets where you can win lots or a little bit of money\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "you can bet make an inside bet\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "a srtaight bet means you bet on 1 number of 36 and you get paid 1:35\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "a split where you bet on 2 adjacent numbers and pays 1:17\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "a corner where you bet on a square of 4 numbers and pays 1:8\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "a street where you bet on a vertcal line of 3 numbers and pays 1:11\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "a double street where you bet on 2 adjacent vertoval lines  of 3 numbers each and pays 1:5\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "you can also make outside bets\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "even or odd where you bet Even or odd and get paid 1:1\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "black or red where you bet on a black or red(~) numbers and get paid 1:1\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "twelves where you bet on sets of twelve numbers and gets paid 1:2\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "1 to 18 and 19 to 36 where you bet on 1 to 18 or 19 to 36 and get paid 1:1\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "columns where you bet on horizontal lines of numbers and gets paid 1:2\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "thats it for Roulette\n\n"; break;
		
	}
	case 'h': {
		cout << "!!!!!!hangman!!!!!!\n";
		this_thread::sleep_for(chrono::seconds(5));
		cout << "NO INFORMATION FOR THIS SUBJECT\n\n"; break;
	}
	}
}