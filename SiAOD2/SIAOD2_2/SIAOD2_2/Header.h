#ifndef SIAOD_HEAD_2_2_H
#define SIAOD_HEAD_2_2_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book
{
	long long int ISBN;
	char fam[50];
	char name[50];
	int year;
};

void txt_to_bin(ifstream& txt_file, ofstream& bin_file)// 1 задание
{ 
	Book tt;
	while (true)
	{
		txt_file >> tt.ISBN;
		if (!txt_file.eof())
		{
			txt_file >> tt.fam >> tt.name >> tt.year;
			bin_file.write((char*)&tt, sizeof(Book));
		}
		else break;
	}

}

void bin_to_txt(ifstream& bin_file, ofstream& txt_file)// 2 задание Проверка на существование;
{ 
														  
	Book tt;
	while (true)
	{
		bin_file.read((char*)&tt, sizeof(tt));
		if (!bin_file.eof())
		{
			txt_file << tt.ISBN << " " << tt.fam << " " << tt.name << " " << tt.year<< " ";
		}
		else
		{
			break;
		}
	}
}

void print_bin(ifstream& bin_file)// 3 задание
{            
	Book tt;
	while (true)
	{
		bin_file.read((char*)&tt, sizeof(tt));
		if (!bin_file.eof())
		{
			cout << tt.ISBN << ' ' << tt.fam << ' ' << tt.name << ' ' << tt.year << '\n';
		}
		else break;
	}
}

Book get_struct(string filename, int position)// 4 задание
{
	Book tt;
	tt.ISBN = 0;
	ifstream bin_file(filename, ios::binary | ios::in);
		if (position == -1)
		{
			bin_file.seekg(-1*(int)sizeof(tt), ios::end);
		}
		else
		{
			bin_file.seekg((position) * sizeof(tt));
		}
		bin_file.read((char*)&tt, sizeof(Book));
		bin_file.close();
		return tt;
}

void remove_struct(string bin_name, long long key)// 5 задание
{ 

	Book tt, replace{};
	replace = get_struct(bin_name, -1);
	ifstream bin_file(bin_name, ios::binary | ios::in);
	ofstream tmp("tmp_rem.txt");
	while (true) {
		bin_file.read((char*)&tt, sizeof(tt));

		if (!bin_file.eof())
		{
			if (tt.ISBN != key)
			{
				tmp << tt.ISBN << " " << tt.fam << " " << tt.name << " " << tt.year<< "\n";
			}
			else
			{
				tmp << replace.ISBN << " " << replace.fam << " " << replace.name << " " << replace.year<< "\n";
			}
		}
		else
		{
			break;
		}
	}
	tmp.close();
	bin_file.close();
	ifstream txt("tmp_rem.txt", ios::in);
	ofstream bin(bin_name, ios::binary);
	txt_to_bin(txt, bin);
	txt.close();
	bin.close();
}

void new_file(ifstream& old_file, ofstream& new_file, string fam, int year)
{
	Book tt;
	while (true)
	{
		old_file.read((char*)&tt, sizeof(tt));
		if (!old_file.eof())
		{
			if (tt.fam == fam&&tt.year == year)
			{
				new_file.write((char*)&tt, sizeof(Book));
			}
		}
		else
		{
			break;
		}
	}
}
void delete_book(fstream& old_file, int year)// 6 задание
{    
	Book tt;
	ofstream tmp("tmp_delete.bin", ios::binary|ios::out);
	while (true)
	{
		old_file.read((char*)&tt, sizeof(tt));
		if (!old_file.eof())
		{
			if (tt.year != year)
			{
				tmp.write((char*)&tt, sizeof(tt));
			}
		}
		else
		{
			break;
		}
	}
}
#endif //SIAOD_HEAD_2_2_H
