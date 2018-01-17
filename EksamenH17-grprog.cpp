//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******

//  Skjellettet/template for eksamen i C++, desember 2017, oppgave 2.
//  Laget av Frode Haug, HiG, NTNU

//  Programmet holder orden på antall ganger Norges ulike fylker
//  er besøkt av ulike personer (bosatt i Oppland).
//  Oppgavene er med unntak av lesfrafil og flestfylkesbesok skrevet av PK.

#ifdef  _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//  INCLUDE:
#include <fstream>              //  ifstream, ofstream
#include <iostream>             //  cin, cout
#include <iomanip>              //  setw
#include <cstring>              //  strcpy, strlen
#include <cctype>               //  toupper
using namespace std;

//  CONST:
const int  STRLEN = 40;     //  Max. tekstlengde.
const int  MAXDELTAGERE = 50;     //  Max. antall deltagere i oversikten.
const int  MAXFYLKER = 18;     //  Antall fylker i Norge (-Oppland).
const char FYLKE[MAXFYLKER][STRLEN / 2] =       // Fylkesnavn (-Oppland):
{ "Østfold",   "Akershus",  "Oslo",  "Hedmark",  "Buskerud",
"Vestfold",  "Telemark", "Aust-Agder", "Vest-Agder", "Rogaland",
"Hordaland", "Sogn og Fjordane", "Møre og Romsdal", "Sør-Trøndelag",
"Nord-Trøndelag", "Nordland", "Troms", "Finnmark" };


class Deltager {    //  KLASSE:
private:
	char navn[STRLEN];              //  Navn
	char klasse[4];                 //  Klassenavn (f.eks: 1B, 4A, 7C, 10A).
	int  antallGanger[MAXFYLKER];   //  Antall besøk i hvert fylke (bruker
									//      indeks nr.0 og oppover).
public:                   //  Deklarasjon/definisjon av medlemsfunksjoner:
	Deltager() {
		strcpy(navn, "");  strcpy(klasse, "");      //  Ferdiglaget:
		for (int i = 0; i < MAXFYLKER; i++)  antallGanger[i] = 0;
	}
	int  totaltAntallBesok();                   //  Oppgave 2A
	void skrivData();                           //  Oppgave 2A
	void lesData();                             //  Oppgave 2B
	void registrerBesok();                      //  Oppgave 2C
	void skrivAlt();                            //  Oppgave 2D
	void skrivTilFil(ofstream & ut);            //  Oppgave 2E
	void lesFraFil(ifstream & inn, char kl[]);  //  Oppgave 2F
	void hentNavn(char nvn[]) { strcpy(nvn, navn); }		//2G
	int  hentAntall(int nr) { return (antallGanger[nr]); }	//2G
};

//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void skrivAllesData();                          //  Oppgave 2A
void registrerNyDeltager();                     //  Oppgave 2B
void registrerBesok();                          //  Oppgave 2C
void skrivAltOmEn();                            //  Oppgave 2D
void skrivTilFil();                             //  Oppgave 2E
void lesFraFil();                               //  Oppgave 2F
void flestFylkesbesok();                        //  Oppgave 2G


												//  GLOBALE VARIABLE:
Deltager deltagere[MAXDELTAGERE + 1];    //  Deltagerne i oversikten.
int sisteDeltager = 0;                   //  Siste indeks/"skuff" brukt.


int main() {       //  HOVEDPROGRAM:
	char kommando;

	lesFraFil();                                    //  Oppgave 2F
	skrivMeny();
	cout << "\nØnske:  ";  kommando = les();
	while (kommando != 'Q') {
		switch (kommando) {
		case 'D': skrivAllesData();       break;  //  Oppgave 2A
		case 'N': registrerNyDeltager();  break;  //  Oppgave 2B
		case 'B': registrerBesok();       break;  //  Oppgave 2C
		case 'A': skrivAltOmEn();         break;  //  Oppgave 2D
		case 'F': flestFylkesbesok();     break;  //  Oppgave 2G
		default:  skrivMeny();            break;
		}
		cout << "\nØnske:  ";  kommando = les();
	}
	skrivTilFil();                                  //  Oppgave 2E
	cout << "\n\n";
	return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

//  Returnerer TOTALT antall fylkesbesøk:
int  Deltager::totaltAntallBesok() {
	int tot = 0;
	for (int i = 0; i < MAXFYLKER; i++)
	{
		tot += antallGanger[i];
	}
	return tot;
}


void Deltager::skrivData() {        //  Skriver alle HOVEDdata:
	cout << navn << '/t' << klasse << '/t' << totaltAntallBesok() << endl;
}


void Deltager::lesData() {         //  Leser deltagerens data:
	les("Skriv inn navn", navn, STRLEN);
	les("Skriv inn klasse", klasse, 4);
}


void Deltager::registrerBesok() {  //  Registrerer ETT besøk i ETT fylke:
	int fylke = les("Skriv fylkenr", 0, MAXFYLKER);
	antallGanger[fylke]++;
}

//  Skriver ALT om en deltager, 
void Deltager::skrivAlt() {    //    inkludert antall besøk i hvert følge:
	skrivData();
	for (int i = 0; i < MAXFYLKER; i++)
	{
		cout << i << " - " << FYLKE[i] << antallGanger[i] << endl;
	}
}


void Deltager::skrivTilFil(ofstream & ut) {  //  Skriver til fil:
	ut << klasse << ' ' << navn << endl;
	for (int i = 0; i < MAXFYLKER; i++)
	{
		ut << ' ' << antallGanger[i];
	}
}

//  Leser deltageren fra fil:
void Deltager::lesFraFil(ifstream & inn, char kl[]) {
	strcpy(klasse, kl);
	inn.getline(navn, STRLEN);
	for (int i = 0; i < MAXFYLKER; i++)
	{
		inn >> antallGanger[i];
	}
	inn.ignore();
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny() {          //  Presenterer lovlige menyvalg:
	cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
	cout << "\tD = skriv alle Deltagernes hoveddata\n";
	cout << "\tN = registrer en Ny deltager\n";
	cout << "\tB = registrerer ett nytt Besøk i et fylke\n";
	cout << "\tA = skriv Alt om en deltager\n";
	cout << "\tF = navn(ene) til de(n) som har besøkt Fylkene flest ganger\n";
	cout << "\tQ = Quit/avslutt\n";
}


char les() {                //  Henter ett ikke-blankt upcaset tegn:
	char ch;
	cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
	return (toupper(ch));         //  Upcaser og returnerer.
}

//  Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max) {
	int n;
	do {                                // Skriver ledetekst:
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> n;   cin.ignore();       // Leser inn ett tall.
	} while (n < min || n > max);       // Sjekker at i lovlig intervall.
	return n;                           // Returnerer innlest tall.
}

//  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {
	do {
		cout << '\t' << t << ": ";  cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);             //  Sjekker at tekstlengden er ulik 0.
}

// --------------------------------------------------------------------

void skrivAllesData() {         //  Skriver ALLE deltagernes hoveddata:
	for (int i = 1; i <= sisteDeltager; ++i)
	{
		cout << i << ": ";
		deltagere[i].skrivData();
	}
}


void registrerNyDeltager() {   //  Legg inn (om mulig) en ny deltager:
	if (sisteDeltager > MAXDELTAGERE)
	{
		cout << ++sisteDeltager;
		deltagere[sisteDeltager].lesData();
	}
	else
	{
		cout << "Ikke plass til flere deltagere!";
	}
}


void registrerBesok() {        //  Registrer nytt fylkesbesøk for EN person:
	int nr = les("Skriv inn deltagernummer", 0, sisteDeltager);
	if (nr != 0)
	{
		deltagere[nr].registrerBesok();
	}
	else
	{
		cout << "Intet gjøres" << endl;
	}
}


void skrivAltOmEn() {          //  ALT om EN deltager skrives:
	int nr = les("Skriv inn deltagernummer", 1, sisteDeltager);
	deltagere[nr].skrivAlt();
}


void skrivTilFil() {           //  Skriver datastrukturen til fil:

	ofstream ut("FYLKESBESOK.DT2");
	for (int i = 1; i <= sisteDeltager; i++)
		deltagere[i].skrivTilFil(ut);
}


void lesFraFil() {              //  Leser HELE datastrukturen fra fil:
	ifstream inn("FYLKESBESOK.DT2");
	char klasse[4];

	if (inn)
	{
		inn >> klasse;
		while (!inn.eof() && sisteDeltager < MAXDELTAGERE)
		{
			inn.ignore();
			deltagere[++sisteDeltager].lesFraFil(inn, klasse);
			inn >> klasse;
		}
	}
}

//  Skriver alle navnene til de som har
void flestFylkesbesok() {      //    besøkt hvert enkelt fylke flest ganger:
	int indekser[MAXDELTAGERE + 1], indexteller, storst, antall;
	char navn[STRLEN];
	for (int i = 0; i < MAXFYLKER; i++)
	{
		indexteller = 0;
		storst = 1;
		for (int j = 1; j <= sisteDeltager; ++j)
		{
			antall = deltagere[j].hentAntall(i);
			if (antall >= storst)
			{
				if (antall > storst)
				{
					indexteller = 0;
					storst = antall;
				}
				indekser[++indexteller] = j;
			}
		}

		cout << i << " - " << FYLKE[i] << " - ";
		if (indexteller != 0)
		{
			cout << storst << " besøk: ";
			for (int k = 1; k <= indexteller; ++k)
			{
				deltagere[indekser[k]].hentNavn(navn);
				cout << navn;
			}
		}
		else
		{
			cout << "0 besøk: -----";
		}
		cout << endl;
	}
}