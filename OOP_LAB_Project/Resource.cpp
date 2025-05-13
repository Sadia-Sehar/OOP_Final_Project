#include "StrongHold.h"

Resource::Resource(string t,int q,int cr):type(t),quantity(q),consumptionRate(cr){}
void Resource::gatherResource(int amount)
{
	quantity += amount;
	cout << "Resource gathered." << getType() << "'s current quantity: " << getQuantity() << endl;
}
void Resource::consumeResource(int amount)
{
	if (amount <= quantity) 
	{
		quantity -= amount;
		cout<<"Resource consumed." << getType() << "'s current quantity: " << getQuantity() << endl;
	}
	else {
		cout <<this->getType() <<": Not enough resources to consume." << endl;
	}
}
void Resource::tradeResource(Resource& other, int amount)
{
	if (quantity >= amount)
	{
		quantity -= amount;
		other.gatherResource(amount);
		cout << "Resources traded. \n" << getType() << "'s current queantity: " << getQuantity() << " | " << other.getType() << "'s current quantity: " << other.getQuantity() << endl;
	}
	else
	{
		cout << "Not enough resources to trade!" << endl;
	}
}
string Resource::getType()
{
	return type;
}
int Resource::getQuantity()
{
	return quantity;
}
int Resource::getConsumptionRate()
{
	return consumptionRate;
}


















