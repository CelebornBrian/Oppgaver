//Oppgave 4.ccp
//Heltall og utregninger

#include <iostream>

using namespace std;

int main() {
	int i, j, k, kvadrati, kvadratj, kvadratk, sum1, sum2;						//Alle int variabler
	float gjen1, gjen2;															//Alle float variabler
	cout << "Skriv in 3 heltall: ";												//Ber om input
	cin >> i >> j >> k;															//Lagrer input i variabler
	kvadrati = (i*i), kvadratj = (j*j), kvadratk = (k*k);						//Regner kvadratene
	cout << "Kvadratet av " << i << " er: " << kvadrati << endl;				//Printer kvadratene
	cout << "Kvadratet av " << k << " er: " << kvadratj << endl;				//--------^---------
	cout << "Kvadratet av " << i << " er: " << kvadratk << endl;				//--------^---------
	sum1 = (i + j + k), sum2 = (kvadrati + kvadratj + kvadratk);				//Regner summene
	cout << "Summen av heltallene er: " << sum1 << endl;						//Printer summene
	cout << "Summen av kvadratene er: " << sum2 << endl;						//-----^---------
	gjen1 = (i + j + k) / 3.0F;													//Regner gjennomsnitt
	gjen2 = (kvadrati + kvadratj + kvadratk) / 3.0F;							//Regner gjennomsnitt
	cout << "Gjennomsnittet av tallene er: " << gjen1 << endl;					//Printer gjennomsnitt
	cout << "Gjennomsnittet av kvadratene er: " << gjen2 << endl;				//--------^-----------
	return 0;
}