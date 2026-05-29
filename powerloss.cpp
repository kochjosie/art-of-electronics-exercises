// powerloss.cpp
// This is a somewhat non-practical example from a practice problem in the Art of Electronics (1980).

#include <iostream>
#include <string>
#include <cmath>
#include "powerloss.h"

using namespace std;

void calculatePowerLost()
{
	double powerDemand;
	double voltageSupplied;
	double resistance;
	double diameter;
	string unit;
	double current;
	double powerLost;

	cout << "\nWhat are your units of length? ";
	cin >> unit;
	cout << "\nWhat are the power demands of your city in watts? ";
	cin >> powerDemand;
	cout << "\nAt what voltage is that power supplied? ";
	cin >> voltageSupplied;
	cout << "\nWhat is the resistance of your cable in ohms? ";
	cin >> resistance;
	cout << "\nWhat is the diameter of your cable? ";
	cin >> diameter;

	current = calculateCurrent(powerDemand, voltageSupplied);
	cout << "The current is " << current << " A.\n";
	powerLost = calculateLoss(current, resistance);
	cout << "The power lost across 1 " << unit << " is " << powerLost << "W.\n";
}

double calculateCurrent(double powerDemand, double voltageSupplied)
{
	double current;
	current = powerDemand / voltageSupplied;
	return current;
}

double calculateLoss(double current, double resistance)
{
	double powerLost;
	powerLost = pow(current, 2) * resistance;
	return powerLost;
}