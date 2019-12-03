#include "快速排序.h"

void printArr(vector<int> arr)
{
	for (auto i : arr)
		cout << i<<", ";
	cout << endl;
}

int main()
{
	vector<int> arr1 = { 92, 23, 42, 27, 14, 70, 28, 60, 32, 77, 34, 10, 73, 28, 53 };
	printArr(arr1);

	QuickSort(arr1, 0, arr1.size() - 1);
	printArr(arr1);

	return 0;
}