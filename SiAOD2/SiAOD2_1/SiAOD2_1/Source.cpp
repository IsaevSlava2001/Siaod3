#include <iostream>
#include <random>
#include <fstream>
#define SIZE 200

using namespace std;
/*���������� ����� � ���� ������
���������:
0-����� int*/
char getdigit(int num)
{
	char dig[10] = { '0','1','2','3','4','5','6','7','8','9' };
	return dig[num];
}
/*���������� ����� � ���� int
���������:
0-����� char*/
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
/*������� ����.
���������:
0-��� �����*/
void create(char name[])
{
	ofstream file;
	file.open(name);
	file.close();
}
/*��������� ���� ������� � ��������� � ��������� ASCII.
���������:
0-��� �����,
1-������ ����� char*/
void fill_file(char name[], char nums[])
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
/*���������, ���������� �� ����. ���� ��, ���������� 1, ����� 0.
���������:
0-��� �����*/
int check(char name[])
{
	bool isExist = false;
	ifstream fin(name);

	if (fin.is_open())
		isExist = true;

	fin.close();
	return isExist;
}
/*������ ���������� ���������� ����� � ��������� ASCII, ��������� ��� � �������� �����. ���������� ������ char
���������:
0-��� �����*/
char *output_str(char name[])
{
	char buff[400];
	char *buff_char = new char[200] {'\0'};
	ifstream fin(name); 
	fin.getline(buff, 400);
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

	return buff_char;
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
			cout << "������� �������� ����� ��� ���������� �� ���������� ��� �����. � ������ ,���� ���������� ����� �������, ��� ����� �� ��������� �������� �� .txt. � ������, ���� ����� ������� �����, ��� � ��� �� ��� ����� �������� �� '.txt'"<< endl;
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
			cout << "���� ";
			for (int i = 0; i < sizeof(name); i++)
			{
				cout << name[i];
			}
			cout << " ��� ������" << endl;
			system("pause");
			main();
		break;
		case 2:
			cout << "������� �������� ����� ��� ���������� �� ���������� ��� �����. � ������ ,���� ���������� ����� �������, ��� ����� �� ��������� �������� �� .txt. � ������, ���� ����� ������� �����, ��� � ��� �� ��� ����� �������� �� '.txt'" << endl;
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
				cout << "������ ����� �� ����������. ���� �� ������ ������� ����, �������������� 1 ������� ����" << endl;
				system("pause");
				main();
			}
			else
			{
				cout << "�������� ������� ����� �������� �������" << endl;
				system("pause");
				system("cls");
				cout << "1-���������� �������\n2-�������������� ����������" << endl;
				int n;
				cin >> n;
				switch (n)
				{
				case 1:
					cout << "������� �������. ���������� ����� �������. ������� �� ����� ������ - ������ ';'" << endl;
					cin >> nums;
					for (int i = 0; i < SIZE; i++)
					{
						if (isdigit(nums[i]))
						{
							if (nums[i + 1] != ',' && nums[i + 1] != ';' && nums[i + 1] != '\0' && !(isdigit(nums[i + 1])))
							{
								cout << "������������ ������������������" << endl;
								system("pause");
								main();
							}
						}
						else if (nums[i] == ',' || nums[i] == ';')
						{
							if (!(isdigit(nums[i + 1])))
							{
								cout << "������������ ������������������" << endl;
								system("pause");
								main();
							}
						}
						else if (nums[0] == '\0')
						{
							cout << "������������ ������������������" << endl;
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
					cout << "������" << endl;
					system("pause");
					main();
					break;
				}
				cout <<endl<< "���� ���������� ���������� �������" << endl;
				for (int i = 0; i < SIZE; i++)
				{
					cout << nums[i];
				}
				cout << endl;
				system("pause");
				fill_file(name, nums);
				cout << endl<<"���� ������� ��������" << endl;
				system("pause");
				main();
			}
		break;
		case 3:
			cout << "������� �������� ����� ��� ���������� �� ���������� ��� �����. � ������ ,���� ���������� ����� �������, ��� ����� �� ��������� �������� �� .txt. � ������, ���� ����� ������� �����, ��� � ��� �� ��� ����� �������� �� '.txt'" << endl;
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
				cout << "������ ����� �� ����������. ���� �� ������ ������� ����, �������������� 1 ������� ����" << endl;
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