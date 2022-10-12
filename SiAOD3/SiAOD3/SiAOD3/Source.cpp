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
struct TypeItem
{
	int key = 0;
	int offset = 0;
	bool openOrClose = true;
	bool deleteOrnot = false;
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

struct HashTable
{
	int L;
	TypeItem *T;
	int insertedCount;
	int deletedCount;
	void CreateHashTable(int k)
	{
		T = new TypeItem[k];
		L = k;
		insertedCount = 0;
		deletedCount = 0;
	}
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
int reHash(HashTable& old);
int reHash(HashTablebin& old);
int Hash(int k, int L, int iter)
{
	int h2 = k % (L / 2 + 1);
	if (h2 == 0)
	{
		h2++;
	}
	return k%L + iter*h2;
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
int InsertInHashTable(int key, int offset, HashTable& t)
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
		i= Hash(key, t.L, iteration);
	}
	while (i > t.L)
	{
		reHash(t);
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
void outTable(HashTable& t)
{
	cout << "номер" << '\t' << "ключ" << '\t' << "значение" << '\t' << "свободен" << '\t' << "удален" << '\n';
	for (int i = 0; i < t.L; i++)
	{
		cout << i << '\t' << t.T[i].key << '\t' << t.T[i].offset << '\t'<<'\t' <<t.T[i].openOrClose << '\t'<<'\t' << t.T[i].deleteOrnot << '\n';
	}
}
void outTable(HashTablebin& t)
{
	cout << "номер" << '\t' << "ключ" << '\t' << '\t' << "значение1" << '\t' << "значение2" << '\t' << "значение3" << '\t' << "свободен" << '\t' << "удален" << '\n';
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
int search(HashTable& t, int key)
{
	int iterator = 0;
	int i = Hash(key, t.L,iterator);
	while (i < t.L && ((t.T[i].openOrClose == false && t.T[i].deleteOrnot == false) || (t.T[i].openOrClose == true && t.T[i].deleteOrnot == true)) && t.T[i].key != key)
	{
		iterator++;
		i = Hash(key, t.L,iterator);
	}
	if (t.T[i].openOrClose == true && t.T[i].deleteOrnot == false)
	{
		return -1;
	}
	return i;
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
	Book tt;
	tt.ISBN = 0;
	for (int l = 0; l < 50; l++)
	{
		tt.fam[l] = '\0';
		tt.name[l] = '\0';
	}
	tt.year = 0;
	if (t.T[i].key != 0)
	{
		tt.ISBN = t.T[i].key;
		strcpy(tt.fam, t.T[i].offset.c_str());
		strcpy(tt.name, t.T[i].offset2.c_str());
		tt.year = t.T[i].offset3;
	}
	return tt;
}
int reHash(HashTable& old)
{
	int size = old.L;
	size = size + 10;
	HashTable new_hash;
	new_hash.CreateHashTable(size);
	for (int i = 0; i < size - 10; i++)
	{
		if (old.T[i].key != 0)
		{
			new_hash.T[i].deleteOrnot = old.T[i].deleteOrnot;
			new_hash.T[i].key = old.T[i].key;
			new_hash.T[i].offset = old.T[i].offset;
			new_hash.T[i].openOrClose = old.T[i].openOrClose;
		}
	}
	old = new_hash;
	return 1;
}
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
			new_hash.T[i].deleteOrnot = old.T[i].deleteOrnot;
			new_hash.T[i].key = old.T[i].key;
			new_hash.T[i].offset = old.T[i].offset;
			new_hash.T[i].offset2 = old.T[i].offset2;
			new_hash.T[i].offset3 = old.T[i].offset3;
			new_hash.T[i].openOrClose = old.T[i].openOrClose;
		}
	}
	old = new_hash;
	return 1;
}
int deleteFromHashTable(HashTable& t, int key)
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
	Book tt;
	string data[3];
	bool isGood=true;
	while (true)
	{
		bin_file.read((char*)&tt, sizeof(tt));
		if (!bin_file.eof())
		{
			data[0] = tt.fam;
			data[1] = tt.name;
			data[2] = to_string(tt.year);
			if (InsertInHashTable(tt.ISBN, data, t) != 0)
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
	Book tt;
	int i = 0;
	while (i<t.L)
	{
		tt=getISBN(t, i);
		if (tt.ISBN != 0)
		{
			bin_file.write((char*)&tt, sizeof(Book));
		}
		i++;
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL,"rus");
	HashTable T;
	T.CreateHashTable(19);
	InsertInHashTable(123, 0, T); 
	InsertInHashTable(12, 3, T);   
	InsertInHashTable(19, 1, T);   
	InsertInHashTable(9, 4, T);    
	InsertInHashTable(28, 2, T);  
	InsertInHashTable(142, 2, T);//5 _ 9
	outTable(T);
	TypeItem r;
	TypeItembin h;
	int i = search(T, 142);
	if (i != -1)
	{
		r = T.T[i];
		cout << "ключ\tзначение" << endl;
		cout << r.key << '\t' << r.offset << endl;
	}
	else
	{
		cout << "Запись не найдена" << endl;
	}
	i = deleteFromHashTable(T, 123);
	if (i == 0)
	{
		cout << "Запись удалена" << endl;;
	}
	else
	{
		cout << "Запись не найдена" << endl;
	}
	outTable(T);
	i = search(T, 142);
	if (i != -1)
	{
		cout << "ключ\tзначение" << endl;
		cout << r.key << '\t' << r.offset << endl;
	}
	else
	{
		cout << "Запись не найдена" << endl;
	}
	reHash(T);
	outTable(T);
	HashTablebin T1;
	T1.CreateHashTable(30);

	ifstream inp;
	inp.open("1.bin", ios::binary);
	if (ReadBin(T1, inp)==0)
	{
		cout << "Успешно вставлено" << endl;
	}
	else
	{
		cout << "Возникли ошибки" << endl;
	}
	outTable(T1);
	ofstream outp;
	outp.open("1_1.bin", ios::binary);
	if (WriteBin(T1, outp) == 0)
	{
		cout << "Успешно" << endl;
	}
	else
	{
		cout << "Возникли ошибки" << endl;
	}
	//514698532105
	i = search(T1, 514698532105);
	if (i != -1)
	{
		h = T1.T[i];
		cout << "ключ\tзначение" << endl;
		cout << h.key << '\t' << h.offset << endl;
	}
	else
	{
		cout << "Запись не найдена" << endl;
	}
	i = deleteFromHashTable(T1, 514698532105);
	if (i == 0)
	{
		cout << "Запись удалена" << endl;;
	}
	else
	{
		cout << "Запись не найдена" << endl;
	}
	outTable(T1);
	system("pause");
}