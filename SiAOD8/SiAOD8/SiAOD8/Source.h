#pragma once

#include <iostream>
#include <vector>
using namespace std;

vector <int> V[100][100];
int a_x = 0, a_y = 0, b_x = 2, b_y = 3, v_speed = 3, h_speed = 2;

int min(int a, int b)
{
	if (a < b) return a;
	else if (b < a) return b;
	else return a;
}
int getWay(int x, int y)
{
	if (x < b_x&&y < b_y)
	{
		return min(V[x + 1][y].back() + V[x][y].back(), V[x][y + 1].back() + V[x][y].back());
	}
	else if (x >= b_x&&y < b_y)
	{
		return V[x][y + 1].back() + V[x][y].back();
	}
	else if (x < b_x&&y >= b_y)
	{
		return V[x + 1][y].back() + V[x][y].back();
	}
	else
	{
		return V[x][y].back();
	}
}
void task()
{
	if (a_x >= b_x || a_y >= b_y)
	{
		cout << "no way" << endl;
		system("pause");
		exit(1);
	}
	V[a_x][a_y].push_back(0);
	V[a_x][a_y].push_back(0);
	for (int i = a_x + 1; i <= b_x; i++)
	{
		V[i][a_y].push_back(i);
		V[i][a_y].push_back(0);
	}
	for (int i = a_y + 1; i <= b_y; i++)
	{
		V[a_x][i].push_back(0);
		V[a_x][i].push_back(i);
	}
	for (int x = a_x + 1; x <= b_x; x++)
	{
		for (int y = a_y + 1; y <= b_y; y++)
		{
			V[x][y].push_back(x);
			V[x][y].push_back(y);
		}
	}
	int k;
	for (int i = a_x; i <= b_x; i++)
	{
		for (int v = a_y; v <= b_y; v++)
		{
			cout << "enter weight of " << i << ";" << v << endl;
			cin >> k;
			V[i][v].push_back(k);
		}
	}
	for (int x = b_x; x >= a_x; x--)
	{
		for (int y = b_y; y >= a_y; y--)
		{
			int u = getWay(x, y);
			V[x][y].pop_back();
			V[x][y].push_back(u);
		}
	}
}