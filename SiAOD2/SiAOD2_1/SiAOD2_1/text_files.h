#pragma once
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
				file << nums[i];
				i++;
			}
		}
		file.close();
	}
	else if (fill == 1)
	{
		int i = 0;
		ofstream file;
		file.open(name, ios::app);
		if (file.is_open())
		{
			char n = '\n';
			file << n;
			while (nums[i] != '\0')
			{
				file << nums[i];
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
	char *buff_char = new char[200]{ '\0' };
	ifstream fin(name);
	char ch;
	int i = 0;
	do
	{
		ch = fin.get(); 
		if (ch == '\n')
		{
			buff_char[i] = '\n';
		}
		else if (getdigit(ch) == -1)
		{
			break;
		}
		else
		{
			buff_char[i] = ch;
		}
		i++;
		
	} while (getdigit(ch) != -1);
	buff_char[i + 1] = '\0';
	fin.close();
	return buff_char;
}
/*ищет число в файле по его момеру. Возвращает char. Если номер находится вне границ файла, возвращает 2000
аргументы:
0-имя файла
1-номер символа*/
int find(char name[], int num)
{
	char buff_char[200];
	char nums_char[200] = { '\0' };
	int nums = 0;
	ifstream fin(name);
	int i = 0;
	char ch;
	do
	{
		ch = fin.get();
		if (ch == '\n')
		{
			buff_char[i] = '\n';
		}
		else if (getdigit(ch) == -1)
		{
			break;
		}
		else
		{
			buff_char[i] = ch;
		}
		i++;

	} while (getdigit(ch) != -1);
	int current = 1;
	int size = 0;
	bool isFound = false;
	fin.close();
	i = 0;
	i = 0;
	int j = 0;
	while (buff_char[i] != '\0')
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
			i = j - 1;
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
/*Возвращает количество чисел в файле
аргументы:
0-имя файла*/
int count_nums(char name[])
{
	char* buff_char = new char[200];
	buff_char = output_str(name);
	int k = 0;
	int count = 1;
	int i = 0;
	while (buff_char[i] != '\0')
	{
		if (buff_char[i] == ' ' || buff_char[i] == '\n')
		{
			count++;
		}
		i++;
	}
	return count;
}
/*Создает новый файл, меняя первый и последний символ местами
Аргументы:
0-имя исходного файла*/
void reverse_file(char name[])
{
	char* nums_return = new char[200];
	nums_return = output_str(name);
	char new_mass[200] = { '\0' };
	int i = 0;
	int num[200];
	int cur_size = 0;
	int j = 0;
	char cur_num[200] = { '\0' };
	int temp = 0;
	int pos_temp = 0;
	int temp1 = 0;
	int pos_temp1 = 0;
	int count = count_nums(name);
	while (nums_return[i] != '\0')
	{
		i++;
	}
	i--;
	j = i;
	while (nums_return[j] != ' ' && nums_return[j] != '\n')
	{
		j--;
	}
	pos_temp = j;
	int size = i - j;
	for (j; j <= i - 1; j++)
	{
		temp = temp + getdigit(nums_return[j + 1]) * pow(10, size - 1);
		size--;
	}
	i = 0;
	j = i;
	while (nums_return[j] != ' ' && nums_return[j] != '\n')
	{
		j++;
	}
	size = j;
	pos_temp1 = j;
	for (i; i < j; i++)
	{
		temp1 = temp1 + getdigit(nums_return[i]) * pow(10, size - 1);
		size--;
	}
	i = 0;
	if (temp < 10)
	{
		new_mass[i] = getdigit(temp);
		new_mass[i + 1] = ' ';
		i = i + 1;

	}
	else if (temp > 9 && temp < 100)
	{
		new_mass[i + 1] = getdigit(temp % 10);
		new_mass[i] = getdigit(temp / 10);
		new_mass[i + 2] = ' ';
		i = i + 2;

	}
	else if (temp > 99 && temp < 400)
	{
		new_mass[i + 2] = getdigit(temp % 10);
		temp = temp / 10;
		new_mass[i + 1] = getdigit(temp % 10);
		new_mass[i] = getdigit(temp / 10);
		new_mass[i + 3] = ' ';
		i = i + 3;

	}
	i++;
	for (int k = i; k < pos_temp+1; k++)
	{
		new_mass[k] = nums_return[pos_temp1 + 1];
		pos_temp1++;
	}
	if (temp1 < 10)
	{
		pos_temp1++;
		pos_temp1++;
		new_mass[pos_temp1] = ' ';
		pos_temp1++;
	}
	else
	{
		pos_temp1++;
	}
	if (temp1 < 10)
	{
		new_mass[pos_temp1] = getdigit(temp1);

	}
	else if (temp1 > 9 && temp1 < 100)
	{
		new_mass[pos_temp1 + 1] = getdigit(temp1 % 10);
		new_mass[pos_temp1] = getdigit(temp1 / 10);

	}
	else if (temp1 > 99 && temp1 < 400)
	{
		new_mass[pos_temp1 + 2] = getdigit(temp1 % 10);
		temp1 = temp1 / 10;
		new_mass[pos_temp1 + 1] = getdigit(temp1 % 10);
		new_mass[pos_temp1] = getdigit(temp1 / 10);

	}
	i = 0;
	char new_name[200];
	while (name[i] != '.')
	{
		new_name[i] = name[i];
		i++;
	}
	i--;
	new_name[i + 1] = '_'; new_name[i + 2] = 'r'; new_name[i + 3] = 'e'; new_name[i + 4] = 'v'; new_name[i + 5] = 'e'; new_name[i + 6] = 'r'; new_name[i + 7] = 's'; new_name[i + 8] = 'e'; new_name[i + 9] = '.'; new_name[i + 10] = 't'; new_name[i + 11] = 'x'; new_name[i + 12] = 't'; new_name[i + 13] = '\0';
	fill_file(new_name, new_mass, 0);

}