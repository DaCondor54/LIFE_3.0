#ifndef BlackJack_h
#define BlackJack_h

#include "Casino.h"
#include <iostream>

class BlackJack : public Casino {
public:
	BlackJack();
	enum Bplays{
		Bstay, Bhit, BDD, Bsplit, Bhand, Bleave
	};
	void GameMenu();
	void changevalue(int &x, std::string &y);
	void BlackJ();
	void HitP();
	void HitD();
	void Endgame();
	int* bustt, * x, * y;
	unsigned int sebastien;
	int n, z, w, t, som, var, vars, b, bou, condi, repetir, DDcond, boby;
	std::string  changer1, changer2, changer3;
};
#endif