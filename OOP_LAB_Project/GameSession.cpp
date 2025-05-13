#include "StrongHold2.h"

GameSession::GameSession():numPlayers(0)
{

}
void GameSession::addPlayer(const string& name)
{
    if (numPlayers < MAX_PLAYERS) {
        players[numPlayers] = new Player(name, numPlayers);
        cout << "Player added: " << name << " with ID " << numPlayers << endl;
        numPlayers++;
    }
    else {
        cout << "Maximum players reached!\n";
    }
}
Player* GameSession::getPlayerById(int id)
{
    if (id >= 0 && id < numPlayers) 
    {
        return players[id];
    }
    return nullptr;
}
void GameSession::simulate()
{
    // Example interaction:
    if (numPlayers < 2) {
        cout << "Not enough players to simulate.\n";
        return;
    }

    // Player 0 sends message to Player 1
    communication.sendMessage(0, 1, "Greetings, shall we form an alliance?");
    communication.displayMessages(1);

    // Form alliance between Player 0 and Player 1
    allianceManager.formAlliance(0, 1);

    // Check alliance status
    cout << "Are Player 0 and Player 1 allied? ";
    cout << (allianceManager.areAllied(0, 1) ? "Yes\n" : "No\n");

    // Player 0 initiates trade with Player 1
    marketSystem.initiateTrade(0, 1, "Wheat", 100);

    // Player 1 declares war on Player 0 (betrayal example)
    conflictManager.declareWar(1, 0);

    // Territory claiming
    gameMap.claimTerritory(0, players[0]->name);
    gameMap.claimTerritory(1, players[1]->name);

    // Display map territories
    gameMap.displayTerritories();
}
GameSession::~GameSession()
{
    for (int i = 0; i < numPlayers; i++) {
        delete players[i];
    }
}