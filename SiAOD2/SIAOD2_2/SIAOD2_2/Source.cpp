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
		cout << "Список команд для выполнения: \n1. Преобразование тестовых данных из текстового файла в двоичный файл. \n2. Преобразование данных из двоичного файла в текстовый. \n3. Вывод всех записей двоичного файла. \n4. Доступ к записи по ее порядковому номеру в файле, используя механизм прямого доступа к записи в двоичном файле. \n5. Удаление записи с заданным значением ключа, выполнить путем замены на последнюю запись \n6. Создать новый типизированный файл и перенести в него записи о книгах указанного автора за указанный год \n7. Удалить книги, изданные в указанном году\n";
		cout << "\nВведите новую команду:\n";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			inp_file = "";
			outp_file = "";
			cout << "Введите имя текстового файла: \n";
			cin >> inp_file;
			inp.open(inp_file, ios::in);
			if (inp.good())
			{
				cout << "Введите имя бинарного файла: \n";
				cin >> outp_file;
				outp.open(outp_file, ios::binary);
				if (outp.good())
				{
					txt_to_bin(inp, outp);
				}
				else cout << "Файл не найден или не создан.";

				outp.close();
				inp.close();
			}
			else
			{
				cout << "Файла с таким именем не существует.";
			}
			system("pause");
		}
			break;
		case 2: 
		{
			inp_file = "";
			outp_file = "";
			cout << "Введите имя бинарного файла:\n";
			cin >> inp_file;
			inp.open(inp_file, ios::binary | ios::in);
			if (inp.good())
			{
				cout << "Введите имя текстового файла:\n";
				cin >> outp_file;
				outp.open(outp_file, ios::out);
				if (outp.good())
				{
					bin_to_txt(inp, outp);
				}
				else cout << "Файл не найден или не создан.";

				outp.close();
				inp.close();
			}
			else
			{
				cout << " Файла с таким именем не существует.";
			}
			system("pause");
		}
			break;
		case 3:
		{
			inp_file = "";
			cout << "Введите имя бинарного файла:\n";
			cin >> inp_file;
			inp.open(inp_file, ios::in | ios::binary);
			if (inp.good())
			{
				cout << "\nВывод содержимого бинарного файла:\n";
				print_bin(inp);
				inp.close();
			}
			else
			{
				cout << "Файла с таким именем не существует.";
			}
			system("pause");
		}
			break;
		case 4: 
		{
			inp_file = "";
			int pos_num;
			cout << "Введите имя бинарного файла: \n";
			cin >> inp_file;
			ifstream check(inp_file);
			if (check.is_open())
			{
				cout << "Введите номер нужной строки: \n";
				cin >> pos_num;
				ifstream tmp(inp_file, ios::binary | ios::in);
				Book tt = get_struct(inp_file, pos_num-1);
				if (tt.ISBN != 0)
				{
					cout << tt.ISBN << ' ' << tt.fam << ' ' << tt.name << ' ' << tt.year << '\n';
				}
				else
				{
					cout << "Введено слишком большое число.\n";
				}
			}
			else
			{
				cout << "Файла с таким именем не существует. ";
			}
			system("pause");
		}
			break;
		        case 5:
				{
					inp_file = "";
					long long int key_val;
					cout << "Введите имя бинарного файла: \n";
					cin >> inp_file;
					Book tt;

					ifstream check(inp_file);
					if (check.is_open())
					{
						cout << "Введите ключевой параметр:\n";
						cin >> key_val;
						remove_struct(inp_file, key_val);
					}
					else
					{
						cout << "Файла с таким именем не существует. ";
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
			cout << "Введите имя файла: \n";
			cin >> inp_file;
			inp.open(inp_file, ios::binary | ios::in);
			if (inp.good())
			{
				cout << "Введите имя нового файла: \n";
				cin >> outp_file;
				outp.open(outp_file, ios::binary | ios::out);
				if (outp.good())
				{
					cout << "Введите фамилию автора:\n";
					cin >> fam;
					cout << "Введите год: \n";
					cin >> year;
					new_file(inp, outp, fam,year);
				}
				else cout << "Файл не найден или не создан.";
				outp.close();
				inp.close();
			}
			else
			{
				cout << "Файла с таким именем не существует. ";
			}
			system("pause");
		}
			break;
		case 7:
		{
			outp_file = "";
			inp_file = "";
			int year;
			cout << "Введите имя файла: \n";
			cin >> inp_file;
			fstream inp1;
			inp1.open(inp_file, ios::binary | ios::in|ios::out);
			if (inp1.good())
			{
				cout << "Введите год: \n";
				cin >> year;
				delete_book(inp1, year);
			}
			else cout << "Файл не найден или не создан.";
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
