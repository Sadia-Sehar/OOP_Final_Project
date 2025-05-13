#ifndef STRONGHOLD_H
#define STRONGHOLD_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Economy;

class Social
{
protected:
	string name;
	int population;
	int wealth;
	int influence;
	int happiness;
public:
	Social(string n = "Unknown", int p = 0, int w = 0, int inf = 0, int hap = 0);
	void interact(Social& other);
	void updateHappiness(int amount);
	void updateWealth(int amount);
	string getName();
	int getPopulation();
	int getWealth();
	int getInfluence();
	int getHappiness();
};

class Population
{
protected:
	int totalPopulation;
	int healthyPopulation;
	int sickPopulation;
	int revolts;
public:
	Population(int tp = 0, int hp = 0, int sp = 0, int r = 0);
	void increasePopulation(int n);
	void decreasePopulation(int n);
	void updateHealth(int healthy, int sick);
	void triggerRevolt();
	int getPopulation();
	int getHealthyPopulation();
	int getSickPopulation();
	int getRevolts();
};

class Army
{
protected:
	int size;
	int morale;
	int trainingLevel;
	int corruptionLevel;
public:
	Army(int s = 0, int m = 0, int tl = 0, int cl = 0);
	void recruit(int n);
	void train(int hours);
	void updateMorale(int change);
	void updateCorruptionLevel(int change); //
	void paySoldiers(Economy& e);
	int getSize();
	int getMorale();
	int getTrainingLevel();
	int getCorruptionLevel();
};

class Leader
{
protected:
	string name;
	int popularity;
	int id;
	string policies; 
	int tenure;
public:
	Leader(string n = "Unknown", int p = 0,int id=0, string po = "None", int t = 0);
	void changePolicies(string newPolicies);
	void holdElection(Leader candidates[],int numCandidates);
	void updatePopularity(int change);
	void appointNewLeader(Leader candidates[], int numCandidates);
	void resetDetails();
	string getName();
	int getPopularity();
	int getId();
	string getPolicies(); 
	int getTenure();
};

class Economy
{
protected:
	int treasury;
	int taxRate;
	int inflationRate;
	int expenses;
public:
	Economy(int t = 0, int tr = 0, int ir = 0, int exp = 0);
	void collectTaxes(Population& p);
	void changeTaxRate(int newRate);
	void calculateInflation();
	void recordExpenses(Economy& e,int amount); 
	void deductFromTreasury(int amount);
	void addToTreasury(int amount);
	int getTreasury();
	int getTaxRate();
	int getInflationRate();
	int getExpenses();

};

class Bank
{
protected:
	int totalLoans;
	int interestRate;
	int fraudLevel; 
public:
	Bank(int tl = 0, int ir = 0, int fl = 0);
	void issueLoan(Economy& e,int amount);
	void audit(); 
	void collectInterest(Economy& e); 
	void updateInterestRate(int newRate);
	int getTotalLoans();
	int getInterestRate();
	int getFraudLevel();
};

class Resource
{
protected:
	string type;
	int quantity;
	int consumptionRate;
public:
	Resource(string t = "Unknown", int q = 0, int cr = 0);
	void gatherResource(int amount);
	void consumeResource(int amount);
	void tradeResource(Resource& other, int amount);
	string getType();
	int getQuantity();
	int getConsumptionRate();
};

class Event
{
protected:
	string eventType;
	int duration;
	bool isActive;
public:
	Event(string t = "Unknown", int d = 0, bool a = false);
	void triggerEvent(Population& p, Economy& e, Resource& r, Army& a, Social& s);
	void applyFamineEffect(Population& p, Economy& e);
	void applyDiseaseEffect(Population& p);
	void applyWarEffect(Army& a, Economy& e);
	void applyPlagueEffect(Resource& r, Economy& e);
	void applyFestivalEffect(Social& s, Resource& r);
	string getEventType()const;
	int getDuration()const;
	bool getStatus()const;
};

class AI
{
public:
	void makeTaxDecision(Economy& economy, Population& population);
	void mobilizeArmy(Army& army, Economy& economy);
	void handleInternalConflict(Population& population, Economy& economy);
};

#endif
