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
};
class BinFile
{
public:
	static int txt_to_bin(string txt_file, string bin_file);
	static Book get_class(string filename, int position);
	static void AddToBin(ofstream& bin_file, Book book);
	static Book linear_search(string txt_file, long long int key);
	static long long int* getISBN(string txt_file);

};
