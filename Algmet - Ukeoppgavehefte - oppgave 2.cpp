#include <iostream>
using namespace std;

const int NUMBER = 15;

int factorial(int N)
{
	int product = 1;
	for (int j = 1; j <= N; j++)
	{
		product *= j;
	}
	return product;
}

int main() {
	int i = factorial(NUMBER);
	cout << i;
	return 0;
}