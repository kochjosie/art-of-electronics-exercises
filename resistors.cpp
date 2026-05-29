//resistors.cpp

#include <iostream>
#include <cstdlib>
#include "resistors.h"

using namespace std;

void calculateResistance()
{
	int nResistors;
	int resistorAlignment;
	double totalResistance;
	int *resistanceAmounts;

	cout << "How many resistors do you have? ";
	cin >> nResistors;
	resistanceAmounts = (int*)malloc(nResistors * sizeof(int));

	resistorAlignment = verifyResistorAlignment();

	cout << "\nPlease enter the resistance amount in ohms of each resistor.\n";

	int i;
	int resistanceAmount;

	for (i = 0; i < nResistors; i++)
	{
		cout << "Enter resistor value #" << i + 1 << " ";
		cin >> resistanceAmount;
		resistanceAmounts[i] = resistanceAmount;
		cout << "You added a " << resistanceAmount << " ohm resistor.\n";
	}

	switch (resistorAlignment)
	{
	case(1):
		totalResistance = inSeries(nResistors, resistanceAmounts);
		break;
	case(2):
		totalResistance = inParallel(nResistors, resistanceAmounts);
		break;
	}

	cout << "\nYour total resistance is: " << totalResistance << " ohms.\n\n";

	free(resistanceAmounts);
	return;
}

int verifyResistorAlignment()
{
	int resistorAlignment;

	do
	{
		cout << "\nAre they in series or in parallel? (1) In series, (2) In parallel ";
		cin >> resistorAlignment;

		if (resistorAlignment != 1 && resistorAlignment != 2)
		{
			cout << "\nError! Please enter either 1 or 2.\n\n";
		}

	} while (resistorAlignment != 1 && resistorAlignment != 2);

	return resistorAlignment;
}

double inSeries(int nResistors, int* resistanceAmounts)
{
	int i;
	double totalResistance = 0;

	for (i = 0; i < nResistors; i++)
	{
		totalResistance += resistanceAmounts[i];
	}

	return totalResistance;
}

double inParallel(int nResistors, int* resistanceAmounts)
{
	int i;
	double totalResistance = 0;

	for (i = 0; i < nResistors; i++)
	{
		totalResistance += (1.0 / resistanceAmounts[i]);
	}

	totalResistance = 1.0 / totalResistance;

	return totalResistance;
}