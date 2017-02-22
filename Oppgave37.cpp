//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave 37
//Leking med pekere
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <iostream>
#include <cctype>
using namespace std;

//  HOVEDPROGRAM:

int main() {
	//int a = 111, b = 222, c = 333, d = 444, e = 555;
	int intarray[5] = { 111, 222, 333, 444, 555 };
	char ch;
	//int* ptr = &c;
	int* ptr = intarray;
	cout << "adressen til prt er: " << ptr << "  verdien ptr peker på: " << *ptr << endl
		<< "Increase eller Decrease ptr?";
	cin >> ch; ch = toupper(ch);
	while (ch == 'I' || ch == 'D')
	{
		if (ch == 'I') //ptr += 8;
		ptr++;
		else //ptr -= 8;
			ptr--;
		cout << "ptr har nå adressen: " << ptr << " og verdien :" << *ptr << endl;
		cout << "Increase eller Decrease ptr?";
		cin >> ch; ch = toupper(ch);
	}
	return 0;
}