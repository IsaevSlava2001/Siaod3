#include "binary_tree.h"

tree_elem* create_tree_element(char s)
{
    tree_elem* elem = new tree_elem;
    elem->s = s;
	elem->left = nullptr;
    elem->right = nullptr;
    return elem;
}

void insert_tree_elem(tree_elem* root, tree_elem* elem)
{
    if (root->s > elem->s)
	{
        if (root->left == nullptr)
		{
            root->left = elem;
        }
        else
		{
            insert_tree_elem(root->left, elem);
        }
    }
    else if (root->s < elem->s)
	{
        if (root->right == nullptr)
		{
            root->right = elem;
        }
        else
		{
            insert_tree_elem(root->right, elem);
        }
    }
}

string to_rpn(string str) 
{
	map<string, int> priority = { {"(", 1}, {")", 1}, {"+", 2}, {"-", 2}, {"*", 3}, {"/", 3} };
	string word;
	stack<string> cur_values;
	string pn = "";
	istringstream ss(str);
	while (ss >> word)
	{
		bool is_keyword = false;
		for (auto& tmp : priority) 
		{
			if (tmp.first == word)
				is_keyword = true;
		}
		if (!is_keyword)
		{
			pn += " " + word;
		}
		else 
		{
			if (word == "(")
				cur_values.push(word);
			else if (word == ")") 
			{
				while (!cur_values.empty() && cur_values.top() != "(")
				{
					pn += " " + cur_values.top();
					cur_values.pop();
				}
				cur_values.pop();
			}
			else
			{
				while (!cur_values.empty() && priority[cur_values.top()] >= priority[word])
				{
					pn += " " + cur_values.top();
					cur_values.pop();
				}
				cur_values.push(word);
			}
		}
	}
	while (!cur_values.empty())
	{
		pn += " " + cur_values.top();
		cur_values.pop();
	}
	return pn;
}

char find_left_elem(tree_elem* root)
{
    if (root->left == nullptr)
	{
		return root->s;
    }
	return find_left_elem(root->left);
}


tree_elem* parse_rpn(string rpn_expression)
{
    stack<tree_elem*> tree_stack;
	tree_elem* te;
    for (int i = 0; i < rpn_expression.size(); i++)
	{
		if (isdigit(rpn_expression[i]))
		{
			te = create_tree_element(rpn_expression[i]);
			tree_stack.push(te);
		}
		else if (rpn_expression[i] == '*' || rpn_expression[i] == '-' ||rpn_expression[i] == '+' || rpn_expression[i] == '/')
		{
			te = create_tree_element(rpn_expression[i]);
			te->right = tree_stack.top();
			tree_stack.pop();
			te->left = tree_stack.top();
			tree_stack.pop();
			tree_stack.push(te);
		}
    }
	return tree_stack.top();
}


double find_result(tree_elem* root)
{
	if (isdigit(root->s))
	{
		return double(int(root->s) - 48);
	}
	if (root->s == '+')
	{
		return double(find_result(root->left)) + double(find_result(root->right));
	}
	else if (root->s == '-')
	{
		return double(find_result(root->left)) - double(find_result(root->right));
	}
	else if (root->s == '*')
	{
		return double(find_result(root->left)) * double(find_result(root->right));
	}
	else if (root->s == '/')
	{
		return double(find_result(root->left)) / double(find_result(root->right));
	}
	return 0.0;
}

void print(tree_elem* Tree, int l)
{
    int i;
    if (Tree != nullptr)
	{
        print(Tree->right, l + 1);
		for (i = 1; i <= l; i++)
		{
			cout << "   ";
		}
        cout << Tree->s << endl;
        print(Tree->left, l + 1);
    }
}