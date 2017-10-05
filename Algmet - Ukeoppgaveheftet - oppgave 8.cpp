// Tidligere oblig 2 i Algmet

//  Permuteringer av texter
//  utskrevet med regler.


#include <iostream>
#include <cstring>
using namespace std;

const int N = 15;                       //  Arrayens lengde.

char arr[N];                            //  Global array av int'er.
int utskrevet = 0;
int textlengde;

bool navnOK(char arr[], int len);
bool allerede(char a[], int i, int t);

void display(char a[]) {               //  Viser arrayens innhold.
									   /*
	if (utskrevet != 0 && !(utskrevet % 24))
	{
		char ch;
		cout << "\nTast inn et tegn for å fortsette..";
		cin >> ch;
	}
									   */
	cout << "\n" << ++utskrevet << ": ";
	for (int i = 0; i < textlengde; i++)
		cout << a[i] << ' ';
}


void bytt(char & a1, char & a2) {       //  Bytter om to array-elementer.
	char aa = a1;
	a1 = a2;
	a2 = aa;
}


void roterVenstre(char a[], int i) {   //  Roterer elementer mot venstre.
	int k;
	char x;
	x = a[i];                            //  Tar vare p† f›rste.
	for (k = i + 1; k < textlengde; k++)          //  Roterer:
		a[k - 1] = a[k];
	a[textlengde - 1] = x;                          //  Legger f›rst inn bakerst.
}


void perm(int i) {
	int t;
	if (i == textlengde - 1 && navnOK(arr, i))      //  N†dd en ny permutasjon:
		display(arr);                     //  Skriver ut arrayens innhold.
	else {									//  Skal permutere:
		if (navnOK(arr, i))
		{
			perm(i + 1);                        //  Beholder n†v‘rende nr.'i'.
		}
											//    Permuterer resten.
		for (t = i + 1; t < textlengde; t++) {
			bytt(arr[i], arr[t]);         //  Bytter nr.'i' etter tur med alle
			
			if (!allerede(arr, i, t) && navnOK(arr, i))
				perm(i + 1);				//    de andre etterf›lgende.
						                   //  For hver av ombyttene: permuterer
		}                                 //    resten av de N etterf›lgende.
		roterVenstre(arr, i);             //  Gjenoppretter opprinnelig array.
	}
}

bool erVokal(char ch) {					//Skjekk om det er en vokal
	if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y' || ch == 'æ' || ch == 'ø' || ch == 'å')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool navnOK(char a[], int i) {      //  'i' vil max. vëre 'N-1'.
	if (i == 1) {                           //  Eksakt TO tegn lang:
		if (a[0] == a[1])  return false;      //  1e: To fõrste bokstaver er LIKE.
	}
	else if (i >= 2) {                    //  MINST TRE tegn lang:
		if (erVokal(a[i])) {             //  Nr. 'i' er en vokal:
			if (a[i] == a[i - 1])  return false; //  1a: To LIKE vokaler
												 //  1b: Tre VOKALER:
			if (erVokal(a[i - 1]) && erVokal(a[i - 2]))  return false;
		}
		else {                        //  Nr. 'i' er en konsonant:
									  //  1c: Tre LIKE konsonanter:
			if (a[i] == a[i - 1] && a[i] == a[i - 2])  return false;
			if (i >= 3) {                     //  MINST FIRE tegn lang:
											  //  1d: FIRE konsonanter:
				if (!erVokal(a[i - 1]) && !erVokal(a[i - 2]) && !erVokal(a[i - 3]))
					return false;
			}
		}
	}
	return true;
}
/*
int navnOK(char a[], int len) {
	for (int i = 0; i < len; i++)
	{
		if (i == 1)
		{
			if (a[0] == a[1])
			{
				return 0;
			}
		}
		else if (i >= 2)
		{
			if (erVokal(a[i]))
			{
				if (a[i] == a[i - 1])
				{
					return 0;
				}
				if (erVokal(a[i - 1]) && erVokal(a[i - 2]))
				{
					return 0;
				}
			}
			else
			{
				if (a[i] == a[i - 1] == a[i - 2])//a[i] == a[i-1] && a[i] == a[i-2]
				{
					return 0;
				}
				if (i >= 3)
				{
					if (!erVokal(a[i - 1]) && !erVokal(a[i - 2]) && !erVokal(a[i - 3]))
					{
						return 0;
					}
				}
			}
		}
		return 1;
	}
}*/
//  Sjekker etter om tegnet 'a[i]'
//      ogs† er † finne i arrayens
bool allerede(char a[], int i, int t) {  //    intervall 'i+1'- 't'.
	for (int j = i + 1; j <= t; j++)
		if (a[i] == a[j])  return true;     //  Duplikater finnes.
	return false;                           //  Alt OK.
}
//  Omgjør en tekststreng til KUN STORE bokstaver,
void uppercase(char tekst[]) {    //  også  'æ', 'ø' og 'å':
	int i, len = strlen(tekst);         //  Finner tekstens lengde.
	for (i = 0; i < len; i++) {      //  Går gjennom hele tekststrengen:
		if (tekst[i] == 'æ')  tekst[i] = 'Æ';       // Tegnet er 'æ', 'ø' eller
		else if (tekst[i] == 'ø')  tekst[i] = 'Ø';  //   'å': konverterer til
		else if (tekst[i] == 'å')  tekst[i] = 'Å';  //   stor bokstav.
		else tekst[i] = toupper(tekst[i]);   //  Ellers prøves å konvertere
	}                                        //   'a'-'z' til STOR bokstav.
}


int main() {
	cout << "Skriv inn tekst som skal permuteres, max " << N << " tegn:\n";
	cin.getline(arr, N);
	uppercase(arr);
	textlengde = strlen(arr);

	perm(0);                             //  Lager/skriver permutasjon av ALLE
										 //    sifrene/arrayelementene.
	cout << '\n';
	//utskrevet--;
	display(arr);                        //  Skriver array etter at ferdig (for
	cout << "\n\n";                      //   † se om orginal er gjenopprettet).
	return 0;
}