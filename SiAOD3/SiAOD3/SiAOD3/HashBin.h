#pragma once
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
struct TypeItembin
{
	long long int key = 0;
	string offset = "null";
	string offset2 = "null";
	int offset3 = 0;
	bool openOrClose = true;
	bool deleteOrnot = false;
};
struct HashTablebin
{
	int L;
	TypeItembin *T;
	int insertedCount;
	int deletedCount;
	void CreateHashTable(int k)
	{
		T = new TypeItembin[k];
		L = k;
		insertedCount = 0;
		deletedCount = 0;
	}
};
int InsertInHashTable(long long int key, string offset[], HashTablebin& t);
int search(HashTablebin& t, long long int key);
int reHash(HashTablebin& old)
{
	int size = old.L;
	size = size + 10;
	HashTablebin new_hash;
	string data[3];
	new_hash.CreateHashTable(size);
	for (int i = 0; i < size - 10; i++)
	{
		if (old.T[i].key != 0)
		{
			data[0] = old.T[i].offset;
			data[1] = old.T[i].offset2;
			data[2] = to_string(old.T[i].offset3);
			InsertInHashTable(old.T[i].key, data, new_hash);
			int t = search(new_hash,old.T[i].key);
			new_hash.T[t].deleteOrnot = old.T[i].deleteOrnot;
			new_hash.T[t].openOrClose = old.T[i].openOrClose;
		}
	}
	old = new_hash;
	return 1;
}
int Hash(long long int k, int L, int iter)
{
	int h2 = k % (L / 2 + 1);
	if (h2 == 0)
	{
		h2++;
	}
	return k%L + iter*h2;
}
int InsertInHashTable(long long int key, string offset[], HashTablebin& t)
{
	if (t.insertedCount >= t.L*0.75)
	{
		reHash(t);
	}
	int iteration = 0;
	int i = Hash(key, t.L, iteration);
	while (i < t.L&&t.T[i].openOrClose == false)
	{
		iteration++;
		i = Hash(key, t.L, iteration);
	}
	while (i > t.L)
	{
		reHash(t);
		while (i < t.L&&t.T[i].openOrClose == false)
		{
			iteration++;
			i = Hash(key, t.L, iteration);
		}
	}
	if (i < t.L)
	{

		t.T[i].key = key;
		t.T[i].offset = offset[0];
		t.T[i].offset2 = offset[1];
		t.T[i].offset3 = stoi(offset[2]);
		t.T[i].openOrClose = false;
		t.insertedCount++;
		return 0;
	}
	else
	{
		return 1;
	}
}
void outTable(HashTablebin& t)
{
	cout << "номер" << '\t' << "ISBN" << '\t' << '\t' << "Имя автора" << '\t' << "Название" << '\t' << "Год выпуска" << '\t' << "свободен" << '\t' << "удален" << '\n';
	for (int i = 0; i < t.L; i++)
	{
		if (t.T[i].key == 0)
		{
			cout << i << '\t' << t.T[i].key << '\t' << '\t' << t.T[i].offset << '\t' << '\t' << t.T[i].offset2 << '\t' << '\t' << t.T[i].offset3 << '\t' << '\t' << t.T[i].openOrClose << '\t' << '\t' << t.T[i].deleteOrnot << '\n';
		}
		else
		{
			cout << i << '\t' << t.T[i].key << '\t' << t.T[i].offset << '\t' << '\t' << t.T[i].offset2 << '\t' << '\t' << t.T[i].offset3 << '\t' << '\t' << t.T[i].openOrClose << '\t' << '\t' << t.T[i].deleteOrnot << '\n';
		}
	}
}
int search(HashTablebin& t, long long int key)
{
	int iterator = 0;
	int i = Hash(key, t.L, iterator);
	while (i < t.L && ((t.T[i].openOrClose == false && t.T[i].deleteOrnot == false) || (t.T[i].openOrClose == true && t.T[i].deleteOrnot == true)) && t.T[i].key != key)
	{
		iterator++;
		i = Hash(key, t.L, iterator);
	}
	if (t.T[i].openOrClose == true && t.T[i].deleteOrnot == false)
	{
		return -1;
	}
	return i;
}
Book getISBN(HashTablebin& t, int i)
{
	Book book;
	book.ISBN = 0;
	for (int l = 0; l < 50; l++)
	{
		book.fam[l] = '\0';
		book.name[l] = '\0';
	}
	book.year = 0;
	if (t.T[i].key != 0)
	{
		book.ISBN = t.T[i].key;
		strcpy(book.fam, t.T[i].offset.c_str());
		strcpy(book.name, t.T[i].offset2.c_str());
		book.year = t.T[i].offset3;
	}
	return book;
}
int deleteFromHashTable(HashTablebin& t, long long int key)
{
	int i = search(t, key);
	if (i == -1)
	{
		return 1;
	}
	else
	{
		t.T[i].key = 0;
		t.T[i].offset = "null";
		t.T[i].offset2 = "null";
		t.T[i].offset3 = 0;
		t.T[i].deleteOrnot = true;
		t.T[i].openOrClose = true;
		t.deletedCount++;
		return 0;
	}
}
int ReadBin(HashTablebin& t, ifstream& bin_file)
{
	Book book;
	string data[3];
	bool isGood = true;
	while (true)
	{
		bin_file.read((char*)&book, sizeof(book));
		if (!bin_file.eof())
		{
			data[0] = book.fam;
			data[1] = book.name;
			data[2] = to_string(book.year);
			if (InsertInHashTable(book.ISBN, data, t) != 0)
			{
				isGood = false;
			}
		}
		else
		{
			if (isGood)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
}
int WriteBin(HashTablebin& t, ofstream& bin_file)
{
	Book book;
	int i = 0;
	while (i<t.L)
	{
		book = getISBN(t, i);
		if (book.ISBN != 0)
		{
			bin_file.write((char*)&book, sizeof(Book));
		}
		i++;
	}
	return 0;
}
//----------------------------------------
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

void txt_to_bin(ifstream& txt_file, ofstream& bin_file)
{
	Book book;
	while (true)
	{
		txt_file >> book.ISBN;
		if (!txt_file.eof())
		{
			txt_file >> book.fam >> book.name >> book.year;
			bin_file.write((char*)&book, sizeof(Book));
		}
		else break;
	}

}
void AddToBin(ofstream& bin_file, Book book)
{
	bin_file.write((char*)&book, sizeof(Book));
}

void bin_to_txt(ifstream& bin_file, ofstream& txt_file)
{

	Book book;
	while (true)
	{
		bin_file.read((char*)&book, sizeof(book));
		if (!bin_file.eof())
		{
			txt_file << book.ISBN << " " << book.fam << " " << book.name << " " << book.year << " ";
		}
		else
		{
			break;
		}
	}
}

void print_bin(ifstream& bin_file)
{
	Book book;
	while (true)
	{
		bin_file.read((char*)&book, sizeof(book));
		if (!bin_file.eof())
		{
			cout << book.ISBN << ' ' << book.fam << ' ' << book.name << ' ' << book.year << '\n';
		}
		else break;
	}
}

Book get_struct(string filename, int position)
{
	Book book;
	ifstream bin_file(filename, ios::binary | ios::in);
	if (position == -1)
	{
		bin_file.seekg(-1 * (int)sizeof(book), ios::end);
	}
	else
	{
		bin_file.seekg((position) * sizeof(book));
	}
	bin_file.read((char*)&book, sizeof(Book));
	bin_file.close();
	return book;
}

void remove_struct(string bin_name, long long key)
{

	Book book, replace{};
	replace = get_struct(bin_name, -1);
	ifstream bin_file(bin_name, ios::binary | ios::in);
	ofstream tmp("tmp_rem.txt");
	while (true) {
		bin_file.read((char*)&book, sizeof(book));

		if (!bin_file.eof())
		{
			if (book.ISBN != key)
			{
				tmp << book.ISBN << " " << book.fam << " " << book.name << " " << book.year << "\n";
			}
			else
			{
				tmp << replace.ISBN << " " << replace.fam << " " << replace.name << " " << replace.year << "\n";
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