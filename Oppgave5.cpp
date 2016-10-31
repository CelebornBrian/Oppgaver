//Oppgave 5
//ASCII tall og float
#include <iostream>

using namespace std;

int main() {
	char char1, char2, char3;													//Variable to use
	float tall1, tall2;															//Float variables to use
	cout << "Skriv inn 3 bokstaver for å få ASCII verdien: ";
	cin >> char1 >> char2 >> char3;												//Input char variables
	cout << int(char1) << '\t' << int(char2) << '\t' << int(char3) << endl;		//Print ASCII values
	cout << "Skriv inn 2 tall med desimaler, bruk . som komma. Viser avrundet ";
	cin >> tall1 >> tall2;														//Input desimaltall
	cout << int(tall1) << '\t' << int(tall2) << '\n';							//Print heltallsverdi of float numbers
	return 0;
	}