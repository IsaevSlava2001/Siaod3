#include "LZ.h"
#include <iostream>
vector<Sequence77> encodeLZ77(string s)
{
	int maxWindow = 10;
	vector<Sequence77> ans;
	int sizeBuffer, sizeUnchecked;
	for (int i = 0; i < s.length(); i++)
	{
		if (i + 1 <= maxWindow)
			sizeBuffer = i;
		else
			sizeBuffer = maxWindow;
		if (i + sizeBuffer < s.length())
			sizeUnchecked = sizeBuffer;
		else
			sizeUnchecked = s.length() - i;
		string buffer = s.substr(i - sizeBuffer, sizeBuffer);
		string unchecked = s.substr(i, sizeUnchecked);
		int off = -1;
		while (true)
		{
			if (!sizeUnchecked)
				break;
			string str3 = unchecked.substr(0, sizeUnchecked);
			off = buffer.find(str3);
			if (off != -1)
				break;
			sizeUnchecked--;
			if (sizeUnchecked <= 0)
				break;
		}
		Sequence77 value;
		value.next = s[i + sizeUnchecked];
		if (off != -1)
		{
			value.length = sizeUnchecked;
			value.offset = sizeBuffer - off;
			ans.push_back(value);
			i += sizeUnchecked;
		}
		else
		{
			value.length = 0;
			value.offset = 0;
			ans.push_back(value);
		}
	}
	return ans;
}

vector<Sequence78> encodeLZ78(string s) {
	string buffer = "";
	map<string, int> dict = {};
	vector<Sequence78> ans;
	for (int i = 0; i < s.size(); ++i) {
		if (dict.find(buffer + s[i]) != dict.end())
			buffer += s[i];
		else {
			Sequence78 value;
			value.next = s[i];
			if (dict[buffer] == 0)
				value.pos = dict[buffer];
			else
				value.pos = dict[buffer] - 1;
			ans.push_back(value);
			dict[buffer + s[i]] = dict.size() + 1;
			buffer = "";
		}
	}
	if (buffer != "") {
		char last_ch = buffer[buffer.size() - 1];
		buffer.pop_back();
		Sequence78 value;
		if (dict.find(buffer + s[s.size() - 1]) != dict.end()) {
			value.next = '$';
			value.pos = dict[buffer + s[s.size() - 1]] - 1;
		}
		else {
			value.next = last_ch;
			value.pos = dict[buffer];
		}
		ans.push_back(value);
	}
	return ans;
}

string decodeLZ77(vector<Sequence77> parameters) {
	string ans;
	for (int i = 0; i < parameters.size(); i++) {
		if (parameters[i].length == 0)
			ans += parameters[i].next;
		else {
			int size = ans.length();
			size -= parameters[i].offset;
			string temp = ans.substr(size, parameters[i].length);
			ans += temp + parameters[i].next;
		}
	}
	return ans;
}

string decodeLZ78(vector<Sequence78> parameters) {
	int currentWord = 0;
	map<int, string> dict = { { currentWord, "" } };
	string ans = "";
	for (auto el : parameters) {
		currentWord++;
		string word = dict[el.pos];
		if (el.next != '$')
			word += el.next;
		ans += word;
		dict[currentWord] = word;
	}
	return ans;
}
