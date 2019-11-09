#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
template <class T>
class keeper
{
	T* ptr;
	int size;
public:
	keeper();
	~keeper();

	void push();
	void pop();
	void write_f(string);
	void read_f(string);
	void show();
	void change();
};

template <class T>
keeper <T>::keeper()
{
	cout << "Constructor keeper" << endl;
	ptr = nullptr;
	size = 0;
}

template <class T>
keeper <T>::~keeper()
{
	cout << "Destructor keeper" << endl;
	delete[] ptr;
}


template <class T>
void keeper <T>::push()
{
	int k, c;
	bool flag = true;
	while (flag) {
		system("cls");
		this->show();
		if (!size) c = 1;
		else
		{
			cout << "Index:  ";
			cin >> c;
		}
		cout << "How many objects do you want to add? " << endl;
		cin >> k;
		if (cin.fail() || k < 0 || c < 0 || (c != 1 && c >= size + 1)) {
			cout << "\nIncorrect input" << endl;
			k = -1;
			cin.clear();
			cin.ignore(100, '\n');
			system("pause");
		}
		else flag = false;
	}
	c--;
	T* tmp = new T[size + k];
	for (int i = 0; i < c; ++i)
		tmp[i] = ptr[i];
	for (int i = 0, z = c; i < k; ++i)
	{
		cout << endl << endl;
		cout << "#" << i + 1 << endl;
		cin >> tmp[z++];
	}
	for (int i = c + k, l = c; l < size; ++i, ++l)
	{
		tmp[i] = ptr[l];
	}
	delete[] ptr;
	ptr = tmp;
	size += k;
	cout << "Done" << endl;
}
template <class T>
void keeper <T>::pop()
{
	int k;
	try {
		if (size == 0) {
			exception ex("No data");
			throw ex;
		}
		cout << "Which object do you want to delete?" << endl;
		cin >> k;
		k--;
		if (k < 0 || k >= size) {
			exception ex("Incorrect input");
			throw ex;
		}

		T* tmp = new T[size - 1];
		for (int i = 0; i < k; ++i)
			tmp[i] = ptr[i];
		for (int j = k; j < size - 1; j++)
			tmp[j] = ptr[j + 1];
		delete[] ptr;
		ptr = tmp;
		size--;
		cout << "Done" << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}

}
template <class T>
void keeper <T>::show()
{
	try {
		if (size == 0) {
			exception ex("No data");
			throw ex;
		}
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << endl;
			cout << ptr[i];
		}
		cout << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
}

template <class T>
void keeper <T>::change()
{
	int i;
	bool flag = true;
	do
	{
		system("cls");
		this->show();
		cout << "\nWhich object do you want to change?" << endl;
		cin >> i;
		i--;
		if (cin.fail() || i < 0 || i >= size) {
			cout << "\Incorrect input" << endl;
			i = -1;
			cin.clear();
			cin.ignore(100, '\n');
			system("pause");
		}
		else flag = false;
	} while (flag);
	system("cls");
	cout << ptr[i];
	cout << endl;
	cin >> ptr[i];
}

template <class T>
void keeper <T>::write_f(string k)
{
	ofstream fout;
	fout.open(k, ios::out);
	if (!size) cout << "No data to record" << endl;
	else
	{
		fout << size << endl;
		for (int i = 0; i < size; ++i)
			fout << ptr[i] << endl;
	}
	fout.close();
	cout << "\nDone" << endl;
}
template <class T>
void keeper <T>::read_f(string k)
{
	try {
		ifstream fin;
		int r;
		long file_size;

		fin.open(k, ios::in);
		if (!fin)
		{
			exception ex("\nNo file\n");
			throw ex;
		}

		fin.seekg(0, ios::end);
		file_size = fin.tellg();
		if (!file_size)
		{
			exception ex1("\nNo data\n");
			throw ex1;
		}
		fin.seekg(0, ios::beg);
		delete[] ptr;
		fin >> size;
		if (fin.fail() || size <= 0)
		{
			size = 0;
			fin.clear();
			fin.ignore(10000, '\n');
			exception ex2("\nIncorrect data\n");
			throw ex2;
		}

		ptr = new T[size];
		for (int i = 0; i < size; ++i)
		{
			fin >> ptr[i];
		}
		fin.close();
		cout << "\nDone" << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
}
