//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave 49
//Skrive ut tallene opp til 45 med andre ord
//når det er divisable med 3 og 5
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream> 
using namespace std;

const int teller = 45;

int main() {
	for (int i = 1; i <= teller; i++)
	{
		if (i%3 == 0 && i%5 == 0)
		{
			cout << "Pomel & Pilt\n";
		}
		else if (i%3 == 0)
		{
			cout << "Pomel\n";
		}
		else if(i%5 == 0)
		{
			cout << "Pilt\n";
		}
		else
		{
			cout << i << endl;
		}
	}
}