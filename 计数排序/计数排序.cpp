#include <iostream>
#include <vector>
using namespace std;

void CountSort(int a[], int n, int maxVal)
{
	vector<int> count(maxVal + 1, 0);
	int i, j;

	for (i = 0; i < n; i++)
		count[a[i]]++;
	for (i = 0, j = 0; i < maxVal + 1; i++)
	{
		while (count[i]-- > 0)
			a[j++] = i;
	}
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
	CountSort(arr1, len, 100);
	printArr(arr1, len);

	return 0;
}