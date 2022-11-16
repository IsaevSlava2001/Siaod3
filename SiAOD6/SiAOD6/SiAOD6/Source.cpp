#include <iostream>
#include <iomanip>
using namespace std;
const int Vmax = 100, Emax = Vmax * 2;
int n, m, i, j, k, v, u, w;
char r;

class Graph
{
	int head[Vmax] = {0};
	int next_el[Emax] = {0};
	int terminal[Emax] = {0};
	int weight[Emax] = {9999};
	int summ[Emax][Emax] = { 0,0 };

public:
	void Add(int v, int u, int w);
	void print();
	void Floyd();
	void Help();
	int Printnew(int i,int j);
	void BeautPrint();
};

void Graph::Add(int v, int u, int w) //добавление ребра
{
	k = k + 1;
	terminal[k] = u;
	next_el[k] = head[v];
	head[v] = k;
	weight[k] = w;
}
void Graph::print()
{
	cout << "Список смежности графа:";
	for (i = 0; i<n + 1; i++)
	{
		j = head[i];
		if (i)
		{
			cout << i << "->";
		}
		while (j>0)
		{
			if (!next_el[j])
			{
				cout << terminal[j] << " (" << weight[j] << ")";
			}
			else
			{
				cout << terminal[j] << " (" << weight[j] << ")" << ", ";
			}
			j = next_el[j];
		}
		cout << endl;
	}
}
void Graph::Floyd()
{
	for (int i = 0; i < n + 1;i++)
	{
		for (int u=0; u < n + 1; u++)
		{
			for (int v = 0; v < n + 1; v++)
			{
				if (summ[u][i] + summ[i][v] < summ[u][v])
				{
					summ[u][v] = summ[u][i] + summ[i][v];
				}
			}
		}
	}
}
void Graph::Help()
{
	for (int i = 0; i < Emax; i++)
	{
		for (int j = 0; j < Emax; j++)
		{
			summ[i][j] = 9999;
		}
	}
	int z = 1;
	while (z < n + 1)
	{
		j = head[z];
		while (j > 0)
		{
			summ[z][terminal[j]] = weight[j];
			j = next_el[j];
		}
		z++;
	}
}
int Graph::Printnew(int i, int j)
{
	if (summ[i][j] < 9999)
	{
		return summ[i][j];
	}
	else
	{
		return 0;
	}
}
void Graph::BeautPrint()
{
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (j == 1)
			{
				cout << i << "        ";
			}
			if (i == 0)
			{
				cout << j << "     ";
			}
			else
			{
				if (summ[i][j] == 9999)
				{
					cout << "er" << "    ";
				}
				else
				{
					cout << summ[i][j] << "     ";
				}
			}
		}
		cout << endl;
	}
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	k = 0;
	int q;
	Graph g;
	while (true)
	{
		system("cls");
		cout << "Выберите пункт меню" << endl;
		cout << "1. Ввод вершин графа\n2. Вывод графа\n3. Поиск кратчайших путей по алгоритму Флойда\n4. Вывод расстояния между двумя вершинами графа" << endl;
		cin >> q;
		if (q == 1)
		{
			cout << "Ввод вершин графа" << endl;
			cout << "Количество вершин >> ";
			cin >> n;
			cout << "Количество ребер >> ";
			cin >> m;
			cout << "В графе есть ориентированные вершины? y/n" << endl;
			char f;
			cin >> f;
			if (f == 'y' || f == 'Y')
			{
				cout << "Вводите смежные вершины и вес пути:" << endl;
				for (i = 0; i<m; i++)
				{
					cin >> v >> u >> w;
					cout << "Ребро ориентированно? (y/n) >> ";
					cin >> r;
					if (r == 'y'||r=='Y')
					{
						g.Add(v, u, w);
					}
					else
					{
						g.Add(v, u, w);
						g.Add(u, v, w);
					}
					cout << "..." << endl;
				}
			}
			else
			{
				cout << "Вводите смежные вершины и вес пути:" << endl;
				for (i = 0; i<m; i++)
				{
					cin >> v >> u >> w;
					g.Add(v, u, w);
					g.Add(u, v, w);
					cout << "..." << endl;
				}
			}
			g.Help();
			system("pause");
		}
		else if (q == 2)
		{
			cout << "Вывод графа" << endl;
			g.print();
			system("pause");
		}
		else if (q == 3)
		{
			cout << "Поиск кратчайших путей по алгоритму Флойда" << endl;
			g.Floyd();
			cout << "Вывод матрицы путей" << endl;
			g.BeautPrint();
			system("pause");
		}
		else if (q == 4)
		{
			while (true)
			{
				system("cls");
				cout << "Введите 2 вершины. Если хотите выйти, введите 0 0" << endl;
				int d, f;
				cin >> d >> f;
				if (d != 0 && f != 0)
				{
					int h = g.Printnew(d, f);
					if (h == 0)
					{
						cout << "Путь не найден" << endl;
					}
					else
					{
						cout << "Кратчайший путь между вершинами " << d << " и " << f << " составляет " << h << endl;
					}
				}
				else
				{
					break;
				}
				system("pause");
			}
		}
		else
		{
			cout << "Вы уверены, что хотите выйти? введите y/n"<<endl;
			char b;
			cin >> b;
			if (b == 'Y' || b == 'y')
			{
				cout << "выход..."<<endl;
				system("pause");
				exit(0);
			}
		}
	}
}