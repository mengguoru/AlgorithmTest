#include "二叉查找树.h"

int main()
{
	BSTree<int> tree;
	int arr1[] = { 92, 23, 42, 27, 14, 70, 28, 60, 32, 77, 34, 10, 73, 28, 53 };
	int len = sizeof(arr1) / sizeof(arr1[0]);

	for (int i = 0; i < len; i++)
		tree.insert(arr1[i]);
	cout << "前序遍历" << endl;
	tree.preOrder();
	cout << endl;
	cout << "中序遍历" << endl;
	tree.inOrder();
	cout << endl;
	cout << "后序遍历" << endl;
	tree.postOrder();
	cout << endl;

	int targetValue = 70;
	cout << targetValue << "查找结果：";
	if (tree.search(70))
		cout << "成功";
	else
		cout << "失败";
	return 0;
}