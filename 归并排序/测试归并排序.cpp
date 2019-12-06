#include "归并排序.h"

void printArr(int a[], int len)
{
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int arr1[] = { 92, 23, 42, 27, 14, 70, 28, 60, 32, 77, 34, 10, 73, 28, 53 };
	int len = sizeof(arr1)/sizeof(arr1[0]);

	printArr(arr1, len);
	MergeSort(arr1, 0, len - 1);
	printArr(arr1, len);

	return 0;
}