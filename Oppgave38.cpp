//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream>
using namespace std;
//  CONST;
int LEN = 80;

//  DEKLARASJON AV FUNKSJONER:
void intarray(int* arr, const int LEN, int verdi);
void skrivArr(int* arr, const int LEN);

//  GLOBALE VARIABLE:


//  HOVEDPROGRAM:

int main() {
	int* intptr = new int[LEN];

	intarray(intptr, LEN, 20);
	skrivArr(intptr, LEN);
	return 0;
}


//  DEFINISJON AV FUNKSJONER:

void intarray(int * arr, const int LEN, int verdi)
{
	for (int i = 0; i < LEN; i++)
	{
		*(arr +i) = verdi;
	}
}

void skrivArr(int * arr, const int LEN)
{
	for (int i = 0; i < LEN; i++)
	{
		cout << *(arr + i) << endl;
	}
}
