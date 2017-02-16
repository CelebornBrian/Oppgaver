//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
// Arv
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <iostream>
using namespace std;

//  CONST:
const int STRLEN = 60;						//Text length

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

class Book : public Publication {
private:
	int pageCount;							//Number of pages
protected:
public:
	void getData();
	void putData();
};

class Tape : public Publication {
private:
	float playingTime;						//Playing time
protected:
public:
	void getData();
	void putData();
};


//  DEKLARASJON AV FUNKSJONER:
//char les(char* t);
float les(const char t[], const int MIN, const int MAX);
void les(const char t[], char s[], const int STRLEN);

//  GLOBALE VARIABLE:


//  HOVEDPROGRAM:

int main() {
	Book bok;
	Tape kasett;
	bok.getData();
	bok.putData();
	kasett.getData();
	kasett.putData();
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

//---------------------------------------------------

void Book::getData() {
	Publication::getData();
	pageCount = int(les("Skriv inn antall sider: ", 20, 5000));
}

void Book::putData()
{
	Publication::putData();
	cout << "Antall sider: " << pageCount << endl;
}

//----------------------------------------------------

void Tape::getData() {
	Publication::getData();
	playingTime = les("Skriv inn spilletid(MIN): ", 60, 50000);
}

void Tape::putData()
{
	Publication::putData();
	cout << "Spilletid: " << playingTime << endl;
}

//  DEFINISJON AV FUNKSJONER:
/*
char les(char* t) {         //  Leser og upcaser ett tegn:
	char ch;
	cout << "\n\n" << t << ": ";
	cin >> ch;   cin.ignore();
	return (toupper(ch));
}*/

//  Leser et tall mellom MIN og MAX:
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