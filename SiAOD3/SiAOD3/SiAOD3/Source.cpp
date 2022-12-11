#include "HashBin.h"
#include "HashTable.h"
#include <ctime>


void menubin()
{
	ifstream inp;
	ofstream outp;
	string inp_file, outp_file;
	system("cls");
	cout << "����� ���������� � ��������� �� ������ � ��������� �������\n���������� ������� ����� �������\n1-��������� ���� � ��������\n2-�������� ���� � ���������\n5-����� ������ � ������ ������\n6-������� �������� ����\n����� ������ ������ �������� � ������ �� ���������" << endl;
	int k;
	cin >> k;
	switch (k)
	{
	case 1:
		inp_file = "";
		outp_file = "";
		cout << "������� ��� ���������� �����: \n";
		cin >> inp_file;
		inp.open(inp_file, ios::in);
		if (inp.good())
		{
			cout << "������� ��� ��������� �����: \n";
			cin >> outp_file;
			outp.open(outp_file, ios::binary);
			if (outp.good())
			{
				txt_to_bin(inp, outp);
			}
			else
			{
				cout << "���� �� ������ ��� �� ������.";
			}
			outp.close();
			inp.close();
			system("pause");
			menubin();
		}
		else
		{
			cout << "����� � ����� ������ �� ����������.";
			system("pause");
			menubin();
		}
		break;
	case 2:
		inp_file = "";
		outp_file = "";
		cout << "������� ��� ��������� �����:\n";
		cin >> inp_file;
		inp.open(inp_file, ios::binary | ios::in);
		if (inp.good())
		{
			cout << "������� ��� ���������� �����:\n";
			cin >> outp_file;
			outp.open(outp_file, ios::out);
			if (outp.good())
			{
				bin_to_txt(inp, outp);
			}
			else
			{
				cout << "���� �� ������ ��� �� ������.";
			}
			outp.close();
			inp.close();
			system("pause");
			menubin();
		}
		else
		{
			cout << " ����� � ����� ������ �� ����������.";
			system("pause");
			menubin();
		}
		break;
	case 4:
	{
		inp_file = "";
		long long int key_val;
		cout << "������� ��� ��������� �����: \n";
		cin >> inp_file;
		ifstream check(inp_file);
		if (check.is_open())
		{
			cout << "������� �������� ��������:\n";
			cin >> key_val;
			remove_struct(inp_file, key_val);
			system("pause");
			menubin();
		}
		else
		{
			cout << "����� � ����� ������ �� ����������. ";
			system("pause");
			menubin();
		}
	}
	break;
	case 5:
	{
		inp_file = "";
		int pos_num;
		cout << "������� ��� ��������� �����: \n";
		cin >> inp_file;
		ifstream check(inp_file);
		if (check.is_open())
		{
			cout << "������� ����� ������ ������: \n";
			cin >> pos_num;
			ifstream tmp(inp_file, ios::binary | ios::in);
			int c = line_counter(tmp) + 1;
			if (pos_num < c)
			{
				Book tt = get_struct(inp_file, pos_num);
				cout << tt.ISBN << ' ' << tt.fam << ' ' << tt.name  << '\n';
				system("pause");
				menubin();
			}
			else
			{
				cout << "������� ������� ������� �����.\n";
				system("pause");
				menubin();
			}
		}
		else
		{
			cout << "����� � ����� ������ �� ����������. ";
			system("pause");
			menubin();
		}
	}
		break;
	case 6:
	{
		inp_file = "";
		cout << "������� ��� ��������� �����:\n";
		cin >> inp_file;
		inp.open(inp_file, ios::in | ios::binary);
		if (inp.good())
		{
			cout << "\n����� ����������� ��������� �����:\n";
			print_bin(inp);
			inp.close();
			system("pause");
			menubin();
		}
		else
		{
			cout << "����� � ����� ������ �� ����������.";
			system("pause");
			menubin();
		}
	}
		break;
	default:
		cout << "�� �������, ��� ������ �����? �/�" << endl;
		char u;
		cin >> u;
		if (u == '�')
		{
			exit(0);
		}
		else
		{
			menubin();
		}
		break;
	}
}
char getchar(int k)
{
	char let []= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	return let[k];
}
char word()
{
	char word;
	int k=rand()%26+1;
	word = getchar(k);
	return word;
}
void generate(int size)
{
	ofstream l;
	l.open("bigfile.txt", ios::app);
	Book k;
	char z[15];
	for (long long int i = 1; i <= size; i++)
	{
		k.fam[17] = '\0';
		k.name[17] = '\0';
		k.ISBN = (rand() % 9 + 1 * 100000000000) + (rand() % 10 * 10000000000) + (rand() % 10 * 1000000000) + (rand() % 10 * 100000000) + (rand() % 10 * 10000000)+(rand() % 10 * 1000000) + (rand() % 10 * 100000) + (rand() % 10 * 10000) + (rand() % 10 * 1000) + (rand() % 10 * 100) + (rand() % 10 * 10) + (rand() % 10);
		for (int i = 0; i < 16; i++)
		{
			k.fam[i] = word();
			k.name[i] = word();
		}
		//k.year = (rand()%9+1*1000)+(rand()%10*100)+(rand()%10*10)+(rand()%10);
		l << k.ISBN << " " << k.fam << " " << k.name  << endl;
		//cout << k.ISBN << " " << k.fam << " " << k.name << " " << k.year << endl;
	}
	l.close();
}


int main()
{
	HashTable T;
	T.CreateHashTable(20);
	TypeItem item;
	HashTablebin Tb;
	Tb.CreateHashTable(20);
	TypeItembin itembin;
	ifstream inp;
	ofstream outp;
	string inp_file, outp_file;
	int h;
	long long int h1;
	int i;
	int j;
	system("chcp 1251");
	while (true)
	{
		system("cls");
		cout << "����� ���������� � ��������� �� ������ � ��� ���������\n���������� ������� ����� �������\n1-������ ���� � �������\n2-������� ���� �� �������\n3-����� ���� � �������\n4-������������ �������(����� ����������� ���� �� ���� ���������� �������)\n5-������� �������\n6-������� � ���� ������ � ��������� �������\n7-������� ����� �� ��������� ����� � ������� ��� � ���-�������\n8-����� ���� � ���-������� �������� ������\n9-������� ���� �� ���-������� �������� ������\n10-������������ ���-������� �������� ������(����� ����������� ���� �� ���� ���������� �������)\n11-������� ���-������� ��������� �������\n12-�������� ������ � �������� ����\n13-������� ������ �� ��������� �����\n����� ������ ������ �������� � ������ �� ���������" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case 1:
			system("cls");
			cout << "������� ����. ����������� �����"<<endl;
			cin >> h;
			cout << "������� ��������. ����������� �����"<<endl;
			cin >> j;
			if (InsertInHashTable(h, j, T) == 0)
			{
				cout << "�������";
				system("pause");
				break;
			}
			else
			{
				cout << "�������� ������";
				system("pause");
				break;
			}
			break;
		case 2:
			system("cls");
			cout << "������� ����. ����������� �����" << endl;
			cin >> h;
			if (deleteFromHashTable(T, h) == 0)
			{
				cout << "�������";
				system("pause");
				break;
			}
			else
			{
				cout << "�������� �� �������";
				system("pause");
				break;
			}
			break;
		case 3:
			system("cls");
			cout << "������� ����. ����������� �����" << endl;
			cin >> h;
			i = search(T, h);
			if (i != -1)
			{
				item = T.T[i];
				cout << "����\t��������" << endl;
				cout << item.key << '\t' << item.offset << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "������ �� �������" << endl;
				system("pause");
				break;
			}
			break;
		case 4:
			system("cls");
			if (reHash(T) == 1)
			{
				cout << "������� ������������" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "�������� ������" << endl;
				system("pause");
				break;
			}
			break;
		case 5:
			system("cls");
			outTable(T);
			system("pause");
			break;
			break;
		case 6:
			menubin();
			break;
		case 7:
			system("cls");
			cout << "������� �������� �����" << endl;
			cin >> inp_file;
			inp.open(inp_file, ios::binary);
			if (inp.good())
			{
				unsigned int start_time = clock();
				if (ReadBin(Tb, inp) == 0)
				{
					unsigned int finish_time = clock();
					unsigned int rez_time = finish_time - start_time;
					cout << "�������. ����� ����������� - "<<rez_time<<" ����������" << endl;
					system("pause");
					inp.close();
					break;
				}
				else
				{
					cout << "�������� ������" << endl;
					system("pause");
					inp.close();
					break;
				}
			}
			else
			{
				cout << "���� �� ������" << endl;
				system("pause");
				inp.close();
				break;
			}
			break;
		case 8:
			system("cls");
			cout << "������� �������� �����" << endl;
			cin >> inp_file;
			inp.open(inp_file, ios::binary);
			if (inp.good())
			{
				cout << "������� ����. ����������� �����" << endl;
				cin >> h1;
				unsigned int start_time = clock();
				i = search(Tb, h1);
				if (i != -1)
				{
					find(i, inp);
					unsigned int finish_time = clock();
					unsigned int search_time = finish_time - start_time;
					cout << "����� ������ ����� " << search_time<<" ����������"<< endl;
					system("pause");
					break;
				}
				else
				{
					cout << "������ �� �������" << endl;
					system("pause");
					break;
				}
			}
			else
			{
				cout << "���� �� ������" << endl;
				system("pause");
				break;
			}
			break;
		case 9:
			system("cls");
			cout << "������� ����. ����������� �����" << endl;
			cin >> h1;
			if (deleteFromHashTable(Tb, h1) == 0)
			{
				cout << "�������";
				system("pause");
				break;
			}
			else
			{
				cout << "�������� �� �������";
				system("pause");
				break;
			}
			break;
		case 10:
			system("cls");
			if (reHash(Tb) == 1)
			{
				cout << "������� ������������" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "�������� ������" << endl;
				system("pause");
				break;
			}
			break;
		case 11:
			system("cls");
			outTable(Tb);
			system("pause");
			break;
		case 12:
		{
			Book temp;
			string temp1;
			outp_file = "";
			cout << "������� ��� ��������� �����:\n";
			cin >> outp_file;
			outp.open(outp_file, ios::binary | ios::in);
			if (outp.good())
			{
				cout << "������� ISBN" << endl;
				cin >> temp.ISBN;
				cout << "������� ��� ������(���������� ����)" << endl;
				cin >> temp1;
				strcpy(temp.fam, temp1.c_str());
				cout << "������� �������� �����(���������� ����)" << endl;
				cin >> temp1;
				strcpy(temp.name, temp1.c_str());
				AddToBin(outp, temp, Tb);
				outp.close();
				inp.open(outp_file, ios::binary);
				Tb.CreateHashTable(20);
				ReadBin(Tb, inp);
				inp.close();
				system("pause");
			}
			else
			{
				cout << " ����� � ����� ������ �� ����������.";
				system("pause");
			}
		}
			break;
		case 13:
		{
			inp_file = "";
			long long int key_val;
			cout << "������� ��� ��������� �����: \n";
			cin >> inp_file;
			ifstream check(inp_file);
			if (check.is_open())
			{
				cout << "������� �������� ��������:\n";
				cin >> key_val;
				remove_struct(inp_file, key_val);
				Tb.CreateHashTable(20);
				ReadBin(Tb, check);
				check.close();
				system("pause");
			}
			else
			{
				cout << "����� � ����� ������ �� ����������. ";
				system("pause");
			}
		}
		break;
		case 14:
		{
			ofstream l;
			l.open("bigfile.txt");
			l << "";
			l.close();
			generate(1000);
			system("pause");
		}
		break;
		default:
			cout << "�� �������, ��� ������ �����? �/�" << endl;
			char u;
			cin >> u;
			if (u == '�')
			{
				exit(0);
			}
			else
			{
				break;
			}
			break;
		}
	}
	system("pause");
}