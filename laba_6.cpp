#include <iostream>

using namespace std;

template <class X, class Y, class Z> int deleteargs(X& length, Y& mas, Z& element)
{
	cout << "here work template" << endl;
	int i = 0;
	while (i<length)
	{
		if (mas[i] == element)
		{
			int j = 0;
			while (i + j < length-1)
			{
				mas[i + j] = mas[i + j + 1];
				j++;
			}
			cout << "length " << length << endl;
			length = length - 1;
			i--;
		}
		i++;
	}
	return length;
}

 int deleteargs(int length, char* mas, char element)
{
	 cout << "here work function (char*)" << endl;
	int i = 0;
	while (i < length)
	{
		if (mas[i] == element)
		{
			int j = 0;
			while (i + j < length - 1)
			{
				mas[i + j] = mas[i + j + 1];
				j++;
			}
			length = length - 1;
			cout << "length " << length << endl;
			i--;
		}
		i++;
	}
	return length;
}

int main()
{
	int x, i;
	char z;
	char* y;
	cout << "Enter length" << endl;
	cin >> x;
	cout << "Enter delete element" << endl;
	cin >> z;
	y = new char[x];
	cout << "Enter mas" << endl;
	for (i = 0; i < x; i++)
	{
		cin >> y[i];
	}
	cout << endl;
	x=deleteargs(x, y, z);
	cout << "mas after delete" << endl;
	for (i = 0; i < x; i++)
		cout << y[i] << " ";
	return 0;
}