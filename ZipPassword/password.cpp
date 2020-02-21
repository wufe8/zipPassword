#include "password.h"
#include <iostream>

password::password(int mode) :
	mode(mode), guess{ 48, 48, 48, 48 },
	part{ 32, 127, 0, 0, 0, 0 }, len{ PASSWORD_LEIGHT_MIN, PASSWORD_LEIGHT_MAX }
{
	std::cout << "class has been create!" << std::endl;
}

password::~password()
{

}

int password::SetMode(int mode)
{
	this->mode = mode;
	return 0;
}

int password::GetMode()
{
	return this->mode;
}

int password::PrintPart()
{
	std::cout << "part[] = {";
	for (int i = 0; i < PASSWORD_TYPE; i++)
	{
		std::cout << part[i] << ", ";
	}
	std::cout << "\b\b";
	std::cout << "}" << std::endl;
	return 0;
}

int password::CalcMode()
{
	for (int i = 0; i < PASSWORD_TYPE; i++) //inz
	{
		part[i] = 0;
	}
	int modeCpy = mode;
	int Ppart = 0;
	if (modeCpy / 16)
	{
		int waste = 0;
		CHAR_ALL(part[0], part[PASSWORD_TYPE - 1]);
		Ppart = -1; //black list mode
		CHAR_SPACE(waste, part[Ppart + 1]);
		Ppart += 2;
		CHAR_NUMBER(part[Ppart], part[Ppart + 1]);
		Ppart += 2;
		CHAR_HIGHER_ALPHA(part[Ppart], part[Ppart + 1]);
		Ppart += 2;
		CHAR_LOWER_ALPHA(part[Ppart], part[Ppart + 1]);
		Ppart = 0; //white list mode
		modeCpy -= 16;
		if (modeCpy / 8)
		{
			CHAR_SPACE(part[Ppart], waste);
			modeCpy -= 8;
		}
		Ppart += 2;
		if (modeCpy / 4)
		{
			CHAR_NUMBER(part[Ppart], waste);
			modeCpy -= 4;
		}
		Ppart += 2;
		if (modeCpy / 2)
		{
			CHAR_HIGHER_ALPHA(part[Ppart], waste);
			modeCpy -= 2;
		}
		Ppart += 2;
		if (modeCpy)
		{
			CHAR_LOWER_ALPHA(part[Ppart], waste);
		}
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 6; i++) //clean up the same part
			{
				if (part[i] == part[i + 1])
				{
					part[i] = part[i + 2];
					part[i + 1] = 0;
					part[i + 2] = 0;
				}
			}
		}
	}
	else //white list mode
	{
		if (modeCpy / 8)
		{
			CHAR_SPACE(part[Ppart], part[Ppart + 1]);
			Ppart += 2;
			modeCpy -= 8;
		}
		if (modeCpy / 4)
		{
			CHAR_NUMBER(part[Ppart], part[Ppart + 1]);
			Ppart += 2;
			modeCpy -= 4;
		}
		if (modeCpy / 2)
		{
			CHAR_HIGHER_ALPHA(part[Ppart], part[Ppart + 1]);
			Ppart += 2;
			modeCpy -= 2;
		}
		if (modeCpy)
		{
			CHAR_LOWER_ALPHA(part[Ppart], part[Ppart + 1]);
			Ppart += 2;
		}
	}
	return 0;
}

int password::PrintChar()
{
	std::cout << std::endl;
	for (int Ppart = 0; Ppart < PASSWORD_TYPE && part[Ppart]; Ppart += 2)
	{
		std::cout << part[Ppart] << " ";
		for (int i = part[Ppart]; i < part[Ppart + 1] - 5; i++)
		{
			std::cout << " ";
		}
		std::cout << part[Ppart + 1] << " ";
	}
	std::cout << std::endl;
	for (int Ppart = 0; Ppart < PASSWORD_TYPE && part[Ppart]; Ppart += 2)
	{
		for (int i = part[Ppart]; i < part[Ppart + 1]; i++)
		{
			std::cout << char(i);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}

int password::GuessPW()
{
	for (int passwordLen = PASSWORD_LEIGHT_MIN; passwordLen < PASSWORD_LEIGHT_MAX; passwordLen++)
	{
		GuessPW(0, passwordLen); //recursive
	}
	return 0;
}

int password::GuessPW(int site, int len)
{
	int Ppart = 0;
	for (int Ppart = 0; Ppart < PASSWORD_TYPE && part[Ppart]; Ppart += 2) //check part[0/2/4/6] is 0
	{
		for (guess[site] = part[Ppart]; guess[site] < part[Ppart + 1]; guess[site]++)
		{
			if (site == len)
			{
				return 0;
			}
			else
			{
				GuessPW(site + 1, len);
			}
			std::cout << "now: ";
			for (int i = 0; i < len; i++)
			{
				std::cout << guess[i]; //down-top
			}
			system("cls");
		}
	}
	return 0;
}