#include "Source.h"

using namespace std;


int main()
{
	cout << "enter start x position" << endl;
	cin >> a_x;
	cout << "enter start y position" << endl;
	cin >> a_y;
	cout << "enter finish x position" << endl;
	cin >> b_x;
	cout << "enter finish y position" << endl;
	cin >> b_y;
	task();
	

	cout << "the shortest way between " << a_x << ";" << a_y << " and " << b_x << ";" << b_y << " is " << V[a_x][a_y].back() << endl;
	system("pause");
}