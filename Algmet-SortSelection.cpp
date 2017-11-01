#include "Algmet-SortLib.h"

using namespace std;

void selectionSort(itemType a[], int N) {
	int i, j, min;
	for (i = 1; i < N; i++)		//Loop through the array
	{
		min = i;				//Assume i is the lowest value in the array
		for (j = i+1; j <= N; j++)	//Loop through the rest
		{
			if (a[j] < a[min])		//If the value in this index is smaller than
			{						//the assumed one
				min = j;			//make this the new minimum
			}
		}
		swap(a, min, i);		//Swap the minimum with the contents of the index
	}							//i so that the lowest value is allways placed 
}								//towards the start.