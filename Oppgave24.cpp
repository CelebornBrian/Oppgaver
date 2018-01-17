//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <iostream>
#include <cstdlib>

using namespace std;

//  CONST:
typedef int itemType;
typedef float typeItem;
const int LINJE = 8;
const int KOLONNE = 10;
//  ENUM:


//  STRUCT


//  KLASSE:


//  DEKLARASJON AV FUNKSJONER:
void fyllArray(itemType arr[][KOLONNE]);
void regnSnitt(itemType arr[][KOLONNE], typeItem linje[], typeItem kolonne[]);
void skrivSnitt(itemType arr[][KOLONNE], typeItem linje[], typeItem kolonne[]);

//  GLOBALE VARIABLE:
itemType tall[LINJE][KOLONNE];
typeItem snittLinje[LINJE];
typeItem snittKolonne[KOLONNE];


//  HOVEDPROGRAM:

int main() {
	fyllArray(tall);
	//regnSnitt(tall, snittLinje, snittKolonne);
	skrivSnitt(tall, snittLinje, snittKolonne);

	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:


//  DEFINISJON AV FUNKSJONER:

void fyllArray(itemType arr[][KOLONNE]) {

	for (int i = 0; i < LINJE; i++)
	{
		for (int j = 0; j < KOLONNE; j++)
		{
			arr[i][j] = (rand() % 11) + 10;
		}
	}
	//cout << "\n" << arr[9][7] << "\t\n";
}

void regnSnitt(itemType arr[][KOLONNE], typeItem linje[LINJE], typeItem kolonne[KOLONNE]) {	
	for (int j = 0; j < KOLONNE; j++)
	{
		for (int i = 0; i < LINJE; i++)
		{
			linje[j] += arr[j][i];
		}

	}
	for (int  i = 0; i < LINJE; i++)
	{
		for (int j = 0; j < KOLONNE; j++)
		{
			kolonne[i] += arr[i][j];
		}

	}
}

void skrivSnitt(itemType arr[][KOLONNE], typeItem linje[], typeItem kolonne[]) {
	for (int j = 0; j < KOLONNE; j++)
	{
		for (int i = 0; i < LINJE; i++)
		{
			cout << "\t" << arr[j][i];
		}
		cout << "\t" << linje[j] << "\n";
	}
	//for (int k = 0; k < 8; k++)
		//cout << '\t' << kolonne[k];
	//cout << "\n";
}