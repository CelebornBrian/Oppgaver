//Oppgave 50
//Brusflasker i kassen
#include <iostream>
using namespace std;

const int antallFlasker = 24;

int main() {
	for (int i = antallFlasker; i > 2; i--)
	{
		cout << i << " brusflasker i kassen, " << i
			<< " flasker med brus.\n";
		cout << "Ta en og drikk den opp, " << i - 1 << " flasker igjen i kassen.\n";
	}
	cout << "2 brusflasker i kassen, 2 flasker med brus\n"
		<< "Ta en og drikk den opp, 1 flaske igjen i kassen.\n"
		<< "1 brusflaske i kassen, 1 flaske med brus.\n"
		<< "Gå til butikken og kjøp mer, " << antallFlasker << " flasker igjen i kassen.\n";
	return 0;
}