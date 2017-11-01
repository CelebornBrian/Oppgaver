#include <iostream>
#include "Algmet-SortLib.h"

using namespace std;

// swap i with j in array a
void swap(itemType a[], int i, int j) {
	itemType t = a[i];
	a[i] = a[j];
	a[j] = t;
}

// print array to screen
void print(itemType a[], int N) {
	for (int i = 1; i <= N; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// validate that a is sorted in ascending order
bool validate(itemType a[], int length) {
	for (int i = 1; i <= length; ++i) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}