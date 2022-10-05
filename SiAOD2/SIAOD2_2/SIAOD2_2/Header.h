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
	//int gr_num; //example: 1234 or etc
	//char sub_name[10]; //example: math or phys or armv or tfya or ciod
	//int les_num;    //example: 1 or 2 ... or 6
	//int week_num;   //example: 1 or 2 .. or 17
	//int day_num;    //example: 1 or 2 .. or 7
	//char sub_type[10]; //example: lec or prc or lab
	//int class_num; //example: 123 or 2953 or etc
};
int line_counter(ifstream& file)
{
	string num_string = "";
	int counter = 1;
	while (!file.eof())
	{
		while (getline(file, num_string))
		{
			counter++;
		}
	}
	return counter;
}

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

void new_cab(string name_file)// 7 задание
{ 
	/*fstream old_sch(name_file, ios::binary | ios::out | ios::in);
	ofstream tmp("tmp_sch.txt");
	old_sch.seekg(0, ios::end);
	int size = old_sch.tellg();
	size = size / sizeof(Book);
	old_sch.seekg(0, ios::beg);
	Book* tts = new Book[size];
	Book tt;
	int flag;
	old_sch.read((char*)tts, sizeof(Book) * size);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if ((tts[j].les_num == tts[i].les_num) && (tts[j].class_num == tts[i].class_num))
			{

				tts[j].class_num = tts[j].class_num + 1;
				tmp << tts[j].gr_num << " " << tts[j].sub_name << " " << tts[j].les_num << " " << tts[j].week_num
					<< " " << tts[j].day_num << " " << tts[j].sub_type << " " << tts[j].class_num << "\n";
				continue;
			}
		}
		tmp << tts[i].gr_num << " " << tts[i].sub_name << " " << tts[i].les_num << " " << tts[i].week_num
			<< " " << tts[i].day_num << " " << tts[i].sub_type << " " << tts[i].class_num << "\n";
	}
	tmp.close();
	old_sch.close();
	ifstream txt("tmp_sch.txt", ios::in);
	ofstream bin(name_file, ios::binary);
	txt_to_bin(txt, bin);
	txt.close();
	bin.close();*/
}

#endif //SIAOD_HEAD_2_2_H
