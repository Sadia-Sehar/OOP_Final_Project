#include "StrongHold2.h"

Player::Player(string n, int x) :name(n), id(x), numAllies(0)
{
	for (int i = 0;i < MAX_ALLIANCES;i++)
	{
		allies[i]=-1; // no ally initially
	}
}