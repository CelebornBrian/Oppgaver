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
	float poengsum;
	int lengde;
	int stilKarakter[ANTALLSTILKARAKTERER];
	void sorterKarakter();
public:
	Hopper();
	void les2(char n[]);
	void hopp();
	void poengSum();
	void skrivNavn();
};

//  DEKLARASJON AV FUNKSJONER:

void les(const char t[], char s[], const int LEN);		//Les tekst
int les(const char t[], const int min, const int max);//Les tall
void regnPoengsum();
void skrivAlle();

//  GLOBALE VARIABLE:

Hopper hoppere[ANTALLHOPPERE + 1];

//  HOVEDPROGRAM:

int main() {
	char navn[STRLEN];
	for (int i = 1; i <= ANTALLHOPPERE; i++)
	{
		les("Navn paa deltaker", navn, STRLEN);
		hoppere[i].les2(navn);
	}
	for (int i = 1; i <= ANTALLHOPPERE; i++)
	{
		cout << "Statistikk for hoppet til "; 
		hoppere[i].skrivNavn(); cout << ": ";
		hoppere[i].hopp();
	}
	skrivAlle();
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
	lengde = les("Lengde på hopp", MINHOPPLENGDE, MAXHOPPLENGDE);
	for (int i = 0; i < ANTALLSTILKARAKTERER; i++)
	{
		stilKarakter[i] = les("Stilkarakter", MINSTILKAR, MAXSTILKAR);
	}
}

void Hopper::poengSum()
{
	float lengdePoeng, stilPoeng;
	sorterKarakter();
	lengdePoeng = (70 + ((lengde - 80) * 1.4));
	stilPoeng = (stilKarakter[1] + stilKarakter[2] + stilKarakter[3]);
	poengsum = (lengdePoeng + stilPoeng);
}
void Hopper::sorterKarakter() {
	int i, j, temp = stilKarakter[0];
	for (i = 0; i < ANTALLSTILKARAKTERER-1; i++)
	{
		for (j = i + 1; j < ANTALLSTILKARAKTERER; j++)
		{
			if (stilKarakter[i] < stilKarakter[j])
			{
				temp = stilKarakter[i];
				stilKarakter[i] = stilKarakter[j];
				stilKarakter[j] = temp;
			}
		}
	}
}
void Hopper::skrivNavn() {
	if (poengsum)
	{
		cout << navn << " med " << poengsum << " antall poeng." << endl;
	}
	else
	{
		cout << navn;
	}
}

//  DEFINISJON AV FUNKSJONER:

//  Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max) {
	int n;
	do {                               // Skriver ledetekst:
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> n;   cin.ignore();         // Leser inn ett tall.
	} while (n < min || n > max);      // Sjekker at i lovlig intervall.
	return n;                           // Returnerer innlest tall.
}
void regnPoengsum()
{
	for (int i = 1; i <= ANTALLHOPPERE; i++)
	{
		hoppere[i].poengSum();
	}
}
//  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {
	do {
		cout << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);           //  Sjekker at tekstlengden er ulik 0.
}

void skrivAlle() {
	for (int i = 1; i <= ANTALLHOPPERE; i++)
	{
		hoppere[i].skrivNavn();
	}
}