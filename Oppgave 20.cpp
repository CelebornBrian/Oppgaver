//Oppgave 20
//Skrive inn lovlig dato og si hvilket dagsnummer i året det er
#include <iostream>
using namespace std;

void lesDato(int dd &, int mm &, int aaaa &)
bool skudaar(int aaaa)
int antallDager(int maaned, int aar)
int dagNummer(int dd, int mm, int aaaa)


void lesDato(int d&, int m&, int aa&) {
	int d, m, aa;
	cout << "Skriv inn datoen i format \"dd mm aaaa\"";
	cin >> d >> m >> aa;
}

bool skudaar(int skudaar) {
	return((skudaar % 400 == 0) || ((skudaar % 4 == 0) && (skudaar % 100) != 0));
}

int antallDager(int maaned, int aar) {
	switch (maaned)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31; break;
	case 4: case 6: case 9: case 11: return 30; break;
	case 2: if (skudaar(aar)) return 29; else return 28; break;
	}
}

int dagNummer(int dd, int mm, int aaaa) {
	int dagnummer;
	if (dd > antallDager(mm, aaaa) || dd < 1) return 0;
	if (mm > 12 || mm < 1) return 0;
	if (aaaa > 2100 || aaaa < 1600) return 0;
	dagnummer = dd;
	for (int i = 0; i < (mm - 1); i++)
	{
		dagnummer += antallDager(i, aaaa);
	}
	dagnummer += dd;
	return dagnummer;
}

