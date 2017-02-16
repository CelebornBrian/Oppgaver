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
const int STRLEN = 60;

//  ENUM:


//  STRUCT


//  KLASSE:
class Publication {
private:
	char title[STRLEN];						//Title
	float price;							//Price
protected:
public:
	void getData();
	void putData();
};

class Disk : public Publication{
private:
	enum diskType
	{
		CD, DVD
	};
	diskType type;
protected:
public:
	void getData();
	void putData();
};

//  DEKLARASJON AV FUNKSJONER:
char les(char* t);
float les(const char t[], const int MIN, const int MAX);
void les(const char t[], char s[], const int STRLEN);

//  GLOBALE VARIABLE:


//  HOVEDPROGRAM:

int main() {
	Disk NewMoon;
	NewMoon.getData();
	NewMoon.putData();
	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:
void Publication::getData() {
	les("Skriv inn navn: ", title, STRLEN);
	price = les("Skriv inn pris: ", 0, 9999);
}

void Publication::putData()
{
	cout << "Tittel: " << title << "\tPris: " << price << '\t';
}

//----------------------------------------------------------------

void Disk::getData()
{
	char valg;
	Publication::getData();
	valg = les("Velg 'c' for CD, 'd' for DVD");
	type = (valg == 'C') ? CD : DVD;
}

void Disk::putData()
{
	Publication::putData();
	cout << "Lagret på en " << ((type == CD) ? "CD" : "DVD") << endl;
}
//  DEFINISJON AV FUNKSJONER:

char les(char* t) {         //  Leser og upcaser ett tegn:
	char ch;
	cout << "\n\n" << t << ": ";
	cin >> ch;   cin.ignore();
	return (toupper(ch));
}

float les(const char t[], const int MIN, const int MAX) {
	float n;
	do {
		cout << '\t' << t << " (" << MIN << '-' << MAX << "): ";
		cin >> n;  cin.ignore();
	} while (n < MIN || n > MAX);
	return n;
}
//  Leser inn en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {
	do {
		cout << '\t' << t << ": ";	//  Skriver ledetekst.
		cin.getline(s, LEN);        //  Leser inn tekst.
	} while (strlen(s) == 0);     //  Sjekker at tekstlengden er ulik 0.
}