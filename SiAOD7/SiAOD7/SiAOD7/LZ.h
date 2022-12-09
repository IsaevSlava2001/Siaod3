#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Sequence77
{
	int offset;
	int length;
	char next;
};

struct Sequence78
{
	int pos;
	char next;
};

vector<Sequence77> encodeLZ77(string s);

vector<Sequence78> encodeLZ78(string s);

string decodeLZ77(vector<Sequence77>);

string decodeLZ78(vector<Sequence78>);
