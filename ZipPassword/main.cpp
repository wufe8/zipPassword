#include <iostream>
#include <windows.h>
#include "password.h"

int main()
{
	/*system("cd f:");
	system("cd prog");*/
	using namespace std;
	password test(15);
	int mode = 1;
	while (mode)
	{
		cout << endl << "enter char part: ";
		cin >> mode;
		system("cls");
		if (mode)
		{
			test.SetMode(mode);
			test.CalcMode();
			test.PrintPart();
			test.PrintChar();
		}
	}
	test.GuessPW();
	//for (char i = 0; i >= 0; i++)
	//{
	//	cout << int(i) << " = " << i << endl;
	//}
	return 0;
}