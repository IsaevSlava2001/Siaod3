#include"BST.h"
#include "BinFile.h"
#include "SplayTree.h"

using namespace std;
extern double counter;

int main()
{
	setlocale(LC_ALL, "rus");
	class node *root = NULL;
	class node *temp_node = NULL;
	string txt_file, bin_file;
	long long int key;
	Book temp;
	int adress;
	long long int *ISBN = new long long int[10000];
	int i = 0;
	while (true)
	{
		system("cls");
		cout << "Введите номер задания:\n1-Создание файла\n2-Поиск с помощью линейного поиска\n3-вывод записи по ее адресу\n4-Добавление записи в файл\n5-Построение бинарного дерева по файлу\n6-Добавление элемента в дерево\n7-Поиск по ключу в дереве\n8-Удаление элемента из дерева\n9-Вывод дерева\n10-Построение косого дерева по файлу\n11-Добавление элемента в дерево\n12-Поиск по ключу в дереве\n13-Удаление элемента из дерева\n14-Вывод дерева\nЛюбой другой номер закроет программу" << endl;
		int k = 0;
		cin >> k;
		if (k == 1)
		{
			system("cls");
			cout << "Создание файла" << endl;
			cout << "Введите имя текстового файла" << endl;
			cin >> txt_file;
			cout << "Введите имя бинарного файла" << endl;
			cin >> bin_file;
			if (BinFile::txt_to_bin(txt_file, bin_file) == 1)
			{
				cout << "Успешно создано" << endl;
			}
			else
			{
				cout << "Файл не существует" << endl;
			}
			system("pause");
		}
		if (k == 2)
		{
			system("cls");
			cout << "Поиск с помощью линейного поиска" << endl;
			cout << "Введите имя бинарного файла" << endl;
			cin >> bin_file;
			cout << "Введите ключ (12 цифр)" << endl;
			cin >> key;
			temp=BinFile::linear_search(bin_file, key);
			if (temp.ISBN != 0)
			{
				cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
			}
			else
			{
				cout <<"Запись с таким ключом не найдена" << endl;;
			}
			system("pause");
		}
		if (k == 3)
		{
			system("cls");
			cout << "вывод записи по ее адресу" << endl;
			cout << "Введите имя бинарного файла" << endl;
			cin >> bin_file;
			cout << "Введите позицию" << endl;
			cin >> adress;
			temp=BinFile::get_class(bin_file, adress);
			if (temp.ISBN != 0)
			{
				cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
			}
			else
			{
				cout << "Запись с таким ключом не найдена" << endl;;
			}
			system("pause");
		}
		if (k == 4)
		{
			system("cls");
			cout << "Добавление записи в файл" << endl; 
			cout << "Введите имя бинарного файла" << endl;
			cin >> bin_file;
			ofstream outp;
			outp.open(bin_file, ios::binary);
			cout << "Введите ISBN(12 цифр) ";
			cin >> temp.ISBN;
			cout << "Введите фамилию автора(английский язык) ";
			cin >> temp.fam;
			cout << "Введите название книги(английский язык) ";
			cin >> temp.name;
			if (outp.good())
			{
				BinFile::AddToBin(outp, temp);
			}
			else
			{
				cout << "Такого файла не существует" << endl;
			}
			outp.close();
			system("pause");
		}
		if (k == 5)
		{
			system("cls");
			cout << "Построение бинарного дерева по файлу" << endl;
			cout << "Введите имя бинарного файла" << endl;
			cin >> bin_file;
			ifstream inp;
			inp.open(bin_file, ios::binary);
			if (inp.good())
			{
				inp.close();
				ISBN = BinFile::getISBN(bin_file);
				while (ISBN[i] != 0)
				{
					root = node::insert(root, ISBN[i], i);
					i++;
				}
				cout << "Успешно" << endl;
			}
			else
			{
				cout << "Файл не существует" << endl;
			}
			system("pause");
		}
		if (k == 6)
		{
			system("cls");
			cout << "Добавление элемента в дерево" << endl;
			cout << "Введите имя бинарного файла" << endl;
			cin >> bin_file;
			ofstream outp;
			outp.open(bin_file, ios::binary);
			cout << "Введите ISBN(12 цифр) ";
			cin >> temp.ISBN;
			cout << "Введите фамилию автора(английский язык) ";
			cin >> temp.fam;
			cout << "Введите название книги(английский язык) ";
			cin >> temp.name;
			if (outp.good())
			{
				BinFile::AddToBin(outp, temp);
				root = node::insert(root, temp.ISBN, i);
				i++;
			}
			else
			{
				cout << "Такого файла не существует" << endl;
			}
			outp.close();
			system("pause");
		}
		if (k == 7)
		{
			system("cls");
			cout << "Поиск по ключу в дереве" << endl;
			cout << "Введите имя бинарного файла" << endl;
			cin >> bin_file;
			ofstream outp;
			outp.open(bin_file, ios::binary);
			if (outp.good())
			{
				cout << "Введите ключ(12 цифр) ";
				cin >> key;
				adress = node::search(root, key);
				temp=BinFile::get_class(bin_file, adress);
				if (temp.ISBN != 0)
				{
					cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
				}
				else
				{
					cout << "Запись с таким ключом не найдена" << endl;
				}
			}
			else
			{
				cout << "такого файла не существует" << endl;
			}
			outp.close();
			system("pause");
		}
		if (k == 8)
		{
			system("cls");
			cout << "Удаление элемента из дерева" << endl;
			cout << "Введите ключ" << endl;
			cin >> key;
			if (node::search(root, key) != -1)
			{
				root = node::deleteNode(root, key);
				cout << "Успешно удалено" << endl;
			}
			else
			{
				cout << "Запись с таким ключом не найдена" << endl;
			}
			system("pause");
		}
		if (k == 9)
		{
			system("cls");
			cout << "Вывод дерева" << endl;
			cout << "Вывод ключей дерева" << endl;
			node::printBT("", root, false, 1);
			cout << "Вывод значений дерева" << endl;
			node::printBT("", root, false, 0);
			system("pause");
		}
		if (k < 1 || k>14)
		{
			cout << "Вы уверены, что хотите выйти? Y/N" << endl;
			char j;
			cin >> j;
			if (j == 'Y')
			{
				cout << "Выход... ";
				system("pause");
				exit(0);
			}
		}
	}
	/*class nodesplay *root = NULL;
	long long int *ISBN = new long long int[10000];
	ISBN = getISBN("1.bin");
	int i = 0;
	while (ISBN[i] != 0)
	{
		root = insertsplay(root,ISBN[i], i,0);
		printsplayBT("", root, false, 0);
		cout << endl;
		printsplayBT("", root, false, 1);
		cout << endl;
		i++;
	}
	cout << "average number of turns " <<counter/i << endl;
	root = searchsplay(root, 547851263942);
	printsplayBT("", root, false, 0);
	cout << endl;
	printsplayBT("", root, false, 1);
	cout << endl;
	root= searchsplay(root, 569874120369);
	printsplayBT("", root, false, 0);
	cout << endl;
	printsplayBT("", root, false, 1);
	cout << endl;
	root = searchsplay(root, 156987542103);
	printsplayBT("", root, false, 0);
	cout << endl;
	printsplayBT("", root, false, 1);
	cout << endl;
	root = removesplay(root, 569874120369);
	printsplayBT("", root, false, 0);
	cout << endl;
	printsplayBT("", root, false, 1);
	cout << endl;
	//УДАЛЕНИЕ ЭЛЕМЕНТОВ SPLAY-ДЕРЕВА!!!!!!
	//printsplayBT("", root, false, 0);
	//printsplayBT("", root, false, 1);
	/*class node *root = NULL;
	long long int *ISBN = new long long int[10000];
	ISBN= getISBN("1.bin");
	int i = 0;
	while (ISBN[i] != 0)
	{
		root = insert(root, ISBN[i], i);
		i++;
	}
	//cout << exists(root, 1000)<<endl;
	//cout << search(root, 93) << endl;
	printBT("", root, false,1);
	cout << endl;
	printBT("", root, false, 0);
	//root = deleteNode(root, 1000);
	//printBT("", root, false);*/
}