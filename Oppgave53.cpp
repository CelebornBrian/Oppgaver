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
#include <fstream>
using namespace std;

//  CONST:
const int STRLEN = 200;

//  ENUM:


//  STRUCT


//  KLASSE:

class LavesteTemp{
private:
	char lavestDato[11];
	float kaldest;
public:
	LavesteTemp() { kaldest = 40; }
	void lesFraFil(ifstream & innfil);
	void skrivLavest();
};

//  DEKLARASJON AV FUNKSJONER:
void lesFraFil();

//  GLOBALE VARIABLE:
LavesteTemp tmp;

//  HOVEDPROGRAM:

int main() {
	lesFraFil();
	tmp.skrivLavest();
	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:
void LavesteTemp::lesFraFil(ifstream & innfil) {
	char dato[11], buffer[STRLEN];
	float temp, minste;
	innfil >> dato;
	//cout << dato; // [3] << dato[4];
	if (dato[3] == '1' && dato[4] == '2')
	{
		innfil >> temp >> minste;
		//cout << temp << "  " << minste << endl;
		if (minste < kaldest)
		{
			//cout << dato << "\n\t" << minste << endl;
			kaldest = minste;
			for (int i = 0; i <= 11; i++)
			{
				lavestDato[i] = dato[i];
			}
		}
	}
	innfil.getline(buffer, STRLEN);
}

void LavesteTemp::skrivLavest()
{
	cout << "Laveste tempratur er paa datoen: " << lavestDato
		<< " med tempraturen " << kaldest << "C\n";
}


//  DEFINISJON AV FUNKSJONER:

void lesFraFil()
{
	char buffer[STRLEN];
	int t1;
	ifstream innfil("DATBLINDERN.DAT");
	if (innfil)
	{
		for (int i = 0; i < 24; i++)
		{
			innfil.getline(buffer, STRLEN);
		}
		innfil >> t1;
		while (t1 == 18700)
		{
			tmp.lesFraFil(innfil);
			innfil >> t1;
		}
	}
}
