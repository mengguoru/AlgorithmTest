#include <iostream>
#include <vector>
using namespace std;

void CountSort(int a[], int n, int exp)
{
	int* result = new int[n];
	int bucket[10] = { 0 };

	for (int i = 0; i < n; i++)
		bucket[(a[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		bucket[i] += bucket[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		result[bucket[(a[i] / exp) % 10] - 1] = a[i];
		bucket[(a[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = result[i];

	delete[] result;
}

void RadixSort(int a[], int n)
{
	//找到最大
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	for (int exp = 1; max / exp > 0; exp *= 10)
		CountSort(a, n, exp);

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
	RadixSort(arr1, len);
	printArr(arr1, len);

	return 0;
}