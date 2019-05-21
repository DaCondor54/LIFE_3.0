#include "Poker.h"
#include "Entity.h"
#include "Cards.h"

using namespace std;
Cards* (Poker::card) = new Cards;
Poker::Poker()
	:P_Money(0), P_balance(10000), Pot(0), enterT(0), P_Table(0), Min_Entry(0), Max_Entry(0), contit(0), Everyone_called(0), call_counter(0), I_exit(0),  top_card(0), top_card2(0),
	choice_P(0), Your_Bet(0), Round_Call(0), Your_Raise(0), Enemy_count(rand() % 6 + 1), enemies(Enemy_count), Min_bet(0), begin_playing(0), stop_playing(0)
{
	//cards.value = 0;
	//cards.suit = '\0';
}

void Poker::gameMenu() {
	//Cards c1;
	//card = &c1;
	cout << "\n*******WELCOME TO POKER*******\n";
	cout << "would you like to enter the table(1) : ";
	cin >> enterT;
	if (enterT == 1) {
		do {
			I_exit = 0;
			EnterR();
			if (Min_Entry != 1) {
				BuyIn();
				do {
					cout << "\nthere are " << Enemy_count << " players in this table\n";
					this_thread::sleep_for(chrono::seconds(2));
					first_Round();
					begin_playing = rand() % (Enemy_count + 1);
					stop_playing = Enemy_count - begin_playing;
					do {

						cout << "\nthe " << begin_playing << " player starts playing\n\n";
						this_thread::sleep_for(chrono::seconds(2));
						Everyone_called = 0;
						call_counter = 0;
						if (Enemy_count == 0) {
							cout << "you won\n";
						}
						else if (begin_playing == 0) {
							first_round_AI(begin_playing, 0);
							if (Everyone_called != 1) {
								PlayerP();
							}
						}
						else if (begin_playing == Enemy_count) {
							PlayerP();
							first_round_AI(0, 0);
						}
						else {
							first_round_AI(begin_playing, 0);
							if (Everyone_called != 1) {
								PlayerP();
								if (Everyone_called != 1) {
									first_round_AI(0, stop_playing);
								}
							}
						}
						for (int i = 0; i < Enemy_count; i++) {
							if (Your_Bet == enemies[i].their_raise) {
								call_counter++;
							}
						}
					} while (call_counter != Enemy_count && Everyone_called != 1);

					cout << "would you like to continue playing at this table(1)  : ";
					cin >> contit;
					if (contit == 1) {
						Enemy_count += folded_enemies.size();
						for (size_t i = 0; i < folded_enemies.size(); i++) {
							if (enemies.size() < folded_enemies[i].seat) {
								enemies.push_back(folded_enemies[i]);
							}
							else {
								enemies.insert(enemies.begin() + folded_enemies[i].seat, folded_enemies[i]);
							}
						}
						Reset_Table();
						folded_enemies.clear();
					}
					if (P_Money < 3000) {
						P_Money = 3000;
						cout << "\nyou got a nice boost\n";
					}
				} while (contit == 1);
			}
			cout << "do you want to go to a new table table(1) or to play someting else(0) : ";
			cin >> I_exit;
			if (I_exit == 1) {
				enemies.clear();
	
				Enemy_count = rand() % 6 + 1;
				enemies.resize(Enemy_count);
				enemies.shrink_to_fit();
			}
		} while (I_exit == 1);
	}
	else {
		cout << "have a nice day";
	}
		//TheirHand.clear();
}
void Poker::PlayerP() {
	if (Your_Bet != Round_Call) {
		cout << "\n\nit's your turn, what would you like to do ?\n";
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
	else {
		Everyone_called = 1;
	}

}

void Poker::first_Round() {
	random_shuffle(deck.begin(), deck.end());
	Discard_Pile.push_back(deck.back());
	deck.pop_back();
	for (int j = 0; j < 2; j++) {
		MyHand.push_back(deck.back());
		deck.pop_back();
	}
	cout << "you got a : " << change_name(MyHand[0].value) << " of " << MyHand[0].suit;
	cout << " and a " << change_name(MyHand[1].value) << " of " << MyHand[1].suit;
	this_thread::sleep_for(chrono::seconds(2));
	//cout << enemies.size();
	for (int i = 0; i < Enemy_count; i++) {
		enemies[i].seat = i;
		for (int j = 0; j < 2; j++) {
			enemies[i].their_hand.push_back(deck.back());
			deck.pop_back();
			
		}
		enemies[i].initial_hand_formula();
	}
}

void Poker::flop() {
	Discard_Pile.push_back(deck.back());
	deck.pop_back();
	MyHand.insert(MyHand.end(), deck.end() - 3, deck.end());
	for (int i = 0; i < Enemy_count; i++) {
		enemies[i].their_hand.insert(enemies[i].their_hand.end(), deck.end() - 3, deck.end());
	}
	for ( it1 = deck.end() - 3; it1 != deck.end(); it1++) {
		cout << "the flop is : " << change_name(it1 -> value) << " of " << it1 -> suit << endl;
	}
	deck.erase(deck.end() - 3, deck.end());

}

void Poker::Set_Cards() {
	Cards c1;
	card = &c1;
	for (int i = 2; i < 15; i++) {
		for (int j = 1; j < 5; j++) {
			card -> value = i;
			switch (j) {
			case 1: {card ->suit = "diamonds"; break; }
			case 2: {card ->suit = "hearts"; break; }
			case 3: {card->suit = "spades"; break; }
			case 4: {card->suit = "clubes"; break; }
			default: {card->suit = "probleme"; break; cout << "there was a problem\n"; }
			}
			deck.push_back(*card);
		}
	}
}

void Poker::Reset_Table() {
	
	for (int i = 0; i < Enemy_count; i++) {

		deck.push_back(enemies[i].their_hand[0]);
		deck.push_back(enemies[i].their_hand[1]);
		enemies[i].their_hand.clear();
		enemies[i].their_raise = 0;
	}
	Round_Call = Min_bet / 2;
	Pot = 0;
	Your_Bet = 0;
	deck.push_back(MyHand[0]);
	deck.push_back(MyHand[1]);
	MyHand.clear();
}

void Poker::BuyIn() {
	do {
		cout << "\nFor how much would you like to buy in: ";
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
		<< "5:10(0), 10:20(1), 20:40(2), 50:100(3), 100:200(4) : ";
	cin >> P_Table;
	switch (P_Table) {
	case 0: {Min_Entry = 100; Max_Entry = 2000; Min_bet = 10; break; }
	case 1: {Min_Entry = 200; Max_Entry = 4000; Min_bet = 20; break; }
	case 2: {Min_Entry = 400; Max_Entry = 8000; Min_bet = 40; break;}
	case 3: {Min_Entry = 1000; Max_Entry = 20000; Min_bet = 100; break; }
	case 4: {Min_Entry = 2000; Max_Entry = 40000; Min_bet = 200; break; }
	default: {cout << "you didn't enter a table\n"; Min_Entry = 1; break; }
	}
	cout << "\nMINIMUM BUY-IN: " << Min_Entry << "\nMAXIMUM BUY-IN: " << Max_Entry << endl;
	for (int i = 0; i < Enemy_count; i++) {
		enemies[i].Personality();
		enemies[i].Total_cash = Max_Entry * rand() % 8 + 2;
		enemies[i].buy_in_cash = Max_Entry / 2 + rand() % (Max_Entry / 2);
	}
	Round_Call = Min_bet / 2;
}

void Poker::Stay() {
	cout << "you stayed\n";
}
void Poker::Call() {
	if (P_Money < Round_Call) {
		Your_Bet += P_Money;
		Pot += P_Money;
		P_Money = 0;
	}
	else {
		Your_Bet = Round_Call;
		Pot += Round_Call;
		P_Money -= Round_Call;
	}
	cout << "you called : " << Your_Bet << "$\n";
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
	Round_Call = Your_Raise;
	Your_Bet = Your_Raise;
	Pot += Your_Raise;
	P_Money -= Your_Raise;
	cout << "you raised : " << Your_Raise << "$\n";
}
void Poker::All_In() {
	
	Your_Bet += P_Money;
	Pot = +P_Money;
	P_Money = 0;
	if (Your_Bet > Round_Call) {
		Round_Call = Your_Bet;
	}
	cout << "you went all in with : " << Your_Bet << "$\n";
}

std::string Poker::change_name(int x) {
	switch (x) {
	case 11: return "Jack";
	case 12: return "Queen";
	case 13: return "King";
	case 14: return "Ace";
	default: return to_string(x);
	}

}

void Poker::CheckResult(){
}

void Poker::Check_Straight() {
	
	for (int i = 0; i < Enemy_count; i++) {
		enemies[i].Straight1 = 0;
		itsmall = std::min_element(enemies[i].their_hand.begin(), enemies[i].their_hand.end(),
			[](Cards const& S_card, Cards const& S_card2) -> bool {return S_card.value < S_card2.value; });

		itssmall = std::min_element(enemies[i].their_hand.begin(), enemies[i].their_hand.end(),
			[itsmall = itsmall](Cards const& S_card3, Cards const& S_card4) -> bool
			{ if (itsmall->value != S_card3.value && itsmall->value != S_card4.value) return  S_card3.value < S_card4.value; else  return  S_card3.value > S_card4.value;  });
		itsmalll = std::min_element(enemies[i].their_hand.begin(), enemies[i].their_hand.end(),
			[itssmall = itssmall](Cards const& S_card3, Cards const& S_card4) -> bool
			{ if (itssmall->value != S_card3.value && itssmall->value != S_card4.value) return  S_card3.value < S_card4.value; else  return  S_card3.value > S_card4.value;  });
		int Scounter = 0, Scounter2 = 0 , Scounter3 = 0;
		
		sorted_hand = enemies[i].their_hand;
		sort(sorted_hand.begin(), sorted_hand.end(), [](Cards const& Sorted1, Cards const& Sorted2) -> bool {return Sorted1.value < Sorted2.value; });
		for (int j = 0; i < 5; j++) {
			if ((itsmall -> value) + j == sorted_hand[j].value) {
				Scounter++;
			}
			if ((itssmall->value) + j == sorted_hand[j+1].value) {
				Scounter2++;
			}
			if ((itsmalll->value) + j == sorted_hand[j + 2].value) {
				Scounter3++;
			}
		}
		if (Scounter == 5 || Scounter2 == 5 || Scounter3 == 5) {
			//cout << "\nyou have a straight\n";
			top_card = 5 + (Scounter3 == 5 ? itsmalll->value : Scounter2 == 5 ? itssmall->value : itsmall->value);
			enemies[i].lowest_S = top_card - 5;
			enemies[i].rankingE = 5;
			enemies[i].Straight1 = 1;


		}
		////card_set.insert(/*card_set.end(),*/ enemies[i].their_hand.begin(), enemies[i].their_hand.end());
		//auto setI = card_set.find(itsmall->value);

	}
}
void Poker::Check_Color() {
	for (int i = 0; i < Enemy_count; i++) {
		enemies[i].Color1 = 0;
		int Scounter = 0;
		int biggestC = 0;
		int li = 0;
		std::string current_suit = "\0";
		std::string biggest_suit = "\0";
		bool change_top = 1;
		sorted_hand = enemies[i].their_hand;
		sort(sorted_hand.begin(), sorted_hand.end(), [](Cards const& Sorted1, Cards const& Sorted2) -> bool {return Sorted1.suit < Sorted2.suit; });
		current_suit = sorted_hand[0].suit;
		li = sorted_hand[0].value;
		for (auto i = sorted_hand.begin(); i != sorted_hand.end(); i++) {
			//current_suit = i->suit;
			if (i->suit == current_suit) {
				//li
				Scounter++;
				if (change_top == 1) {
					top_card = top_card < i->value ? i->value : top_card;
				}
			}
			else {
				Scounter < 5 ? top_card = i->value : change_top = 0;
				if (Scounter > biggestC) {
					biggestC = Scounter;
					biggest_suit = current_suit;
				}
				current_suit = i->suit;
				Scounter = 1;
				if (Scounter == 1 && change_top == 1) {
					li = i->value;
				}
			}
		}
		if (biggestC > 4) {
			enemies[i].rankingE = 6;
			enemies[i].Color1 = 1;
			enemies[i].Dominant_Suit = biggest_suit;
			enemies[i].Lowest_F = li;
			enemies[i].Highest_F = top_card;
		}
	}
}

void Poker::Check_full_house() {
	for (int io = 0; io < Enemy_count; io++) {
		int high_card;
		int Scounter = 0;
		int current_num = 0;
		bool TrioF = 0, PaireF = 0;
		int biggestT = 0, biggestP = 0, biggestP2;
		sorted_hand = enemies[io].their_hand;
		sort(sorted_hand.begin(), sorted_hand.end(), [](Cards const& Sorted1, Cards const& Sorted2) -> bool {return Sorted1.value < Sorted2.value; });
		current_num = sorted_hand[0].value;
		high_card = sorted_hand[0].value;
		for (auto i = sorted_hand.begin(); i != sorted_hand.end(); i++) {
			if (high_card < i-> value) {
				high_card = i->value;
			}
			if (i->value == current_num) {
				Scounter++;
				if (Scounter == 3/* && (TrioF == 0 || i -> value > biggestT)*/) {
					if (i->value > biggestT) {
						if (biggestP < biggestT) {
							biggestP = biggestT;
							PaireF = 1;
						}	
							biggestT = i->value;
					}
					else {
						biggestT = current_num;
					}
						TrioF = 1;
						Scounter = 0;
						current_num = (i + 1)->value;
					
				}
				if (Scounter == 2 && TrioF == 0 && (i+1) == sorted_hand.end()) {

					if (i->value > biggestP) {
						biggestP2 = biggestP;
						biggestP = i->value;
					}
					else {
						biggestP2 = i->value;
						PaireF = 1;
					}
					PaireF = 1;
				}
				else if (Scounter == 2 && TrioF != 0) {
					if((i + 1) == sorted_hand.end()){
						if (biggestP < i->value) {
							biggestP2 = biggestP;
							biggestP = current_num;
							PaireF = 1;
							break;
						}
					}
					else if ((i + 1)->value != current_num) {
						if (biggestP < i->value) {
							biggestP2 = biggestP;
							biggestP = current_num;
							PaireF = 1;
							break;
						}
					}
				}
			}
			else {
				if (Scounter == 2) {
					if ((i-1)->value > biggestP) {
						biggestP2 = biggestP;
						biggestP = (i-1)->value;
					}
					else {
						biggestP2 = i->value;
					}
					PaireF = 1;
				}
				current_num = i->value;
				Scounter = 1;
			}
			if (PaireF == 1 && TrioF == 1) {
				
				enemies[io].rankingE = 8;
				top_card = biggestT;
				break;
			}
			else if (TrioF == 1 && PaireF != 1) {
				enemies[io].rankingE = 4;
				
				top_card = biggestT;
			}
			else if (TrioF != 1 && PaireF == 1)
			{
				if (biggestP2 > 0) {
					enemies[io].rankingE = 3;
					top_card = biggestP;
					top_card2 = biggestP2;
				}
				else {
					enemies[io].rankingE = 2;
					top_card = biggestP;
				}
			}
			else {
				enemies[io].rankingE = 1;
				top_card = high_card;
				
			}
		}
	
	}
}

void Poker::Check_4_of_a_kind() {
	for (int io = 0; io < Enemy_count; io++) {
		int Scounter = 0;
		int current_num = 0;
		sorted_hand = enemies[io].their_hand;
		sort(sorted_hand.begin(), sorted_hand.end(), [](Cards const& Sorted1, Cards const& Sorted2) -> bool {return Sorted1.value < Sorted2.value; });
		current_num = sorted_hand[0].value;
		for (auto i = sorted_hand.begin(); i != sorted_hand.end(); i++) {
			if (i->value == current_num) {
				Scounter++;
			}
			else {
				current_num = i->value;
				Scounter = 1;
			}
			if (Scounter == 4) {
				enemies[io].rankingE = 8;
				top_card = current_num;
				break;
			}
		}
	}
}

void Poker::check_Straight_Flush() {
	for (int io = 0; io < Enemy_count; io++) {
		int counterSF =0;
		if (enemies[io].Straight1 == 1 && enemies[io].Color1 == 1 && enemies[io].lowest_S == enemies[io].Lowest_F && enemies[io].lowest_S + 5 == enemies[io].Highest_F) {
			cout << "you have a straight flush";
			enemies[io].rankingE = 9;
		}
	}
}

void Poker::first_round_AI(int first_player, int last_player) {
	for (int e = first_player; e < Enemy_count - last_player; e++) {
		if (enemies[e].their_raise != Round_Call) {
			cout << "\n";
			int keep_going, choiceF, Final_Raise = 0, ratio_call, callF, raiseF, HRaise, RaiseFF;
			ratio_call = 100 - (Round_Call * 100 / enemies[e].buy_in_cash);
			keep_going = ratio_call != 0 ? ((enemies[e].Raise_factor + enemies[e].Call_factor - enemies[e].initial_formula) * ratio_call / 100) : 1;
			//cout << keep_going << " " << enemies[e].Raise_factor << " " << ratio_call << " " << enemies[e].Call_factor << " " << formula1 << "\n";
			choiceF = rand() % 101;
			if (choiceF >= 100 - keep_going) {
				//cout << choiceF<< "\n";
				callF = (keep_going * (100 - enemies[e].Raise_factor)) / 100 >= 1 ? (keep_going * (100 - enemies[e].Raise_factor)) / 100 : 1;
				raiseF = keep_going - callF;

				if (choiceF > 100 - raiseF) {
					HRaise = keep_going - rand() % keep_going;
					//cout << callF << " "<< raiseF << " " << HRaise << endl ;

					if (HRaise == rand() % 101) {
						Final_Raise = enemies[e].buy_in_cash;
						cout << enemies[e].Enemies_Name << " " << enemies[e].seat << " went all-in\n";
					}
					else {
						//	cout << "quasi llego\n";
						int bonusV = rand() % keep_going + 1;
						RaiseFF = rand() % ((enemies[e].buy_in_cash * bonusV) / 100);
						//cout << bonusV << " "<<  RaiseFF <<" " << enemies[e].buy_in_cash <<   endl;
					//	cout << "llego aqui\n";
						if (enemies[e].buy_in_cash < Round_Call) {
							Final_Raise = enemies[e].buy_in_cash;
						}
						else {
							Final_Raise = RaiseFF > Round_Call ? RaiseFF : RaiseFF + Round_Call > enemies[e].buy_in_cash ? enemies[e].buy_in_cash - (((enemies[e].buy_in_cash - Round_Call) * RaiseFF) / 100) : RaiseFF + Round_Call;
						}
						cout << enemies[e].Enemies_Name << " " << enemies[e].seat << " raised " << Final_Raise << "$\n";

					}

				}
				else {
					Final_Raise = Round_Call > enemies[e].buy_in_cash ? enemies[e].buy_in_cash : Round_Call;
					cout << enemies[e].Enemies_Name << " " << enemies[e].seat << " called " << Final_Raise << "$\n";
				}
			}
			else {
				if (Round_Call < Min_bet * 5) {
					Final_Raise = Round_Call;
					cout << enemies[e].Enemies_Name << " " << enemies[e].seat << " called " << Final_Raise << "$\n";
				}
				else {
					cout << enemies[e].Enemies_Name << " " << enemies[e].seat << " folded \n";
					//folded_enemies.push_back(enemies[e]);

					fold_enemies_count.push_back(e);

				}
			}
			//cout << "llego5\n";
			enemies[e].buy_in_cash -= Final_Raise;
			if (Final_Raise > Round_Call) {
				Round_Call = Final_Raise;
			}
			Pot += Final_Raise;
			enemies[e].their_raise = Final_Raise;
			this_thread::sleep_for(chrono::seconds(2));
		}
		else {
			
			Everyone_called = 1;
			break;
		}
	}
	int counteri = 0;
	for (it_e = fold_enemies_count.begin(); it_e != fold_enemies_count.end(); it_e++) {
		//cout << "llego a for\n";
		folded_enemies.push_back(enemies[*it_e - counteri]);
		//int contS = *it_e;
		//cout << "llego  a for2\n";
		enemies.erase(enemies.begin() + (*it_e - counteri));
		//cout << "llego a for3\n";
		Enemy_count--;
		counteri++;
		if (*it_e < begin_playing) {
			begin_playing--;
			stop_playing--;
		}
		/*if (Enemy_count < begin_playing) {
			begin_playing--;
		}*/

	}
	fold_enemies_count.clear();


}

