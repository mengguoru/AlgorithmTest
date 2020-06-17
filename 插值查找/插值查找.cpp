#include <iostream>
#include <vector>
using namespace std;

int InsertionSearch(int a[], int n, int value)
{
	for (int low = 0, high = n - 1, target; low < high;)
	{
		target = low + (value - a[low]) / (a[high] - a[low]) * (high - low);
		if (value == a[target])
			return target;
		else if (value < a[target])
			high = target - 1;
		else
			low = target + 1;
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
	cout << targetValue << "在数组中的位置：" << InsertionSearch(arr1, len, 70) << endl;

	return 0;
}