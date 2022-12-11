#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int i = 0;
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
	int offset = 0;
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
int InsertInHashTable(long long int key, int offset, HashTablebin& t);
int search(HashTablebin& t, long long int key);
int reHash(HashTablebin& old)
{
	int size = old.L;
	size = size + 10;
	HashTablebin new_hash;
	new_hash.CreateHashTable(size);
	for (int i = 0; i < size - 10; i++)
	{
		if (old.T[i].key != 0)
		{
			InsertInHashTable(old.T[i].key, old.T[i].offset, new_hash);
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
	long long int h1;
	if (k % 2 == 0)
	{
		h1 = k << 2 % 9;
	}
	else
	{
		h1 = 9 % k << 2;
	}
	h1++;
	long long int h2;
	if (h1 % 2 == 0)
	{
		h2 = h1 % 7;
	}
	else
	{
		h2 = 7 % h1;
	}
	h2++;
	return (h1 + iter*h2) % L;
}
int InsertInHashTable(long long int key, int offset, HashTablebin& t)
{
	if (t.insertedCount >= t.L*0.75)
	{
		reHash(t);
	}
	int iteration = 0;
	int i = Hash(key, t.L, iteration);
	while (i < t.L&&t.T[i].openOrClose == false)
	{
		if (iteration > t.L)
		{
			reHash(t);
		}
		iteration++;
		i = Hash(key, t.L, iteration);
	}
	while (i > t.L)
	{
		return -1;
	}
	if (i < t.L)
	{

		t.T[i].key = key;
		t.T[i].offset = offset;
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
	cout << "номер" << '\t' << "ISBN" << '\t' << '\t' << "Номер записи" << '\t' << "свободен" << '\t' << "удален" << '\n';
	for (int i = 0; i < t.L; i++)
	{
		if (t.T[i].key == 0)
		{
			cout << i << '\t' << t.T[i].key << '\t' << '\t' << t.T[i].offset << '\t'<<'\t' << t.T[i].openOrClose << '\t' << '\t' << t.T[i].deleteOrnot << '\n';
		}
		else
		{
			cout << i << '\t' << t.T[i].key << '\t' << t.T[i].offset << '\t' << '\t' << t.T[i].openOrClose << '\t' << '\t' << t.T[i].deleteOrnot << '\n';
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
	return t.T[i].offset;
}
void find(int i, ifstream& file)
{
	Book book;
	file.seekg(i*sizeof(Book),ios::beg);
	file.read((char*)&book, sizeof(book));
	cout << book.ISBN << ' ' << book.fam << ' ' << book.name <<' '<<book.year << '\n';
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
		t.T[i].offset = 0;
		t.T[i].deleteOrnot = true;
		t.T[i].openOrClose = true;
		t.deletedCount++;
		return 0;
	}
}
int ReadBin(HashTablebin& t, ifstream& bin_file)
{
	Book book;
	bool isGood = true;
	while (true)
	{
		bin_file.read((char*)&book, sizeof(book));
		if (!bin_file.eof())
		{
			if (InsertInHashTable(book.ISBN, i, t) != 0)
			{
				isGood = false;
			}
			i++;
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
			txt_file >> book.fam >> book.name>>book.year;
			bin_file.write((char*)&book, sizeof(Book));
		}
		else break;
	}

}
void AddToBin(ofstream& bin_file, Book book, HashTablebin& t)
{
	bin_file.seekp(0,ios::end);
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
			txt_file << book.ISBN << " " << book.fam << " " << book.name  << " "<<book.year<<" ";
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
			cout << book.ISBN << ' ' << book.fam << ' ' << book.name  <<' '<<book.year<< '\n';
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
	while (true)
	{
		bin_file.read((char*)&book, sizeof(book));

		if (!bin_file.eof())
		{
			if (book.ISBN != key)
			{
				tmp << book.ISBN << " " << book.fam << " " << book.name <<" "<<book.year<< "\n";
			}
			else
			{
				tmp << replace.ISBN << " " << replace.fam << " " << replace.name << "\n";
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