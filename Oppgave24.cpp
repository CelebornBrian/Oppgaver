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
//  ENUM:


//  STRUCT


//  KLASSE:


//  DEKLARASJON AV FUNKSJONER:
void fyllArray(itemType arr[][10]);
void regnSnitt(itemType arr[][10], typeItem linje[], typeItem kolonne[]);
void skrivSnitt(itemType arr[][10], typeItem linje[], typeItem kolonne[]);

//  GLOBALE VARIABLE:
itemType tall[8][10];
typeItem snittLinje[8];
typeItem snittKolonne[10];


//  HOVEDPROGRAM:

int main() {
	fyllArray(tall);
	regnSnitt(tall, snittLinje, snittKolonne);
	skrivSnitt(tall, snittLinje, snittKolonne);

	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:


//  DEFINISJON AV FUNKSJONER:

void fyllArray(itemType arr[][10]) {

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = (rand() % 11) + 10;
		}
	}
	//cout << "\n" << arr[9][7] << "\t\n";
}

void regnSnitt(itemType arr[][10], typeItem linje[], typeItem kolonne[]) {	
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			linje[j] += arr[j][i];
		}

	}
	for (int  i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			kolonne[i] += arr[i][j];
		}

	}
}

void skrivSnitt(itemType arr[][10], typeItem linje[], typeItem kolonne[]) {
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << "\t" << arr[j][i];
		}
		cout << "\t" << linje[j] << "\n";
	}
	for (int k = 0; k < 8; k++)
		//cout << '\t' << kolonne[k];
	cout << "\n";
}