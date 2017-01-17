//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave 8
//Be om heltall frem til 0 eller negative tall så skrive ut 
//hvor mange tall, total sum og gjennomsnitt av de inskrevene tall
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
using namespace std;

int helTall;
int totalTall;
int antallTall;

int main() {
	antallTall = 0;
	do
	{
		cout << "Skriv inn heltall, 0 eller negative tall avslutter: ";
		cin >> helTall;
		if (helTall > 0)
		{
			totalTall += helTall;
			antallTall++;
		}
	} while (helTall > 0);
	cout << "Antall tall: " << antallTall << '\t';
	cout << "Total sum: " << totalTall << '\t';
	cout << "Gjennomsnitt: " << float(totalTall) / antallTall << endl;

	return 0;
}