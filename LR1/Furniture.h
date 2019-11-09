#pragma once
#include <fstream>
#include "keeper.h"
#include "Base.h"

using namespace std;

class Furniture :public Base
{
public:
	Furniture();
	Furniture(const Furniture& el);
	~Furniture();
	void set_type(string);
	void set_gabarit(string);
	void set_color(string);
	void set_material(string);
	void set_price(string);
	string get_type();
	string get_gabarit();
	string get_color();
	string get_material();
	string get_price();
	friend istream& operator >>(istream& stream, Furniture & o);
	friend ostream& operator << (ostream& stream, Furniture & o);
	friend istream& operator >>(ifstream& stream, Furniture& o);
	friend ostream& operator << (ofstream& stream, Furniture& o);
private:
	string type;	
	string gabarit;	
	string color;	
	string material;	
	string price;
};
