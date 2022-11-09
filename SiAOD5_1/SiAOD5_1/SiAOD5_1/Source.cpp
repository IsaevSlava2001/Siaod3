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
		cout << "������� ����� �������:\n1-�������� �����\n2-����� � ������� ��������� ������\n3-����� ������ �� �� ������\n4-���������� ������ � ����\n5-���������� ��������� ������ �� �����\n6-���������� �������� � ������\n7-����� �� ����� � ������\n8-�������� �������� �� ������\n9-����� ������\n10-���������� ������ ������ �� �����\n11-���������� �������� � ������\n12-����� �� ����� � ������\n13-�������� �������� �� ������\n14-����� ������\n����� ������ ����� ������� ���������" << endl;
		int k = 0;
		cin >> k;
		if (k == 1)
		{
			system("cls");
			cout << "�������� �����" << endl;
			cout << "������� ��� ���������� �����" << endl;
			cin >> txt_file;
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			if (BinFile::txt_to_bin(txt_file, bin_file) == 1)
			{
				cout << "������� �������" << endl;
			}
			else
			{
				cout << "���� �� ����������" << endl;
			}
			system("pause");
		}
		if (k == 2)
		{
			system("cls");
			cout << "����� � ������� ��������� ������" << endl;
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			cout << "������� ���� (12 ����)" << endl;
			cin >> key;
			temp=BinFile::linear_search(bin_file, key);
			if (temp.ISBN != 0)
			{
				cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
			}
			else
			{
				cout <<"������ � ����� ������ �� �������" << endl;;
			}
			system("pause");
		}
		if (k == 3)
		{
			system("cls");
			cout << "����� ������ �� �� ������" << endl;
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			cout << "������� �������" << endl;
			cin >> adress;
			temp=BinFile::get_class(bin_file, adress);
			if (temp.ISBN != 0)
			{
				cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
			}
			else
			{
				cout << "������ � ����� ������ �� �������" << endl;;
			}
			system("pause");
		}
		if (k == 4)
		{
			system("cls");
			cout << "���������� ������ � ����" << endl; 
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			ofstream outp;
			outp.open(bin_file, ios::binary);
			cout << "������� ISBN(12 ����) ";
			cin >> temp.ISBN;
			cout << "������� ������� ������(���������� ����) ";
			cin >> temp.fam;
			cout << "������� �������� �����(���������� ����) ";
			cin >> temp.name;
			if (outp.good())
			{
				BinFile::AddToBin(outp, temp);
			}
			else
			{
				cout << "������ ����� �� ����������" << endl;
			}
			outp.close();
			system("pause");
		}
		if (k == 5)
		{
			system("cls");
			cout << "���������� ��������� ������ �� �����" << endl;
			cout << "������� ��� ��������� �����" << endl;
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
				cout << "�������" << endl;
			}
			else
			{
				cout << "���� �� ����������" << endl;
			}
			system("pause");
		}
		if (k == 6)
		{
			system("cls");
			cout << "���������� �������� � ������" << endl;
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			ofstream outp;
			outp.open(bin_file, ios::binary);
			cout << "������� ISBN(12 ����) ";
			cin >> temp.ISBN;
			cout << "������� ������� ������(���������� ����) ";
			cin >> temp.fam;
			cout << "������� �������� �����(���������� ����) ";
			cin >> temp.name;
			if (outp.good())
			{
				BinFile::AddToBin(outp, temp);
				root = node::insert(root, temp.ISBN, i);
				i++;
			}
			else
			{
				cout << "������ ����� �� ����������" << endl;
			}
			outp.close();
			system("pause");
		}
		if (k == 7)
		{
			system("cls");
			cout << "����� �� ����� � ������" << endl;
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			ofstream outp;
			outp.open(bin_file, ios::binary);
			if (outp.good())
			{
				cout << "������� ����(12 ����) ";
				cin >> key;
				adress = node::search(root, key);
				temp=BinFile::get_class(bin_file, adress);
				if (temp.ISBN != 0)
				{
					cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
				}
				else
				{
					cout << "������ � ����� ������ �� �������" << endl;
				}
			}
			else
			{
				cout << "������ ����� �� ����������" << endl;
			}
			outp.close();
			system("pause");
		}
		if (k == 8)
		{
			system("cls");
			cout << "�������� �������� �� ������" << endl;
			cout << "������� ����" << endl;
			cin >> key;
			if (node::search(root, key) != -1)
			{
				root = node::deleteNode(root, key);
				cout << "������� �������" << endl;
			}
			else
			{
				cout << "������ � ����� ������ �� �������" << endl;
			}
			system("pause");
		}
		if (k == 9)
		{
			system("cls");
			cout << "����� ������" << endl;
			cout << "����� ������ ������" << endl;
			node::printBT("", root, false, 1);
			cout << "����� �������� ������" << endl;
			node::printBT("", root, false, 0);
			system("pause");
		}
		if (k < 1 || k>14)
		{
			cout << "�� �������, ��� ������ �����? Y/N" << endl;
			char j;
			cin >> j;
			if (j == 'Y')
			{
				cout << "�����... ";
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
	//�������� ��������� SPLAY-������!!!!!!
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