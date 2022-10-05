#include <iostream>
#include <random>
#include <fstream>
#include "text_files.h"
#define SIZE 200

using namespace std;

int main()
{
	char sym = ' ';
	char name[SIZE] = "";
	char nums[SIZE] = "";
	bool isNewline = false;
	int iteration = 0;
	int y = 0;
	setlocale(LC_ALL,"rus"); 
	system("cls");
	int menu;
	bool isNew = true;
	if (isNew)
	{
		cout << "Добро пожаловать в программу для работы с текстовыми файлами." << endl;
	}
	cout << "Для выбора задания необходимо ввести номер задания. Любой номер, не указаный в списке отроет меню выхода.\n1-Создание текстового файла с пользовательским именем\n2-Заполнение файла числами в кодировке ASCII\n3-Вывод содержимого текстового файла\n4-Добавление новой строки в конец файла\n5-Получить число из файл по его порядковому номеру\n6-Опрееделение количества чисел в файле\n7-Создать новый файл из исходного, поменяв местами первое и последнее числа в файле" << endl;
	cin >> menu;
	switch (menu)
	{
		case 1:
			system("cls");
			cout << "1-Создание текстового файла с пользовательским именем" << endl;
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
			system("cls");
			cout << "2-Заполнение файла числами в кодировке ASCII" << endl;
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
					cout << "Введите символы. Разделяйте числа запятой. Переход на новую строку - символ ';' Максимальное число - 99" << endl;
					cin >> nums;
					for (int i = 0; i < SIZE; i++)
					{
						if ((getdigit(nums[i]) >= 1 && nums[i] != ','&&nums[i] != ';'&&nums[i ] != '\0') && (getdigit(nums[i + 1]) >= 0 && nums[i + 1] != ','&&nums[i + 1] != ';'&&nums[i + 1] != '\0') && (getdigit(nums[i + 2]) >= 0 && nums[i + 2] != ','&&nums[i + 2] != ';'&&nums[i + 2] != '\0'))
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
						else if (num > 99 && num < 500)
						{
							num = num / 10;
							nums[i + 1] = getdigit(num % 10);
							nums[i] = getdigit(num / 10);
							nums[i + 2] = ' ';
							i = i + 2;
							isNewline = false;
						}
						else if (num > 499)
						{
							if (iteration != 1)
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
						iteration++;
						y = i;
					}
					nums[y + 1] = '9';
					nums[y + 2] = '5';
					nums[103] = '\0';
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
			system("cls");
			cout << "3-Вывод содержимого текстового файла" << endl;
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
			system("cls");
			cout << "4-Добавление новой строки в конец файла" << endl;
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
				cout << "Разделяйте числа запятой. Максимальное число - 99" << endl;
				cin >> nums;
				for (int i = 0; i < SIZE; i++)
				{
					if ((getdigit(nums[i]) >= 1 && nums[i] != ','&&nums[i] != ';'&&nums[i] != '\0') && (getdigit(nums[i + 1]) >= 0 && nums[i + 1] != ','&&nums[i + 1] != ';'&&nums[i + 1] != '\0') && (getdigit(nums[i + 2]) >= 0 && nums[i + 2] != ','&&nums[i + 2] != ';'&&nums[i + 2] != '\0'))
					{
						cout << "Неправильная последовательность" << endl;
						system("pause");
						main();
					}
					if (isdigit(nums[i]))
					{
						if (nums[i + 1] != ',' && nums[i + 1] == ';' && nums[i + 1] != '\0' && !(isdigit(nums[i + 1])))
						{
							cout << "Неправильная последовательность" << endl;
							system("pause");
							main();
						}
					}
					else if (nums[i] == ',' || nums[i] != ';')
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
					else if (nums[i] == ';')
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
			system("cls");
			cout << "5-Получить число из файл по его порядковому номеру" << endl;
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
			system("cls");
			cout << "6-Определение количества чисел в файле" << endl;
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
				cout <<"В файле содержится "<< count_nums(name)<<" чисел" << endl;
				system("pause");
				main();
			}
		break;
		case 7:
			system("cls");
			cout << "7-Создать новый файл из исходного, поменяв местами первое и последнее числа в файле" << endl;
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
				reverse_file(name);
				cout << "Новый файл успешно создан. Открыть его вы можете, используя имя ";
				int i = 0;
				while (name[i] != '.')
				{
					cout << name[i];
					i++;
				}
				cout << "_reverse.txt" << endl;
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