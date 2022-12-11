#include"BST.h"
#include "BinFile.h"
#include "SplayTree.h"
#include <ctime>

using namespace std;
extern double counter;

char getchar(int k)
{
	char let[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	return let[k];
}
char word()
{
	char word;
	int k = rand() % 26 + 1;
	word = getchar(k);
	return word;
}
void generate(int size)
{
	ofstream l;
	l.open("bigfile.txt", ios::app);
	Book k;
	for (long long int i = 1; i <= size; i++)
	{
		k.fam[10] = '\0';
		k.name[10] = '\0';
		int k10 = rand() % 9+1;
		int k11 = rand() % 10;
		int k12 = rand() % 10;
		k.ISBN = k10 * 100 + k11 * 10 + k12;
		for (int i = 0; i < 10; i++)
		{
			k.fam[i] = word();
			k.name[i] = word();
		}
		l << k.ISBN << " " << k.fam << " " << k.name << endl;
	}
	l.close();
}
int main()
{
	setlocale(LC_ALL, "rus");
	class node *root = NULL;
	class nodesplay *root_splay = NULL;
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
			unsigned int start_time = clock();
			temp=BinFile::linear_search(bin_file, key);
			unsigned int finish_time = clock();
			if (temp.ISBN != 0)
			{
				cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
				unsigned int rez_time = finish_time - start_time;
				cout << "����� �������� �� " <<rez_time <<" ����������"<< endl;
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
			outp.open(bin_file, ios::binary || ios::app);
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
			outp.open(bin_file, ios::binary || ios::app);
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
			outp.open(bin_file, ios::binary || ios::app);
			if (outp.good())
			{
				outp.close();
				cout << "������� ����(12 ����) ";
				cin >> key;
				unsigned int start_time = clock();
				adress=node::search(root, key);
				if (adress != -1)
				{
					temp = BinFile::get_class(bin_file, adress);
					unsigned finish_time = clock();
					unsigned rez_time = finish_time - start_time;
					cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
					cout << "����� �������� �� " << rez_time<< " ����������" << endl;
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
		if (k == 10)
		{
			system("cls");
			cout << "���������� ������ ������ �� �����" << endl;
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			ifstream inp;
			i = 0;
			inp.open(bin_file, ios::binary || ios::app);
			if (inp.good())
			{
				inp.close();
				ISBN = BinFile::getISBN(bin_file);
				while (ISBN[i] != 0)
				{
					root_splay = nodesplay::insertsplay(root_splay, ISBN[i], i, 0);
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
		if (k == 11)
		{
			system("cls");
			cout << "���������� �������� � ������" << endl;
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			ofstream outp;
			outp.open(bin_file, ios::binary || ios::app);
			cout << "������� ISBN(12 ����) ";
			cin >> temp.ISBN;
			cout << "������� ������� ������(���������� ����) ";
			cin >> temp.fam;
			cout << "������� �������� �����(���������� ����) ";
			cin >> temp.name;
			if (outp.good())
			{
				BinFile::AddToBin(outp, temp);
				root_splay = nodesplay::insertsplay(root_splay, temp.ISBN, i, 0);
				i++;
			}
			else
			{
				cout << "������ ����� �� ����������" << endl;
			}
			outp.close();
			system("pause");
		}
		if (k == 12)
		{
			system("cls");
			cout << "����� �� ����� � ������" << endl;
			cout << "������� ��� ��������� �����" << endl;
			cin >> bin_file;
			ofstream outp;
			outp.open(bin_file, ios::binary || ios::app);
			if (outp.good())
			{
				cout << "������� ����(12 ����) ";
				cin >> key;
				unsigned int start_time = clock();
				root_splay=nodesplay::searchsplay(root_splay, key);
				if (root_splay->key==key)
				{
					temp = BinFile::get_class(bin_file, root_splay->value);
					unsigned int finish_time = clock();
					unsigned rez_time = finish_time - start_time;
					cout << temp.ISBN << " " << temp.fam << "  " << temp.name;
					cout << "����� �������� �� " << rez_time<< " ����������" << endl;
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
		if (k == 13)
		{
			system("cls");
			cout << "�������� �������� �� ������" << endl;
			cout << "������� ����" << endl;
			cin >> key;
			root_splay = nodesplay::searchsplay(root_splay, key);
			if (root_splay->key == key)
			{
				root_splay = nodesplay::removesplay(root_splay, key);
				cout << "������� �������" << endl;
			}
			else
			{
				cout << "������ � ����� ������ �� �������" << endl;
			}
			system("pause");
		}
		if (k == 14)
		{
			system("cls");
			cout << "����� ������" << endl;
			cout << "����� ������ ������" << endl;
			nodesplay::printsplayBT("", root_splay, false, 1);
			cout << "����� �������� ������" << endl;
			nodesplay::printsplayBT("", root_splay, false, 0);
			system("pause");
		}
		if (k == 15)
		{
				ofstream l;
				l.open("bigfile.txt");
				l << "";
				l.close();
				generate(1000);
				system("pause");
		}
		if (k < 1 || k>15)
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
}