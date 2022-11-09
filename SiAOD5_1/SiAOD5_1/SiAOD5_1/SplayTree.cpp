#include "SplayTree.h"
#include "BST.h"
double counter = 0;
nodesplay* nodesplay::newNode(long long int key)
{
	nodesplay* Node = new nodesplay();
	Node->key = key;
	Node->left = Node->right = NULL;
	return (Node);
}

nodesplay *nodesplay::rightRotate(nodesplay *x)
{
	nodesplay *y = x->left;
	x->left = y->right;
	y->right = x;
	counter++;
	return y;
}

nodesplay *nodesplay::leftRotate(nodesplay *x)
{
	nodesplay *y = x->right;
	x->right = y->left;
	y->left = x;
	counter++;
	return y;
}

nodesplay *nodesplay::splay(nodesplay *root, long long int key)
{
	if (root == NULL || root->key == key)
		return root;

	if (root->key > key)
	{
		if (root->left == NULL)
		{
			return root;
		}

		// Zig-Zig (Левый-левый) 
		if (root->left->key > key)
		{
			// Сначала рекурсивно поднимаем
			// ключ как корень left-left
			root->left->left = splay(root->left->left, key);

			// Первый разворот для root, 
			// второй разворот выполняется после else
			root = rightRotate(root);
		}
		else if (root->left->key < key) // Zig-Zag (Левый-правый) 
		{
			// Сначала рекурсивно поднимаем
			// ключ как корень left-right
			root->left->right = splay(root->left->right, key);

			// Выполняем первый разворот для root->left
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}

		// Выполняем второй разворот для корня
		return (root->left == NULL) ? root : rightRotate(root);
	}
	else // Ключ находится в правом поддереве
	{
		// Ключа нет в дереве, мы закончили
		if (root->right == NULL)
		{
			return root;
		}

		// Zag-Zig (Правый-левый) 
		if (root->right->key > key)
		{
			// Поднять ключ как корень right-left 
			root->right->left = splay(root->right->left, key);

			// Выполняем первый поворот для root->right
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->key < key)// Zag-Zag (Правый-правый) 
		{
			// Поднимаем ключ как корень 
			// right-right и выполняем первый разворот
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}

		// Выполняем второй разворот для root
		return (root->right == NULL) ? root : leftRotate(root);
	}
}

nodesplay *nodesplay::searchsplay(nodesplay *root, long long int key)
{
	return splay(root, key);
}

void nodesplay::preOrder(nodesplay *root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
nodesplay *nodesplay::insertsplay(nodesplay *root, long long int key, int value, bool depth)
{
	if (root == nullptr)
	{
		root = newNode(key);
		root->value = value;
	}
	else if (key < root->key)
	{
		if (root->left == nullptr)
		{
			root->left = newNode(key);
			root->left->value = value;
			if (!depth)
			{
				root = splay(root, key);
			}
		}
		else
		{
			root->left = insertsplay(root->left, key, value, 1);
			root = splay(root, key);
		}
	}
	else
	{
		if (root->right == nullptr)
		{
			root->right = newNode(key);
			root->right->value = value;
			if (!depth)
			{
				root = splay(root, key);
			}
		}
		else
		{
			root->right = insertsplay(root->right, key, value, 1);
			root = splay(root, key);
		}
	}
	return root;
}

nodesplay *nodesplay::tree_max_key(nodesplay *root)
{
	nodesplay *curr = root;
	while (curr->right != nullptr)
	{
		curr = curr->right;
	}
	return curr;
}

nodesplay *nodesplay::merge(nodesplay *tree1, nodesplay *tree2)
{
	tree1 = splay(tree1, tree_max_key(tree1)->key);
	tree1->right = tree2;
	return tree1;
}

nodesplay *nodesplay::removesplay(nodesplay *root, long long int key)
{
	root = splay(root, key);
	class nodesplay *tree1 = NULL;
	class nodesplay *tree2 = NULL;
	tree1 = root->left;
	tree2 = root->right;
	root = merge(tree1, tree2);
	return root;
}


void nodesplay::printsplayBT(const string& prefix, nodesplay* node, bool isLeft, bool key)
{
	if (key)
	{
		if (node != nullptr)
		{
			std::cout << prefix;
			std::cout << (isLeft ? "|-----------" : "L-----------");
			std::cout << node->key << endl;
			printsplayBT(prefix + (isLeft ? "|            " : "             "), node->right, true, 1);
			printsplayBT(prefix + (isLeft ? "|            " : "             "), node->left, false, 1);
		}
	}
	else
	{
		if (node != nullptr)
		{
			std::cout << prefix;
			std::cout << (isLeft ? "|--" : "L--");
			std::cout << node->value << endl;
			printsplayBT(prefix + (isLeft ? "|   " : "    "), node->right, true, 0);
			printsplayBT(prefix + (isLeft ? "|   " : "    "), node->left, false, 0);
		}
	}
}