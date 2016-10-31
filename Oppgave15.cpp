//Oppgave 18
//Program om ansattnummer, alder og vekt

#include <iostream>
using namespace std;

struct Ansatt
{
	int ansattNummer;
	int alder;
	int vekt;
};

int main() {
	Ansatt nr1, nr2, nr3, temp;
	int totalAge, eldst;
	float averageWeight;

	for (int i = 1; i <= 3; i++)
	{
		cout << "Skriv inn ansattnummer, alder og vekt for person " << i
			<< " separer med space: ";
		cin >> temp.ansattNummer >> temp.alder >> temp.vekt;
		switch (i)
		{
		case 1: nr1 = temp; break;
		case 2: nr2 = temp; break;
		case 3: nr3 = temp; break;
		}
	}
	totalAge = nr1.alder + nr2.alder + nr3.alder;
	averageWeight = (nr1.vekt + nr3.vekt + nr3.vekt) / 3.0F;
	if (nr1.alder > nr2.alder && nr1.alder > nr3.alder)
	{
		eldst = nr1.ansattNummer;
	}
	else if (nr2.alder > nr1.alder && nr2.alder > nr3.alder)
	{
		eldst = nr2.ansattNummer;
	}
	else eldst = nr3.ansattNummer;
	cout << "Total alder er: " << totalAge
		<< " gjennomsnlttlig vekt er: " << averageWeight
		<< " ansattnr: " << eldst << " er eldst\n";

	return 0;
}