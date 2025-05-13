#include "StrongHold.h"

Event::Event(string t,int d,bool a):eventType(t),duration(d),isActive(a){}
void Event::triggerEvent(Population& p,Economy& e,Resource& r,Army& a,Social& s)
{
    int randomEventType = rand() % 5; 
    switch (randomEventType) {
    case 0: // Famine
        this->eventType = "Famine";
        applyFamineEffect(p,e);
        break;
    case 1: // Disease
        this->eventType = "Disease";
        applyDiseaseEffect(p);
        break;
    case 2: // War
        this->eventType = "War";
        applyWarEffect(a,e);
        break;
    case 3: // Plague
        this->eventType = "Natural Disaster";
        applyPlagueEffect(r,e);
        break;
    case 4: // Festival
        this->eventType = "Festival";
        applyFestivalEffect(s,r);
        break;
    }
    isActive = true; 
}

void Event::applyFamineEffect(Population& p,Economy& e)
{
    cout << "A famine has struck the kingdom!" << endl;
    p.decreasePopulation(static_cast<int>(p.getPopulation() * 0.1)); // Decrease population by 10%
    cout << "Population decreased due to famine. Current population: " << p.getPopulation() << endl;
    e.recordExpenses(e,50);
    cout << "Expenses recorded. Current treasury: "<<e.getTreasury() << endl;
}
void Event::applyDiseaseEffect(Population& p)
{
    std::cout << "A disease outbreak has occurred!" << std::endl;
    p.updateHealth(-10, 10);
    cout << "Current healthy Population: " << p.getHealthyPopulation() << " | Current sick Population: " << p.getSickPopulation() << endl;
}
void Event::applyWarEffect(Army& a,Economy& e)
{
    std::cout << "The kingdom is at war!" << std::endl;
    a.updateMorale(-20); 
    cout << "Morale decreased. current morale: " << a.getMorale() << endl;
    e.recordExpenses(e,100);
    cout << "Expenses recorded. Current treasury: " << e.getTreasury() << endl;
}
void Event::applyPlagueEffect(Resource& r,Economy& e)
{
    std::cout << "A natural disaster has devastated the land!" << std::endl;
    r.consumeResource(50); 
    cout << "Resource "<<r.getType()<<" consumed.Current resource quantity : "<<r.getQuantity() << endl;
    e.recordExpenses(e,200);
    cout << "Expenses recorded. Current treasury: " << e.getTreasury() << endl;
}
void Event::applyFestivalEffect(Social& s,Resource& r)
{
    std::cout << "A festival is being held!" << std::endl;
    s.updateHappiness(15);
    cout << "Happiness level increased. Current happiness level: " << s.getHappiness() << endl;
    r.gatherResource(20);
    cout << "Resource " << r.getType() << " gathered. current quantity: "<<r.getQuantity() << endl;
}
string Event::getEventType()const
{
    return eventType;
}
int Event::getDuration()const
{
    return duration;
}
bool Event::getStatus()const
{
    return isActive;
}