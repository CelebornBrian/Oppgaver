//Oppgave9
//Program som leser inn to heltall, deretter adderer
//subtrakterer og multipliserer disse før det blir spurt om dette skal gjøres igjen

#include <iostream>
using namespace std;

//Variabler
int	tall1, tall2;
char igjen;

int main() {
	do
	{
		cout << "Skriv in 2 heltall separert med space: "; cin >> tall1 >> tall2;

		cout << tall1 << "addert med " << tall2 << " er lik "
			<< tall1 + tall2 << endl;
		cout << tall1 << "subtraktert med " << tall2 << " er lik "
			<< tall1 - tall2 << endl;
		cout << tall1 << "multiplisert med " << tall2 << " er lik "
			<< tall1 * tall2 << endl;
		do
		{
			cout << "Vil du kjore programmet igjen?Y/n ";
			cin >> igjen;
		} while (igjen != 'y' && igjen != 'Y' &&
				 igjen != 'n' && igjen != 'N');
	} while (igjen == 'Y' || igjen == 'y');
	return 0;
}