#pragma once
#include <iostream>
#include <random>
#include <fstream>
#include "text_files.h"
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
1-������ ����� char
3-����� ���������� �����. ���� ���� ��� ����������, 1, ���� ���� ��� ������, 0*/
void fill_file(char name[], char nums[], int fill)
{
	if (fill == 0)
	{
		int pos_temp = 0;
		ofstream file;
		file.open(name);
		if (file.is_open())
		{
			while (nums[pos_temp] != '\0')
			{
				int x = nums[pos_temp];
				file << x;
				pos_temp++;
			}
		}
		file.close();
	}
	else if (fill == 1)
	{
		int pos_temp = 0;
		ofstream file;
		file.open(name, ios::app);
		if (file.is_open())
		{
			char n = '\n';
			int x = n;
			file << x;
			while (nums[pos_temp] != '\0')
			{
				int x = nums[pos_temp];
				file << x;
				pos_temp++;
			}
		}
		file.close();
	}
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
	char buff[600];
	char *buff_char = new char[200]{ '\0' };
	ifstream fin(name);
	fin.getline(buff, 600);
	fin.close();
	int pos_temp = 0;
	int k = 0;
	char x = ' ';
	while (getdigit(buff[pos_temp]) * 10 + getdigit(buff[pos_temp + 1]) != -52)
	{
		x = getdigit(buff[pos_temp]) * 10 + getdigit(buff[pos_temp + 1]);
		buff_char[k] = x;
		pos_temp = pos_temp + 2;
		k++;
	}
	for (int pos_temp = 0; pos_temp < SIZE; pos_temp++)
	{
		if (buff_char[pos_temp] == '�')
		{
			buff_char[pos_temp] = '\0';
		}
	}
	return buff_char;
}
/*���� ����� � ����� �� ��� ������. ���������� char. ���� ����� ��������� ��� ������ �����, ���������� 2000
���������:
0-��� �����
1-����� �������*/
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
	int pos_temp = 0;
	int k = 0;
	char x = ' ';
	while (getdigit(buff[pos_temp]) * 10 + getdigit(buff[pos_temp + 1]) != -52)
	{
		x = getdigit(buff[pos_temp]) * 10 + getdigit(buff[pos_temp + 1]);
		buff_char[k] = x;
		pos_temp = pos_temp + 2;
		k++;
	}
	for (int pos_temp = 0; pos_temp < SIZE; pos_temp++)
	{
		if (buff_char[pos_temp] == '�')
		{
			buff_char[pos_temp] = '\0';
		}
	}
	pos_temp = 0;
	int j = 0;
	while (buff_char[pos_temp] != '\0')
	{
		if (buff_char[pos_temp] == ' ' || buff_char[pos_temp] == '\n')
		{
			current++;
		}
		if (current == num)
		{
			isFound = true;
			int o = 0;
			j = pos_temp;
			if (num != 1)
			{
				j = pos_temp + 1;
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
			pos_temp = j - 1;
		}
		pos_temp++;
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
/*���������� ���������� ����� � �����
���������:
0-��� �����*/
int count_nums(char name[])
{
	char buff[600];
	char buff_char[200];
	char nums_char[200] = { '\0' };
	ifstream fin(name);
	fin.getline(buff, 600);
	int pos_temp = 0;
	int k = 0;
	int count = 1;
	fin.close();
	char x = ' ';
	while (getdigit(buff[pos_temp]) * 10 + getdigit(buff[pos_temp + 1]) != -52)
	{
		x = getdigit(buff[pos_temp]) * 10 + getdigit(buff[pos_temp + 1]);
		buff_char[k] = x;
		pos_temp = pos_temp + 2;
		k++;
	}
	for (int pos_temp = 0; pos_temp < SIZE; pos_temp++)
	{
		if (buff_char[pos_temp] == '�')
		{
			buff_char[pos_temp] = '\0';
		}
	}
	pos_temp = 0;
	while (buff_char[pos_temp] != '\0')
	{
		if (buff_char[pos_temp] == ' ' || buff_char[pos_temp] == '\n')
		{
			count++;
		}
		pos_temp++;
	}
	return count;
}
/*������� ����� ����, ����� ������ � ��������� ������ �������
���������:
0-��� ��������� �����*/
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
	j = i;
	while (nums_return[j] != ' ' && nums_return[j] != '\n')
	{
		j--;
	}
	pos_temp = j;
	int size = i - j - 1;
	for (j + 1; j < i - 1; j++)
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
	for (int k = i; k < pos_temp + 1; k++)
	{
		new_mass[k] = nums_return[pos_temp1 + 1];
		pos_temp1++;
	}
	pos_temp1++;
	pos_temp1++;
	new_mass[pos_temp1] = ' ';
	pos_temp1++;
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