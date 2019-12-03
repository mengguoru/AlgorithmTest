#include "插入排序.h"

void printArr(vector<int> arr)
{
	for (auto i : arr)
		cout << i<<", ";
	cout << endl;
}

int main()
{
	vector<int> arr1 = { 92, 23, 42, 27, 14, 70, 29, 60, 32, 77, 34, 10, 73, 28, 53 };
	printArr(arr1);

	InsertionSort(arr1);
	printArr(arr1);

	return 0;
}