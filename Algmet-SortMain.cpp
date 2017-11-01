//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Main file that includes different sorting algorithms and validates them
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <iostream>
#include "Algmet-SortLib.h"

using namespace std;
//  CONST:
const int LEN = 15;


//  HOVEDPROGRAM:

int main() {
	itemType arr[LEN + 1] = { ' ', 'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E',
		'X', 'A', 'M', 'P', 'L', 'E' };

	print(arr, LEN);

	selectionSort(arr, LEN);
	insertionSort(arr, LEN);
	bubbleSort(arr, LEN);

	cout << "\nArrayet er " << ((validate(arr, LEN)) ? "IKKE " : "") << "sortert.\n";
	print(arr, LEN);

	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:


//  DEFINISJON AV FUNKSJONER:

