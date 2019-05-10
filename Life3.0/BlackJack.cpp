#include "BlackJack.h"
using namespace std;

//**********Constructor**********n
BlackJack::BlackJack()
:repetir(0), DDcond(0), n(0), som(0), t(0), var(0), vars(0), w(0), z(0), b(0), bou(0), condi(0), sebastien(0), boby(0)
//x = NULL;
{
	//repetir = 0; DDcond = 0; n = 0; som = 0; t = 0; var = 0; vars = 0; w = 0; z = 0; b = 0; bou = 0; condi = 0, sebastien(0), boby(0)
	//x = NULL;
	//y = NULL;
	x = &var;
	y = &vars;
	bustt = &b;
	changer1 = "\0";
	changer2 = "\0";
	changer3 = "\0";
	//sebastien = 0;
	//boby = 0;
}

//**********This is beginning to BLACKJACK func**********
void BlackJack::GameMenu() {
	cout << "\n*****WELCOME TO BLACKJACK*****\n";
	do {
		this_thread::sleep_for(chrono::seconds(1));
		Casino::Bet(1, Casino::Cbalance);
		*x = rand() % 13 + 2;
		*y = rand() % 13 + 2;
		changevalue(*x, changer1);
		changevalue(*y, changer2);
		cout << "\nPlayer 1: " << changer1 << " " << changer2 << "\n";
		//cout << "\nPlayer 1: " << *x << " " << *y << "\n";
		this_thread::sleep_for(chrono::seconds(1));
		outcome.resultado = *x + *y;
		if (outcome.resultado == 21) {
			BlackJ();           //BlackJack
		}
		else {
			z = rand() % 13 + 2;
			w = rand() % 10 + 2;
			som = z + w;
			changevalue(z, changer1);
			cout << "Dealer: " << changer1 << " ?\n";
			HitP();               //Card Loop
			if (outcome.resultado <= 21 or bou == 1) {
				changevalue(w, changer2);
				cout << "Dealer: " << changer1 << " " << changer2 << "\n";
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
		sebastien = outcome.apuesta * 2;
		if (*x == *y) {
			cout << "\nStay(0), Hit(1), Double Down(2), Split(3), Change Hand(4) : ";
		}
		else if (*x == *y and DDcond > 0) {
			cout << "\nStay(0), Hit(1), Split(3), Change Hand(4) : ";
		}
		else if (DDcond > 0) {
			cout << "\nStay(0) or Hit(1): ";
		}
		else {
			cout << "\nStay(0), Hit(1) or Double Down(2) : ";
		}
		cin >> n;
		if (n == Bhit or n == BDD) {
			if (n == BDD and (DDcond > 0 || balance < sebastien)) {
				n = Bhit;
				cout << "You can't Double down";
			}
			else {
				t = rand() % 13 + 2;
				changevalue(t, changer3);
				cout << "You got a: " << changer3 << "\n";
				++DDcond;
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
						n = Bleave;
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
						boby = 0;
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
						n = ((*bustt == 1) ? Bhand : Bleave);
						cout << *bustt << "bob" << endl;
						if (*bustt != 3) {
							outco.pop_back();
						}
						else if (*bustt > 2) {
							outco.clear();
						}
					}
				}
				if (n == BDD) {
					++condi;
					outcome.apuesta = outcome.apuesta * 2;
					outco.push_back(outcome);
					outcome.apuesta = outcome.apuesta / 2;
					if (repetir > 0 and condi != 2 and condi != 3) {
						n = Bhand;
						
					}
					else {
						n = Bleave;
					}
						
				}
			}
		}
		if (n == Bsplit and *x == *y) {
			outcome.resultado = *x;
			cout << outcome.resultado << endl;
			repetir++;
		}
		else if (n == Bsplit and *x != *y) {
			cout << "You Can't Split\n";
		}
		if (n == Bhand and repetir > 0) {
			if (outco.empty() and repetir != 2) {
				outco.push_back(outcome);
			}
			outcome.resultado = *y;
			cout << outcome.resultado << endl;
			n = Bhit;
			repetir++;
			++* bustt;
			++condi;
			DDcond = 0;
		}
		else if (n == Bhand and repetir < 1) {
			cout << "You didn't Split\n";
		}
		if (n != Bleave && (n == Bstay || n > Bhand)) {
			outco.push_back(outcome);
			n = Bleave;
		}
	}while(n > Bstay  and n < Bleave); // end of hitting cards loop
	DDcond = 0;
}

//**********dealer plays**********  
void BlackJack::HitD() {
	do {
		t = rand() % 13 + 2;
		this_thread::sleep_for(chrono::seconds(2));
		changevalue(t, changer3);
		cout << "Dealer got a: " << changer3 << "\n\n";
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

void BlackJack::changevalue(int &x, string &y) {
		switch (x) {
		case 11: {x = 10; y = "J"; break; }
		case 12: {x = 10; y = "Q"; break; }
		case 13: {x = 10; y = "K"; break; }
		case 14: {x = 11; y = "A"; break; }
		default: {y = to_string(x); break; }
		}
	
	

}
