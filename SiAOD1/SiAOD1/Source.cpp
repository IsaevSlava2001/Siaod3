#include <iostream>

using namespace std;

void coutp(unsigned int x)
{
	int n = sizeof(int) * 8;
	unsigned  maska = (1 << (n - 1));

	for (int i = 1; i <= n; i++)
	{
		cout << ((x&maska) >> (n - i));
		maska = maska >> 1;
	}
}
int func1(int x,int maska)
{
//1,6,9
	return x | maska;
}
int func2(int x, int maska)
{
	//1,6,9
	return x&maska;
}
int func3(int x)
{
	return x<<3;
}
int func4(int x)
{
	return x>>3;
}
int func5(int x, int maska, int n)
{
	maska = maska << n;
	return x | maska;
}
int main()
{
	setlocale(LC_ALL,"rus");
	cout << "Введите номер задания\n1-превратить в 1 1-ый, 6-ой, 9-ый биты статичного числа\n2-ввести с клавиатуры число, превратить в 0 1-ый, 6-ой, 9-ый биты введенного числа\n3-умножить введенное с клавиатуры число на 8\n4-разделить введенное с клавиатуры число на 8\n5-ввести число с клавиатуры и номер бита, который нужно превратить в 1, используя маску с 1 в младшем разряде" << endl;
	int num = 0;
	int k,maska,n;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "Задание 1: превратить в 1 1-ый, 6-ой, 9-ый биты статичного числа" << endl;
		k = 5;
		maska = 0x242;
		cout << "До обработки" << endl;
		cout << "Число в 10-чной системе: " << k << endl;
		cout << "Число в 2-чной системе: ";
		coutp(k);
		cout << endl;
		cout << "Маска в 10-чной системе: " << maska << endl;
		cout << "Маска в 2-чной системе: ";
		coutp(maska);
		cout << endl;
		cout << "После обработки" << endl;
		cout << "Число в 10-чной системе: " << func1(k, maska) << endl;
		cout << "Число в 2-чной системе: ";
		coutp(func1(k,maska));
		cout << endl;
		break;
	case 2:
		cout << "Задание 2: ввести с клавиатуры число, превратить в 0 1-ый, 6-ой, 9-ый биты введенного числа" << endl;
		cout << "Введите число в 10-чной системе" << endl;
		cin>>k;
		maska = 0xFFFFFDBD;
		cout << "До обработки" << endl;
		cout << "Число в 10-чной системе: " << k << endl;
		cout << "Число в 2-чной системе: ";
		coutp(k);
		cout << endl;
		cout << "Маска в 10-чной системе: " << maska << endl;
		cout << "Маска в 2-чной системе: ";
		coutp(maska);
		cout << endl;
		cout << "После обработки" << endl;
		cout << "Число в 10-чной системе: " << func2(k, maska) << endl;
		cout << "Число в 2-чной системе: ";
		coutp(func2(k, maska));
		cout << endl;
		break;
	case 3:
		cout << "Задание 3: умножить введенное с клавиатуры число на 8" << endl;
		cout << "Введите число в 10-чной системе" << endl;
		cin >> k;
		cout << "До обработки" << endl;
		cout << "Число в 10-чной системе: " << k << endl;
		cout << "Число в 2-чной системе: ";
		coutp(k);
		cout << endl;
		cout << "После обработки" << endl;
		cout << "Число в 10-чной системе: " << func3(k) << endl;
		cout << "Число в 2-чной системе: ";
		coutp(func3(k));
		cout << endl;
		break;
	case 4:
		cout << "Задание 4: разделить введенное с клавиатуры число на 8" << endl;
		cout << "Введите число в 10-чной системе" << endl;
		cin >> k;
		cout << "До обработки" << endl;
		cout << "Число в 10-чной системе: " << k << endl;
		cout << "Число в 2-чной системе: ";
		coutp(k);
		cout << endl;
		cout << "После обработки" << endl;
		cout << "Число в 10-чной системе: " << func4(k) << endl;
		cout << "Число в 2-чной системе: ";
		coutp(func4(k));
		cout << endl;
		break;
		break;
	case 5:
		cout << "Задание 5: ввести число с клавиатуры и номер бита, который нужно превратить в 1, используя маску с 1 в младшем разряде" << endl;
		cout << "Введите число в 10-чной системе" << endl;
		cin >> k;
		cout << "Введите номер бита для изменения" << endl;
		cin >> n;
		maska = 0x1;
		cout << "До обработки" << endl;
		cout << "Число в 10-чной системе: " << k << endl;
		cout << "Число в 2-чной системе: ";
		coutp(k);
		cout << endl;
		cout << "Маска в 10-чной системе: " << (maska << n) << endl;
		cout << "Маска в 2-чной системе: ";
		coutp(maska << n);
		cout << endl;
		cout << "После обработки" << endl;
		cout << "Число в 10-чной системе: " << func5(k, maska, n) << endl;
		cout << "Число в 2-чной системе: ";
		coutp(func5(k, maska, n));
		cout << endl;
		break;
	default:
		cout << "Неправильный номер"<<endl;
		system("pause");
		exit(0);
		break;
	}
	system("pause");
}