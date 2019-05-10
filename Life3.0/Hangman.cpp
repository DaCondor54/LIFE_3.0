#include "Hangman.h"

using namespace std;

Hangman::Hangman()
: rep(0), error(0), choice(0), counter(0), i(0), gro(0), sup(0), isit(0), decision(0), isit2(0), a(0), com(0), death(0)
{
	//rep = 0; error = 0; choice = 0; counter = 0; i = 0; gro = 0; sup = 0;
	//isit = 0; decision = 0, isit2 = 0;
	x = '\0';
	special = '\0';
	//a = 0; com = 0;
	//death = 0;
}

void Hangman::GameMenu() {
	string arrname[27] = { "charles", "cynthia", "lea", "gabriel", "simon", "william", "victor",
	 "megane", "audreya", "sophia", "charlotte", "joe", "laeticia", "tina", "marieve",
	"sandrine", "andrea", "micheal","maria", "jennifer", "vladimir", "laurie", "catherine",
		"jonathan", "hugo", "james", "justin" };
	cout << "\n*****WELCOME TO HANGMAN******\n";
	do {
		Bet(1, Cbalance);
		outcome.resultado = 1;
		error = 0; isit = 0; counter = 0; isit2 = 0;
		i = rand() % 27;
		special = arrname[i];
		gro = special.size();
		set();
		do {
			rep = 0;
			sup = 0;
			findme();
			check();
		} while (counter < gro and error < 6);
		if (counter == gro) {
			for (it = outco.begin(); it != outco.end(); ++it) {
				outcome.apuesta *= 5;
				outco.push_back(outcome);
				Bet(2, Cbalance);
			}
		}
		cin.clear(); cin.ignore(256, '\n');
		Ccontinue();
			v.clear();
			wrong.clear();
			supa.clear();
	} while (*cont == 0);
	//cout << "Have a nice day!!!";

}

void Hangman::stage() {
	switch (error) {
	case 6: { cout << "HANG MAN\n" << " __\n|  |\n|  o\n| /|\\\n| / \\\n______\n"; break; }
	case 5: { cout << "HANG MAN\n" << " __\n|  |\n|  o\n| /|\\\n| /\n______\n"; break; }
	case 4: { cout << "HANG MAN\n" << " __\n|  |\n|  o\n| /|\\\n|\n______\n"; break; }
	case 3: { cout << "HANG MAN\n" << " __\n|  |\n|  o\n| /|\n|\n______\n"; break; }
	case 2: { cout << "HANG MAN\n" << " __\n|  |\n|  o\n| /\n|\n______\n"; break; }
	case 1: { cout << "HANG MAN\n" << " __\n|  |\n|  o\n|\n|\n______\n"; break; }
	case 0: { cout << "HANG MAN\n" << " __\n|  |\n|\n|\n|\n______\n"; break; }
	}
}
void Hangman::set() {
	for (size_t i = 0; i < gro; i++) {
		v.push_back('_');
	}
	stage();
	printme();
	cout << endl;
}

void Hangman::findme() {
	cout << "Write a letter : ";
	cin >> x;
	cout << "\n\n\n\n\n\n\n\n\n";
	a = special.find(x);
	for (itera = v.begin(); itera != v.end(); ++itera) {
		if (*itera == x) {
			stage();
			cout << "You already found this letter!\n";
			printme();
			isit = 1;
			break;
		}
	}
	if (a != string::npos && isit == 0) {
		v.at(a) = x;
		do {
			a = special.find(x, a + 1);
			if (a != string::npos) {
				v.at(a) = x;
				--gro;
			}
		} while (a != string::npos);
		sup++;
	}
}

void Hangman::printme() {
	for (itera = v.begin(); itera != v.end(); ++itera) {
		cout << *itera << " ";
	}
	cout << endl;
}

void Hangman::check() {
	if (a == string::npos and sup == 0) {
		for (itero = wrong.begin(); itero != wrong.end(); ++itero) {
			if (*itero == x) {
				stage();
				cout << "You already said this letter!\n";
				printme();
				isit2 = 1;
				break;
			}
		}
		if (isit2 == 0) { ++error; stage(); }
		if (error < 6 && isit2 == 0) {
			wrong.push_back(x);
			cout << "That letter isn't in the word\n";
			printme();

		}
		else if (error > 5) {
			death = rand() % 100 + 1;
			if (death <= 10) {
				superprint();
			}
			else {
				cout << "YOU GOT HANGED\n";
				for (int i = 0; i < special.size(); i++) {
					cout << special.at(i) << ' ';
				}
				cout << endl;
				for (it = outco.begin(); it != outco.end(); ++it) {
					outco.push_back(outcome);
					Bet(3, Cbalance);
				}
			}
		}
		isit2 = 0;
	}
	else {
		if (isit == 0) {
			isit = 0;
			stage();
			cout << endl;
			printme();
			counter++;
		}isit = 0;
	}
}

void Hangman::superprint() {
	supa.push_back("   YYYY          YYYY   OOOOOOOOOOOOO       UUUU           UUUU	    DDDDDDDDDDDD      IIIIIIIIIIIIII  EEEEEEEEEEEEEEEEEE  DDDDDDDDDDDD      ");
	supa.push_back("    YYYY        YYYY  OOOOOOOOOOOOOOOOO     UUUU           UUUU	    DDDDDDDDDDDDDD         IIII       EEEEEEEEEEEEEEEEEE  DDDDDDDDDDDDDD    ");
	supa.push_back("     YYYY      YYYY  OOO             OOO    UUUU           UUUU	    DDDD         DDD       IIII	      EEEE                DDDD          DDD  ");
	supa.push_back("      YYYY    YYYY  OOO               OOO   UUUU           UUUU	    DDDD          DDD      IIII	      EEEE                DDDD           DDD ");
	supa.push_back("       YYYY  YYYY  OOO                 OOO  UUUU           UUUU	    DDDD           DDD     IIII       EEEE                DDDD            DDD");
	supa.push_back("        YYYYYYYY  OOO                   OOO UUUU           UUUU     DDDD           DDD     IIII       EEEEEEEEEEEE        DDDD            DDD");
	supa.push_back("         YYYYYY   OOO                   OOO UUUU           UUUU	    DDDD           DDD     IIII       EEEEEEEEEEEE        DDDD            DDD");
	supa.push_back("         YYYYYY    OOO                 OOO  UUUU           UUUU	    DDDD           DDD     IIII       EEEE                DDDD            DDD");
	supa.push_back("         YYYYYY     OOO               OOO   UUUU           UUUU	    DDDD          DDD      IIII       EEEE                DDDD           DDD ");
	supa.push_back("         YYYYYY      OOO             OOO     UUU           UUU 	    DDDD         DDD       IIII       EEEE                DDDD          DDD  ");
	supa.push_back("         YYYYYY       OOOOOOOOOOOOOOOOO       UUUUUUUUUUUUUU        DDDDDDDDDDDDDDD        IIII       EEEEEEEEEEEEEEEEEE  DDDDDDDDDDDDDDD   ");
	supa.push_back("         YYYYYY         OOOOOOOOOOOOO          UUUUUUUUUUUU         DDDDDDDDDDDDD     IIIIIIIIIIIIII  EEEEEEEEEEEEEEEEEE  DDDDDDDDDDDDD     ");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";

	for (its = supa.begin(); its != supa.end(); ++its) {
		cout << *its << endl;
	}
	exit(0);

}
