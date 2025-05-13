#ifndef STRONGHOLD2_H
#define STRONGHOLD2_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_PLAYERS = 10; // Max players
const int MAX_MESSAGES = 50; // Max messages per player
const int MAX_ALLIANCES = 5; // Max alliances per player
const int MAX_TERRITORIES = 10; // Max territories in the map

//Player
class Player
{
public:
	string name;
	int id;
	int allies[MAX_ALLIANCES];
	int numAllies;
public:
	Player(string n = "Unknown", int x = 0);

};

//Communication System
class CommunicationSystem
{
private:
	string messages[MAX_PLAYERS][MAX_MESSAGES];
	int messageCount[MAX_PLAYERS];
public:
	CommunicationSystem();
	void sendMessage(int senderId, int receiverId, const string& message);
	void displayMessages(int playerId);
};

//Alliance Manager
class AllianceManager
{
private:
	int alliances[MAX_PLAYERS][MAX_PLAYERS];
public:
	AllianceManager();
	void formAlliance(int player1, int player2);
	void breakAlliance(int player1,int player2);
	bool areAllied(int player1,int player2);
};

//Market System
class MarketSystem
{
public:
	void initiateTrade(int sellerId, int buyerId, const string& item, int price);
};

//ConflictManager
class ConflictManager
{
public:
	void declareWar(int attackerId, int defenderId);
};

//Territory
class Territory
{	
public:
	int id;
	string owner;
	Territory(int x = 0, string o = "Unknown");
};

//Map
class Map
{
private:
	Territory territories[MAX_TERRITORIES];
public:
	Map();
	void claimTerritory(int territoryId, const string& playerName);
	void displayTerritories();
};

//Game Session
class GameSession
{
private:
	Player* players[MAX_PLAYERS];
	int numPlayers;

	CommunicationSystem communication;
	AllianceManager allianceManager;
	MarketSystem marketSystem;
	ConflictManager conflictManager;
	Map gameMap;
public:
	GameSession();
	void addPlayer(const string& name);
	Player* getPlayerById(int id);
	void simulate();
	~GameSession();
};

#endif