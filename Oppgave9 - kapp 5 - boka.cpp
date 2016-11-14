//Oppgave 9 - kapp5 - boka
//Bytter om to verdier
#include <iostream>
#include <iomanip>
using namespace std;

struct tid
{
	int timer;
	int minutter;
	int sekunder;
};

void swap(tid &, tid &);

int main() {
	tid en = { 23, 59, 59 };
	tid to = { 01, 01, 01 };
	cout << "Before swap,\t Tid1 =: " << setw(2) << en.timer << ":" << setw(2) << en.minutter << ":" << setw(2) << en.sekunder << endl;
	cout << "\t\t Tid2 =: " << setw(2) << to.timer << setw(2) << ":" << to.minutter << setw(2) << ":" << to.sekunder << endl;
	swap(en, to);
	cout << "After swap,\t Tid1 =: " << setw(2) << en.timer << ":" << setw(2) << en.minutter << ":" << setw(2) << en.sekunder << endl;
	cout << "\t\t Tid2 =: " << setw(2) << to.timer << setw(2) << ":" << to.minutter << setw(2) << ":" << to.sekunder << endl;
	return 0;
}

void swap(tid & en, tid & to) {
	tid temp = en;
	en = to;
	to = temp;
}