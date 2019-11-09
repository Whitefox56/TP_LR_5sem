#include "Car.h"
#include <iostream>
#include <string>

using namespace std;
Car::Car()
{
	setlocale(LC_ALL, "Rus");

	cout << "Constructor Car ";
	number = "No";
	mark = "No";
	model = "No";
}

Car::Car(const Car& el)
{
	this->mark = el.mark;
	this->model = el.model;
	this->number = el.number;
}
Car::~Car()
{
	cout << "Destructor Car ";
}



ostream& operator <<(ostream& stream, Car& o)
{
	stream << "Mark: " << o.mark << endl;
	stream << "Model: " << o.model << endl;
	stream << "Number: " << o.number << endl;
	return stream;
}
istream& operator >>(istream& stream, Car& o)
{
	cout << "Mark:";
	stream >> o.mark;
	stream.ignore(100, '\n');
	cout << "Model:";
	stream >> o.model;
	stream.ignore(100, '\n');
	cout << "Number: ";
	stream >> o.number;
	stream.ignore(100, '\n');
	return stream;
}

istream& operator >>(ifstream& stream, Car& o)
{
	stream  >> o.mark >> o.model >> o.number;
	return stream;
}

ostream& operator << (ofstream& stream, Car& o)
{
	stream  << o.mark << " " << o.model << " " << o.number;
	return stream;
}

void Car::set_number(string a)
{
	number = a;
}
void Car::set_mark(string a)
{
	mark = a;
}
void Car::set_model(string a)
{
	model = a;
}
string Car::get_mark()
{
	return mark;
}
string Car::get_model()
{
	return model;
}
string Car::get_number()
{
	return number;
}
