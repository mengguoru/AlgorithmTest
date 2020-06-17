#include <iostream>
#include <vector>
using namespace std;

int SequenceSearch(int a[], int n, int value)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == value)
			return i;
	}
	return -1;
}

//打印数组
void printArr(int a[], int len)
{
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int arr1[] = { 92, 23, 42, 27, 14, 70, 28, 60, 32, 77, 34, 10, 73, 28, 53 };
	int len = sizeof(arr1) / sizeof(arr1[0]);

	printArr(arr1, len);
	int targetValue = 70;
	cout << targetValue << "在数组中的位置：" << SequenceSearch(arr1, len, 70) << endl;

	return 0;
}