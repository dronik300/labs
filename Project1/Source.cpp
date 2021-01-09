#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <string>
class  House
{
public:
	House()
	{
		m_floors = 0;
		m_type = "Block of flats";
	}
	House(int floors, std::string type) :m_floors(floors), m_type(type)
	{

	}
	~House()
	{

	}
	virtual void showInfo()
	{
		std::cout << "Model of this house is " << m_type << " and it has " << m_floors << " floors\n";

	}

protected:
	int m_floors;
	std::string m_type;
};

class Deteched : virtual  public House
{
public:
	Deteched(int id = 0, int address = 0, int floors = 1, std::string type1 = "Deteched")
		:m_id1(id), m_address_line1(address), House(floors, type1)
	{

	}


	void showInfo()
	{
		std::cout << "Model of this house is " << m_type << " and it has " << m_floors << " floors\n";
		std::cout << "ID is " << m_id1 << " Address line " << m_address_line1 << "\n";
	}
protected:

	int m_id1;
	int m_address_line1;

};

class Flat : virtual public House
{
public:
	Flat(int id = 0, int post_index = 0, int floors = 1, std::string type = "Deteched") 
		:m_id(id), m_post_index(post_index), House(floors, type)
	{

	}


	void showInfo()
	{
		std::cout << "Model of this house is " << m_type << " and it has " << m_floors << " floors\n";
		std::cout << "ID is " << m_id << " Post index " << m_post_index << '\n';
	}

protected:
	int m_id;
	int m_post_index;
};

class SemiDeteched : public Deteched
{
public:
	SemiDeteched(double living, int number, int id = 0, int address = 0, int floors = 1, 
		std::string type1 = "SemiDeteched") 
		:m_living_area(living), m_number_of_neighbours(number), Deteched(id, address)
	{
		m_floors = floors;
		m_type = type1;
	}
	~SemiDeteched()
	{

	}
	SemiDeteched()
	{

	}
	void showInfo()
	{
		std::cout << "Model of this house is " << m_type << " and it has " << m_floors << " floor(s)\n";
		std::cout << "ID is " << m_id1 << " Address line " << m_address_line1 << "\n";
		std::cout << """Living area:" << m_living_area << " Amount of neigbours:" << m_number_of_neighbours << '\n';
	}

protected:
	double m_living_area;
	int m_number_of_neighbours;
};

class Studio : public Flat
{
public:
	~Studio()
	{

	}
	Studio(int rooms = 1, int persons = 2, int id = 0, int post_index = 0, int floors = 1, std::string type = "Studio") 
		:m_number_of_rooms(rooms), m_persons_to_live(persons), Flat(id, post_index)
	{
		m_floors = floors;
		m_type = type;
	}
	void showInfo()
	{
		std::cout << "Model of this house is " << m_type << " and it has " << m_floors << " floors\n";
		std::cout << "ID is " << m_id << " Post index " << m_post_index << '\n';
		std::cout << "Number of rooms " << m_number_of_rooms << " Persones to live " << m_persons_to_live << '\n';
	}

protected:
	int m_number_of_rooms;
	int m_persons_to_live;
};


class Mansion : public SemiDeteched, public Studio
{
public:
	Mansion(int id, int addres_line, int neighbours, int numbers_rooms, int postindex, double living_area, 
		double general)
	{
		m_id = id;
		m_living_area = living_area;
		m_address_line1 = addres_line;
		m_number_of_neighbours = neighbours;
		m_number_of_rooms = numbers_rooms;
		m_post_index = postindex;
		m_general_area = general;

	}

	void showInfo()
	{
		using namespace std;
		cout << "Mansion has id " << m_id << endl;
		cout << "Mansion has living area " << m_living_area << endl;
		cout << "Mansion has address " << m_address_line1 << endl;
		cout << "Mansion has " << m_number_of_neighbours << "neighbours" << endl;
		cout << "Mansion has " << m_number_of_rooms << "rooms" << endl;
		cout << "Mansion has postindex " << m_post_index << endl;
		cout << "Mansion has general area " << m_general_area << endl;

	}
private:
	double m_general_area;
};





int main()
{
	using namespace std;
	int id, address, neighbours, rooms, post;
	double living, general;
	while (1)
	{
		cout << "id: ";
		cin >> id;
		if (id > 0)
			break;
	}
	while (1)
	{
		cout << "addres: ";
		cin >> address;
		if (address > 0)
			break;
	}
	while (1)
	{
		cout << "neigbours: ";
		cin >> neighbours;
		if (neighbours > 0 && neighbours < 100)
			break;
	}
	while (1)
	{
		cout << "rooms: ";
		cin >> rooms;
		if (rooms > 0 && rooms < 20)
			break;
	}
	while (1)
	{
		cout << "post: ";
		cin >> post;
		if (post > 0)
			break;
	}
	while (1)
	{
		cout << "living: ";
		cin >> living;
		if (living > 0)
			break;
	}
	while (1)
	{
		cout << "general: ";
		cin >> general;
		if (general > living)
			break;
	}
	Mansion mansion(id, address, neighbours, rooms, post, living, general);
	mansion.showInfo();
	House h;
	h.showInfo();
}