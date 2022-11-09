#include "BST.h"
bool node::exists(node * root, long long int a)
{
	if (root == nullptr)
	{
		return false;
	}
	if (root->key == a)
	{
		return true;
	}
	if (a < root->key)
	{
		return exists(root->left, a);
	}
	return exists(root->right, a);
}
int node::search(node * root, long long int a)
{
	if (root == nullptr)
	{
		return -1;
	}
	if (root->key == a)
	{
		return root->value;
	}
	if (a < root->key)
	{
		return search(root->left, a);
	}
	return search(root->right, a);
}

node * node::insert(node * root, long long int a, int b)
{
	if (exists(root, a))
	{
		return root;
	}
	if (root == nullptr)
	{
		return new node(a, b);
	}
	if (a < root->key)
	{
		root->left = insert(root->left, a, b);
	}
	if (a > root->key)
	{
		root->right = insert(root->right, a, b);
	}
	return root;
}
node * node::minValueNode(class node *node)
{
	class node *current = node;
	while (current && current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
node * node::deleteNode(node * root, long long int key)
{
	if (root == NULL)
	{
		return root;
	}
	if (key < root->key)
	{
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = deleteNode(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			class node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			class node *temp = root->left;
			free(root);
			return temp;
		}
		class node *temp = minValueNode(root->right);
		root->key = temp->key;
		root->value = temp->value;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
void node::printBT(const string& prefix, const node* node, bool isLeft, bool key)
{
	if (key)
	{
		if (node != nullptr)
		{
			std::cout << prefix;
			std::cout << (isLeft ? "|-----------" : "L-----------");
			std::cout << node->key << endl;
			printBT(prefix + (isLeft ? "|            " : "             "), node->right, true,1);
			printBT(prefix + (isLeft ? "|            " : "             "), node->left, false,1);
		}
	}
	else
	{
		if (node != nullptr)
		{
			std::cout << prefix;
			std::cout << (isLeft ? "|--" : "L--");
			std::cout << node->value << endl;
			printBT(prefix + (isLeft ? "|   " : "    "), node->right, true,0);
			printBT(prefix + (isLeft ? "|   " : "    "), node->left, false,0);
		}
	}
}

