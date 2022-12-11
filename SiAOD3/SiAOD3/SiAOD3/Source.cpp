#include "HashBin.h"
#include "HashTable.h"
#include <ctime>


void menubin()
{
	ifstream inp;
	ofstream outp;
	string inp_file, outp_file;
	system("cls");
	cout << "Добро пожаловать в программу по работе с бинарными файлами\nПожалуйста введите номер задания\n1-Текстовый файл в бинарный\n2-Бинарный файл в текстовый\n5-найти запись с нужным ключом\n6-Вывести бинарный файл\nлюбой другой символ приведет к выходу из программы" << endl;
	int k;
	cin >> k;
	switch (k)
	{
	case 1:
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
			else
			{
				cout << "Файл не найден или не создан.";
			}
			outp.close();
			inp.close();
			system("pause");
			menubin();
		}
		else
		{
			cout << "Файла с таким именем не существует.";
			system("pause");
			menubin();
		}
		break;
	case 2:
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
			else
			{
				cout << "Файл не найден или не создан.";
			}
			outp.close();
			inp.close();
			system("pause");
			menubin();
		}
		else
		{
			cout << " Файла с таким именем не существует.";
			system("pause");
			menubin();
		}
		break;
	case 4:
	{
		inp_file = "";
		long long int key_val;
		cout << "Введите имя бинарного файла: \n";
		cin >> inp_file;
		ifstream check(inp_file);
		if (check.is_open())
		{
			cout << "Введите ключевой параметр:\n";
			cin >> key_val;
			remove_struct(inp_file, key_val);
			system("pause");
			menubin();
		}
		else
		{
			cout << "Файла с таким именем не существует. ";
			system("pause");
			menubin();
		}
	}
	break;
	case 5:
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
				cout << "Введено слишком большое число.\n";
				system("pause");
				menubin();
			}
		}
		else
		{
			cout << "Файла с таким именем не существует. ";
			system("pause");
			menubin();
		}
	}
		break;
	case 6:
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
			system("pause");
			menubin();
		}
		else
		{
			cout << "Файла с таким именем не существует.";
			system("pause");
			menubin();
		}
	}
		break;
	default:
		cout << "Вы уверены, что хотите выйти? Д/Н" << endl;
		char u;
		cin >> u;
		if (u == 'Д')
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
		cout << "Добро пожаловать в программу по работе с хеш таблицами\nПожалуйста введите номер задания\n1-Ввести ключ в таблицу\n2-Удалить ключ из таблицы\n3-Найти ключ в таблице\n4-Рехешировать таблицу(может происходить само по мере увеличения таблицы)\n5-Вывести таблицу\n6-перейти в меню работы с бинарными файлами\n7-Считать текст из бинарного файла и занести его в хеш-таблицу\n8-Найти ключ в хеш-таблице бинарных файлов\n9-Удалить ключ из хеш-таблицы бинарных файлов\n10-Рехешировать хеш-таблицу бинарных файлов(может происходить само по мере увеличения таблицы)\n11-Вывести хеш-таблицу бинарными файлами\n12-Добавить запись в бинарный файл\n13-Удалить запись из бинарного файла\nлюбой другой символ приведет к выходу из программы" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case 1:
			system("cls");
			cout << "Введите ключ. Обязательно число"<<endl;
			cin >> h;
			cout << "Введите значение. Обязательно число"<<endl;
			cin >> j;
			if (InsertInHashTable(h, j, T) == 0)
			{
				cout << "Успешно";
				system("pause");
				break;
			}
			else
			{
				cout << "Возникли ошибки";
				system("pause");
				break;
			}
			break;
		case 2:
			system("cls");
			cout << "Введите ключ. Обязательно число" << endl;
			cin >> h;
			if (deleteFromHashTable(T, h) == 0)
			{
				cout << "Успешно";
				system("pause");
				break;
			}
			else
			{
				cout << "Значение не найдено";
				system("pause");
				break;
			}
			break;
		case 3:
			system("cls");
			cout << "Введите ключ. Обязательно число" << endl;
			cin >> h;
			i = search(T, h);
			if (i != -1)
			{
				item = T.T[i];
				cout << "ключ\tзначение" << endl;
				cout << item.key << '\t' << item.offset << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "Запись не найдена" << endl;
				system("pause");
				break;
			}
			break;
		case 4:
			system("cls");
			if (reHash(T) == 1)
			{
				cout << "Успешно рехешировано" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "Возникли ошибки" << endl;
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
			cout << "Введите название файла" << endl;
			cin >> inp_file;
			inp.open(inp_file, ios::binary);
			if (inp.good())
			{
				unsigned int start_time = clock();
				if (ReadBin(Tb, inp) == 0)
				{
					unsigned int finish_time = clock();
					unsigned int rez_time = finish_time - start_time;
					cout << "Успешно. Время хеширвоания - "<<rez_time<<" милисекунд" << endl;
					system("pause");
					inp.close();
					break;
				}
				else
				{
					cout << "Возникли ошибки" << endl;
					system("pause");
					inp.close();
					break;
				}
			}
			else
			{
				cout << "Файл не найден" << endl;
				system("pause");
				inp.close();
				break;
			}
			break;
		case 8:
			system("cls");
			cout << "Введите название файла" << endl;
			cin >> inp_file;
			inp.open(inp_file, ios::binary);
			if (inp.good())
			{
				cout << "Введите ключ. Обязательно число" << endl;
				cin >> h1;
				unsigned int start_time = clock();
				i = search(Tb, h1);
				if (i != -1)
				{
					find(i, inp);
					unsigned int finish_time = clock();
					unsigned int search_time = finish_time - start_time;
					cout << "Время поиска ключа " << search_time<<" милисекунд"<< endl;
					system("pause");
					break;
				}
				else
				{
					cout << "Запись не найдена" << endl;
					system("pause");
					break;
				}
			}
			else
			{
				cout << "Файл не найден" << endl;
				system("pause");
				break;
			}
			break;
		case 9:
			system("cls");
			cout << "Введите ключ. Обязательно число" << endl;
			cin >> h1;
			if (deleteFromHashTable(Tb, h1) == 0)
			{
				cout << "Успешно";
				system("pause");
				break;
			}
			else
			{
				cout << "Значение не найдено";
				system("pause");
				break;
			}
			break;
		case 10:
			system("cls");
			if (reHash(Tb) == 1)
			{
				cout << "Успешно рехешировано" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "Возникли ошибки" << endl;
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
			cout << "Введите имя бинарного файла:\n";
			cin >> outp_file;
			outp.open(outp_file, ios::binary | ios::in);
			if (outp.good())
			{
				cout << "Введите ISBN" << endl;
				cin >> temp.ISBN;
				cout << "Введите Имя автора(английский язык)" << endl;
				cin >> temp1;
				strcpy(temp.fam, temp1.c_str());
				cout << "Введите название книги(английский язык)" << endl;
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
				cout << " Файла с таким именем не существует.";
				system("pause");
			}
		}
			break;
		case 13:
		{
			inp_file = "";
			long long int key_val;
			cout << "Введите имя бинарного файла: \n";
			cin >> inp_file;
			ifstream check(inp_file);
			if (check.is_open())
			{
				cout << "Введите ключевой параметр:\n";
				cin >> key_val;
				remove_struct(inp_file, key_val);
				Tb.CreateHashTable(20);
				ReadBin(Tb, check);
				check.close();
				system("pause");
			}
			else
			{
				cout << "Файла с таким именем не существует. ";
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
			cout << "Вы уверены, что хотите выйти? Д/Н" << endl;
			char u;
			cin >> u;
			if (u == 'Д')
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