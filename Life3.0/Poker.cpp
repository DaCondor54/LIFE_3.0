#include "Poker.h"
using namespace std;
Poker::Poker()
	:P_Money(0), P_balance(1000), Pot(0), enterT(0), P_Table(0), Min_Entry(0), Max_Entry(0), contit(0), choice_P(0), Your_Bet(0), Round_Call(0), Your_Raise(0)
{
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
				firstR();
				PlayerP();
			}



			cin >> contit;
		} while (contit == 0);
	}
	else {
		cout << "have a nice day";
	}
	MyHand.clear();
		TheirHand.clear();
}
void Poker::PlayerP() {
	cout << "it's your turn, what would you like to do ?\n";
	do {
	cout << "Stay(0), Call(1), Raise(2), All - in(3), Tip dealer(4)\n";
	cin >> choice_P;
	if (choice_P < 0 || choice_P > 3) {
		cout << "this is not a choice\n";
	}
	} while (choice_P < 0 || choice_P > 3);
		
		switch (choice_P) {
		case Stay_P: {Stay(); break; }
		case Call_P: {Call(); break; }
		case Raise_P: {Raise(); break; }
		case AllIn_P: {All_In(); break; }
		default: cout << "this is not a choice";
		}

}


void Poker::firstR()
{
	for (int i = 0; i < 2; i++)
	{
		cards.value = rand() % 13 + 2;
		int x = rand() % 4;
		switch (x) {
			case 0: {cards.suit = "hearts"; break; }
			case 1: {cards.suit = "spades"; break; }
			case 2: {cards.suit = "clubs"; break; }
			case 3: {cards.suit = "diamonds"; break; }

		}
		MyHand.push_back(cards);
	}
	for (it1 = MyHand.begin(); it1 != MyHand.end(); ++it1) {
		cout << "\nyour cards are " << it1->value << " " << it1->suit << "\n\n";
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
	cout << "MINIMUM BUY-IN: " << Min_Entry << "\nMAXIMUM BUY-IN" << Max_Entry << endl;
}

void Poker::Stay() {
	cout << "you stayed\n";
}

void Poker::Call() {
	Your_Bet = Round_Call;
	Pot += Round_Call;
	P_Money -= Round_Call;
	cout << "you called : " << Round_Call << "$\n";
}
void Poker::Raise() {
	do {
		cout << "how much would you like to raise : ";
		cin >> Your_Raise;
		if (Your_Raise < Round_Call) {
			cout << "this is not enought\n";
		}
		else if (Your_Raise > P_Money) {
			cout << "you don't have enough\n";
		}
	} while (Your_Raise < Round_Call || Your_Raise > P_Money);
	Your_Bet += Your_Raise;
	Pot += Your_Raise;
	P_Money -= Your_Raise;
	cout << "you raised : " << Your_Raise << "$\n";
}
void Poker::All_In() {
	Your_Bet += P_Money;
	Pot = +P_Money;
	P_Money = 0;
	cout << "you went all in with : " << Your_Bet << "$\n";
}

