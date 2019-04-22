#include "BlackJack.h"
using namespace std;

//**********Constructor**********n
BlackJack::BlackJack() {
	repetir = 0; DDcond = 0; n = 0; som = 0; t = 0; var = 0; vars = 0; w = 0; z = 0; b = 0; bou = 0; condi = 0;
	x = NULL;
	y = NULL;
	x = &var;
	y = &vars;
	bustt = &b;
}

//**********This is beginning to BLACKJACK func**********
void BlackJack::GameMenu() {
	cout << "\n*****WELCOME TO BLACKJACK*****\n";
	do {
		this_thread::sleep_for(chrono::seconds(1));
		Casino::Bet(1, Casino::Cbalance);
		*x = rand() % 10 + 2;
		*y = rand() % 10 + 2;
		cout << "\nPlayer 1: " << *x << " " << *y << "\n";
		this_thread::sleep_for(chrono::seconds(1));
		outcome.resultado = *x + *y;
		if (outcome.resultado == 21) {
			BlackJ();           //BlackJack
		}
		else {
			z = rand() % 10 + 2;
			w = rand() % 10 + 2;
			som = z + w;
			cout << "Dealer: " << z << " ?\n";
			HitP();               //Card Loop
			if (outcome.resultado <= 21 or bou == 1) {
				cout << "Dealer: " << z << " " << w << "\n";
				if (som < 17) {
					HitD();         //Dealer card loop
				}
				if (som <= 21) {
					Endgame();      //endgame loop
				}
			}
		}
		Ccontinue();
	} while (*cont == 0);
}

//**********In Case of a BLACKJACK**********
void BlackJack::BlackJ() {
	cout << "BLACKJACK\n";
	outcome.apuesta = outcome.apuesta * 3 / 2;
	outco.push_back(outcome);
	for (it = outco.begin(); it != outco.end(); ++it) {
		Bet(2, Cbalance);
	}
}

//**********end game**********
void BlackJack::Endgame() {
	this_thread::sleep_for(chrono::seconds(1));
	for (it = outco.begin(); it != outco.end(); ++it) {
		if (it->resultado > som and it->resultado < 22) {
			it->apuesta;
			Bet(2, Cbalance);
		}
		else if (it->resultado == som) {
			it->apuesta;

			Bet(4, Cbalance);
		}
		else if (it->resultado < som or it->resultado > 21) {
			it->apuesta;
			Bet(3, Cbalance);
		}
	}
}
//**********beginning of hitting cards loop**********
void BlackJack::HitP() {
	do {
		//DDcond = 0;
		unsigned int sebastien = outcome.apuesta * 2;
		if (*x == *y) {
			cout << "\nHit(0), Stay(1), Double Down(2), Split(3), Change Hand(4) : ";
		}
		else if (*x == *y and DDcond > 0) {
			cout << "\nHit(0), Stay(1), Split(3), Change Hand(4) : ";
		}
		else if (DDcond > 0) {
			cout << "\nHit(0) or Stay(1): ";
		}
		else {
			cout << "\nHit(0), Stay(1) or Double Down(2) : ";
		}
		cin >> n;
		if (n == 0 or n == 2) {
			if (n == 2 and (DDcond > 0 || balance < sebastien)) {
				n = 0;
				cout << "You can't Double down";
			}
			else {
				t = rand() % 10 + 2;
				++DDcond;
				cout << "You got a: " << t << endl;
				this_thread::sleep_for(chrono::seconds(1));
				outcome.resultado += t;
				if (outcome.resultado > 21 and repetir == 0) {
					if (*x == 11) {
						*x -= 10;
						outcome.resultado -= 10;
						cout << outcome.resultado << endl;
					}
					else if (*y == 11 and *x != 11) {
						*y -= 10;
						outcome.resultado -= 10;
						cout << outcome.resultado << endl;
					}
					else if (t == 11 and *x != 11 and *y != 11) {
						t -= 10;
						outcome.resultado -= 10;
						cout << outcome.resultado << endl;
					}
					if (outcome.resultado > 21) {
						cout << "****YOU BUSTED****\n";
						outco.push_back(outcome);
						for (it = outco.begin(); it != outco.end(); ++it) {
							Bet(3, Cbalance);
						}
						n = 10;
					}
				}
				else if (outcome.resultado > 21 and repetir > 0) {
					if (*x == 11) {
						*x -= 10;
						outcome.resultado -= 10;
						cout << outcome.resultado << endl;
					}
					else if (t == 11 and *x != 11) {
						t -= 10;
						outcome.resultado -= 10;
						cout << outcome.resultado << endl;
					}
					if (outcome.resultado > 21) {
						outco.push_back(outcome);
						int boby = 0;
						for (it = outco.begin(); it != outco.end(); ++it) {
							++boby;
							if (outco.size() == 2 and boby == 2) {
								Bet(3, Cbalance);
								++bou;
							}
							else if (outco.size() == 1) {
								Bet(3, Cbalance);
							}
						}
						cout << "****YOU BUSTED****\n";
						++repetir;
						*bustt += 1;
						cout << *bustt << endl;
						n = ((*bustt == 1) ? 4 : 10);
						cout << *bustt << "bob" << endl;
						if (*bustt != 3) {
							outco.pop_back();
						}
						else if (*bustt > 2) {
							outco.clear();
						}
					}
				}
				if (n == 2) {
					++condi;
					outcome.apuesta = outcome.apuesta * 2;
					outco.push_back(outcome);
					outcome.apuesta = outcome.apuesta / 2;
					if (repetir > 0 and condi != 2 and condi != 3) {
						n = 4;
						cout << "haleluya\n\n";
					}
					else {
						n = 10;
						cout << "haleluyasfasfasfasfasfa\n\n";
					}
				}
			}
		}
		if (n == 3 and *x == *y) {
			outcome.resultado = *x;
			cout << outcome.resultado << endl;
			repetir++;
		}
		else if (n == 3 and *x != *y) {
			cout << "You Can't Split\n";
		}
		if (n == 4 and repetir > 0) {
			if (outco.empty() and repetir != 2) {
				outco.push_back(outcome);
			}
			outcome.resultado = *y;
			cout << outcome.resultado << endl;
			n = 0;
			repetir++;
			++* bustt;
			++condi;
			DDcond = 0;
		}
		else if (n == 4 and repetir < 1) {
			cout << "You didn't Split\n";
		}
		if (n != 10 && (n == 1 || n > 4)) {
			outco.push_back(outcome);
			n = 10;
		}
	} while (n >= 0 and n < 5); // end of hitting cards loop
	DDcond = 0;
}

//**********dealer plays**********  
void BlackJack::HitD() {
	do {
		t = rand() % 10 + 2;
		this_thread::sleep_for(chrono::seconds(2));
		cout << "Dealer got a: " << t << "\n\n";
		som += t;
		if (som > 21) {
			if (z == 11) {
				z -= 10;
				som -= 10;
				cout << som << endl;
			}
			else if (w == 11 and z != 11) {
				w -= 10;
				som -= 10;
				cout << som << endl;
			}
			if (som > 21) {
				cout << "\n**DEALER BUSTED**\n";
				for (it = outco.begin(); it != outco.end(); ++it) {
					Bet(2, Cbalance);
				}
			}
		}
	} while (som < 17);
}
