#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include "MyQueue.h"
#include "LZ.h"
#include <fstream>
using namespace std;

Node** p = nullptr;

int rebase(char a)
{
	switch (a)
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
	case 'a':
		return 10;
		break;
	case 'b':
		return 11;
		break;
	case 'c':
		return 12;
		break;
	case 'd':
		return 13;
		break;
	case 'e':
		return 14;
		break;
	case 'f':
		return 15;
		break;
	case 'g':
		return 16;
		break;
	case 'h':
		return 17;
		break;
	case 'i':
		return 18;
		break;
	case 'j':
		return 19;
		break;
	case 'k':
		return 20;
		break;
	case 'l':
		return 21;
		break;
	case 'm':
		return 22;
		break;
	case 'n':
		return 23;
		break;
	case 'o':
		return 24;
		break;
	case 'p':
		return 25;
		break;
	case 'q':
		return 26;
		break;
	case 'r':
		return 27;
		break;
	case 's':
		return 28;
		break;
	case 't':
		return 29;
		break;
	case 'u':
		return 30;
		break;
	case 'v':
		return 31;
		break;
	case 'w':
		return 32;
		break;
	case 'x':
		return 33;
		break;
	case 'y':
		return 34;
		break;
	case 'z':
		return 35;
		break;
	default:
		break;
	}
	return NULL;
}

string encodeRle(string value)
{
	string ans = "";
	int counter = 1;
	char prev = value[0];
	for (int i = 1; i < value.size(); ++i)
	{
		if (prev == value[i])
			counter++;
		else {
			if (counter > 9)
			{
				char buffer[33];
				_itoa(counter, buffer, 36);
				ans += buffer;
			}
			else
			{
				ans += to_string(counter);
			}
			ans += prev;
			prev = value[i];
			counter = 1;
		}
	}
	if (counter)
	{
		ans += to_string(counter);
		ans += prev;
		prev = value[value.size() - 1];
	}
	return ans;
}

string decodeRle(string value)
{
	string ans = "";
	for (int i = 0; i < value.size() - 1; i += 2)
		for (int j = 0; j < rebase(value[i]); ++j)
			ans += value[i + 1];
	return ans;
}

void ShannonFanoMethod(int begin, int end)
{
	if ((begin + 1) == end || begin == end || begin> end)
	{
		if (begin == end || begin> end)
			return;
		p[end]->arr += '0';
		p[begin]->arr += '1';
		return;
	}
	else
	{
		double group1 = 0, group2 = 0;
		double difference1 = 0, difference2 = 0;
		for (int i = begin; i <= end - 1; i++)
			group1 = group1 + p[i]->frequency;
		group2 = group2 + p[end]->frequency;
		difference1 = group1 - group2;
		if (difference1 < 0)
			difference1 = difference1 * -1;
		int k;
		for (int j = 2; j != end - begin + 1; j++) {
			k = end - j;
			group1 = 0;
			group2 = 0;
			for (int i = begin; i <= k; i++)
				group1 = group1 + p[i]->frequency;
			for (int i = end; i > k; i--)
				group2 = group2 + p[i]->frequency;
			difference2 = group1 - group2;
			if (difference2 < 0)
				difference2 = difference2 * -1;
			if (difference2 >= difference1)
				break;
			difference1 = difference2;
		}
		k++;
		for (int i = begin; i <= k; i++)
			p[i]->arr += '1';
		for (int i = k + 1; i <= end; i++)
			p[i]->arr += '0';
		ShannonFanoMethod(begin, k);
		ShannonFanoMethod(k + 1, end);
	}
}

string decodeShennonFano(string value, int size)
{
	string ans = "";
	string buffer = "";
	vector<int> candidates;
	for (int i = 0; i < value.size(); ++i)
	{
		buffer += value[i];
		for (int j = 0; j < size; ++j)
		{
			if (buffer.size() != p[j]->arr.size())
				continue;
			bool isCandidate = true;
			for (int k = 0; k < buffer.size(); ++k)
			{
				if (buffer[k] != p[j]->arr[k])
					isCandidate = false;
			}
			if (isCandidate && find(candidates.begin(), candidates.end(), j) == candidates.end())
				candidates.push_back(j);
			else candidates.erase(remove(candidates.begin(), candidates.end(), j), candidates.end());
		}
		if (candidates.size() == 1)
		{
			ans += p[candidates[0]]->symbol;
			candidates.erase(candidates.begin());
			buffer = "";
		}
	}
	return ans;
}

void getCodes(string value, int size)
{
	cout << "    Символ\t Частота     Двоичный код";
	for (int i = size - 1; i >= 0; i--)
	{
		cout << "\n    " << " <" << p[i]->symbol << ">" << "\t" << p[i]->frequency << "\t";
		for (int j = 0; j <= p[i]->arr.size(); j++)
			cout << p[i]->arr[j];
	}
}

string encodeText(string value, int size)
{
	string ans = "";
	for (int i = 0; i < value.size(); ++i)
		for (int j = 0; j < size; ++j)
			if (value[i] == p[j]->symbol)
				ans += p[j]->arr;
	return ans;
}

string decodeHuffman(string str, Node* root_main, bool flag_ex)
{
	int counter = 0;
	string ans = "";
	int i = counter;
	while (i < str.size())
	{
		Node* temp = root_main;
		while (true)
		{
			if (str[i] == '0')
			{
				if (temp->left != nullptr)
					temp = temp->left;
				else
				{
					ans += temp->symbol;
					break;
				}
			}
			else
			{
				if (temp->right != nullptr)
					temp = temp->right;
				else
				{
					ans += temp->symbol;
					break;
				}
			}
			i++;
			counter = i;
		}
		if (flag_ex)
			i++;
		else
			i = counter;
	}
	return ans;
}

void printLeaves(Node* root, string path)
{
	if (!root->left && !root->right)
	{
		cout << "    Символ: <" << root->symbol << "> Частота: " << root->frequency << " Код: " << path << "\n";
		root->arr = path;
		return;
	}
	if (root->left != nullptr)
		printLeaves(root->left, path + "0");
	if (root->right != nullptr)
		printLeaves(root->right, path + "1");
}

Node* HuffmanMethod(int size)
{
	int current = size;
	MyQueue ans;
	for (int i = 0; i <= size; ++i)
		ans.push(p[i]);
	while (ans.checkSize())
	{
		Node* first = ans.pop();
		Node* second = ans.pop();
		Node* tmp = new Node('!', first->frequency + second->frequency, first, second);
		ans.push(tmp);
	}
	return ans.pop();
}

int CountUniqueSymbols(string input) 
{
	string tmp = "";
	tmp += input[0];
	for (int i = 0; i < input.size(); ++i)
		if (count(tmp.begin(), tmp.end(), input[i]) == 0)
			tmp += input[i];
	p = new Node *[tmp.size()];
	for (int i = 0; i < tmp.size(); ++i)
		p[i] = new Node(tmp[i], double(count(input.begin(), input.end(), tmp[i])) / double(input.size()));
	return tmp.size();
}

void sortByfrequency(int size)
{
	for (int j = 1; j < size; j++)
		for (int i = 0; i < size - 1; i++)
			if (p[i]->frequency > p[i + 1]->frequency)
				swap(p[i], p[i + 1]);
}


int main() {
	setlocale(0, "RUS");
	while (true) 
	{
		system("pause");
		system("cls");
		cout << "Меню задач:"
			<< "\n    1. RLE\n    " << "2. LZ77\n    " << "3. LZ78\n    " << "4. Шеннона-Фано\n    " << "5. Хаффман\n" << "6. Зашифровать файл методом Хаффмана\n" << "Иная команда прекратит работу программы\n";
		int choice;
		cout << "Введите номер команды: ";
		cin >> choice;
		switch (choice) 
		{
		case 1: 
		{
			string a = "aaaaaaaabbbbbbbbcccddddddddddde";
			string b = "dsnafjsdanflijadkfnaildjkgansd";
			cout << "Пункт а: " << "\n\tИсходная строка: " << a << "\n\tКодирование: " << encodeRle(a) << "\n\tДекодирование: " << decodeRle(encodeRle(a)) <<"\n\tРазмер начальной строки: "<<a.size()<<"\n\tРазмер сжатой строки: "<< encodeRle(a).size() <<"\n\tКоэффициент сжатия: "<< (double)a.size() / (double)encodeRle(a).size() <<"\n";
			cout << "Пункт b: " << "\n\tИсходная строка: " << b << "\n\tКодирование: " << encodeRle(b) << "\n\tДекодирование: " << decodeRle(encodeRle(b))<< "\n\tРазмер начальной строки: " << b.size() << "\n\tРазмер сжатой строки: " << encodeRle(b).size() << "\n\tКоэффициент сжатия: " << (double)b.size() / (double)encodeRle(b).size() << "\n";
			break;
		}
		case 2: 
		{
			string lz77 = "010110110110100010001";
			cout << "Исходная строка: " << lz77 << "\n";
			vector<Sequence77> ans = encodeLZ77(lz77);
			cout << "Кодирование:\n";
			for (auto el : ans)
				cout << "\t<" << el.offset << ", " << el.length << ", " << el.next << ">\n";
			cout << "\n\tРамзер начальной строки: " << lz77.size() << "\n\tРазмер закодированного слова: " << ans.size() << "\n\tКоэффициент сжатия: " << (double)lz77.size() / (double)ans.size() << "\n";
			cout << "Декодирование: " << decodeLZ77(ans) << "\n";
			break;
		}
		case 3: 
		{
			string lz78 = "sarsalsarsanlasanl";
			cout << "Исходная строка: " << lz78 << "\n";
			vector<Sequence78> ans2 = encodeLZ78(lz78);
			cout << "Кодирование:\n";
			for (auto el : ans2)
				cout << "\t<" << el.pos << ", " << el.next << ">\n";
			cout << "\n\tРамзер начальной строки: " << lz78.size() << "\n\tРазмер закодированного слова: " << ans2.size() << "\n\tКоэффициент сжатия: " << (double)lz78.size() / (double)ans2.size() << "\n";
			cout << "Декодирование: " << decodeLZ78(ans2) << "\n";
			break;
		}
		case 4: 
		{
			string shenonFano = "Мой котёнок очень странный, Он не хочет есть сметану, К молоку не прикасался И от рыбки отказался.";
			cout << "Исходная строка: " << shenonFano << "\n";
			int size = CountUniqueSymbols(shenonFano);
			sortByfrequency(size);
			ShannonFanoMethod(0, size - 1);
			cout << "Кодирование: ";
			string ans = encodeText(shenonFano, size);
			cout << ans << " " << ans.size() << "\n";
			cout << "\n\tРамзер начальной строки: " << shenonFano.size() << "\n\tРазмер закодированного слова: " << ans.size() << "\n\tКоэффициент сжатия: " << (double)shenonFano.size() / (double)ans.size() << "\n";
			cout << "Декодирование: " << decodeShennonFano(ans, size) << "\n";
			break;
		}
		case 5: 
		{
			string haffman = "Исаев Вячеслав Викторович";
			cout << "Исходная строка: " << haffman << "\n";
			int size = CountUniqueSymbols(haffman);
			sortByfrequency(size);
			Node* ans = HuffmanMethod(size - 1);
			printLeaves(ans, "");
			cout << "Кодирование: ";
			string text = encodeText(haffman, size);
			cout << text << " " << text.size() << "\n";
			cout << "\n\tРамзер начальной строки: " << haffman.size() << "\n\tРазмер закодированного слова: " << text.size() << "\n\tКоэффициент сжатия: " << (double)haffman.size() / (double)text.size() << "\n";
			cout << "Декодирование: " << decodeHuffman(text, ans, 0) << "\n";
			break;
		}
		case 6:
		{
			string s;
			string book;
			ifstream f;
			f.open("book.txt");
			while (getline(f, s))
			{
				book += s;
			}
			f.close();
			int bam = CountUniqueSymbols(book);
			sortByfrequency(bam);
			Node* kek = HuffmanMethod(bam - 1);
			printLeaves(kek, "");
			string coded = encodeText(book,bam);
			ofstream out;
			out.open("bookhaffman.txt");
			out << coded;
			out.close();
			break;
		}
		default:
			cout << "Завершение работы";
			return 0;
			break;
		}
	}
}
