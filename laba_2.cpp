#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int input_check(char s[])
{
	int i = 0, n = 0;
	while (s[i])
	{
		if (int(s[i]) >= 48 && int(s[i]) <= 57)
			n = n*10 + int(s[i] - 48);
		else
		{
			cout << "Vvedeno ne chislo, vvedite chislo\n";
			cin >> s;
			return input_check(s);
		}
		i++;
	}
	return n;
}

class fruit {
	friend class manager;
	friend void get(fruit& fruct);
private:
	int number;
	string fruit_name;
	int fruit_price;


public:
	fruit() : number(0), fruit_price(0), fruit_name(" ") {

	}
	fruit(int id, int price, string name) {
		this->number = id;
		this->fruit_name = name;
		this->fruit_price = price;
	}
	~fruit() {
	}

};

void get(fruit& fruct) {
	cout << fruct.number << "---" << fruct.fruit_name << "---" << fruct.fruit_price << endl;
}

class manager {
public:
	manager() {

	}
	~manager() {

	}
	void set(fruit& fruct, int data) {
		fruct.fruit_price = data;
	}
};

int main() {
	int amount, ID=0, set_price=0;
	string set_name;
	char data[20];
	fruit ptr[3];
	manager m;
	amount = 3;
	for (int i = 0; i < amount; i++) {
		cout << "Vvedite identificacionni nomer: ";
		cin >> data;
		ID = input_check(data);
		cout << "Vvedite nazvanie fructa: ";
		cin >> set_name;
		cout << endl;
		ptr[i] = { ID, 0, set_name };
		cout << endl;
		cout << "=======================================" << endl;;
		cout << endl;
	}

	for (int i = 0; i < amount; i++) {
		get(ptr[i]);
	}
	cout << endl;
	for (int i = 0; i < amount; i++) {
		cout << "Vvedite ceny " << i + 1 << "fructa :";
		cin >> data;
		set_price = input_check(data);
		m.set(ptr[i], set_price);
	}
	cout << endl;
	for (int i = 0; i < amount; i++) {
		get(ptr[i]);
	}
	return 0;
}
