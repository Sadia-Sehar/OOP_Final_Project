#include "StrongHold.h"

void AI::makeTaxDecision(Economy& economy, Population& population)
{
	int currentWealth = economy.getTreasury();
	int populationSize = population.getPopulation();
	if (currentWealth < 2000)
	{
		economy.changeTaxRate(30);
		cout << "AI: Changed tax rate to 30% due to low treasury." << endl;
	}
	else if (currentWealth > 500)
	{
		economy.changeTaxRate(10);
		cout << "AI: Changed tax rate to 10% due to high treasury." << endl;
	}
	else
	{
		cout << "AI: Maintained current tax rate of " << economy.getTaxRate() << " %" << endl;
	}
}

void AI::mobilizeArmy(Army& army, Economy& economy)
{
	int armySize = army.getSize();
	int treasury = economy.getTreasury();
	if (treasury > 300 && armySize < 200)
	{
		army.recruit(50);
		economy.deductFromTreasury(1500);
		cout << "AI: Mobilized army by recruiting 50 soldiers." << endl;
	}
	else
	{
		cout << "AI: Army size and treasury level are adequate." << endl;
	}
}

void AI::handleInternalConflict(Population& population, Economy& economy)
{
	int revolts = population.getRevolts();
	if (revolts > 2)
	{
		economy.recordExpenses(economy,100);
		population.updateHealth(population.getHealthyPopulation() + 15, population.getSickPopulation() - 15);
		cout << "AI:: Spent resources to quell revolts and improve population health." << endl;
	}
	else
		cout << "AI: No significant revolts detected." << endl;
}