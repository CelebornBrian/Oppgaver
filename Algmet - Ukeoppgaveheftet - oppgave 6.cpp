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

using namespace std;

//  CONST:


//  ENUM:


//  STRUCT


//  KLASSE:

//  DEKLARASJON AV FUNKSJONER:
void flytt1(int n, char fra, char via, char til);

//  GLOBALE VARIABLE:
int i = 0;

//  HOVEDPROGRAM:

int main() {

	int antSkiver;
	char ch;

	cout << "\nAntall skiver:  ";        //  Leser antall skiver/ringer.
	cin >> antSkiver;

	flytt1(antSkiver, 'A', 'B', 'C');
	cout << i;
	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:


//  DEFINISJON AV FUNKSJONER:

void flytt1(int n, char fra, char via, char til) {
	i++;
	if (n == 1)                      // Nytt trekk kan foretas:
		cout << fra << " => " << til << "    ";
	else {
		flytt1(n - 1, fra, til, via);  // N-1 stk: Fra "fra" til "via" via "til".
		flytt1(1, fra, via, til);    // Den siste: fra "fra" til "til" via "via"
		flytt1(n - 1, via, fra, til);  // N-1 fra det ›verste rekursive kallet:
	}                                //   Fra "via" via "fra" til "til".
}