#include "StrongHold2.h"

Map::Map()
{
    for (int i = 0; i < MAX_TERRITORIES; i++) {
        territories[i].id = i;
        territories[i].owner = "None";
    }
}
void Map::claimTerritory(int territoryId, const string& playerName)
{
    territories[territoryId].owner = playerName;
    cout << playerName << " has claimed territory " << territoryId << "." << endl;
}
void Map::displayTerritories()
{
    cout << "Territory Ownership:\n";
    for (int i = 0; i < MAX_TERRITORIES; i++) 
    {
        cout << "Territory " << territories[i].id << " owned by: " << territories[i].owner << endl;
    }
}