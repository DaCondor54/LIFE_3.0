
#ifndef POKER_H
#define POKER_H
#include <iostream>
#include <vector>


class Poker { //poker class soon to be child of Casino
public:
	Poker();
	struct Cards { // the cards;
		int value;
		char suit;
	};
	void players();  // creates players sort of AI
	void gameMenu(); // game main menu will later become virtual GameMenu
	void BuyIn(); // buy in to play when you hit 0 or to begin to play
	void EnterR(); // enters betting round
	void flop(); // drops the flop
	void River(); // the river
	void CheckResult(); // checks results

	void Call();
	void Raise();
	void Stay();
	void All_In();
	void Tip(); // tips the dealer
	Cards cards;
	std::vector<Cards> TheirHand; //their hand vector with struct cards
	std::vector<Cards>::iterator it2; //their iterator
	std::vector<Cards> MyHand; //my hand vector with struct cards
	std::vector<Cards>::iterator it;  //my iterator


private:
	bool enterT;
	int P_Money;
	int Pot;
	int P_balance;
	int P_Table;
	int Min_Entry;
	int Max_Entry;
	int contit; // *cont



};





#endif