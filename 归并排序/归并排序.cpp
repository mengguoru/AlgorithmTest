#include "归并排序.h"

void Merge(int a[], int left, int mid, int right)
{
	int length1 = mid - left + 1;
	int length2 = right - mid;
	int* l1 = new int[length1];
	int* l2 = new int[length2];
	int i, j;

	for (i = 0; i < length1; i++)
		l1[i] = a[left + i];
	for (i = 0; i < length2; i++)
		l2[i] = a[mid + 1 + i];

	i = j = 0;
	while (i < length1 && j < length2)
	{
		if (l1[i] < l2[j])
			a[left++] = l1[i++];
		else
			a[left++] = l2[j++];
	}

	while (i < length1)
		a[left++] = l1[i++];
	while (j < length2)
		a[left++] = l2[j++];
	delete[]l1;
	delete[]l2;
}

void MergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}