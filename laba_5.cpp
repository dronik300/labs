#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

int int_check(string s)
{
	int i = 0, n = 0;
	while (s[i])
	{
		if (int(s[i]) >= 48 && int(s[i]) <= 57)
			n = n * 10 + int(s[i] - 48);
		else
		{
			cout << "Vvedeno ne chislo, vvedite chislo\n";
			cin >> s;
			return int_check(s);
		}
		i++;
	}
	return n;
}

string string_check(string s)
{
	int i = 0;
	string str;
	while (s[i])
	{
		if ((int(s[i]) >= 48 && (int(s[i]) <= 57)) || ((s[i] >= 97) && (s[i] <= 122)))
			str = str + s[i];
		else
		{
			cout << "Vvedeno ne chislo ili bukva, vvedite chislo ili bukvu\n";
			cin >> s;
			return string_check(s);
		}
		i++;
	}
	return str;
}

class Studio {
protected:
	string* Stud_name;

public:
	Studio()
	{
		Stud_name = new string;
		*Stud_name = " ";
	}

	Studio(string studio_name)
	{
		Stud_name = new string;
		int i = 0;
		*Stud_name = studio_name;
	}

	virtual void Show()
	{
		cout << "Studio name-" << *Stud_name << endl;
	}

	~Studio()
	{
		delete Stud_name;
	}
};

class Serial : virtual public Studio
{
protected:
	string* Ser_name;

public:
	Serial()
	{
		Ser_name = new string;
		*Ser_name = " ";
	}

	Serial(string serials_name, string studio_name)
		: Studio(studio_name)
	{
		Ser_name = new string;
		int i = 0;
		*Ser_name = serials_name;
	}

	virtual void Show()
	{
		cout << "studio name-" << *Stud_name;
		cout << " serial name-" << *Ser_name << endl;
	}

	~Serial()
	{
		delete Ser_name;
	}
};

class Seasons : public Serial
{
protected:
	int Seas_numbers;


public:
	Seasons()
	{

		Seas_numbers = 0;
	}

	Seasons(int seasons_numbers, string studio_name, string serials_name)
		:Serial(serials_name, studio_name)
	{
		Seas_numbers = seasons_numbers;
		*Stud_name = studio_name;
	}

	virtual void Show()
	{
		cout << "studio name-" << *Stud_name;
		cout << " serial name-" << *Ser_name;
		cout << " season numbers-" << Seas_numbers << endl;
	}

	~Seasons()
	{

	}
};

class Movie : virtual public Studio
{
protected:
	string* Mname;

public:
	Movie()
	{
		Mname = new string;
	}

	Movie(string movie_name, string studio_name = " ")
		: Studio(studio_name)
	{
		Mname = new string;
		int i = 0;
		*Mname = movie_name;
	}

	virtual void Show()
	{
		cout << "studio name-" << *Stud_name;
		cout << " movie name-" << *Mname << endl;;
	}

	~Movie()
	{
		delete Mname;
	}
};

class Universe : public Movie
{
protected:
	string* Uname;

public:
	Universe()
	{
		Uname = new string;
	}

	Universe(string universe_name, string movie_name ,
		string studio_name )
		:Movie(movie_name, studio_name)
	{
		Uname = new string;
		*Uname = universe_name;
		*Stud_name = studio_name;
	}


	virtual void Show()
	{
		cout << "studio name-" << *Stud_name;
		cout << " movie name-" << *Mname;
		cout << " universe name-" << *Uname << endl;
	}

	~Universe()
	{
		delete Uname;
	}
};

class Actors : public Seasons, public Universe
{
protected:
	string* Actor_name;
	int* fee;
public:
	Actors()
	{
		Actor_name = new string;
		*Actor_name = " ";
		fee = new int;
		*fee = 0;
	}

	Actors(
		string actor_name, int pay, string universe_name, string movie_name,
		string serials_name, string studio_name, int seasons)
		:Seasons(seasons, studio_name, serials_name), Universe(universe_name, movie_name, studio_name)
	{
		*Stud_name = studio_name;

		*Ser_name = serials_name;

		*Mname = movie_name;

		*Uname = universe_name;

		Actor_name = new string;
		*Actor_name = actor_name;
		fee = new int;
		*fee = pay;
		Seas_numbers = seasons;
	}

	virtual void Show()
	{
		cout << "Stud_name " << *Stud_name << endl;
		cout << "Ser_name " << *Ser_name << endl;
		cout << "Seas_numbers " << Seas_numbers << endl;
		cout << "Mname " << *Mname << endl;
		cout << "Uname " << *Uname << endl;
		cout << "fee " << *fee << endl;
		cout << "A_name " << *Actor_name << endl;
	}

	~Actors()
	{
		delete Actor_name;
		delete fee;
	}
};

int main()
{
	Studio* b;
	string data;
	int pay, seasons;
	string studio_name, serials_name, movie_name, universe_name, actor_name;

	cout << "enter studio_name" << data << endl;
	cin >> data;
	studio_name = string_check(data);

	cout << "enter serials_name" << endl;
	cin >> data;
	serials_name = string_check(data);


	cout << "enter movie_name" << data << endl;
	cin >> data;
	movie_name = string_check(data);


	cout << "enter universe_name" << endl;
	cin >> data;
	universe_name = string_check(data);



	cout << "enter actor_name" << endl;
	cin >> data;
	actor_name = string_check(data);

	cout << "enter actor_fee " << endl;
	cin >> data;
	pay = int_check(data);

	cout << "enter Seas_numbers" << endl;
	cin >> data;
	seasons = int_check(data);


	cout << "===============================================" << endl;
	Studio stud(studio_name);
	b = &stud;
	b->Show();

	cout << "===============================================" << endl;
	Serial ser(serials_name, studio_name);
	b = &ser;
	b->Show();

	cout << "===============================================" << endl;
	Seasons ses(seasons, studio_name, serials_name); //????
	b = &ses;
	b->Show();

	cout << "===============================================" << endl;
	Movie mov(movie_name, studio_name);
	b = &mov;
	b->Show();

	cout << "===============================================" << endl;
	Universe un(universe_name, movie_name, studio_name); //????
	b = &un;
	b->Show();

	Actors actor(actor_name, pay, universe_name, movie_name, serials_name, studio_name, seasons);
	b = &actor;
	cout << "===============================================" << endl;
	b->Show();
	cout << "===============================================" << endl;
	return 0;
}