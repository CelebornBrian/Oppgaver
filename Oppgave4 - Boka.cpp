//Oppgave4 fra side 127 i læreboka
//Four function calculator

#include <iostream>
using namespace std;

//Variables
float number1;
float number2;
char function;
float sum;
char cont;

int main() {
	do
	{
		cout << "Enter first number, operator, second number(Seperate with space): ";
		cin >> number1 >> function >> number2;

		switch (function)
		{
		case '+':
			sum = number1 + number2;
			break;
		case '-':
			sum = number1 - number2;
			break;
		case '*':
			sum = number1 * number2;
			break;
		case '/':
			sum = number1 / number2;
			break;
		default:
			cout << "Error: incorrect operator";
		}
		cout << "Answer = " << sum << endl;
		do
		{
			cout << "Do another (y/n)?";
			cin >> cont;
		} while (cont != 'y' && cont != 'n');
	} while (cont == 'y');
	return 0;
}
