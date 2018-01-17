
//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H17_2.CPP

//  Løsningsforslag til eksamen i C++, desember 2017, oppgave 2.
//  Laget av Frode Haug, NTNU

//  Programmet holder orden på antall ganger Norges ulike fylker
//  er besøkt av ulike personer (bosatt i Oppland).

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
	void hentNavn(char nvn[]) { strcpy(nvn, navn); }         //  NY: Oppgave 2G
	int  hentAntall(int nr) { return (antallGanger[nr]); } //  NY: Oppgave 2G
	int  totaltAntallBesok();                   //  Oppgave 2A
	void skrivData();                           //  Oppgave 2A
	void lesData();                             //  Oppgave 2B
	void registrerBesok();                      //  Oppgave 2C
	void skrivAlt();                            //  Oppgave 2D
	void skrivTilFil(ofstream & ut);            //  Oppgave 2E
	void lesFraFil(ifstream & inn, char kl[]);  //  Oppgave 2F
};

//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void skrivAllesData();                       //  Oppgave 2A
void registrerNyDeltager();                  //  Oppgave 2B
void registrerBesok();                       //  Oppgave 2C
void skrivAltOmEn();                         //  Oppgave 2D
void skrivTilFil();                          //  Oppgave 2E
void lesFraFil();                            //  Oppgave 2F
void flestFylkesbesok();                     //  Oppgave 2G


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

//  Oppgave 2A - Returnerer TOTALT antall fylkesbesøk:
int  Deltager::totaltAntallBesok() {
	int sum = 0;                            //  Nullstiller totalsummen.
	for (int i = 0; i < MAXFYLKER; i++)     //  Går gjennom HELE arrayen:
		sum += antallGanger[i];             //  Oppdaterer totalsummen.
	return sum;                             //  Returnerer totalsummen.
}


void Deltager::skrivData() {           //  Oppgave 2A - Skriver alle HOVEDdata:
	cout << '\t' << navn << ", " << klasse
		<< "  #besøk: " << totaltAntallBesok() << '\n';
}


void Deltager::lesData() {            //  Oppgave 2B - Leser deltagerens data:
	les("Navn  ", navn, STRLEN);
	les("Klasse", klasse, 3);
}

//  Oppgave 2C - Registrerer ETT besøk i ETT fylke:
void Deltager::registrerBesok() {
	antallGanger[les("Fylke besøkt", 0, MAXFYLKER - 1)]++;
}

//  Oppgave 2D - Skriver ALT om en deltager, 
void Deltager::skrivAlt() {    //        inkludert antall besøk i hvert følge:
	skrivData();                          //  Skriver hoveddatene.
	for (int i = 0; i < MAXFYLKER; i++)   //  Skriver antall besøk i hvert fylke:
		cout << '\t' << setw(4) << i << ':' << setw(5)
		<< antallGanger[i] << " gang(er) - " << FYLKE[i] << '\n';
}


void Deltager::skrivTilFil(ofstream & ut) {  //  Oppgave 2E - Skriver til fil:
	ut << klasse << ' ' << navn << '\n';        //  Skriver to stk datamedlemmer.
	for (int i = 0; i < MAXFYLKER; i++)         //  Skriver antall besøk 
		ut << ' ' << antallGanger[i];            //      i hvert fylke,
	ut << '\n';                                 //      på EN linje.
}

//  Oppgave 2F - Leser deltageren fra fil:
void Deltager::lesFraFil(ifstream & inn, char kl[]) {
	strcpy(klasse, kl);                   //  Lagrer unna medsendt klassenavn.
	inn.getline(navn, STRLEN);            //  Leser deltagerens navn.
	for (int i = 0; i < MAXFYLKER; i++)   //  Leser antall besøk i hvert fylke:
		inn >> antallGanger[i];
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
		cout << '\t' << t << ": "; cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);            //  Sjekker at tekstlengden er ulik 0.
}

// --------------------------------------------------------------------

void skrivAllesData() {	//  Oppgave 2A - Skriver ALLE deltagernes hoveddata:
	for (int i = 1; i <= sisteDeltager; i++) {  //  For hver deltager:
		cout << setw(11) << i << ':';
		deltagere[i].skrivData();               //  Skrives dens hoveddata.
	}
}

//  Oppgave 2B - Legg inn (om mulig) en ny deltager:
void registrerNyDeltager() {
	if (sisteDeltager < MAXDELTAGERE) {       //  Plass til flere:
		cout << "\tNy deltagers nr: " << ++sisteDeltager << '\n';
		deltagere[sisteDeltager].lesData();    //  Ny tas i bruk. Leser selv data.
	}
	else                                    //  Fullt med deltagere:
		cout << "\n\tFullt med " << MAXDELTAGERE << " deltagere allerede!\n\n";
}

//  Oppgave 2C - Registrer nytt fylkesbesøk for EN person:
void registrerBesok() {                //  Leser deltagerens nr/indeks:
	int nr = les("Hvem har hatt nytt besøk i et fylke", 0, sisteDeltager);
	if (nr != 0)                        //  Reelt nr:
		deltagere[nr].registrerBesok(); //  Deltageren registerer selv besøk.
	else                                //  0 (null) - ingen deltager:
		cout << "\n\tOK - ingen ny registrering.\n\n";
}

//  Oppgave 2D - ALT om EN deltager skrives:
void skrivAltOmEn() {  //  Lest deltagernummer skriver selv ALT:
	deltagere[les("ALLE data om", 1, sisteDeltager)].skrivAlt();
}


void skrivTilFil() {       //  Oppgave 2E - Skriver datastrukturen til fil:
	ofstream ut("FYLKESBESOK.DT2");           //  Åpner aktuell fil:

	cout << "\n\tSkriver til filen 'FYLKESBESOK.DT2' .....\n";
	for (int i = 1; i <= sisteDeltager; i++)  //  Hver enkelt skriver
		deltagere[i].skrivTilFil(ut);         //     ALT om seg selv.
}


void lesFraFil() {          //  Oppgave 2F - Leser HELE datastrukturen fra fil:
	ifstream inn("FYLKESBESOK.DTA");    //  Åpner aktuell fil:
	char klasse[4];

	if (inn) {                          //  Filen finnes:
		cout << "\n\tLeser fra filen 'FYLKESBESOK.DTA' .....\n";
		inn >> klasse;                  //  Prøver å lese 1.feltet.
										//  Ikke slutt og fortsatt plass:
		while (!inn.eof() && sisteDeltager < MAXDELTAGERE) {
			inn.ignore();               //  Deltager leser resten selv fra fil:
			deltagere[++sisteDeltager].lesFraFil(inn, klasse);
			inn >> klasse;              //  Prøver å lese 1.feltet.
		}
	}                                   //  Filen ikke funnet:
	else
		cout << "\n\tFinner ikke filen 'FYLKESBESOK.DTA'!\n";
}

//  Oppgave 2G - Skriver alle navnene til de som har besøkt
void flestFylkesbesok() {      //      hvert enkelt fylke flest ganger:
	int i, j, k, antall,        //  Løkkevariable og antall besøk i ETT fylke.
		storst, nr;             //  Flest fylkesbesøk hittil og indeksteller.
	int indekser[MAXDELTAGERE + 1];  // Indeksene til deltagerne med flest besøk.
	char navn[STRLEN];             // Deltagers navn.

	for (i = 0; i < MAXFYLKER; i++) {       //  Går gjennom ALLE fylkene:
		nr = 0;                             //  Nullstiller.
		storst = 1;                         //  Initierer (kan IKKE være 0!!!)
		for (j = 1; j <= sisteDeltager; j++) { //  Går gjennom ALLE deltagerne:
			antall = deltagere[j].hentAntall(i); // Henter ant.besøk i fylket.
			if (antall >= storst) {         //  Ny rekord eller tangering:
				if (antall > storst) {      //  Ny rekord:
					nr = 0;                 //  Setter tilbake til arraystart.
					storst = antall;        //  Oppdaterer med ny rekord.
				}                           //  I begge tilfeller:
				indekser[++nr] = j;         //  Oppdaterer neste 'skuff'.
			}
		}                                   //  Skriver fylkets nummer og navn:
		cout << setw(10) << i << " - " << FYLKE[i] << " - ";
		if (nr != 0) {                      //  Fylket er besøkt:
			cout << storst << " besøk: ";   //  Rekorden for fylket.
			for (k = 1; k <= nr; k++) {     //  De(n) med flest besøk:
				deltagere[indekser[k]].hentNavn(navn);  //  Henter og skriver
				cout << "  " << navn;                   //   de(n)s navn.
			}
		}
		else cout << "0 besøk: -----";  //  Ingen besøk i fylket (foreløpig).
		cout << '\n';
	}
}