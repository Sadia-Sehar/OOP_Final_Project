#include "StrongHold2.h"

void MarketSystem::initiateTrade(int sellerId, int buyerId, const string& item, int price)
{
	cout << "Trade initiated : Player " << sellerId << " sells " << item << " to " << buyerId << " for " << price << " gold." << endl;
}