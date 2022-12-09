#pragma once
#include <iostream>
using namespace std;

struct Node
{
	char symbol;
	double frequency;
	string arr = "";
	Node* left;
	Node* right;
	Node(char s, double f, Node* l = nullptr, Node* r = nullptr) : symbol(s), frequency(f), left(l), right(r) {};
};

struct NodeQueue
{
	Node* value;
	NodeQueue* next;
	NodeQueue(Node* newValue) : value(newValue), next(nullptr) {};
};

class MyQueue
{
private:
	NodeQueue* head = nullptr;
public:
	void push(Node*);
	Node* pop();
	bool checkSize();
};