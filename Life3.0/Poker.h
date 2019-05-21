
#ifndef POKER_H
#define POKER_H
struct Cards;
#include "Cards.h"
#include "Entity.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>
#include <unordered_set>


class Poker { //poker class soon to be child of Casino
public:
	Poker();
	/*struct Cards { // the cards;
		int value;
		std::string suit;
	};*/
	void PlayerP();  // creates players sort of AI
	void gameMenu(); // game main menu will later become virtual GameMenu
	void BuyIn(); // buy in to play when you hit 0 or to begin to play
	void EnterR(); // enters betting round
	void flop(); // drops the flop
	void River(); // the river
	void CheckResult(); // checks results
	void Check_Straight();
	void Check_Color();
	void Check_4_of_a_kind();
	void Check_full_house();
	void check_Straight_Flush();
	void first_Round();


	void Call();
	void Raise();
	void Stay();
	void All_In();
	void Tip(); // tips the dealer
	void Set_Cards();
	void Reset_Table();
	std::string change_name(int x);

	static Cards* card;

	//std::vector<Cards> TheirHand; //their hand vector with struct cards
	//std::vector<Cards>::iterator it2; //their iterator

	std::vector<Cards> MyHand; //my hand vector with struct cards
	std::vector<Cards>::iterator it1;  //my iterator
	std::vector<Cards>::iterator itsmall;
	std::vector<Cards>::iterator itssmall;
	std::vector<Cards>::iterator itsmalll;
	std::vector<Cards> deck;
	std::vector<Cards> Discard_Pile;
	int Enemy_count;
	std::vector<Entity> enemies;
	std::vector<Entity> folded_enemies;
	std::vector<int> fold_enemies_count;
	std::vector<int>::iterator it_e;
	std::vector<Cards> sorted_hand;
	//std::unordered_set<Cards> card_set;

	void first_round_AI(int first_player, int last_player);

private:
	bool enterT, I_exit/*, Straight1, Color1*/;
	bool Everyone_called;
	int call_counter;
	//int Enemy_count;
	int begin_playing, stop_playing;
	int Min_bet;
	int P_Money;
	int Pot;
	int P_balance;
	int P_Table;
	int Min_Entry;
	int Max_Entry;
	//int ranking;
	int top_card;
	int top_card2;
	int contit; // *cont
	enum actionsP {
		Stay_P, Call_P, Raise_P, AllIn_P
	
	};
	int choice_P;
	int Your_Bet;
	int Round_Call;
	int Your_Raise;



};



#endif