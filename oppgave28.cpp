//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <iostream>
using namespace std;

//  CONST:


//  ENUM:


//  STRUCT


//  KLASSE:

class Vektor {
private:
	int x;
	int y;
public:
	Vektor() { x = 0, y = 0; };
	Vektor(int xx, int yy) { x = xx, y = yy; };
	void skrivPunkt();

	Vektor operator + (Vektor rhs);
	Vektor operator - (Vektor rhs);
	Vektor operator * (int rhs);
	Vektor operator / (int rhs);
};

//  DEKLARASJON AV FUNKSJONER:


//  GLOBALE VARIABLE:


//  HOVEDPROGRAM:

int main() {
	Vektor v1(4, 5), v2(5, 4), v3;
	v1.skrivPunkt(); v2.skrivPunkt();
	v3 = v1 + v2; v3.skrivPunkt();
	v3 = v1 - v2; v3.skrivPunkt();
	v2 = v2 * 10; v3.skrivPunkt();
	v3 = v2 / 5; v3.skrivPunkt();

	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:

void Vektor::skrivPunkt()
{
	cout << "Koordinater er: (" << x << "," << y << ")" << endl;
}

Vektor Vektor::operator+ (Vektor rhs) {
	return Vektor(x + rhs.x, y + rhs.y);
}

Vektor Vektor::operator- (Vektor rhs) {
	return Vektor(x - rhs.x, y - rhs.y);
}

Vektor Vektor::operator* (int rhs) {
	return Vektor(x * rhs, y * rhs);
}

Vektor Vektor::operator/ (int rhs) {
	if ((x % rhs) == 0 && (y % rhs) == 0)
	{
		return Vektor(x / rhs, y / rhs);
	}
	else
	{
		cout << "Ingen heltall som svar ";
		return *this;	
	}
}


//  DEFINISJON AV FUNKSJONER:

