#include <iostream>
#include <random>
#include <fstream>
#define SIZE 200

using namespace std;
/*возвращает число в виде строки
аргументы:
0-число int*/
char getdigit(int num)
{
	char dig[10] = { '0','1','2','3','4','5','6','7','8','9' };
	return dig[num];
}
/*возвращает число в виде int
аргументы:
0-число char*/
int getdigit(char num)
{
	switch (num)
	{
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break; 
	case '3':
		return 3;
	break; 
	case '4':
		return 4;
		break; 
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break; 
	case '7':
		return 7;
		break; 
	case '8':
		return 8;
		break; 
	case '9':
		return 9;
		break;
	}
}
/*создает файл.
Аргументы:
0-имя файла*/
void create(char name[])
{
	ofstream file;
	file.open(name);
	file.close();
}
/*заполняет файл числами и переводит в кодировку ASCII.
Аргументы:
0-имя файла,
1-массив чисел char
3-число заполнения файла. Если файл уже заполнялся, 1, если файл еще пустой, 0*/
void fill_file(char name[], char nums[], int fill)
{
	if (fill == 0)
	{
		int i = 0;
		ofstream file;
		file.open(name);
		if (file.is_open())
		{
			while (nums[i] != '\0')
			{
				int x = nums[i];
				file << x;
				i++;
			}
		}
		file.close();
	}
	else if (fill==1)
	{
		int i = 0;
		ofstream file;
		file.open(name, ios::app);
		if (file.is_open())
		{
			char n = '\n';
			int x = n;
			file << x;
			while (nums[i] != '\0')
			{
				int x = nums[i];
				file << x;
				i++;
			}
		}
		file.close();
	}
}
/*проверяет, существует ли файл. Если да, возвращает 1, иначе 0.
Аргументы:
0-имя файла*/
int check(char name[])
{
	bool isExist = false;
	ifstream fin(name);

	if (fin.is_open())
		isExist = true;

	fin.close();
	return isExist;
}
/*читает содержимое текстового файла в кодировке ASCII, переводит его в читаемый текст. Возвращает массив char
Аргументы:
0-имя файла*/
char *output_str(char name[])
{
	char buff[600];
	char *buff_char = new char[200] {'\0'};
	ifstream fin(name); 
	fin.getline(buff, 600);
	fin.close();
	int i = 0;
	int k = 0;
	char x = ' ';
	while(getdigit(buff[i]) * 10 + getdigit(buff[i + 1])!=-52)
	{
		x = getdigit(buff[i])*10+getdigit(buff[i+1]);
		buff_char[k] = x;
		i = i + 2;
		k++;
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (buff_char[i] == 'М')
		{
			buff_char[i] = '\0';
		}
	}
	return buff_char;
}
/*ищет число в файле по его момеру. Возвращает char. Если номер находится вне границ файла, возвращает '&'
аргументы:
0-имя файла
1-номер символа*/
int find(char name[], int num)
{
	char buff[600];
	char buff_char[200];
	char nums_char[200] = { '\0' };
	int nums = 0;
	ifstream fin(name);
	fin.getline(buff, 600);
	int current = 1;
	int size = 0;
	bool isFound = false;
	fin.close();
	int i = 0;
	int k = 0;
	char x = ' ';
	while (getdigit(buff[i]) * 10 + getdigit(buff[i + 1]) != -52)
	{
		x = getdigit(buff[i]) * 10 + getdigit(buff[i + 1]);
		buff_char[k] = x;
		i = i + 2;
		k++;
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (buff_char[i] == 'М')
		{
			buff_char[i] = '\0';
		}
	}
	i = 0;
	int j = 0;
	while(buff_char[i]!='\0')
	{
		if (buff_char[i] == ' ' || buff_char[i] == '\n')
		{
			current++;
		}
		if (current == num)
		{
			isFound = true;
			int o = 0;
			j = i;
			if (num != 1)
			{
				j = i + 1;
			}
			while (buff_char[j] != ' '&&buff_char[j] != '\n')
			{
				nums_char[o] = buff_char[j];
				o++;
				j++;
			}
			nums_char[o + 1] = '\0';
			o = 0;
			while (nums_char[o] != '\0')
			{
				size++;
				o++;
			}
			o = 0;
			while (nums_char[o] != '\0')
			{
				nums = nums + getdigit(nums_char[o])*pow(10, size - 1);
				size--;
				o++;
			}
			i = j-1;
		}
		i++;
	}
	if (!isFound)
	{
		return 2000;
	}
	else
	{
		return nums;
	}
}

int main()
{
	char sym = ' ';
	char name[SIZE] = "";
	char nums[SIZE] = "";
	bool isNewline = false;
	setlocale(LC_ALL,"rus"); 
	system("cls");
	int menu;
	cin >> menu;
	switch (menu)
	{
		case 1:
			system("cls");
			cout << "Введите название файла без расширения на английском без точки. В случае ,если расширение будет введено, оно будет по умолчанию изменено на .txt. В случае, если будет введена точка, она и все за ней будет заменено на '.txt'"<< endl;
			cin>>name;
			for (int i = 0; i < 100; i++)
			{
				if (name[i] =='.')
				{
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
				else if (name[i] == '\0')
				{
					name[i] = '.';
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
			}
			create(name);
			cout << "Файл ";
			for (int i = 0; i < sizeof(name); i++)
			{
				cout << name[i];
			}
			cout << " был создан" << endl;
			system("pause");
			main();
		break;
		case 2:
			cout << "Введите название файла без расширения на английском без точки. В случае ,если расширение будет введено, оно будет по умолчанию изменено на .txt. В случае, если будет введена точка, она и все за ней будет заменено на '.txt'" << endl;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name[i] == '.')
				{
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
				else if (name[i] == '\0')
				{
					name[i] = '.';
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
			}
			if (check(name) != 1)
			{
				cout << "Такого файла не существует. Если Вы хотите создать файл, воспользуйтесь 1 пунктом меню" << endl;
				system("pause");
				main();
			}
			else
			{
				cout << "Проверка наличия файла пройдена успешно" << endl;
				system("pause");
				system("cls");
				cout << "1-Заполнение вручную\n2-автоматическое заполнение" << endl;
				int n;
				cin >> n;
				switch (n)
				{
				case 1:
					cout << "Введите символы. Разделяйте числа запятой. Переход на новую строку - символ ';' Максимальное число - 1000" << endl;
					cin >> nums;
					for (int i = 0; i < SIZE; i++)
					{
						if (getdigit(nums[i]) >= 1 && getdigit(nums[i + 1]) >= 0 && getdigit(nums[i + 2]) >= 0 && getdigit(nums[i + 3]) >= 0)
						{
							cout << "Неправильная последовательность" << endl;
							system("pause");
							main();
						}
						if (isdigit(nums[i]))
						{
							if (nums[i + 1] != ',' && nums[i + 1] != ';' && nums[i + 1] != '\0' && !(isdigit(nums[i + 1])))
							{
								cout << "Неправильная последовательность" << endl;
								system("pause");
								main();
							}
						}
						else if (nums[i] == ',' || nums[i] == ';')
						{
							if (!(isdigit(nums[i + 1])))
							{
								cout << "Неправильная последовательность" << endl;
								system("pause");
								main();
							}
						}
						else if (nums[0] == '\0')
						{
							cout << "Неправильная последовательность" << endl;
							system("pause");
							main();
						}
						else if (nums[i] == '\0' && nums[i + 1] == '\0')
						{
							break;
						}
					}
					for (int i = 0; i < SIZE; i++)
					{
						if (nums[i] == ',')
						{
							nums[i] = ' ';
						}
						else if (nums[i] == ';')
						{
							nums[i] = '\n';
						}
					}
					break;
				case 2:
					int num;
					for (int i = 0; i < 100; i++)
					{
						num = 0 + rand() % (1001 - 0 + 1);
						if (num < 10)
						{
							nums[i] = getdigit(num);
							nums[i + 1] = ' ';
							i = i + 1;
							isNewline = false;
						}
						else if (num > 9 && num < 100)
						{
							nums[i + 1] = getdigit(num % 10);
							nums[i] = getdigit(num / 10);
							nums[i + 2] = ' ';
							i = i + 2;
							isNewline = false;
						}
						else if (num > 99 && num < 400)
						{
							nums[i + 2] = getdigit(num % 10);
							num = num / 10;
							nums[i + 1] = getdigit(num % 10);
							nums[i] = getdigit(num / 10);
							nums[i + 3] = ' ';
							i = i + 3;
							isNewline = false;
						}
						else if (num > 399)
						{
							if (!isNewline)
							{
								if (nums[i - 1] == ' ')
								{
									nums[i - 1] = '\n';
									i = i - 1;
								}
								else
								{
									nums[i] = '\n';
								}
								isNewline = true;
							}
							else
							{
								i = i - 1;
							}
						}

					}
					nums[100] = '\0';
					break;
				default:
					cout << "Ошибка" << endl;
					system("pause");
					main();
					break;
				}
				cout <<endl<< "Файл заполнится следующими числами" << endl;
				for (int i = 0; i < SIZE; i++)
				{
					cout << nums[i];
				}
				cout << endl;
				system("pause");
				fill_file(name, nums,0);
				cout << endl<<"Файл успешно заполнен" << endl;
				system("pause");
				main();
			}
		break;
		case 3:
			cout << "Введите название файла без расширения на английском без точки. В случае ,если расширение будет введено, оно будет по умолчанию изменено на .txt. В случае, если будет введена точка, она и все за ней будет заменено на '.txt'" << endl;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name[i] == '.')
				{
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
				else if (name[i] == '\0')
				{
					name[i] = '.';
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
			}
			if (check(name) != 1)
			{
				cout << "Такого файла не существует. Если Вы хотите создать файл, воспользуйтесь 1 пунктом меню" << endl;
				system("pause");
				main();
			}
			else
			{
				char* nums_return = new char[200];
				nums_return = output_str(name);
				for (int i = 0; i < 200; i++)
				{
					cout << nums_return[i];
				}
				cout << endl;
				system("pause");
				main();
			}
		break;
		case 4:
			cout << "Введите название файла без расширения на английском без точки. В случае ,если расширение будет введено, оно будет по умолчанию изменено на .txt. В случае, если будет введена точка, она и все за ней будет заменено на '.txt'" << endl;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name[i] == '.')
				{
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
				else if (name[i] == '\0')
				{
					name[i] = '.';
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
			}
			if (check(name) != 1)
			{
				cout << "Такого файла не существует. Если Вы хотите создать файл, воспользуйтесь 1 пунктом меню" << endl;
				system("pause");
				main();
			}
			else
			{
				cout << "Проверка пройдена успешно" << endl;
				system("pause");
				system("cls");
				cout << "Введите числа, которые надо добавить в файл"<<endl;
				cout << "Разделяйте числа запятой" << endl;
				cin >> nums;
				for (int i = 0; i < SIZE; i++)
				{
					if (isdigit(nums[i]))
					{
						if (nums[i + 1] != ',' && nums[i + 1] == ';' && nums[i + 1] != '\0' && !(isdigit(nums[i + 1])))
						{
							cout << "Неправильная последовательность" << endl;
							system("pause");
							main();
						}
					}
					else if (nums[i] == ',')
					{
						if (!(isdigit(nums[i + 1])))
						{
							cout << "Неправильная последовательность" << endl;
							system("pause");
							main();
						}
					}
					else if (nums[0] == '\0')
					{
						cout << "Неправильная последовательность" << endl;
						system("pause");
						main();
					}
					else if (nums[i] == '\0' && nums[i + 1] == '\0')
					{
						break;
					}
				}
				for (int i = 0; i < SIZE; i++)
				{
					if (nums[i] == ',')
					{
						nums[i] = ' ';
					}
				}
				fill_file(name, nums,1);
				cout << "Строки успешно добавлены" << endl;
				system("pause");
				main();
			}
		break;
		case 5:
			cout << "Введите название файла без расширения на английском без точки. В случае ,если расширение будет введено, оно будет по умолчанию изменено на .txt. В случае, если будет введена точка, она и все за ней будет заменено на '.txt'" << endl;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name[i] == '.')
				{
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
				else if (name[i] == '\0')
				{
					name[i] = '.';
					name[i + 1] = 't';
					name[i + 2] = 'x';
					name[i + 3] = 't';
					break;
				}
			}
			if (check(name) != 1)
			{
				cout << "Такого файла не существует. Если Вы хотите создать файл, воспользуйтесь 1 пунктом меню" << endl;
				system("pause");
				main();
			}
			else
			{
				cout << "Проверка пройдена успешно" << endl;
				system("pause");
				system("cls");
				cout << "Введите номер элемента для поиска" << endl;
				int n;
				cin >> n;
				if (n < 1)
				{
					cout << "Номер элемента не может быть меньше 1" << endl;
					system("pause");
					main();
				}
				else
				{
					int num = find(name, n);
					if (num == 2000)
					{
						cout << "Элемента с таким номером не существует" << endl;
						system("pause");
						main();
					}
					else
					{
						cout << "Элемент файла под номером " << n << " это - " << num << endl;
					}
					system("pause");
					main();
				}
			}
		break;
		case 6:
		break;
		case 9:
			cout << "Are you sure want to exit? Print y/n" << endl;
			cin >> sym;
			if (sym == 'y')
			{
				exit(0);
			}
			else if (sym == 'n')
			{
				main();
			}
			else
			{
				cout << "error answer. Return to menu"<<endl;
				system("pause");
				main();
			}
		break;
		default:
			cout << "Are you sure want to exit? Print y/n" << endl;
			cin >> sym;
			if (sym == 'y')
			{
				exit(0);
			}
			else if (sym == 'n')
			{
				main();
			}
			else
			{
				cout << "error answer. Return to menu" << endl;
				system("pause");
				main();
			}
		break;
	}


	system("pause");
}