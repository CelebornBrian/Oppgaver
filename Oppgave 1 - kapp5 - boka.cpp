//Oppgave 1 i boka kappitel 5
//Fuksjon for areal av sirkel
#include <iostream>
using namespace std;

float circarea(float);

int main() {
	int radius;
	float area;
	cout << "Skriv inn radius på sirkel for a regne ut areal: ";
	cin >> radius; 
	area = circarea(radius);
	cout << "Arealet er: " << area << endl;

}

float circarea(float rad) {
	const float PI = 3.14159F;
	float area = PI * rad * rad;
	return area;
}
