#include "StrongHold.h"


Economy::Economy(int t,int tr,int ir,int exp):treasury(t),taxRate(tr),inflationRate(ir),expenses(exp){}

void Economy::collectTaxes(Population& p)
{
	int taxCollected = p.getPopulation() * taxRate; //hypothetical
	treasury += taxCollected;
}

void Economy::changeTaxRate(int newRate)
{
	if (newRate >= 0 && newRate <= 100) {
		taxRate = newRate;

	}
	else {
		cout << "Invalid tax rate. Must be between 0 and 100." << endl;
	}
}
void Economy::calculateInflation()
{
	if (expenses > treasury * 0.5) 
	{ 
		inflationRate += 5; 
	}
	if (inflationRate > 100) 
	{
		inflationRate = 100; 
	}
}

void Economy::recordExpenses(Economy& e,int amount)
{
	if (amount <= treasury) 
	{
		deductFromTreasury(amount);
		expenses += amount;
		cout << "Expenses covered. Current treasury: " << e.getTreasury() << endl;
	}
	else 
	{
		cout << "Not enough funds to cover the expense." << endl;
	}
}
void Economy::deductFromTreasury(int amount)
{
	treasury -= amount;
}

void Economy::addToTreasury(int amount)
{
	treasury += amount;
}
int Economy::getTreasury()
{
	return treasury;
}
int Economy::getTaxRate()
{
	return taxRate;
}
int Economy::getInflationRate()
{
	return inflationRate;
}
int Economy::getExpenses()
{
	return expenses;
}