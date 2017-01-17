//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave 07
//Regne volum for sirkler opp til 20
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
using namespace std;

const int HOYDE = 4;
const float PI = 3.141592;

int radie;

int main() {
	for (int radie = 1; radie <= 20; radie++)
	{
		cout << "Radien = " << radie << "\t";
		cout << "Volum: ";
		cout << PI * radie * radie * HOYDE << endl;
	}
	return 0;
}