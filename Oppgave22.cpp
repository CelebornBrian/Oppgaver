//Oppgave 22 
//Hoppere
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:

#include <iostream>						//  cin, cout
#include <cstring>						//  strcpy, strcmp, strlen
using namespace std;

//  CONST:

const int STRLEN = 40;
const int ANTALLHOPPERE = 2;
const int ANTALLSTILKARAKTERER= 5;
const int MINHOPPLENGDE = 20;
const int MAXHOPPLENGDE = 130;
const int MINSTILKAR = 5;
const int MAXSTILKAR = 20;

//  KLASSE:

class Hopper {
private:
	char navn[STRLEN];
	int poengsum,
		lengde;
	int stilKarakter[ANTALLSTILKARAKTERER];
public:
	Hopper();
	void les2(char n[]);
	void hopp();
};

//  DEKLARASJON AV FUNKSJONER:

void les(const char t[], char s[], const int LEN);
//int les(const char t[], const int min, const int max);
float les(const char t[], const int min, const int max);//Les tall

//  GLOBALE VARIABLE:

Hopper hoppere[ANTALLHOPPERE + 1];

//  HOVEDPROGRAM:

int main() {
	char navn[STRLEN];
	for (int i = 1; i <= ANTALLHOPPERE; i++)
	{
		les("Navn: ", navn, STRLEN);
		hoppere[i].les2(navn);
	}
	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:

Hopper::Hopper()
{
	strcpy(navn, ""); poengsum = 0; lengde = -1;
}
void Hopper::les2(char n[]) {
	strcpy(navn, n);
}
void Hopper::hopp() {
	lengde = ::les("Lengde på hopp: ", MINHOPPLENGDE, MAXHOPPLENGDE);
	for (int i = 0; i < ANTALLSTILKARAKTERER; i++)
	{
		stilKarakter[i] = ::les("Stilkarakter: ", MINSTILKAR, MAXSTILKAR);
	}
}

//  DEFINISJON AV FUNKSJONER:

//  Leser et tall i et visst intervall:
float les(const char t[], const int min, const int max) {
	float n;
	do {                               // Skriver ledetekst:
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> n;   cin.ignore();         // Leser inn ett tall.
	} while (n < min || n > max);      // Sjekker at i lovlig intervall.
	return n;                           // Returnerer innlest tall.
}
//  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {
	do {
		cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);           //  Sjekker at tekstlengden er ulik 0.
}