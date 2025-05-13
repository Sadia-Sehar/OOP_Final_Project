#include "StrongHold.h"

Bank::Bank(int tl,int ir,int fl):totalLoans(tl),interestRate(ir),fraudLevel(fl){}
void Bank::issueLoan(Economy& e,int amount)
{
	totalLoans += amount;
	e.addToTreasury(amount);
}

void Bank::audit()
{
	int auditOutcome = rand() % 100; 
	if (auditOutcome < fraudLevel) 
	{
		cout << "Fraud detected during the audit!" << endl;
	}
	else 
	{
		std::cout << "Audit completed with no issues." << std::endl;
	}
}
void Bank::collectInterest(Economy& e)
{
	double interestCollected = totalLoans * (interestRate / 100.0);
	e.addToTreasury(static_cast<int>(interestCollected));
	cout << "Interest collected. Current treasury: " << e.getTreasury() << endl;
}
void Bank::updateInterestRate(int newRate)
{
	interestRate=newRate;
	cout << "Interest rate updated." << endl;
}
int Bank::getTotalLoans()
{
	return totalLoans;
}
int Bank::getInterestRate()
{
	return interestRate;
}
int Bank::getFraudLevel()
{
	return fraudLevel;
}