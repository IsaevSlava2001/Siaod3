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
	cout << "������� ����� �������\n1-���������� � 1 1-��, 6-��, 9-�� ���� ���������� �����\n2-������ � ���������� �����, ���������� � 0 1-��, 6-��, 9-�� ���� ���������� �����\n3-�������� ��������� � ���������� ����� �� 8\n4-��������� ��������� � ���������� ����� �� 8\n5-������ ����� � ���������� � ����� ����, ������� ����� ���������� � 1, ��������� ����� � 1 � ������� �������" << endl;
	int num = 0;
	int k,maska,n;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "������� 1: ���������� � 1 1-��, 6-��, 9-�� ���� ���������� �����" << endl;
		k = 5;
		maska = 0x242;
		cout << "�� ���������" << endl;
		cout << "����� � 10-���� �������: " << k << endl;
		cout << "����� � 2-���� �������: ";
		coutp(k);
		cout << endl;
		cout << "����� � 10-���� �������: " << maska << endl;
		cout << "����� � 2-���� �������: ";
		coutp(maska);
		cout << endl;
		cout << "����� ���������" << endl;
		cout << "����� � 10-���� �������: " << func1(k, maska) << endl;
		cout << "����� � 2-���� �������: ";
		coutp(func1(k,maska));
		cout << endl;
		break;
	case 2:
		cout << "������� 2: ������ � ���������� �����, ���������� � 0 1-��, 6-��, 9-�� ���� ���������� �����" << endl;
		cout << "������� ����� � 10-���� �������" << endl;
		cin>>k;
		maska = 0xFFFFFDBD;
		cout << "�� ���������" << endl;
		cout << "����� � 10-���� �������: " << k << endl;
		cout << "����� � 2-���� �������: ";
		coutp(k);
		cout << endl;
		cout << "����� � 10-���� �������: " << maska << endl;
		cout << "����� � 2-���� �������: ";
		coutp(maska);
		cout << endl;
		cout << "����� ���������" << endl;
		cout << "����� � 10-���� �������: " << func2(k, maska) << endl;
		cout << "����� � 2-���� �������: ";
		coutp(func2(k, maska));
		cout << endl;
		break;
	case 3:
		cout << "������� 3: �������� ��������� � ���������� ����� �� 8" << endl;
		cout << "������� ����� � 10-���� �������" << endl;
		cin >> k;
		cout << "�� ���������" << endl;
		cout << "����� � 10-���� �������: " << k << endl;
		cout << "����� � 2-���� �������: ";
		coutp(k);
		cout << endl;
		cout << "����� ���������" << endl;
		cout << "����� � 10-���� �������: " << func3(k) << endl;
		cout << "����� � 2-���� �������: ";
		coutp(func3(k));
		cout << endl;
		break;
	case 4:
		cout << "������� 4: ��������� ��������� � ���������� ����� �� 8" << endl;
		cout << "������� ����� � 10-���� �������" << endl;
		cin >> k;
		cout << "�� ���������" << endl;
		cout << "����� � 10-���� �������: " << k << endl;
		cout << "����� � 2-���� �������: ";
		coutp(k);
		cout << endl;
		cout << "����� ���������" << endl;
		cout << "����� � 10-���� �������: " << func4(k) << endl;
		cout << "����� � 2-���� �������: ";
		coutp(func4(k));
		cout << endl;
		break;
		break;
	case 5:
		cout << "������� 5: ������ ����� � ���������� � ����� ����, ������� ����� ���������� � 1, ��������� ����� � 1 � ������� �������" << endl;
		cout << "������� ����� � 10-���� �������" << endl;
		cin >> k;
		cout << "������� ����� ���� ��� ���������" << endl;
		cin >> n;
		maska = 0x1;
		cout << "�� ���������" << endl;
		cout << "����� � 10-���� �������: " << k << endl;
		cout << "����� � 2-���� �������: ";
		coutp(k);
		cout << endl;
		cout << "����� � 10-���� �������: " << (maska << n) << endl;
		cout << "����� � 2-���� �������: ";
		coutp(maska << n);
		cout << endl;
		cout << "����� ���������" << endl;
		cout << "����� � 10-���� �������: " << func5(k, maska, n) << endl;
		cout << "����� � 2-���� �������: ";
		coutp(func5(k, maska, n));
		cout << endl;
		break;
	default:
		cout << "������������ �����"<<endl;
		system("pause");
		exit(0);
		break;
	}
	system("pause");
}