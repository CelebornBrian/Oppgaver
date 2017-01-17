//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
//  Skjellettet/template for eksamen i C++, desember 2016, oppgave 2.
//  Laget av Frode Haug, HiG, NTNU

//  Programmet holder orden på ulike utlegg/utgifter en person har ifm. en
//  felles vennetur, og hvem av deltagerne som skal betale og har betalt
//  hva av utleggene.


					//  INCLUDE:
#include <fstream>				//  ifstream, ofstream
#include <iostream>				//  cin, cout
#include <cstring>				//  strcpy, strlen
#include <cctype>				//  toupper
using namespace std;

					//  CONST:
const int  STRLEN       =   60;		//  Max. tekstlengde.
const int  MAXDELTAGERE =   10;		//  Max. antall deltagere på turen.
const int  MAXUTLEGG    =   50;		//  Max. antall utlegg/utgifter.
const int  MAXPRPERSON  = 5000;		//  Max. pris pr.person for ETT utlegg.


class Deltager {		//  KLASSER:
  private:
	char navn[STRLEN];				//  Deltagerens: - navn
	char mail[STRLEN];				//               - mail-adresse
	int  tlf;                       //               - telefon (mobil)

  public:					//  Deklarasjon/definisjon av medlemsfunksjoner:
	Deltager() {  strcpy(navn, "");  strcpy(mail, "");  tlf = 0;  }
	void lesData();								//  Oppgave 2B
	void skrivNavn() {  cout << navn;  }
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

int main()  {		//  HOVEDPROGRAM:
	char kommando;

	registrerDeltagereEllerLesFraFil();		//  (OPPGAVE 2B og 2G)
	skrivMeny();
	cout << "\nØnske:  ";  kommando = les();
	while (kommando != 'Q')  {
		switch (kommando)  {
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
}


void Deltager::skrivData() {	//  Skriver ALLE deltagerens data:
	//  Oppgave 2C:  Lag innmaten
}


void Deltager::lesFraFil(ifstream & inn) {  //  Leser ALT fra fil:
	//  Oppgave 2G:  Lag innmaten
}

// --------------------------------------------------------------------

Utlegg::Utlegg() {			//  Initierer/"nullstiller" objektet:
	//  Oppgave 2A:  Lag innmaten
}


void Utlegg::skrivData() {	//  Skriver ALLE data:
	//  Oppgave 2C:  Lag innmaten
}


void Utlegg::lesData() {	//  Leser utlegget og hvem skal betale:
   //  Oppgave 2D:  Lag innmaten
}

							//  Registerer innbetaling fra deltager 'n':
void Utlegg::registrerBetaling(int n) {
	//  Oppgave 2E:  Lag innmaten
}


void Utlegg::lesFraFil(ifstream & inn) {   //  Leser ALT fra fil:
   //  Oppgave 2G:  Lag innmaten
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
}


void skrivAlt() {				//  Skriver ALLE deltagerne og utleggene:
	//  Oppgave 2C:  Lag innmaten
}


void nyttUtlegg() {				//  Nytt utlegg registeres/har forekommet:
	//  Oppgave 2D:  Lag innmaten
}


void registrerBetaling() {		// Registrerer innbetaling(er):
	//  Oppgave 2E:  Lag innmaten
}

								
void deltagerneSkylder()  {		//  Skriver hva hver enkelt deltager skylder:
	//  Oppgave 2F:  Lag innmaten
}


void lesFraFil() {				//  Leser HELE datastrukturen fra fil:
	//  Oppgave 2G:  Lag innmaten
}
