#include "binary_tree.h"

void main_menu()
{
	setlocale(0, "");
	system("pause");
	system("cls");
	cout << "1) Создать дерево на основе выражения\n2) Вычислить значение дерева выражения\n3) Вывести дерево выражения\n4) Вывод самого левого узла\n5) Завершить работу программы" << endl;
}

int main()
{
	setlocale(0, "");
	tree_elem* exp_tree = nullptr;

	int choice;
	bool is_not_executed = true;
	while (is_not_executed)
	{
		main_menu();
		cin >> choice;
		switch (choice)
		{

		case 1:
		{
			string str;
			cout << "Введите выражение: " << endl;
			cin.get();
			getline(cin, str);
			str = to_rpn(str);
			exp_tree = parse_rpn(str);
			cout << "Дерево успешно было создано\n";
		}
		break;
		case 2:
		{
			if (exp_tree == nullptr)
			{
				cout << "Пожалуйста, ведите сначала выражение" << endl;
				continue;
			}
			cout << find_result(exp_tree) << endl;
		}
		break;
		case 3:
		{
			if (exp_tree == nullptr)
			{
				cout << "Пожалуйста, ведите сначала выражение" << endl;
				continue;
			}
			print(exp_tree, 0);
		}
		break;
		case 4:
		{
			if (exp_tree == nullptr)
			{
				cout << "Пожалуйста, ведите сначала выражение" << endl;
				continue;
			}
			cout << find_left_elem(exp_tree) << endl;
		}
		break;
		case 5:
		{
			is_not_executed = false;
		}
		break;
		}
	}
	system("pause");
}