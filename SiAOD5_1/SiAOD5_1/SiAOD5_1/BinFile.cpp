#include "BinFile.h"

int BinFile::txt_to_bin(string txt_file, string bin_file)
{
	ifstream inp;
	inp.open(txt_file, ios::binary || ios::app);
	ofstream outp;
	outp.open(bin_file, ios::binary || ios::app);
	if (inp.good() && outp.good())
	{
		Book tt;
		while (true)
		{
			inp >> tt.ISBN;
			if (!inp.eof())
			{
				inp >> tt.fam >> tt.name;
				outp.write((char*)&tt, sizeof(Book));
			}
			else break;
		}
		inp.close();
		outp.close();
		return 1;
	}
	else
	{
		inp.close();
		outp.close();
		return 0;
	}

}
Book BinFile::get_class(string filename, int position)
{
	Book book;
	ifstream bin_file(filename, ios::binary);
	bin_file.seekg((position) * sizeof(book));
	bin_file.read((char*)&book, sizeof(Book));
	bin_file.close();
	return book;
}

void BinFile::AddToBin(ofstream& bin_file, Book book)
{
	bin_file.seekp(0, ios::end);
	bin_file.write((char*)&book, sizeof(Book));
}
Book BinFile::linear_search(string bin_file, long long int key)
{
	ifstream inp;
	inp.open(bin_file, ios::binary || ios::app);
	Book tt;
	tt.ISBN = 0;
	while (true)
	{
		inp.read((char*)&tt, sizeof(tt));
		if (!inp.eof())
		{
			if (tt.ISBN == key)
			{
				return tt;
			}
		}
		else
		{
			break;
		}
	}
	inp.close();
	return tt;
}
long long int* BinFile::getISBN(string txt_file)
{
	ifstream inp;
	inp.open(txt_file, ios::binary|| ios::app);
	Book tt;
	long long int ISBN[10000] = {0};
	int i = 0;
	while (true)
	{
		inp.read((char*)&tt, sizeof(tt));
		if (!inp.eof())
		{
			ISBN[i] = tt.ISBN;
			i++;
		}
		else
		{
			break;
		}
	}
	inp.close();
	return ISBN;
}