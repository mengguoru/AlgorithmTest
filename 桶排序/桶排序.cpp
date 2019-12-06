#include <iostream>
#include <vector>
using namespace std;

void BucketSort(int a[], int n)
{
	int** bucket = new int* [10];
	for (int i = 0; i < 10; i++)
		bucket[i] = new int[10];

	int count[10] = { 0 };

	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		int flag = (int)tmp / 10;
		bucket[flag][count[flag]] = tmp;
		int j = count[flag]++;

		//对桶执行插入排序
		for (; j > 0 && tmp < bucket[flag][j - 1]; j--)
			bucket[flag][j] = bucket[flag][j - 1];

		bucket[flag][j] = tmp;
	}

	//桶中的放回原数组
	for (int k = 0, i = 0; i < 10; i++)
	{
		for (int j = 0; j < count[i]; j++)
			a[k++] = bucket[i][j];
	}

	for (int i = 0; i < 10; i++)
		delete[] bucket[i];
	delete[] bucket;
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
	BucketSort(arr1, len);
	printArr(arr1, len);

	return 0;
}