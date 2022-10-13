#include "HashBin.h"
#include "HashTable.h"


void menubin()
{
	ifstream inp;
	ofstream outp;
	string inp_file, outp_file;
	system("cls");
	cout << "����� ���������� � ��������� �� ������ � ��������� �������\n���������� ������� ����� �������\n1-��������� ���� � ��������\n2-�������� ���� � ���������\n3-�������� ������ � �������� ����\n4-������� ������ �� ��������� �����\n5-����� ������ � ������ ������\n6-������� �������� ����\n����� ������ ������ �������� � ������ �� ���������" << endl;
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
	case 3:
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
			cout << "������� ��� �������" << endl;
			cin >> temp.year;
			AddToBin(outp, temp);
			outp.close();
			system("pause");
			menubin();
		}
		else
		{
			cout << " ����� � ����� ������ �� ����������.";
			system("pause");
			menubin();
		}
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
				cout << tt.ISBN << ' ' << tt.fam << ' ' << tt.name << ' ' << tt.year << '\n';
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
		cout << "����� ���������� � ��������� �� ������ � ��� ���������\n���������� ������� ����� �������\n1-������ ���� � �������\n2-������� ���� �� �������\n3-����� ���� � �������\n4-������������ �������(����� ����������� ���� �� ���� ���������� �������)\n5-������� �������\n6-������� � ���� ������ � ��������� �������\n7-������� ����� �� ��������� ����� � ������� ��� � ���-�������\n8-����� ���� � ���-������� �������� ������\n9-������� ���� �� ���-������� �������� ������\n10-������������ ���-������� �������� ������(����� ����������� ���� �� ���� ���������� �������)\n11-������� ���-������� ��������� �������\n12-�������� ���-������� �������� ������ � �������� ����\n����� ������ ������ �������� � ������ �� ���������" << endl;
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
				if (ReadBin(Tb, inp) == 0)
				{
					cout << "�������" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "�������� ������" << endl;
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
		case 8:
			system("cls");
			cout << "������� ����. ����������� �����" << endl;
			cin >> h1;
			i = search(Tb, h1);
			if (i != -1)
			{
				itembin = Tb.T[i];
				cout << "ISBN\t��� ������\t��������\t��� �������" << endl;
				cout << itembin.key << '\t' << itembin.offset << itembin.offset2 << itembin.offset3 << endl;
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
			break;
		case 12:
			system("cls");
			cout << "������� �������� �����" << endl;
			cin >> outp_file;
			outp.open(outp_file, ios::binary);
			if (outp.good())
			{
				if (WriteBin(Tb, outp) == 0)
				{
					cout << "�������" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "�������� ������" << endl;
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