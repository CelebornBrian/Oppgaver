//Oppgave 14
//Enkel kalkulator
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float tall, akkumulator = 0.0F;
	char operasjon;

	cout << setiosflags(ios::fixed)
		<< setiosflags(ios::showpoint)
		<< setprecision(3);

	cout << "Enkel kalkulator starter:\n\n";
	cout << "= " << akkumulator;

	cout << "\n\n: ";
	cin >> operasjon;
	while (operasjon != 's')
	{
		switch (operasjon)
		{
		case '+': cin >> tall; akkumulator += tall; break;
		case '-': cin >> tall; akkumulator -= tall; break;
		case '*': cin >> tall; akkumulator *= tall; break;
		case '/': cin >> tall; if (tall == 0)
			{

			cout << "Feil! Dele på null er tull";
			}
				  else akkumulator /= tall; break;
		case 't': cin >> tall; akkumulator = tall;  break;
		case 'c': akkumulator = 0.000F; break;
		default: cout << "Feil! Ukjent kommando gitt"; break;
		}
		cout << "= " << akkumulator << "\n\n: ";
		cin >> operasjon >> tall;
	}
	cout << "\n Enkel kalkulator stopper.\n";
	return 0;
}