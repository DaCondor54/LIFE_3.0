
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

};
#endif