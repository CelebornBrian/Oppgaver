//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <iostream>          //  cin, cout
#include <iomanip>			 //  setw
#include <fstream>           //  ifstream, ofstream
#include <cstring>           //  strcpy, strlen
#include <cctype>            //  toupper
#include "TIMER.H"			 //  klokkeslett
using namespace std;

//  CONST:

const int STRLEN = 13;
const int MAXLOPERE = 50;

//  KLASSE:

class Lopere {
private:
	char navn[STRLEN];
	char etterNavn[STRLEN];
	char land[3];
public:
	Lopere();
	void lesFraFil(ifstream & inn);
	void skrivMeg(ofstream & ut);
	void skrivMeg();
};

class Resultat {
private:
	int loper;
	int pass_sek;
public:
	Resultat();
	void skrivResultat(ofstream & ut);
	void skrivResultatListe();
	int passSek();
	void lagrePassTid(int nr);
};

//  DEKLARASJON AV FUNKSJONER:

void skriv_meny();
char les_kommando();
char les();
int les(const char t[], const int min, const int max);
void lesFraFil();
void skrivTilFil();
void startIntervall();
void startTid();
void skrivTid(ofstream & ut, const int sek);
void skrivResultat();
void registerPassering();
int hentTid();
void sorterListe();

//  GLOBALE VARIABLE:
Lopere lopere[MAXLOPERE + 1];
Resultat resultat[MAXLOPERE + 1];
Timer tp;
int ant_lopere = 6;
int start_int = 0;
int start_tid = 0;
int har_passert = 0;


//  HOVEDPROGRAM:

int main() {
	char kommando;
	lesFraFil();
	startIntervall();
	startTid();
	skriv_meny();              //  Skriver aktuelle valg/muligheter.

	kommando = les_kommando(); //  Leser brukerens valg.
	while (kommando != 'Q') {
		switch (kommando) {
		case 'S': skrivTilFil();			break;
		case 'O': skrivResultat();			break;
		case 'R': registerPassering();		break;
		default:  skriv_meny();             break;
		}
		kommando = les_kommando();        //  Leser brukerens valg.
	}
	skrivTilFil();
	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:
Lopere::Lopere() {
	strcpy(navn, "");
	strcpy(etterNavn, "");
	strcpy(land, "");
}
void Lopere::lesFraFil(ifstream & inn) {
	char text[STRLEN-1];
	inn >> text; strcpy(navn, text);
	inn >> text; strcpy(etterNavn, text);
	inn >> text; strcpy(land, text);
}

void Lopere::skrivMeg(ofstream & ut) {
	ut << setw(22) << navn << " " << etterNavn << "\t";
}

void Lopere::skrivMeg() {
	cout << setw(22) << navn << " " << etterNavn << "\t";
}

//-------------------------------------------------------------------------

Resultat::Resultat() {
	loper = pass_sek = 0;
}

void Resultat::skrivResultat(ofstream & ut) {
	lopere[loper].skrivMeg(ut);
	if (!pass_sek)
	{
		skrivTid(ut, pass_sek);
	}
}

void Resultat::skrivResultatListe()
{
	int time, minutt, sekund;
	if (!pass_sek)
	{
		lopere[loper].skrivMeg();
		time = pass_sek / 3600;
		minutt = (pass_sek % 3600) / 60;
		sekund = pass_sek % 60;
		cout << ((time < 10) ? "0" : "") << time << ":"
			<< ((minutt < 10) ? "0" : "") << minutt << ":"
			<< ((sekund < 10) ? "0" : "") << sekund << endl;
	}
	else
	{
		cout << "Ingen passeringer!" << endl;
	}
}

int Resultat::passSek()
{
	return pass_sek;
}

void Resultat::lagrePassTid(int nr)
{
	pass_sek = nr;
}

//  DEFINISJON AV FUNKSJONER:

void skriv_meny() {         //  Skriver meny/lovlige kommandoer til bruker:
	cout << "\n\n\nFølgende kommandoer er lovlig:\n";
	cout << "\tS - Skriv resultatliste til fil\n";
	cout << "\tO - Vis resultatliste over paserte hittil\n";
	cout << "\tR - Registre ny passering\n";
	cout << "\tQ - Quit / avslutt\n";
}


char les_kommando() {            //  Leser og returnerer ETT upcaset tegn.
	char ch;
	cout << "\n\nKommando:  ";   cin >> ch;   cin.ignore();
	return (toupper(ch));
}

char les() {			//  Henter ett ikke-blankt upcaset tegn:
	char ch;
	cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
	return (toupper(ch));         //  Upcaser og returnerer.
}

//  Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max) {
	int n;
	do {								// Skriver ledetekst:
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> n;   cin.ignore();		// Leser inn ett tall.
	} while (n < min || n > max);		// Sjekker at i lovlig intervall.
	return n;							// Returnerer innlest tall.
}

void lesFraFil() {
	ifstream innfil("DATLOPERE.DAT");          //  Åpner aktuell fil.
	if (innfil) {                            //  Filen finnes:
		innfil >> ant_lopere; innfil.ignore();
		for (int i = 1; i <= ant_lopere; i++)
		{
			lopere[i].lesFraFil(innfil);
		}
	}
	else
		cout << "\n\nFant ikke filen 'DATLOPERE.DAT'!";
}

void skrivTilFil() {
	ofstream utfil("DATLOPERE.RES");
	for (int i = 1; i <= ant_lopere; i++)
	{
		resultat[i].skrivResultat(utfil);
	}
	cout << "Naavaerende resultatliste skrevet til \"DATLOPERE.RES\"" << endl;
}
void startIntervall() {
	do
	{
		cout << "Skriv inn startintervall mellom lopere (30 eller 60): " << endl;
		cin >> start_int;
	} while (start_int != 30 && start_int != 60);
}

void startTid() {
	int time, minutt, sekund, tidsek, startsek;
	tidsek = hentTid();
	do
	{
		time = les("Startid time: ", 0, 23);
		minutt = les("Startid minutt: ", 0, 59);
		sekund = les("Startid sekund: ", 0, 59);
		startsek = time * 3600 + minutt * 60 + sekund;
	} while ((tidsek - startsek) > 3600);
	start_tid = startsek;
}

void skrivTid(ofstream & ut, const int sek) {
	int time, minutt, sekund;
	time = sek / 3600;
	minutt = (sek % 3600) / 60;
	sekund = sek % 60;
	ut << ((time < 10) ? "0" : "") << time << ":"
		<< ((minutt < 10) ? "0" : "") << minutt << ":"
		<< ((sekund < 10) ? "0" : "") << sekund << endl;
}

void skrivResultat() {
	char ch;
	for (int i = 1; i <= har_passert; i++)
	{
		if (!(i%20))
		{
			cout << "Skriv in tegn for aa fortsette: ";
			ch = les();
		}
		resultat[i].skrivResultatListe();
	}
}

void registerPassering()
{
	int passTid, nr = les("Skriv in nummer paa loper som passerer: ", 1, ant_lopere);
	passTid = hentTid();
	if (passTid >= (start_tid + ((nr-1) * start_int)))
	{
		resultat[nr].lagrePassTid(passTid);
		sorterListe();
	}
}

int hentTid() {
	int time, minutt, sekund, tidsek;
	tp.hent(time, minutt, sekund);
	tidsek = time * 3600 + minutt * 60 + sekund;
	return tidsek;
}

void sorterListe() {
	int i, j;
	Resultat temp;
	for (i = 0; i < ant_lopere - 1; i++)    //  For hver nasjon, untatt den siste:
		for (j = i + 1; j < ant_lopere; j++)  // Sammenligner med de etterf›lgende.
			if (resultat[i].passSek() < resultat[j].passSek()) {  // Dersom noen med flere medaljer:
				temp = resultat[i];             // S† bytter disse plass. 
				resultat[i] = resultat[j];
				resultat[j] = temp;
			}
}