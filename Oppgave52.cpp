//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave 52
//Skrive ut 10 og 10 tall, evig
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream>
#include <cctype>
using namespace std;
/*
int main() {
	char fortsette;
	for (int i = 1; true; i++)
	{
		cout << i << endl;
		if (i%10 == 0)
		{
			cout << "Vil du fortsette Y/n: \n";
			cin >> fortsette;
			fortsette = toupper(fortsette);
			if (fortsette == 'N') break;
		}
	}
}
*/
int main() {
	int totalTall = 1;
	char fortsette;
	do
	{
		for (int i = 1; i <= 10; i++)
		{

			cout << totalTall << endl;
			totalTall++;
		}
		cout << "Fortsette(Y/n)";
		cin >> fortsette;
		fortsette = toupper(fortsette);
	} while (fortsette != 'N');
}