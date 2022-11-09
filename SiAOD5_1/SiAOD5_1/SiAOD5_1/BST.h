#pragma once
#include <iostream>
#include <string>
using namespace std;
class node
{
public:
	int value;
	long long int key;
	node *left, *right;
	node(long long int a, int b)
	{
		key = a;
		value = b;
		left = nullptr;
		right = nullptr;
	}
	static bool exists(node * root, long long int a);
	static int search(node * root, long long int a);
	static node * insert(node * root, long long int a, int b);
	static class node *minValueNode(class node *node);
	static class node *deleteNode(class node *root, long long int key);
	static void printBT(const string& prefix, const node* node, bool isLeft, bool key);
};