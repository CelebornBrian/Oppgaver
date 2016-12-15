#include <iostream>
#include <fstream>
using namespace std;

class Grid {
private:
	int x, y;
	char face;
public:
	Grid() { x = 0; y = 0; face = 'N'; }
	void directionChange(char d);
	void posisionChange(int n);
	void skrivAlt();
	//void lesFraFil(ifstream & inn, ch);
};

void lesFraFil();

Grid Bunny;

int main() {
	lesFraFil();
	Bunny.skrivAlt();
	return 0;
}

void Grid::directionChange(char d) {
	if (face == 'N' && d == 'R')
	{
		face = 'E';
	}
	else if (face == 'N' && d == 'L')
	{
		face = 'W';
	}
	else if (face == 'E' && d == 'R')
	{
		face = 'S';
	}
	else if (face == 'E' && d == 'L')
	{
		face = 'N';
	}
	else if (face == 'S' && d == 'R')
	{
		face = 'W';
	}
	else if (face == 'S' && d == 'L')
	{
		face = 'E';
	}
	else if (face == 'W' && d == 'R')
	{
		face = 'N';
	}
	else if (face == 'W' && d == 'L')
	{
		face = 'S';
	}
	else
	{
		cout << "Direction Error";
	}
}

void Grid::posisionChange(int n) {
	switch (face)
	{
	case 'N': y += n; break;
	case 'E': x += n; break;
	case 'S': y -= n; break;
	case 'W': x -= n; break;
	default: cout << "Posision Error";
		break;
	}
}

void Grid::skrivAlt() {
	cout << "X: " << x << '\n' << "Y: " << y << '\n';
	cout << "Antall blocks away: " << x + y << endl;
}

//void Grid::lesFraFil(ifstream & inn, ch) {


void lesFraFil() {
	ifstream innfil("AdventOfCode_1.txt");
	char ch;
	int i;
	if (innfil)
	{
		
		while (innfil >> ch >> i)
		{
			Bunny.directionChange(ch);
			Bunny.posisionChange(i);
			//cout << ch << " " << i << endl;
		}
	}
	else
	{
		cout << "Fil ikke funnet!" << endl;
	}
}