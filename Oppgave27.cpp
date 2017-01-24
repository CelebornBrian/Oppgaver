//Oppgave 27
//Overloading of operators
#include <iostream>
using namespace std;

class Tid {
private:
	int time;
	int minutt;
	
public:
	Tid() { time = 0; minutt = 0; }
	Tid(int t, int m) { time = t; minutt = m; }
	void skrivTid();

	void operator += (const int rhs);
	void operator -= (const int rhs);
	Tid  operator + (const Tid & rhs)const;
	Tid operator - (const Tid & rhs)const;
	bool operator == (const Tid & rhs)const;
	bool operator < (const Tid & rhs)const;

};



int main() {
	Tid t1(15, 29), t2(15, 30), t3;
	t1.skrivTid(); t1 += 47; t1.skrivTid();

	t2.skrivTid(); t2 -= 16; t2.skrivTid();

	t3 = t1 + t2; t3.skrivTid();

	t3 = t1 - t2; t3.skrivTid();

	cout << ((t1 == t2) ? "Like" : "Ulike") << endl;

	cout << ((t1 < t2) ? "Mindre" : "Ikke Mindre") << endl;

	return 0;
}

// **********************   DEFINISJON AV KLASSEFUNKSJONER:    *********************


void Tid::operator += (const int rhs)
{
	int tot = time * 60 + minutt + rhs;
	time = tot / 60; minutt = tot % 60;
	/*minutt += rhs;
	while (minutt > 59)
	{
		time++;
		minutt -= 60;
	}*/
}

void Tid::operator -= (const int rhs) {
	minutt -= rhs;
	while (minutt < 0)
	{
		time--;
		minutt += 60;
	}
}

Tid Tid::operator + (const Tid & rhs) const {
	Tid temp;
	temp.minutt = minutt + rhs.minutt;
	while (temp.minutt > 59)
	{
		temp.time++;
		temp.minutt -= 60;
	}
	temp.time += time + rhs.time;
	return temp;
}

Tid Tid::operator - (const Tid & rhs) const {
	Tid temp;
	temp.minutt = (minutt - rhs.minutt);
	while (temp.minutt < 0)
	{
		temp.time--;
		temp.minutt += 60;
	}
	temp.time -= (time - rhs.time);
	return temp;
}

bool Tid::operator == (const Tid & rhs) const {
	return (time == rhs.time && minutt == rhs.minutt);
	/*if (minutt != rhs.minutt)
	{
		return false;
	}
	else if (time != rhs.time)
	{
		return false;
	}
	else return true;*/
}

bool Tid::operator < (const Tid & rhs) const {
	if (time < rhs.time)
	{
		return true;
	}
	else if (time == rhs.time && minutt < rhs.minutt)
	{
		return true;
	}
	else return false;
}

void Tid::skrivTid() {
	if (time > 0)
	{
		//cout << "Ugyldig Tid!" << endl; //Operatorer burde ikke skrive meldinger!
		time = minutt = 0;
	}
	cout << ((time < 10) ? "0" : "") << time << ":"
		<< ((minutt < 10) ? "0" : "") << minutt << endl;
}