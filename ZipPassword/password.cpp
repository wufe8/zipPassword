#include "password.h"
#include <iostream>

password::password(int mode) :
	mode(mode), guess{ 48, 48, 48, 48 }, part{ 32, 127, 0, 0, 0, 0 }
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

int password::GuessPW()
{
	GuessPW(0); //recursive
	return 0;
}

int password::GuessPW(int site)
{
	if (site == PASSWORD_LEIGHT)
	{
		return 0;
	}
	for (guess[site] = part[0]; guess[site] < part[1]; guess[site]++)
	{
		GuessPW(site + 1);
		for (int i = 0; i < PASSWORD_LEIGHT; i++)
		{
			std::cout << guess[i];
		}
		std::cout << std::endl;
	}
	if (part[2])
	{
		for (guess[site] = part[2]; guess[site] < part[3]; guess[site]++)
		{
			GuessPW(site + 1);
			for (int i = 0; i < PASSWORD_LEIGHT; i++)
			{
				std::cout << guess[i];
			}
			std::cout << std::endl;
		}
	}
	if (part[4])
	{
		for (guess[site] = part[4]; guess[site] < part[5]; guess[site]++)
		{
			GuessPW(site + 1);
			for (int i = 0; i < PASSWORD_LEIGHT; i++)
			{
				std::cout << guess[i];
			}
			std::cout << std::endl;
		}
	}
	if (part[6])
	{
		for (guess[site] = part[6]; guess[site] < part[7]; guess[site]++)
		{
			GuessPW(site + 1);
			for (int i = 0; i < PASSWORD_LEIGHT; i++)
			{
				std::cout << guess[i];
			}
			std::cout << std::endl;
		}
	}
	return 0;
}