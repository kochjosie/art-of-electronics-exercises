//main.cpp

#include <iostream>
#include "resistors.h"
#include "powerloss.h"

using namespace std;

int main()
{
	int userSelection;
	char continueDesire;

	do
	{
		cout << "What do you need help with?\n";
		cout << "1. Calculating total resistance of multiple resistors\n";
		cout << "2. Calculating loss when getting power to a city\n";

		cin >> userSelection;

		switch (userSelection)
		{
		case 1:
			calculateResistance();
			break;
		case 2:
			calculatePowerLost();
		}

		cout << "Would you like to continue? (y/n) ";
		cin >> continueDesire;
		cout << "\n";
	
	} while (continueDesire == 'y');

	return 0;
}