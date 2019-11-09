#include <iostream>
#include "keeper.h"
#include "Furniture.h"
#include "Car.h"
#include "Worker.h"
#include "dop_menu.h"

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int cc;
	bool flag = true, flag2 = true;
	keeper <Furniture> f;
	keeper <Car> c;
	keeper <Worker> w;
	system("pause");
	while (flag)
	{
		do
		{
			system("cls");
			cout << " 1 - Furniture;\n 2 - Worker;\n 3 - Car;\n 4 - Exit;" << endl;
			cin >> cc;
			if (cin.fail() || cc < 0 || cc > 4) {
				cout << "\nERROR: enter a number from 1 to 4" << endl;
				cc = -1;
				cin.clear();
				cin.ignore(10000, '\n');
				system("pause");
			}
			else flag2 = false;
		} while (flag2);

		switch (cc)
		{
		case 1:
			system("cls");
			dop_menu(f, "Furniture");
			break;
		case 2:
			system("cls");
			dop_menu(w, "Worker");
			system("pause");
			break;
		case 3:
			system("cls");
			dop_menu(c, "Car");
			system("pause");
			break;
		case 4:
			flag = false;
			cout << "\nGoodbye" << endl;
			break;
		}
	}
	return 0;
}
