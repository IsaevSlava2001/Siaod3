#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void menu() {
	setlocale(LC_ALL, "Russian");
}

int main() {
	string inp_file, outp_file;
	ifstream inp;
	ofstream outp;
	menu();
	int num;
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << "������ ������ ��� ����������: \n1. �������������� �������� ������ �� ���������� ����� � �������� ����. \n2. �������������� ������ �� ��������� ����� � ���������. \n3. ����� ���� ������� ��������� �����. \n4. ������ � ������ �� �� ����������� ������ � �����, ��������� �������� ������� ������� � ������ � �������� �����. \n5. �������� ������ � �������� ��������� �����, ��������� ����� ������ �� ��������� ������ \n6. ������� ����� �������������� ���� � ��������� � ���� ������ � ������ ���������� ������ �� ��������� ��� \n7. ������� �����, �������� � ��������� ����\n";
		cout << "\n������� ����� �������:\n";
		cin >> num;
		switch (num)
		{
		case 1:
		{
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
				else cout << "���� �� ������ ��� �� ������.";

				outp.close();
				inp.close();
			}
			else
			{
				cout << "����� � ����� ������ �� ����������.";
			}
			system("pause");
		}
			break;
		case 2: 
		{
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
				else cout << "���� �� ������ ��� �� ������.";

				outp.close();
				inp.close();
			}
			else
			{
				cout << " ����� � ����� ������ �� ����������.";
			}
			system("pause");
		}
			break;
		case 3:
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
			}
			else
			{
				cout << "����� � ����� ������ �� ����������.";
			}
			system("pause");
		}
			break;
		case 4: 
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
				Book tt = get_struct(inp_file, pos_num-1);
				if (tt.ISBN != 0)
				{
					cout << tt.ISBN << ' ' << tt.fam << ' ' << tt.name << ' ' << tt.year << '\n';
				}
				else
				{
					cout << "������� ������� ������� �����.\n";
				}
			}
			else
			{
				cout << "����� � ����� ������ �� ����������. ";
			}
			system("pause");
		}
			break;
		        case 5:
				{
					inp_file = "";
					long long int key_val;
					cout << "������� ��� ��������� �����: \n";
					cin >> inp_file;
					Book tt;

					ifstream check(inp_file);
					if (check.is_open())
					{
						cout << "������� �������� ��������:\n";
						cin >> key_val;
						remove_struct(inp_file, key_val);
					}
					else
					{
						cout << "����� � ����� ������ �� ����������. ";
					}
					system("pause");
				}
			break;
		case 6:
		{
			outp_file = "";
			inp_file = "";
			string fam;
			int year;
			cout << "������� ��� �����: \n";
			cin >> inp_file;
			inp.open(inp_file, ios::binary | ios::in);
			if (inp.good())
			{
				cout << "������� ��� ������ �����: \n";
				cin >> outp_file;
				outp.open(outp_file, ios::binary | ios::out);
				if (outp.good())
				{
					cout << "������� ������� ������:\n";
					cin >> fam;
					cout << "������� ���: \n";
					cin >> year;
					new_file(inp, outp, fam,year);
				}
				else cout << "���� �� ������ ��� �� ������.";
				outp.close();
				inp.close();
			}
			else
			{
				cout << "����� � ����� ������ �� ����������. ";
			}
			system("pause");
		}
			break;
		case 7:
		{
			outp_file = "";
			inp_file = "";
			int year;
			cout << "������� ��� �����: \n";
			cin >> inp_file;
			fstream inp1;
			inp1.open(inp_file, ios::binary | ios::in|ios::out);
			if (inp1.good())
			{
				cout << "������� ���: \n";
				cin >> year;
				delete_book(inp1, year);
			}
			else cout << "���� �� ������ ��� �� ������.";
			outp.close();
			inp.close();
			system("pause");
		}
			break;
		default:
			flag = false;
			break;
		}
	}

	return 0;
}
