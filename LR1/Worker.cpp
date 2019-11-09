#include "Worker.h"
#include <iostream>
#include <string>

using namespace std;
Worker::Worker()
{

	cout << "Constructor Worker ";
	name = "No";
	position = "No";
	money = "No";
	address = "No";
	phone = "No";
}

Worker::Worker(const Worker& el)
{
	this->name = el.name;
	this->position = el.position;
	this->money = el.money;
	this->address = el.address;
	this->phone = el.phone;
}

Worker::~Worker()
{
	cout << "Destructor Worker ";
}



ostream& operator <<(ostream& stream, Worker& o)
{
	stream << "Name: " << o.name << endl;
	stream << "Position: " << o.position << endl;
	stream << "Money: " << o.money << endl;
	stream << "Address: " << o.address << endl;
	stream << "Phone: " << o.phone << endl;
	return stream;
}
istream& operator >>(istream& stream, Worker& o)
{
	cout << "Position:";
	stream >> o.position;
	stream.ignore(100, '\n');
	cout << "Name:";
	getline(stream, o.name);
	cout << "Money:";
	stream >> o.money;
	stream.ignore(100, '\n');
	cout << "Address:";
	stream >> o.address;
	stream.ignore(100, '\n');
	cout << "Phone:";
	stream >> o.phone;
	stream.ignore(100, '\n');
	return stream;
}

istream& operator >>(ifstream& stream, Worker& o)
{
	stream >> o.position >> o.money >> o.address >> o.phone;
	getline(stream, o.name);
	return stream;
}

ostream& operator << (ofstream& stream, Worker& o)
{
	stream << o.name << " " << o.position << " " << o.money << " " << o.address << " " << o.phone;
	return stream;
}

void Worker::set_name(string a)
{
	name = a;
}
void Worker::set_position(string a)
{
	position = a;
}
void Worker::set_money(string a)
{
	money = a;
}
void Worker::set_address(string a)
{
	address = a;
}
void Worker::set_phone(string a)
{
	phone = a;
}
string Worker::get_name()
{
	return name;
}
string Worker::get_position()
{
	return position;
}

string Worker::get_money()
{
	return money;
}

string Worker::get_address()
{
	return address;
}

string Worker::get_phone()
{
	return phone;
}
