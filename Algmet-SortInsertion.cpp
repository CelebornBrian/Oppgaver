#include <iostream>
#include "Algmet-SortLib.h"

using namespace std;

void insertionSort(itemType a[], int N) {
	int i, j;
	itemType v;
	for (i = 2; i <= N; i++)	//Loop trough array, start at 2nd index
	{
		v = a[i];				//save current index
		j = i;					//start next loop from current location
		while (a[j-1] > v)		//As long as the value in the index before the 
		{						//current is less than this value
			a[j] = a[j - 1];	//Jump values forward
			j--;				//Count down towards the start of the array
		}
		a[j] = v;				//Insert the value at it's correct 
	}
}