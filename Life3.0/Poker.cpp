#include "Poker.h"
using namespace std;
Poker::Poker(){
	P_Money = 0;
	P_balance = 1000;
	Pot = 0;
	enterT = 0;
	P_Table = 0;
	Min_Entry = 0;
	Max_Entry = 0;
	contit = 0;
	cards.value = 0;
	cards.suit = '\0';
}

void Poker::gameMenu() {
	 cout << "\n*******WELCOME TO POKER*******\n";
	cout << "would you like to enter the table(1) : ";
	cin >> enterT;
	if (enterT == 1) {
		do {
			EnterR();
			if (Min_Entry != 1) {
				BuyIn();
			}
		


			cin >> contit;
		} while (contit == 0);
	}
	else {
		cout << "have a nice day";
	}
}

void Poker::BuyIn() {
	do {
		cout << "For how much would you like to buy in: ";
		cin >> P_Money;
		while (cin.fail()) {
			cout << "\n\n****INVALID BUY IN****\n";
			cin.clear();
			cin.ignore(256, '\n');
			cout << "For how much would you like to buy in: ";
			cin >> P_Money;
		}
		if (P_Money > P_balance) {
			cout << "\n\nYOU DON'T HAVE ENOUGH MONEY\n";
		}
		else if (P_Money < Min_Entry) {
			cout << "\n\nYOU NEED AT LEAST " << Min_Entry << "$ TOO BUY IN AT THIS TABLE\n";
		}
		else if (P_Money > Max_Entry) {
			cout << "\n\nYOU CAN'T BUY IN WITH MORE THAN " << Max_Entry << "$\n";
		}
	} while (P_Money > P_balance || P_Money  < Min_Entry || P_Money > Max_Entry);

}

void Poker::EnterR() {
	cout << "\nWhat table would you like to enter\n"
		<< "5:10(0), 10:20(1), 20:40(3), 50:100(4), 100:200(5) : ";
	cin >> P_Table;
	switch (P_Table) {
	case 0: {Min_Entry = 100; Max_Entry = 2000; break; }
	case 1: {Min_Entry = 200; Max_Entry = 4000; break; }
	case 2: {Min_Entry = 400; Max_Entry = 8000; break; }
	case 3: {Min_Entry = 1000; Max_Entry = 20000; break; }
	case 4: {Min_Entry = 2000; Max_Entry = 40000; break; }
	default: {cout << "you didn't enter a table\n"; Min_Entry = 1; break; }
	}
}
