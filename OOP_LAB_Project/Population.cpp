#include "StrongHold.h"


Population::Population(int tp,int hp,int sp,int r):totalPopulation(tp),healthyPopulation(hp),sickPopulation(sp),revolts(r){}

void Population::increasePopulation(int n)
{
	totalPopulation += n;
	healthyPopulation += n;//Let's assume that new population is healthy
}

void Population::decreasePopulation(int n)
{
	if (n > totalPopulation)
	{
		totalPopulation = 0;
	}
	else
	{
		totalPopulation -= n;
		if (healthyPopulation > n) {
			healthyPopulation -= n;
		}
		else {
			sickPopulation -= (n - healthyPopulation);
			healthyPopulation = 0;
		}
	}
	
}

void Population::updateHealth(int healthy, int sick)
{
	healthyPopulation += healthy;
	sickPopulation += sick;
	totalPopulation = healthyPopulation + sickPopulation;
}

void Population::triggerRevolt()
{
	revolts++;
	int decrease = totalPopulation * 0.05;// 5% population decrease as a result of one revolt
	decreasePopulation(decrease);
}

int Population::getPopulation()
{
	return totalPopulation;
}
int Population::getHealthyPopulation()
{
	return healthyPopulation;
}
int Population::getSickPopulation()
{
	return sickPopulation;
}
int Population::getRevolts()
{
	return revolts;
}