#ifndef ENTITY_H
#define ENTITY_H
#include "Cards.h"
#include <vector>
class Entity
{
public:
	Entity();
	std::vector<Cards> their_hand;
	void Personality();
	void initial_hand_formula();
	std::string Enemies_Name;
	int Special_Chance, Name_Chance;
	int rankingE, Best_Card, Second_Best_Card;
	bool Color1, Straight1;
	int lowest_S, Lowest_F, Highest_F;
	std::string Dominant_Suit;

	int sum_of_cards, initial_formula, folding_chance, Has_A_Pair, Same_Color, Straight_posibility, Hand_level;

	int their_raise;
	int Total_cash;
	int buy_in_cash;

	int Call_factor, Fold_factor, Raise_factor;
	int Call_range, Fold_range, Raise_range;
	std::size_t seat;

	~Entity();
};

#endif

