//Oppgave 8 - kapp5 - boka
//Bytter om to verdier
#include <iostream>
using namespace std;

void swap(int &, int &);

int main() {
	int en, to;
	cout << "Skriv in to verdier som skal byttes, sparer med space: ";
	cin >> en >> to;
	swap(en, to);
	cout << "Verdiene er: " << en << " - " << to << endl;
	return 0;
}

void swap(int & en,int & to) {
	int temp = en;
	en = to;
	to = temp;
}