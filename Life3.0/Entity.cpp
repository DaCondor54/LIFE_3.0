#include "Entity.h"



Entity::Entity()
	:Call_factor(rand() % 31 + 30), Fold_factor(rand() % 10 + 1), Raise_factor(100 - Call_factor - Fold_factor), seat(0),
	Has_A_Pair(0), Straight_posibility(0), Same_Color(0), sum_of_cards(0), Hand_level(0), folding_chance(0), Name_Chance(0), Special_Chance(0), initial_formula(0), Enemies_Name("\0"),
	Call_range(Fold_factor), Fold_range(0), Raise_range(Fold_factor + Call_factor), Total_cash(0), buy_in_cash(0), their_raise(0), Best_Card(0), Second_Best_Card(0), Color1(0), Straight1(0), Highest_F(0), Lowest_F(0),
	lowest_S(0), rankingE(0)
	
{
}
void Entity::Personality() {
	std::string Normal_Array[28] = { "Charles", "Cynthia", "Lea", "Gabriel", "Simon", "William", "Victor",
	 "Megane", "Audrey", "Sophia", "Charlotte", "Joe", "Laeticia", "Tina", "marieve",
	"Sandrine", "Andrea", "Micheal", "Sarah-Michelle","Maria", "Jennifer", "Vladimir", "Laurie", "Catherine",
		"Jonathan", "Hugo", "James", "Justin" };
	std::string Special_Array[9] = { "Tyron","Marine", "Malina", "Anais", "Coco", "Gabdub", "Guay", "Pierre-Marc" };
	Special_Chance = rand() % 100 + 1;
	if (Special_Chance < 6) {
		Name_Chance = rand() % 9;
		Enemies_Name = Special_Array[Name_Chance];
	}
	else {
		Name_Chance = rand() % 28;
		Enemies_Name = Normal_Array[Name_Chance];
	}
}
void Entity::initial_hand_formula() {
	Has_A_Pair = 1; Straight_posibility = 0; Same_Color = 0;
	sum_of_cards = their_hand[0].value + their_hand[1].value;

	Hand_level = sum_of_cards >= 10 ? sum_of_cards >= 18 ? sum_of_cards >= 24 ? 4 : 3 : 2 : 1;
	folding_chance = Hand_level * -20 + 100;
	if (their_hand[0].value == their_hand[1].value) {
		Has_A_Pair = 2;
	}
	for (int i = 1; i < 3; i++) {
		if (their_hand[0].value + i == their_hand[1].value || their_hand[0].value - i == their_hand[1].value) {
			Straight_posibility = 24 / Hand_level;

		}
	}
	if (their_hand[0].suit == their_hand[1].suit) {
		Same_Color = 24 / Hand_level;
	}
	initial_formula = folding_chance / Has_A_Pair - Straight_posibility - Same_Color;
}


Entity::~Entity()
{
}
