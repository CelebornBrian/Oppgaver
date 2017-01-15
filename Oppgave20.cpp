//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave 20
//Dagnummer
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
using namespace std;

//  DEKLARASJON AV FUNKSJONER:

bool skuddaar(int aa);
int dagnummer(int & da, int & ma, int & aa);
void les(int & da, int & maane, int & aa);

int main() {
	int dag, maaned, aar, totalDagnr;
	do
	{
		les(dag, maaned, aar);
		if ((totalDagnr = dagnummer(dag, maaned, aar)) != 0)
		{
			cout << "Datoen er " << totalDagnr << " dager inn i aaret.\n\n";
		}
	} while (totalDagnr != 0);
	cout << "Ikke gyldig dato, program avsluttes.\n\n";

	return 0;
}

// ***********************  DEFINISJON AV FUNKSJONER:  ***********************
bool skuddaar(int aa) {    //  Sjekker om et visst �r er skudd�r:
								//  Skudd�r dersom: (delelig med 400) ELLER 
								//    (delelig med 4 OG ikke med 100)
	return ((aa % 400 == 0) || ((aa % 4 == 0) && (aa % 100) != 0));
}
int dagnummer(int & da, int & ma, int & aa) {
	//  Setter opp antall dager i m�nedene.
	//   Verdien for februar settes senere.
	int dagerPrMaaned[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalDagnr, i;
	if (aa < 1600 || aa > 2100) return 0;    //  Ulovlig �r.
	if (ma < 1 || ma > 12)   return 0;    //  Ulovlig m�ned.
										  //Ut fra om �ret er skudd�r eller ei
	dagerPrMaaned[1] = (skuddaar( aa)) ? 29 : 28;//s� settes februar verdien
	if (da < 1 || da > dagerPrMaaned[ma - 1])  return 0;  // Ulovlig dag:
														  //  Garantert at er en lovlig dato!!
	totalDagnr = da;
	for (i = 0; i < ma - 1; i++)              // Regner ut datoens dagnummer.
		totalDagnr += dagerPrMaaned[i];

	return totalDagnr;                          // Returnerer dagnummeret.
}
//  Leser inn og returnerer verdi i [MIN, MAX]:
void les(int & da, int & maane, int & aa) {
	cout << "Skriv inn dato paa formen dd mm aaaa: ";
	cin >> da >> maane >> aa;
}