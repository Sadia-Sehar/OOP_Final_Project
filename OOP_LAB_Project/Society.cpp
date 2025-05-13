#include "StrongHold.h"




Social::Social(string n,int p,int w,int inf,int hap):name(n),population(p),wealth(w),influence(inf),happiness(hap){}

void Social::interact(Social& other)
{
	cout << getName() << " interacting with " << other.getName() << " randomly.\nLet's find out what fate has written for them! " << endl;
	int outcome = rand() % 3;//0=trade, 1=conflict, 2=support
	if (outcome == 0)
	{
		this->wealth += 10;
		other.wealth += 10;
		cout << "Trade Interaction. Wealth of both social classes has increased." << endl;
		cout << this->getName() << " Current Wealth: " << this->getWealth() << " | " << other.getName() << " Current Wealth: " << other.getWealth() << endl;
	}
	else if (outcome == 1)
	{
		this->happiness -= 5;
		other.happiness -= 5;
		cout << "Conflict Interaction.Happiness decreased by 5." << endl;
		cout << this->getName() << " Current Happiness: " << this->getHappiness() << " | " << other.getName() << " Current Happiness: " << other.getHappiness() << endl;
	}
	else if (outcome == 2)
	{
		this->influence += 1;
		other.influence += 1;
		cout << "Support Interaction. Influence increased by 1 point." << endl;
		cout << this->getName() << " Current Influence: " << this->getInfluence() << " | " << other.getName() << " Current Influence: " << other.getInfluence() << endl;
	}
}

void Social::updateHappiness(int amount)
{
	happiness += amount;
	if (happiness < 0) happiness = 0;
	if (happiness > 100) happiness = 100;
	cout << getName() << "'s happiness updated. Current happiness level: " << getHappiness() << endl;
}

void Social::updateWealth(int amount)
{
	wealth += amount;
	cout << getName() << "'s happiness updated. Current wealth: " << getWealth() << endl;
}
string Social::getName()
{
	return name;
}
int Social::getPopulation()
{
	return population;
}
int Social::getWealth()
{
	return wealth;
}
int Social::getInfluence()
{
	return influence;
}
int Social::getHappiness()
{
	return happiness;
}