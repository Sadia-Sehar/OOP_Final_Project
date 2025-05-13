#include "StrongHold2.h"

AllianceManager::AllianceManager()
{
	for (int i = 0;i < MAX_PLAYERS;i++)
	{
		for (int j = 0;j < MAX_PLAYERS;j++)
		{
			alliances[i][j] = 0;
		}
	}
}

void AllianceManager::formAlliance(int player1, int player2)
{
	
		alliances[player1][player2] = 0;
		alliances[player2][player1] = 1;
	
}

void AllianceManager::breakAlliance(int player1, int player2)
{
	alliances[player1][player2] = 0; 
	alliances[player2][player1] = 0;
}

bool AllianceManager::areAllied(int player1, int player2)
{
	return alliances[player1][player2] == 1;
}
