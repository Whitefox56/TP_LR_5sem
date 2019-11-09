#include <iostream>
#include "keeper.h"
#include "Furniture.h"
#include "Worker.h"
#include "Car.h"



using namespace std;

template <typename T>
void dop_menu(T& o, string s)
{
	int c;
	bool flag = true, flag2 = true;

	while (flag)
	{
		do
		{
			system("cls");
			cout << s << endl << endl;
			cout << "1. Add the object \n2. Delete object \n3. Change object \n4. Display on screen \n5. Save to file\n6. Recover from file\n7. Exit to the main menu" << endl;
			cin >> c;
			if (cin.fail() || c < 0 || c > 7) {
				cout << "\nERROR: enter a number from 1 to 7" << endl;
				c = -1;
				cin.clear();
				cin.ignore(10000, '\n');
				system("pause");
			}
			else flag2 = false;
		} while (flag2);
		switch (c)
		{
		case 1:
			o.push();
			system("pause");
			break;
		case 2:
			o.show();
			o.pop();
			system("pause");
			break;
		case 3:
			o.change();
			system("pause");
			break;
		case 4:
			o.show();
			system("pause");
			break;
		case 5:
			o.write_f(s);
			system("pause");
			break;
		case 6:
			o.read_f(s);
			system("pause");
			break;
		case 7:
			flag = false;
			break;
		}

	}
}
