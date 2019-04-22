#include "Roulette.h"
using namespace std;

Roulette::Roulette() {
	n = 0;
	chipsr = 0;
	numberr = 0;
	decision = 0;
	ba = 0;
	place = 0;
	resultr = 0;
	ball = 0;
	place2 = 0;
	col = 0;
	wino = 0;
}

/*
//**********This is beginning to ROULETTE func**********boby
void Roulette::Play() {
	cout << "\n*****WELCOME TO ROULETTE*****\n";
	do {
		this_thread::sleep_for(chrono::seconds(1));
		Bet(1, balance);
		cout << "Even(0) or Odd(1): ";
		cin >> n;
		outcome.resultado = rand() % 36 + 1;
		this_thread::sleep_for(chrono::seconds(1));
		cout << outcome.resultado << endl;
		outcome.resultado = outcome.resultado % 2;
		this_thread::sleep_for(chrono::seconds(1));
		outco.push_back(outcome);
		if (outcome.resultado == n) {
			for (it = outco.begin(); it != outco.end(); ++it) {
				Bet(2, balance);
			}
		}
		else {
			for (it = outco.begin(); it != outco.end(); ++it) {
				Bet(3, balance);
			}
		}
		Bet(4, balance);
	} while (*cont == 0);
}*/

void Roulette::GameMenu() {
	std::cout << "\n*****WELCOME TO ROULETTE*****\n";
	do {
		ball = rand() % 37;
		cout << "\nhow much chips would you like to have\n";
		cin >> chipsr;
		do {
			ba = 0; wino = 0;
			megaprint();
			cout << "\nwould you like to bet inside(0) or outside(1) : ";
			cin >> decision;
			if (decision == T_Inside) {
				Inside();
			}
			else if(decision == T_Outside){
				Outside();
			}
			if (ba != 1) {
				outcome.resultado = 0;
				outco.push_back(outcome);
			}
		} while (chipsr > 0);
		cout << "\n\nAnd the result is : " << ball << "\n\n";
		for (it = outco.begin(); it != outco.end(); ++it) {
			if (it->resultado == 1) {
				it->apuesta;	
				Bet(2, Cbalance);
			}
			else if (it->resultado == 0) {
				it->apuesta;
				Bet(3, Cbalance);
			}
		}
		Ccontinue();
	} while (*cont == 0);
}
void Roulette::Inside() {
	cout << "\nstraight bet(0), split bet(1) , corner bet(2), street bet(3), double street bet(4) : ";
	cin >> n;
	if (n == I_straight) {
		withinrange();
		howmany();
		checkchipsr();
		if (place == ball) {
			outcome.apuesta *= 35;
			Youwon();
		}
	}
	else if (n == I_split) {
		withinrange();
		do {
			wino = 0;
			cout << "with what other number would you like to bet ";
			cin >> place2;
			for (int j = 1; j < 4; j++) {
				for (int i = j; i <= 36; i += 3) {
					if (ball == i) {
						col = j;
					}
				}
			}
			if (place == 1 || place == 2 || place == 34 || place == 35 || place == 36 || place == 0) {

				if (place == 1 && (place2 == (place + 3) || place2 == (place + 1) || place2 == (place - 1))) {
					wino = 1;
				}
				else if (place == 2 && (place2 == (place + 3) || place2 == (place + 1) || place2 == (place - 1) || place2 == (place -2))) {
					wino = 1;
				}
				else if (place == 34 && (place2 == (place - 3) || place2 == (place + 1))) {
					wino = 1;
				}
				else if (place == 35 && (place2 == (place - 3) || place2 == (place - 1) || place2 == (place + 1))) {
					wino = 1;
				}
				else if (place == 36 && (place2 == (place - 3) || place2 == (place - 1))) {
					wino = 1;
				}
				else if (place == 0 && (place2 == (place + 1) || place2 == (place + 2) || place2 == (place + 3))) {
					wino = 1;
				}
			}
			else if (place != 1 && place != 2 && place != 34 && place != 35 && place != 36 && place != 0) {
				if (col == 2 && (place2 == (place - 3) || place2 == (place + 3) || place2 == (place - 1) || place2 == (place + 1))) {
					wino = 1;
				}
				else if (col == 1 && (place2 == (place - 3) || place2 == (place + 3) || place2 == (place + 1))) {
					wino = 1;
				}
				else if (col == 3 && (place2 == (place - 3) || place2 == (place + 3) || place2 == (place - 1))) {
					wino = 1;
				}
			}
			if (wino != 1) {
				cout << "invalid placement\n";
			}
		}while(wino != 1);
		howmany();
		checkchipsr();
		if (ball == place || ball == place2) {
			outcome.apuesta *= 17;
			Youwon();
		}
	}
	else if (n == I_corner) {
		withinrange();
		do {
			wino = 0;
			cout << "\nin what horizontal line would you like to bet(1) or(2) ";
			cin >> place2;
			if (place2 == 1 || place2 == 2) {
				wino = 1;
			}
			else{
				cout << "Invalid placement\n";
			}
		} while (wino != 1);
		howmany();
		checkchipsr();
		for (int i = 0; i < 5; i++) {
			if (ball == (place2 + ((place-1)*3) + i) && (i == 0 || i == 1 || i == 3 || i == 4)) {
				outcome.apuesta *= 8;
				Youwon();
			}
		}
	}
	else if (n == I_street) {
		withinrange();
		howmany();
		checkchipsr();
		for (int i = 1; i < 4; i++) {
			if (ball == ((place * 3) - i)) {
				outcome.apuesta *= 11;
					Youwon();
			}
		}
	}
	else if (n == I_Dstreet) {
		withinrange();
		howmany();
		checkchipsr();
		for (int i = 1; i < 7; i++) {
			if (ball == (((place- 1)*3) + i)) {
				outcome.apuesta *= 5;
				Youwon();
			}
		}
	}
}

void Roulette::Outside() {
	int reda[18] = { 1, 3,5, 7, 9, 12, 14, 16, 18, 21, 23, 25,27, 28, 30, 32, 34, 36 };
	int blacka[18] = { 2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 20, 22, 24, 26, 29, 31, 33, 35 };
	cout << "EVEN(0), ODD(1), RED(2), BLACK(3), 1 TO 18(4), 19 TO 36(5),1st 12(6), columns(7) : ";
	cin >> n;
	howmany();
	checkchipsr();
	resultr = ball % 2;
	if (resultr == n && (n == O_EVEN || n == O_ODD)) {
		Youwon();
	}
	for (int i = 0; i < 18; i++) {
		if (ball == reda[i] && n == O_RED) {
			Youwon();
		}
	}
	for (int i = 0; i < 18; i++) {
		if (ball == blacka[i] && n == O_BLACK) {
			Youwon();
		}
	}
	if (ball >= 1 && ball <= 18 && n == O_1to18) {
		Youwon();
	}
	else if (ball >= 19 && ball <= 36 && n == O_19to36) {
		Youwon();
	}
	if (n == O_Twelve || n == O_Columns) {
		col12();
		if (ball >= 1 && ball <= 12 && n == O_Twelve && place == 1) {
			outcome.apuesta *= 2;
			Youwon();
		}
		else if (ball >= 13 && ball <= 24 && n == O_Twelve && place == 2) {
			outcome.apuesta *= 2;
			Youwon();
		}
		else if (ball >= 25 && ball <= 36 && n == O_Twelve && place == 3) {
			outcome.apuesta *= 2;
			Youwon();
		}
		for (int j = 1; j < 4; j++) {
			for (int i = j; i <= 36; i += 3) {
				if (ball == i && place == j && n == O_Columns) {
					outcome.apuesta *= 2;
					Youwon();
				}
			}
		}
	}
}

void Roulette::megaprint() {
	cout << "\n\n\n\n\n      ____________________________________________________________\n"
		<< "      |           1 TO 18           |           19 TO 36         |      \n"
		<< "  ____|____1________________________|________________________11__|_______\n"
		<< " /    |~3~~| 6  |~9~~|~12~| 15 |~18~|~21~| 24 |~27~|~30~| 33 |~36~| col3 |\n"
		<< " |    |___________________________________________________________|2_____| \n"
		<< " | 0  | 2  |~5~~| 8  | 11 |~14~| 17 | 20 |~23~| 26 | 29 |~32~| 35 | col2 |\n"
		<< " |    |___________________________________________________________|1_____|\n"
		<< " |    |~1~~| 4  |~7~~| 10 | 13 |~16~| 19 | 22 |~25~|~28~| 31 |~34~| col  |\n"
		<< " \\____|___________________________________________________________|______|\n"
		<< "      |      1 To 12      |      13 TO 24      |     25 TO 36     |\n"
		<< "      |___________________________________________________________|\n"
		<< "      |     EVEN     |     RED      |   BLACK      |     ODD      |\n"
		<< "      |___________________________________________________________|\n\n";
}

void Roulette::checkchipsr() {
	do {
		cin >> numberr;
		if (numberr > chipsr) {
			cout << "\nYOU don't have enough chips!!!\n";
			howmany();
		}
		else if (chipsr == 0) {
			cout << "\nYou need to at least bet something!!!\n";
			howmany();
		}
	} while (numberr > chipsr || chipsr == 0);
	chipsr -= numberr;
	outcome.apuesta = numberr;

}

void  Roulette::howmany() {
	if(decision == 0){
		switch (n) {
		case 0: { cout << "how many chips would you like to bet for straight bet : "; break; }
		case 1: { cout << "how many chips would you like to bet for split bet : "; break; }
		case 2: { cout << "how many chips would you like to bet for corner bet : "; break; }
		case 3: { cout << "how many chips would you like to bet for street bet : "; break; }
		case 4: { cout << "how many chips would you like to bet for double street bet : "; break; }
		default: {cout << "problem\n\n"; }
		}
	}
	else if (decision == 1) {
		switch (n) {
		case 0: { cout << "how many chips would you like to bet for EVEN : "; break; }
		case 1: { cout << "how many chips would you like to bet for ODD : "; break; }
		case 2: { cout << "how many chips would you like to bet for RED : "; break; }
		case 3: { cout << "how many chips would you like to bet for BLACK : "; break; }
		case 4: { cout << "how many chips would you like to bet for 1 TO 18 : "; break; }
		case 5: { cout << "how many chips would you like to bet for 19 TO 36 : "; break; }
		case 6: { cout << "how many chips would you like to bet for TWELVE : "; break; }
		case 7: { cout << "how many chips would you like to bet for columns : "; break; }
		default:{ cout << "problem\n\n";}
		}
	}
}

void Roulette::col12() {
	do {
		if (n == O_Twelve) {
			cout << "\nIn which 12 would you like to bet : ";
		}
		else if (n == O_Columns) {
			cout << "\nIn which column would you like to bet : ";
		}
		cin >> place;
		if (place < 1 || place > 3) {
			cout << "\n\nInvalid placement\n";
		}
	} while (place < 1 && place > 3);
}

void Roulette::Youwon() {
	outcome.resultado = 1;
	outco.push_back(outcome);
	ba = 1;
}

void Roulette::withinrange() {
	if (n == I_straight || n == I_split) {
		do {
			cout << "\nwhere would you like to bet : ";
			cin >> place;
			if (place < 0 || place > 36) {
				cout << "invalid placement\n";
			}
		} while (place < 0 || place  > 36);
	}
	else if (n == I_corner || n == I_street || n == I_Dstreet) {
		do {
			if (n == I_corner || n == I_Dstreet) {
				cout << "\nIn what vertical line(line of the roulette image) would you like to bet(1) tot(11) : ";
				n = 2;
			}
			else if (n == I_street) {
				cout << "\nIn what vertical row(street) would you like to bet(1) tot(12) : ";
			}
			cin >> place;
			if (place < 0 || place > (9 + n)) {
				cout << "invalid placement\n";
			}
		} while (place < 0 || place > (9 + n));
	}
}
