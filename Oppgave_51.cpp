//Cesar Cipher
#include <iostream>
#include <cstring>
using namespace std;

const int MAXLENGTH = 81;
const int KEYMIN = 0;
const int KEYMAX = 25;
const int MOVE = int ('A');

int main() {
	char txt[MAXLENGTH], cipher[MAXLENGTH], buffer;
	int key = -1, j;
	cout << "Skriv inn text som skal krypteres, max tegn = " << MAXLENGTH - 1 << ": ";
	cin.getline(txt, MAXLENGTH);
	for (int i = 0; i <= strlen(txt); i++)
	{
		txt[i] = toupper(txt[i]);
	}
	while (key < KEYMIN || key > KEYMAX)
	{
		cout << "Skriv inn cipher key " << KEYMIN << "-" << KEYMAX << ": ";
		cin >> key;
	}
	for (j = 0; j < strlen(txt); j++)
	{
		buffer = char(((txt[j] - MOVE) + key) % (KEYMAX + 1));
		cipher[j] = char(buffer + MOVE);
	}
	cipher[j] = '\0';
	cout << txt << endl << cipher << endl;
	return 0;
}