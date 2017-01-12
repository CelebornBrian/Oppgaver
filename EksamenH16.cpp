
//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H16_2.TPL

//  Skjellettet/template for eksamen i C++, desember 2016, oppgave 2.
//  Laget av Frode Haug, HiG, NTNU

//  Programmet holder orden på ulike utlegg/utgifter en person har ifm. en
//  felles vennetur, og hvem av deltagerne som skal betale og har betalt
//  hva av utleggene.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <fstream>				//  ifstream, ofstream
#include <iostream>				//  cin, cout
#include <cstring>				//  strcpy, strlen
#include <cctype>				//  toupper
using namespace std;

//  CONST:
const int  STRLEN = 60;		//  Max. tekstlengde.
const int  MAXDELTAGERE = 10;		//  Max. antall deltagere på turen.
const int  MAXUTLEGG = 50;		//  Max. antall utlegg/utgifter.
const int  MAXPRPERSON = 5000;		//  Max. pris pr.person for ETT utlegg.


class Deltager {		//  KLASSER:
private:
	char navn[STRLEN];				//  Deltagerens: - navn
	char mail[STRLEN];				//               - mail-adresse
	int  tlf;                       //               - telefon (mobil)

public:					//  Deklarasjon/definisjon av medlemsfunksjoner:
	Deltager() { strcpy(navn, "");  strcpy(mail, "");  tlf = 0; }
	void lesData();								//  Oppgave 2B
	void skrivNavn() { cout << navn; }
	void skrivData();							//  Oppgave 2C
	void lesFraFil(ifstream & inn);				//  Oppgave 2G
};


class Utlegg {
private:
	char hva[STRLEN];				//  Utleggets:  - type/"navn"
	int  prisPrPerson;				//              - pris pr.person
	int  betalt[MAXDELTAGERE + 1];	//              - status ift. hvem skal og
									//                  har betalt for seg

public:					//  Deklarasjon/definisjon av medlemsfunksjoner:
	Utlegg();									//  Oppgave 2A
	void skrivData();							//  Oppgave 2C
	void lesData();								//  Oppgave 2D
	void registrerBetaling(int n);				//  Oppgave 2E
	void lesFraFil(ifstream & inn);				//  Oppgave 2G
	int returnGjeld(int delnr);
};

//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void registrerDeltagereEllerLesFraFil(); //  (Oppgave 2B og 2G)
void registrerDeltagere();				 //  Oppgave 2B
void skrivAlt();						 //  Oppgave 2C
void nyttUtlegg();						 //  Oppgave 2D
void registrerBetaling();				 //  Oppgave 2E
void deltagerneSkylder();				 //  Oppgave 2F
void lesFraFil();						 //  Oppgave 2G


										 //  GLOBAL VARIABEL:
Deltager deltagere[MAXDELTAGERE + 1];		//  Deltagerne/vennene på turen.
Utlegg   utlegg[MAXUTLEGG + 1];				//  Utleggene for turen.
int sisteDeltager, sisteUtlegg;             //  Siste indeks/"skuff" brukt 
											//    i de to arrayene.

int main() {		//  HOVEDPROGRAM:
	char kommando;

	registrerDeltagereEllerLesFraFil();		//  (OPPGAVE 2B og 2G)
	skrivMeny();
	cout << "\nØnske:  ";  kommando = les();
	while (kommando != 'Q') {
		switch (kommando) {
		case 'S': skrivAlt();			break;	//  Oppgave 2C  
		case 'U': nyttUtlegg();			break;	//  Oppgave 2D
		case 'B': registrerBetaling();	break;	//  Oppgave 2E
		case 'D': deltagerneSkylder();	break;	//  Oppgave 2F
		default:  skrivMeny();			break;
		}
		cout << "\nØnske:  ";  kommando = les();
	}
	cout << "\n\n";
	return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Deltager::lesData() {		//  Leser ALLE deltagerens data:
								//  Oppgave 2B:  Lag innmaten
	les("Navn: ", navn, STRLEN);
	les("Mail: ", mail, STRLEN);
	tlf = les("Tlf: ", 10000000, 99999999);
}


void Deltager::skrivData() {	//  Skriver ALLE deltagerens data:
								//  Oppgave 2C:  Lag innmaten
	cout << navn << '\n' << mail << '\n' << tlf << '\n';
}


void Deltager::lesFraFil(ifstream & inn) {  //  Leser ALT fra fil:
											//  Oppgave 2G:  Lag innmaten
	inn.getline(navn, STRLEN);
	inn.getline(mail, STRLEN);
	inn >> tlf; inn.ignore();
}

// --------------------------------------------------------------------

Utlegg::Utlegg() {			//  Initierer/"nullstiller" objektet:
							//  Oppgave 2A:  Lag innmaten
	strcpy(hva, ""); prisPrPerson = 0; 
	for (int i = 1; i < MAXDELTAGERE + 1; i++)
	{
		betalt[i] = -1;
	}
}


void Utlegg::skrivData() {	//  Skriver ALLE data:
							//  Oppgave 2C:  Lag innmaten
	cout << hva << " " << prisPrPerson << '\n';
	for (int i = 1; i <= MAXDELTAGERE; i++)
	{
		deltagere[i].skrivNavn(); cout << '\t';
		if (betalt[i] == -1)
		{
			cout << "Melding 1";
		}
		else if (betalt[i] == 0)
		{
			cout << "Melding 2";
		}
		else
		{
			cout << prisPrPerson;
		}
	}
}


void Utlegg::lesData() {	//  Leser utlegget og hvem skal betale:
							//  Oppgave 2D:  Lag innmaten
	les("Navn på utlegg: ", hva, STRLEN);
	prisPrPerson = les("Pris per pers:", 1, MAXPRPERSON);
	for (int i = 1; i <= MAXDELTAGERE; i++)
	{
		deltagere[i].skrivNavn();
		cout << '\n' << "Skal betale? (J\n)";
		char ch = les();
		if (ch == 'J')
		{
			betalt[i] = 0;
		}
	}
}

//  Registerer innbetaling fra deltager 'n':
void Utlegg::registrerBetaling(int n) {
	//  Oppgave 2E:  Lag innmaten
	deltagere[n].skrivNavn(); cout << '\t';
	if (betalt[n] == 0)
	{
		cout << prisPrPerson << '\n';
		betalt[n] = 1;
	}
	else if (betalt[n] == 1)
	{
		cout << "Har allerede betalt" << '\n';
	}
	else
	{
		cout << "Skal IKKE betale dette utlegget" << '\n';
	}
}


void Utlegg::lesFraFil(ifstream & inn) {   //  Leser ALT fra fil:
										   //  Oppgave 2G:  Lag innmaten
	inn.getline(hva, STRLEN);
	inn >> prisPrPerson; inn.ignore();
	for (int k = 1; k <= MAXDELTAGERE + 1; k++)
	{
		inn >> betalt[k];
	}
	inn.ignore();
}

int Utlegg::returnGjeld(int delnr)
{
	if (betalt[delnr] == 1)
	{
		return prisPrPerson;
	}
	return 0;
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny() {          //  Presenterer lovlige menyvalg:
	cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
	cout << "\tS = Skriv alle deltagere og utlegg\n";
	cout << "\tU = nytt Utlegg har forekommet\n";
	cout << "\tB = Betaling foretatt av en av deltagerne\n";
	cout << "\tD = hva hver av Deltagerne skylder\n";
	cout << "\tQ = Quit/avslutt\n";
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

//  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {
	do {
		cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);             //  Sjekker at tekstlengden er ulik 0.
}

// --------------------------------------------------------------------

void registrerDeltagereEllerLesFraFil() {	//  (Oppgave 2B og 2G)
	ifstream inn("DELTAGERE.DTA");
	if (!inn)
		registrerDeltagere();					//  Oppgave 2B
	else {
		inn.close();
		lesFraFil();							//  Oppgave 2G
	}
}


void registrerDeltagere() {		//  Registrerer ALLE deltagerne:
								//  Oppgave 2B:  Lag innmaten
	sisteDeltager = les("Hvor mange deltakere?", 1, MAXDELTAGERE);
	for (int i = 1; i <= sisteDeltager; i++)
	{
		deltagere[i].lesData();
	}
}


void skrivAlt() {				//  Skriver ALLE deltagerne og utleggene:
								//  Oppgave 2C:  Lag innmaten
	for (int i = 1; i <= sisteDeltager; i++)
	{
		cout << i << ": "; deltagere[i].skrivData();
	}
	for (int j = 1; j <= sisteUtlegg; j++)
	{
		cout << j << ": ";  utlegg[j].skrivData();
	}
}


void nyttUtlegg() {				//  Nytt utlegg registeres/har forekommet:
								//  Oppgave 2D:  Lag innmaten
	if (sisteUtlegg < MAXUTLEGG + 1)
	{
		utlegg[++sisteUtlegg].lesData();
	}
	else
	{
		cout << "Utlegg fult";
	}
}


void registrerBetaling() {		// Registrerer innbetaling(er):
								//  Oppgave 2E:  Lag innmaten
	int m, n;
	m = les("Deltaker nummer: ", 0, sisteDeltager);
	while (m != 0)
	{
		n = les("Utleggsnummer: ", 0, sisteUtlegg);
		while (n != 0)
		{
			utlegg[n].registrerBetaling(m);
		}
		m = les("Deltaker nummer: ", 0, sisteDeltager);
	}
	cout << "Intet gjøres";
}


void deltagerneSkylder() {		//  Skriver hva hver enkelt deltager skylder:
								//  Oppgave 2F:  Lag innmaten
	int i, sum = 0, j;
	for (int i = 1; i <= sisteDeltager; i++)
	{
		deltagere[i].skrivNavn(); cout << '\t';
		for (int j = 1; j <= sisteUtlegg; j++)
		{
			sum += utlegg[j].returnGjeld(i);
		}
		cout << "Skylder: " << sum;
	}
}


void lesFraFil() {				//  Leser HELE datastrukturen fra fil:
								//  Oppgave 2G:  Lag innmaten
	ifstream innfil("UTLEGG.DTA");
	if (innfil)
	{
		innfil >> sisteUtlegg; innfil.ignore();
		for (int i = 1; i <= sisteUtlegg; i++)
		{
			utlegg[i].lesFraFil(innfil);
		}
	}
	ifstream innfil2("DELTAGERE.DTA");
	if (innfil2)
	{
		innfil2 >> sisteDeltager; innfil2.ignore();
		for (int j = 1; j <= sisteDeltager; j++)
		{
			deltagere[j].lesFraFil(innfil);
		}
	}

}
