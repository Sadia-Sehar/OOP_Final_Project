#include "StrongHold.h"



Leader::Leader(string n, int p, int i, string po, int t) :name(n), popularity(p), id(i), policies(po), tenure(t) {}

void Leader::changePolicies(string newPolicies)
{
	policies = newPolicies;
	cout << "Policies updated." << endl;
}

void Leader::holdElection(Leader candidates[], int numCandidates)
{
	cout << "Election being held...." << endl;
	int electionOutcome = rand() % 100;
	if (electionOutcome < popularity)
	{
		cout << name << " has been re-elected!" << endl;
	}
	else
	{
		cout << name << " has been ousted from power!" << endl;
		appointNewLeader(candidates, numCandidates);
	}
}

void Leader::resetDetails()
{
	name = "";
	popularity = 0;
	id = -1;
	policies = "";
	tenure = 0;
}

void Leader::appointNewLeader(Leader candidates[], int numCandidates)
{
	Leader* newLeader = nullptr;
	int l = rand() % numCandidates;
	for (int i = 0;i < numCandidates;i++)
	{
		if (i == l)
		{
			newLeader = &candidates[i];
		}
	}
	if (newLeader)
	{
		resetDetails();
		name = newLeader->name;
		popularity = newLeader->popularity;
		id = newLeader->id;
		policies = newLeader->policies;
		tenure = newLeader->tenure;
		cout << name << " has been appointed as the new leader!" << endl;
	}
}

void Leader::updatePopularity(int change)
{
	popularity += change;
	cout << "Popularity updated to " << this->getPopularity() << endl;
}
string Leader::getName()
{
	return name;
}
int Leader::getPopularity()
{
	return popularity;
}
int Leader::getId()
{
	return id;
}
string Leader::getPolicies()
{
	return policies;
}
int Leader::getTenure()
{
	return tenure;
}