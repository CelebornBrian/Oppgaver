#include "Algmet-SortLib.h"

using namespace std;

void bubbleSort(itemType a[], int N) {
	int i, j;
	for (i = N; i >= 1; i--)			//Loop through the array from end to start
	{									//and for each
		for (j = 2; j <= i; j++)		//Loop from 2nd to i
		{
			if (a[j-1] > a[j])			//If the previous itemType is bigger than
			{							//current itemType
				swap(a, j - 1, j);		//Swap them
			}
		}
	}
}