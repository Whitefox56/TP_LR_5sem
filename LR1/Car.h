#pragma once
#include "keeper.h"
#include "Base.h"

using namespace std;

class Car :public Base
{
	string mark;	
	string model;	
	string number;	
public:
	Car();
	Car(const Car& el);
	~Car();
	void set_mark(string);
	void set_model(string);
	void set_number(string);
	string get_mark();
	string get_model();
	string get_number();
	friend istream& operator >>(istream& stream, Car& o);
	friend ostream& operator << (ostream& stream, Car& o);
	friend istream& operator >>(ifstream& stream, Car& o);
	friend ostream& operator << (ofstream& stream, Car& o);
};
