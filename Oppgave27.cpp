//Oppgave 27
//Overloading of operators
#include <iostream>
using namespace std;

class Tid {
private:
	int time;
	int minutt;

public:
	Tid() { time = 0; minutt = 0; }
	Tid(int t, int m) { time = t; minutt = m; }

	Tid& operator+=(int rhs);

};

void skrivMeny();
char les();

int main() {
	char kommando;
	Tid t1(9, 30), t2(19, 32), t3;
	skrivMeny();
	cout << "\nCommand: "; kommando = les();
	while (kommando != 'Q') {
		switch (kommando) {
		case 'A': t1 += 47;			break;	//  Oppgave 2C  
											//case 'U': nyttUtlegg();			break;	//  Oppgave 2D
											//case 'B': registrerBetaling();	break;	//  Oppgave 2E
											//case 'D': deltagerneSkylder();	break;	//  Oppgave 2F
		default:  skrivMeny();			break;
		}
		cout << "\nØnske:  ";  kommando = les();
	}
	cout << "\n\n";
	return 0;
}

// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny() {          //  Presenterer lovlige menyvalg:
	cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
	cout << "\tA = Legges til antall minutter i objektet \n";
	//cout << "\tU = nytt Utlegg har forekommet\n";
	//cout << "\tB = Betaling foretatt av en av deltagerne\n";
	//cout << "\tD = hva hver av Deltagerne skylder\n";
	cout << "\tQ = Quit/avslutt\n";
}


char les() {			//  Henter ett ikke-blankt upcaset tegn:
	char ch;
	cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
	return (toupper(ch));         //  Upcaser og returnerer.
}

Tid & Tid::operator+=(int rhs)
{
	// TODO: insert return statement here
}
