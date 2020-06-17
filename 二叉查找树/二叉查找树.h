#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_
#include <iostream>
using namespace std;

template <class T>
class BSTNode
{
public:
	T key;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;

	BSTNode(T value, BSTNode*p,BSTNode* l, BSTNode* r):key(value),parent(p),left(l),right(r){}
};

template <class T>
class BSTree
{
private:
	BSTNode<T>* root;

public:
	BSTree();
	~BSTree();

	void destroy();

	//前序遍历
	void preOrder();
	//中序遍历
	void inOrder();
	//后序遍历
	void postOrder();

	BSTNode<T>* search(T key);

	//树中最小值
	T minimum();
	//树中最大值
	T maximum();

	//x的前驱结点
	BSTNode<T>* predecessor(BSTNode<T>* x);
	//x的后驱结点
	BSTNode<T>* sucessor(BSTNode<T>* x);

	void insert(T key);
	void remove(T key);
private:
	void destroy(BSTNode<T>*& tree);

	void preOrder(BSTNode<T>* tree) const;
	void inOrder(BSTNode<T>* tree) const;
	void postOrder(BSTNode<T>* tree) const;

	BSTNode<T>* search(BSTNode<T>* tree, T key) const;

	BSTNode<T>* minimum(BSTNode<T>* tree) const;
	BSTNode<T>* maximum(BSTNode<T>* tree) const;

	void insert(BSTNode<T>* &tree, BSTNode<T>* x);
	void remove(BSTNode<T>*& tree, BSTNode<T>* x);
};

template <class T>
BSTree<T>::BSTree():root(NULL){}

template <class T>
BSTree<T>::~BSTree()
{
	destroy();
}

template<class T>
void BSTree<T>::destroy()
{
	destroy(root);
}


template<class T>
void BSTree<T>::destroy(BSTNode<T>*& tree)
{
	if (NULL == tree)
		return;
	if (NULL != tree->left)
		destroy(tree->left);
	if (NULL != tree->right)
		destroy(tree->right);

	delete tree;
	tree = NULL;
}

template<class T>
void BSTree<T>::preOrder()
{
	preOrder(root);
}

template<class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const
{
	if (NULL != tree)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

//中序遍历
template<class T>
void BSTree<T>::inOrder()
{
	inOrder(root);
}

template<class T>
void BSTree<T>::inOrder(BSTNode<T>* tree) const
{
	if (NULL != tree)
	{
		inOrder(tree->left);
		cout << tree->key << " ";
		inOrder(tree->right);
	}
}

//后序遍历
template<class T>
void BSTree<T>::postOrder()
{
	postOrder(root);
}

template<class T>
void BSTree<T>::postOrder(BSTNode<T>* tree) const
{
	if (NULL != tree)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";
	}
}

//查找
template<class T>
BSTNode<T>* BSTree<T>::search(T key)
{
	return search(root, key);
}

template<class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* tree, T key) const
{
	BSTNode<T>* tmp = tree;

	while (NULL != tmp)
	{
		if (tmp->key == key)
			return tmp;
		else if (tmp->key < key)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return NULL;
}

//树中最小值
template<class T>
T BSTree<T>::minimum()
{
	BSTNode<T>* tmp = minimum(root);
	if (NULL != tmp)
		return tmp->key;
	return (T)NULL;
}

template<class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree) const
{
	BSTNode<T>* tmp = tree;

	while (NULL != tmp->left)
		tmp = tmp->left;
	//如果tree为空，那返回也是个空值
	return tmp;
}

//最大值
template<class T>
T BSTree<T>::maximum()
{

}

template<class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree) const
{
	BSTNode<T>* tmp = tree;
	while (NULL != tmp->right)
		tmp = tmp->right;
	return tmp;
}

//x的前驱结点
template<class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T>* x)
{
	//有左子树，则前驱结点为其中最大值
	if (NULL != x->left)
		return maximum(x->left);
	//无左子树，判断它和父节点关系
	//它是父节点的右孩子，父节点即前驱结点；
	//它是父节点的左孩子，得向上找父节点，直到找到一个父节点有右孩子，则这一个父节点为前驱结点
	BSTNode<T>* parent = x->parent;
	while (NULL != parent && x != parent->right)
	{
		x = parent;
		parent = x->parent;
	}
	return parent;
}

//x的后驱结点
template<class T>
BSTNode<T>* BSTree<T>::sucessor(BSTNode<T>* x)
{
	//有右子树，则后继节点为其中最小值
	if (NULL != x->right)
		return minimum(x->right);
	//无右子树，判断它和父节点关系
	//它是父节点的左孩子，父节点即后驱节点；
	//它是父节点的右孩子，得向上找父节点，直到找到一个父节点有左孩子，则这一个父节点为后驱节点
	BSTNode<T>* parent = x->parent;
	while (NULL != parent && x != parent->left)
	{
		x = parent;
		parent = x->parent;
	}
	return parent;
}

template<class T>
void BSTree<T>::insert(T key)
{
	BSTNode<T>* tmp = new BSTNode<T>(key, NULL, NULL, NULL);
	if (NULL == tmp)
		return;
	insert(root, tmp);
}

template<class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T>* x)
{
	BSTNode<T>* parent = NULL;
	BSTNode<T>* tmp = tree;

	while (NULL != tmp)
	{
		parent = tmp;
		if (x->key > tmp->key)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	x->parent = parent;
	if (NULL == parent)
		tree = x;
	else if (x->key > parent->key)
		parent->right = x;
	else
		parent->left = x;
}

//删除
template<class T>
void BSTree<T>::remove(BSTNode<T>*& tree, BSTNode<T>* x)
{
	BSTNode<T>* current = x;
	BSTNode<T>* parent = current->parent;

	//只有右孩子
	if (NULL == current->left)
	{
		if (current == tree)
			tree = current->right;
		else if (current == parent->left)
			parent->left = current->right;
		else
			parent->right = current->right;
		delete current;
	}
	else if (NULL == current->right)//只有左孩子
	{
		if (current == tree)
			tree = current->left;
		else if (current == parent->left)
			parent->left = current->left;
		else
			parent->right = current->left;
		delete current;
	}
	else
	{
		//找到右子树最左的节点（即删除节点的后驱节点）
		BSTNode<T>* sucessor = current->right;
		parent = current;
		while (sucessor->left)
		{
			parent = sucessor;
			sucessor = sucessor->left;
		}
		//交换值
		current->key = sucessor->key;
		if (parent->left = sucessor)
			parent->left = sucessor->right;
		else
			parent->right = sucessor->right;
		delete sucessor;
	}
}

template<class T>
void BSTree<T>::remove(T key)
{
	BSTree<T>* tmp;
	if (tmp = search(key))
		remove(root, tmp);
}
#endif