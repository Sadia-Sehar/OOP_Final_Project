#include "StrongHold.h"

Army::Army(int s,int m,int tl,int cl):size(s),morale(m),trainingLevel(tl),corruptionLevel(cl){}

void Army::recruit(int n)
{
	if (n > 0)
	{
		size += n;
		cout << n << " soldiers recruited. Current Army size: " << getSize() << endl;
	}
	else
		cout << "Invalid input. Army size same as before." << endl;
}

void Army::train(int hrs)
{
	if (hrs > 0)
	{
		trainingLevel += hrs;
		if (trainingLevel > 100) {
			trainingLevel = 100;
		}
		cout << "Training level increased to " << getTrainingLevel() << endl;
	}
	else
		cout << "Invalid Input. Hours should be positive." << endl;
}

void Army::updateMorale(int change)
{
	morale += change;
	if (morale < 0) morale = 0;
	if (morale > 100) morale = 100;
	cout << "Morale updated to " << getMorale() << endl;
}

void Army::updateCorruptionLevel(int change)
{
	corruptionLevel += change;
	if (corruptionLevel < 0)
		corruptionLevel = 0;
	if (corruptionLevel > 0)
		corruptionLevel=100;
	cout << "Corruption Level updated to " << getCorruptionLevel() << endl;
}
void Army::paySoldiers(Economy& e)
{
	int payment = size * 5;
	if (e.getTreasury() >= payment)
	{
		e.deductFromTreasury(payment);
		cout << "Soldiers have been paid. Current treasury: "<<e.getTreasury() << endl;
		if (Army::getCorruptionLevel() > 0)
		{
			cout << "Corruption found ! Morale dropped by 10." << endl;
			updateMorale(-10);
		}
	}
	else
	{
		cout << "Not enough funds to pay soldiers !\n Morale dropped by 20." << endl;
		updateMorale(-20);
	}
}
int Army::getSize()
{
	return size;
}
int Army::getMorale()
{
	return morale;
}
int Army::getTrainingLevel()
{
	return trainingLevel;
}
int Army::getCorruptionLevel()
{
	return corruptionLevel;
}