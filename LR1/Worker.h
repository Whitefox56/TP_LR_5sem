#pragma once
#include "keeper.h"
#include "Base.h"

using namespace std;

class Worker :public Base
{
	string name;	
	string position;	
	string money;
	string address;
	string phone;
public:
	Worker();
	Worker(const Worker& el);
	~Worker();
	void set_name(string);
	void set_position(string);
	void set_money(string);
	void set_address(string);
	void set_phone(string);
	string get_name();
	string get_position();
	string get_money();
	string get_address();
	string get_phone();
	friend istream& operator >>(istream& stream, Worker& o);
	friend ostream& operator << (ostream& stream, Worker& o);
	friend istream& operator >>(ifstream& stream, Worker& o);
	friend ostream& operator << (ofstream& stream, Worker& o);
};
