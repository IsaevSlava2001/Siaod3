#pragma once
#include <string>
using namespace std;
extern double counter;
class nodesplay
{
public:
	long long int key;
	int value;
	nodesplay *left, *right;
	static void printsplayBT(const string& prefix, nodesplay* node, bool isLeft, bool key);
	static nodesplay* newNode(long long int key);
	static nodesplay *rightRotate(nodesplay *x);
	static nodesplay *leftRotate(nodesplay *x);
	static nodesplay *splay(nodesplay *root, long long int key);
	static nodesplay *searchsplay(nodesplay *root, long long int key);
	static void preOrder(nodesplay *root);
	static nodesplay *insertsplay(nodesplay *root, long long int key, int value, bool depth);
	static nodesplay *tree_max_key(nodesplay *root);
	static nodesplay *merge(nodesplay *tree1, nodesplay *tree2);
	static nodesplay *removesplay(nodesplay *root, long long int key);
};



