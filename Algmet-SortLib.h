#ifndef SORTLIB_H
#define SORTLIB_H

typedef char itemType;

void swap(itemType a[], int i, int j);		//swap i with j in a
void print(itemType a[], int N);			//print array to screen
bool validate(itemType a[], int length);	//return true if array is sorted

void selectionSort(itemType a[], int N);	//sort by selection
void insertionSort(itemType a[], int N);	//sort by insertion
void bubbleSort(itemType a[], int N);		//sort by trash

#endif // !SORTLIB_H