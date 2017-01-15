//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave10
//Spillet NIM
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
using namespace std;
const int MAXANTALLPINS = 25;			//Må være i formen MAXANTALLPINS = 0+(x*4)

int main() {
	int brukertrekk;
	int currentPins = MAXANTALLPINS;
	cout << "Antall pins er " << MAXANTALLPINS << endl;
	do
	{
		do
		{
			cout << "Trekk pinn(s) 1-3: ";
			cin >> brukertrekk;
		} while (brukertrekk < 1 || brukertrekk > 3);
		currentPins -= brukertrekk;
		cout << "Antall pins er na: " << currentPins << endl;
		cout << "Programmet velger: " << 4 - brukertrekk << endl;
		cout << "Antall pins er na: " << currentPins + (brukertrekk - 4) << endl;
		currentPins += brukertrekk - 4;
	} while (currentPins != 1);
	cout << "Programmet vinner!\n";
	return 0;
}