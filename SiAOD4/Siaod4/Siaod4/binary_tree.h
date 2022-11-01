#ifndef BINARY_FILES_H
#define BINARY_FILES_H
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <sstream>
using namespace std;

struct tree_elem
{
    char s;
    tree_elem* left;
    tree_elem* right;
};

string to_rpn(string expression);

tree_elem* create_tree_element(char s);

void insert_tree_elem(tree_elem* root, tree_elem* elem);

char find_left_elem(tree_elem* root); 

tree_elem* parse_rpn(string rpn_expression);

double find_result(tree_elem* root);

void print(tree_elem* tree, int l);

#endif 