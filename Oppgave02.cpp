//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//oppgave2
//Demonstrates integer variables
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream>
using namespace std;

int main() {
	int var1;					//Define var1
	int var2;					//Define var2
	var1 = 20;					//Assign value to var1
	var2 = var1 + 10;			//Assign value to var2
	cout << "var1+10 is ";		//Output text
	cout << var2 << endl;		//Output value of var2
	cout << char(248) << endl;
	return 0;
}