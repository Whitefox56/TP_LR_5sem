#include "Furniture.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;
Furniture::Furniture()
{
	cout << "Constructor Furniture ";
	type = "No";
	gabarit = "No";
	color = "No";
	material = "No";
	price = "No";
}
Furniture::Furniture(const Furniture & el)
{
	cout << "Constructor copy Furniture ";
	this->type = el.type;
	this->color = el.color;
	this->gabarit = el.gabarit;
	this->material = el.material;
	this->price = el.price;
}

Furniture::~Furniture()
{
	cout << "Destructor Furniture ";
}


ostream& operator <<(ostream& stream, Furniture& o)
{
	stream << "Type: " << o.type << endl;
	stream << "Color: " << o.color << endl;
	stream << "Gabarit: " << o.gabarit << endl;
	stream << "Material: " << o.material << endl;
	stream << "Price: " << o.price << endl;
	return stream;
}
istream & operator >>(istream & stream, Furniture& o)
{
	cout << "Type: ";
	stream >> o.type;
	stream.ignore(100, '\n');
	cout << "Color:";
	stream >> o.color;
	stream.ignore(100, '\n');
	cout << "Gabarit:";
	getline(stream, o.gabarit);
	cout << "Material:";
	stream >> o.material;
	stream.ignore(100, '\n');
	cout << "Price:";
	stream >> o.price;
	stream.ignore(100, '\n');
	return stream;
}

istream& operator >>(ifstream& stream, Furniture& o)
{
	stream >> o.type >> o.color >> o.price >> o.material;
	getline(stream, o.gabarit);
	return stream;
}

ostream& operator << (ofstream& stream, Furniture& o)
{
	stream << o.type << " " << o.color << " " << o.price << " " << o.material << " " << o.gabarit;
	return stream;
}

void Furniture::set_type(string a)
{
	type = a;
}
void Furniture::set_gabarit(string a)
{
	gabarit = a;
}
void Furniture::set_color(string a)
{
	color = a;
}
void Furniture::set_material(string a)
{
	material = a;
}
void Furniture::set_price(string a)
{
	price = a;
}
string Furniture::get_type()
{
	return type;
}
string Furniture::get_gabarit()
{
	return gabarit;
}
string Furniture::get_color()
{
	return color;
}
string Furniture::get_material()
{
	return material;
}
string Furniture::get_price()
{
	return price;
}
