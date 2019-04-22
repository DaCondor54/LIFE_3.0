
#ifndef Roulette_h
#define Roulette_h

#include "Casino.h"
#include <iostream>

class Roulette : public Casino {
public:
	Roulette();
	//void Play();
	void GameMenu();
	void Inside();
	void Outside();
	void megaprint();
	void checkchipsr();
	void howmany();
	void Youwon();
	void col12();
	void withinrange();
	int n, chipsr, numberr, decision, place, place2, resultr, ball, col;
	bool ba, wino;
	enum Table {
		T_Inside, T_Outside
	};
	enum Inside_Bet{
		I_straight, I_split, I_corner, I_street, I_Dstreet
	};
	enum Outside_Bet {
		O_EVEN, O_ODD, O_RED, O_BLACK, O_1to18, O_19to36, O_Twelve, O_Columns
	};
};
#endif