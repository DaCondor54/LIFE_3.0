#include "Person.h"
using namespace std;
int Person::salaryp = 0;
Person::Person()
	:totalm(0), chanceN(0), ites(0), ite(0), hours(0), odes(0), possibility(0)
{
	/*totalm = 0;
	chanceN = 0;
	ites = 0;
	ite = 0;
	hours = 0;
	odes = 0;
	possibility = 0;*/
}

void Person::Name() {
	counterD = 0;
	offday = 0;
	bonuss = 0;
	job = 1;
	counterD++;
	cout << "\n\nDay " << counterD << endl;
	string arrname[28] = { "Charles", "Cynthia", "Lea", "Gabriel", "Simon", "William", "Victor",
	 "Megane", "Audrey", "Sophia", "Charlotte", "Joe", "Laeticia", "Tina", "marieve",
	"Sandrine", "Andrea", "Micheal", "Sarah-Michelle","Maria", "Jennifer", "Vladimir", "Laurie", "Catherine",
		"Jonathan", "Hugo", "James", "Justin" };
	string arrspecial[9] = { "Tyron","Marine", "Malina", "Anais", "Coco", "Gabdub", "Guay", "Pierre-Marc" };
	chanceN = rand() % 100 + 1;
	if (chanceN < 6) {
		ites = rand() % 9;
		namez = arrspecial[ites];
		cout << namez << endl;
	}
	else {
		ite = rand() % 28;
		namez = arrname[ite];
		cout << namez << endl;
	}
	salaryp = rand() % 24 + 12;
	cout << "Your salary!: " << salaryp << "$\n";

}
void Person::Salary() {
	hours;
	odes = rand() % 40;
	if (odes > 4) {
		hours = 8;
		if (odes > 34) {

			bonuss = rand() % 70 + 30;
		}
		else {
			bonuss = 0;
		}
	}
	else if (odes <= 4) {
		hours = odes;
		offday++;
	}
	TotalE = salaryp * hours;
	TotalE += bonuss;

	Work(balance);
	if (offday >= 3) {
		Fired();
	}
}
void Person::Fired() {
	cout << "You weren't coming enough to work your Boss decided to fire you\n";
	salaryp = 0;
	job = 0;
}
void Person::newjob() {
	possibility = rand() % 100;
	if (possibility > 89) {
		salaryp = rand() % 24 + 12;
		offday = 0;
		job = 1;
		cout << "You found a new job!\nwith a salary of: " << salaryp << "$\n";
	}
	else {
		cout << "BAD LUCK!\nYou didn't find a job\n";
	}
}//nojob pcont boby Person