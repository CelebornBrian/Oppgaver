//Oppgave 7

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