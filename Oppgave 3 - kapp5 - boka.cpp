//Opppgave 1 - kapp5 - boka
//Funksjon for å sette den minste av 2 verdier til 0
#include <iostream>
using namespace std;

void zeroSmaller(int &, int &);

int main() {
	int int1, int2;
	cout << "Skriv inn to tall separert med space: ";
	cin >> int1 >> int2; //cin.ignore();
	zeroSmaller(int1, int2);
	cout << int1 << "-" << int2 << endl;
	return 0;
}

void zeroSmaller(int & int1, int & int2) {
	if (int1 < int2)
	{
		int1 = 0;
	}
	else if (int2 < int1)
	{
		int2 = 0;
	}
	else int1 = 0; int2 = 0;
}