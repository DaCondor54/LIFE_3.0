#ifndef BlackJack_h
#define BlackJack_h

#include "Casino.h"
#include <iostream>

class BlackJack : public Casino {
public:
	BlackJack();
	void GameMenu();
	void BlackJ();
	void HitP();
	void HitD();
	void Endgame();
	int* bustt, * x, * y;
	int n, z, w, t, som, var, vars, b, bou, condi, repetir, DDcond;
};
#endif