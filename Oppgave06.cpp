//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave 6
//Lage program med fastsatt output
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << setw(25) << "Kamper     "	<< setw(6) << "Serie" << setw(8) << "Uavgj." << setw(8) << "Tap" << setw(8) << "Poeng" << '\n';
	cout <<				"STORHAMAR  "	<< setw(6) << "18" << setw(11) << "14"<< setw(8) << "1" << setw(10) << "3" << setw(8) << "29" << '\n';
	cout <<				"Lillehammer"	<< setw(6) << "18" << setw(11) << "12" << setw(8) << "4" << setw(10) << "2" << setw(8) << "28" << '\n'; 
	cout <<				"Stavanger  "	<< setw(6) << "18" << setw(11) << "10" << setw(8) << "3" << setw(10) << "5" << setw(8) << "23" << '\n';
	cout <<				"VIF Hockey "	<< setw(6) << "18" << setw(11) << "10" << setw(8) << "2" << setw(10) << "6" << setw(8) << "22" << '\n';
	cout << "GRATULERER MED SEIERSMESTERSKAPET, STORHAMAR !!\n";
	return 0;
}