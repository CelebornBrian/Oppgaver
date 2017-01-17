//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave18
//Kassaapperat i butikk
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream>
using namespace std;

//Variabler
char kommando;
char kommando2;
char nyVare;
int rabatt;
float currentVare;
float totalsum;
float alleSummer;
float betaling;

int main() {
	do
	{
		alleSummer = 0;
		do
		{
			cout << "Velg:\nV for innleseing in vare,\t A for angring av siste vare"
				<< "\nE for fratrekk av verdi,\t S for avslutting av current customer\n";
			cin >> kommando;
		} while (kommando != 'V' && kommando != 'A'
			&& kommando != 'E' && kommando != 'S');
		totalsum = 0;
		switch (kommando)
		{
		case 'V':
//			do
//			{
				cout << "Varens pris: "; cin >> currentVare;
				totalsum += currentVare;
//				cout << "Legge til flere varer (y/n)? " << endl;
//				cin >> nyVare;
//			} while (nyVare == 'y');
			break;
		case 'A':
			totalsum -= currentVare;
			break;
		case 'E':
			cout << "Skriv inn et belop som skal trekkes fra sum: ";
			cin >> rabatt;
			if (rabatt > 0 && rabatt < totalsum)
			{
				totalsum -= rabatt;
			}
			else
			{
				cout << "Ugyldig verdi";
			}
			break;
		}									//Eneste mulighet er S, avslutter nåværende kunde
		cout << totalsum << endl;
		alleSummer += totalsum;
		do
		{
			cout << "Velg\nT for regning av hvor mye kunden skal ha tilbake etter betaling"
				<<"\nR for å se totalsum for solgte varer siden programmet startet"
				<< "\nN for å starte ny kunde, Q for å avslutte\n";
			cin >> kommando2;
		} while (kommando2 != 'T' && kommando2 != 'R'
			&& kommando2 != 'N' && kommando2 != 'Q');
		switch (kommando2)
		{
		case 'T':
			cout << "Hva har kunden betalt: ";
			cin >> betaling;
			if (betaling > totalsum)
			{
				cout << "Kunden skal få tilbake: " << betaling - totalsum;
			}
			else
			{
				cout << "Ugyldig verdi";
			}
			break;
		case 'R':
			cout << "Totalsum siden programmet startet: " << alleSummer;
			break;
		}
	} while (kommando2 == 'N');
	cout << "Summen for alle kunder er: "		//Eneste mulighet er Q
		 << alleSummer << endl;
	return 0;
}