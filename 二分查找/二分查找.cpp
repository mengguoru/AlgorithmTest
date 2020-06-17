#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(int a[], int n, int value)
{
	for (int low = 0, high = n - 1, mid; low < high;)
	{
		mid = (low + high) / 2;
		if (value == a[mid])
			return mid;
		else if (value < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
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
	int arr1[] = { 10, 14, 23, 27, 28, 29, 32, 34, 42, 53, 60, 70, 73, 77, 92 };
	int len = sizeof(arr1) / sizeof(arr1[0]);

	printArr(arr1, len);
	int targetValue = 70;
	cout << targetValue << "在数组中的位置：" << BinarySearch(arr1, len, 70) << endl;

	return 0;
}