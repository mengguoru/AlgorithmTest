#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void Heapify(int tree[], int n, int parent)
{
	//其实不写也会退出递归
	/*if (parent >= n)
		return;*/

	int leftChild = 2 * parent + 1;
	int rightChild = 2 * parent + 2;
	int maxIndex = parent;

	if (leftChild < n && tree[leftChild] > tree[maxIndex])
		maxIndex = leftChild;
	if (rightChild < n && tree[rightChild] > tree[maxIndex])
		maxIndex = rightChild;

	if (maxIndex != parent)
	{
		swap(tree, parent, maxIndex);
		Heapify(tree, n, maxIndex);
	}
}

void BuildHeap(int tree[], int n)
{
	int last = n - 1;
	int lastParent = (last - 1) / 2;
	for (int i = lastParent; i >= 0; i--)
		Heapify(tree, n, i);
}

void HeapSort(int arr[], int n)
{
	BuildHeap(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr, i, 0);
		Heapify(arr, i, 0);
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
	HeapSort(arr1, len);
	printArr(arr1, len);

	return 0;
}