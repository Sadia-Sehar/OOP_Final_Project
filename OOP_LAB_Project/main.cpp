#include "StrongHold.h"
#include "StrongHold2.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <fstream>
using namespace std;

    void displayMenu()
    {
        
        cout << "\n--- StrongHold Game Menu ---" << endl;
        cout << " 1. Chancellor [Economic growth and stability] " << endl;
        cout << " 2. Arbiter [Manage social harmony]" << endl;
        cout << " 3. Sovereign [Lead with authority]" << endl;
        cout << " 4. Banker [Control finances and credit]" << endl;
        cout << " 5. Provisioner [Oversee resources and supplies]" << endl;
        cout << " 6. Warlord [Command military forces]" << endl;
        cout << " 7. Event Maestro [Control Events]" << endl;
        cout << " 8. Save Game" << endl;
        cout << " 9. Load Game" << endl;
        cout << "10. Run AI Turn" << endl;
        cout << "11. Exit" << endl;
        cout << "Choose an option: ";
    }
    void logScoreAndResource(int score, string resourceName, int resourceQuantity) {
        ofstream scoreFile("score.txt", ios::app);
        if (scoreFile.is_open()) {
            time_t now = time(0);
            tm ltm;
            localtime_s(&ltm, &now);
            char timeStr[20];
            strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &ltm);

            scoreFile << "[" << timeStr << "] Score: " << score << ", Resource " << resourceName << " Usage: " << resourceQuantity << endl;
            scoreFile.close();
        }
        else {
            cout << "Error opening score.txt for logging." << endl;
        }
    }
    int main()
    {
        GameSession session;

        session.addPlayer("Arthur");
        session.addPlayer("Lancelot");

        session.simulate();
        srand(static_cast<unsigned int>(time(0)));
        cout << "Welcome to Imperial Kingdom of Sehmav! \nBy Steel and Will, Sehmav Reigns~" << endl;
        cout << "Choose Your Role and Govern The Kingdom!" << endl;

        Social s1("Merchants", 1000, 5000, 50, 77);
        Social s2("Peasants", 800, 3000, 45, 80);
        Population population(5000, 4000, 1000, 3);
        Army army(150, 80, 5, 0);
        string leaderPolicies =
            "1. Promote trade and commerce to boost the economy.\n"
            "2. Ensure equal rights and opportunities for all citizens.\n"
            "3. Implement sustainable practices to protect natural resources.\n"
            "4. Strengthen the military to protect the kingdom's borders.\n"
            "5. Invest in education and healthcare for a healthier society.";
        Leader currentLeader("Alice", 70, 1, leaderPolicies, 5);
        Leader candidates[] = {
            Leader("Bob", 50, 2,leaderPolicies,3),
            Leader("Charlie", 60, 3,leaderPolicies,2),
            Leader("David", 40, 4,leaderPolicies,5)
        };
        int numCandidates = sizeof(candidates) / sizeof(candidates[0]);
        Economy economy(5000, 20, 3, 0);
        Bank bank(1000, 3, 20);
        Resource r1("Food", 4500, 10);
        Resource r2("Wood", 550, 4);
        Resource r3("Iron", 200, 1);
        Event event;
        AI ai;
        int option;
        int amount;
        int choice;
        bool running = true;

        while (running) 
        {
            displayMenu();
            cin >> choice;

            switch (choice) 
            {
            case 1:// Economic growth and stability
            {
                bool x = true;
                while (x)
                {
                    cout << "\n---Economy Control Menu---" << endl;
                    cout << "1. Collect Taxes" << endl;
                    cout << "2. Change tax rate" << endl;
                    cout << "3. Calculate Inflation" << endl;
                    cout << "4. Record Expenses" << endl;
                    cout << "5. Exit " << endl;
                    cout << "Pick an option: ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                    {
                        economy.collectTaxes(population);
                        cout << "Tax collected. Current treasury: " << economy.getTreasury() << endl;
                    }
                    break;
                    case 2:
                    {
                        int newTaxRate;
                        cout << "Enter new Tax Rate: ";
                        cin >> newTaxRate;
                        if (newTaxRate < 0)
                        {
                            cout << "Invalid tax rate input." << endl;
                        }
                        else
                        {
                            economy.changeTaxRate(newTaxRate);
                            cout << "Tax rate changed. New tax rate: " << newTaxRate << endl;
                        }
                    }
                    break;
                    case 3:
                    {
                        economy.calculateInflation();
                        cout << "Inflation rate calculated.Current inflation rate: " << economy.getInflationRate() << endl;
                    }
                    break;
                    case 4:
                    {
                        cout << "Enter amount to record expenses: ";
                        cin >> amount;
                        if (amount < 0)
                            cout << "Invalid Input! " << endl;
                        else
                        {
                            economy.recordExpenses(economy, amount);
                        }
                    }
                    break;
                    case 5:
                        x = false;
                        cout << "Exiting Economy Control.\n" << endl;
                        break;
                    default:
                        cout << "Invalid Option Input! " << endl;
                    }
                }
                
            }

                break;
            case 2:// Manage social harmony
            {
                bool x = true;
                while (x)
                {
                    cout << "\n---Society Control Menu---" << endl;
                    cout << "1. Invoke interaction" << endl;
                    cout << "2. Update Happiness" << endl;
                    cout << "3. Update Wealth" << endl;
                    cout << "4. Exit " << endl;
                    cout << "Pick an option: ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                    {
                        s1.interact(s2);
                    }
                    break;
                    case 2:
                    {
                        cout << "Enter points: ";
                        cin >> amount;
                        s1.updateHappiness(amount);
                        s2.updateHappiness(amount);
                    }
                    break;
                    case 3:
                    {
                        cout << "Enter amount: ";
                        cin >> amount;
                        s1.updateWealth(amount);
                        s2.updateWealth(amount);
                    }
                    break;
                    case 4:
                        x = false;
                        cout << "Exiting Society Control.\n" << endl;
                        break;
                    default:
                        cout << "Invalid Option Input!" << endl;
                    }
                }
            }
                break;
            case 3:// Lead with authority
            {
                bool x = true;
                while (x)
                {
                    cout << "\n---Leadership Control Menu---" << endl;
                    cout << "1. Change current policies" << endl;
                    cout << "2. Hold election" << endl;
                    cout << "3. Update Popularity" << endl;
                    cout << "4. Exit " << endl;
                    cout << "Pick an option: ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                    {
                        string newPolicies;
                        cout << "Enter new policies: ";
                        cin.ignore();
                        getline(cin, newPolicies);
                        currentLeader.changePolicies(newPolicies);
                    }
                    break;
                    case 2:
                    {
                        currentLeader.holdElection(candidates, numCandidates);
                    }
                    break;
                    case 3:
                    {
                        cout << "Enter points to update popularity: ";
                        cin >> amount;
                        currentLeader.updatePopularity(amount);
                    }
                    break;
                    case 4:
                        x = false;
                        cout << "Exiting Leadership Control.\n" << endl;
                        break;
                    default:
                        cout << "Invalid option Input!" << endl;
                    }
                }
            }
                break;
            case 4:// Control finances and credit
            {
                bool x = true;
                while (x)
                {
                    cout << "\n---Bank Control Menu---" << endl;
                    cout << "1. Issue Loan" << endl;
                    cout << "2. Do Audit" << endl;
                    cout << "3. Collect Interest" << endl;
                    cout << "4. Update Interest rate" << endl;
                    cout << "5. Exit " << endl;
                    cout << "Pick an option: ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                    {
                        cout << "Enter amount to issue loan: " << endl;
                        cin >> amount;
                        if (amount < 0)
                            cout << "Invalid amount! default set to 0." << endl;
                        bank.issueLoan(economy, amount);
                        cout << "Loan issued. Currant treasury: " << economy.getTreasury() << endl;

                    }
                    break;
                    case 2:
                    {
                        bank.audit();
                    }
                    break;
                    case 3:
                    {
                        bank.collectInterest(economy);
                    }
                    break;
                    case 4:
                    {
                        cout << "Enter new Interest rate: " << endl;
                        cin >> amount;
                        bank.updateInterestRate(amount);
                    }
                    break;
                    case 5:
                        x = false;
                        cout << "Exiting Bank Control.\n" << endl;
                        break;
                    default:
                        cout << "Invalid Option Input!" << endl;
                    }
                }
            }
                break;
            case 5:// Oversee resources and supplies
            {
                bool x = true;
                while (x)
                {
                    cout << "\n---Resources Control Menu---" << endl;
                    cout << "1. Gather resources" << endl;
                    cout << "2. Consume resources" << endl;
                    cout << "3. Trade resources" << endl;
                    cout << "4. Exit " << endl;
                    cout << "Pick an option: ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                    {
                        cout << "Enter amount to gather: ";
                        cin >> amount;
                        r1.gatherResource(amount);
                        r2.gatherResource(amount);
                        r3.gatherResource(amount);
                    }
                    break;
                    case 2:
                    {
                        cout << "Enter amount to consume: ";
                        cin >> amount;
                        r1.consumeResource(amount);
                        r2.consumeResource(amount);
                        r3.consumeResource(amount);
                    }
                    break;
                    case 3:
                    {
                        cout << "Trading resources between Food and Wood...." << endl;
                        cout << "Enter trade amount: ";
                        cin >> amount;
                        r1.tradeResource(r2, amount);
                    }
                    break;
                    case 4:
                        x = false;
                        cout << "Exiting Resource Control.\n" << endl;
                        break;
                    default:
                        cout << "Invalid option Input! " << endl;
                    }
                }
            }

                break;
            case 6:// Command military forces
            {
                bool x = true;
                while (x)
                {
                    cout << "\n---Military Control Menu---" << endl;
                    cout << "1. Recruit" << endl;
                    cout << "2. Train Soldiers" << endl;
                    cout << "3. Update Morale " << endl;
                    cout << "4. Update Corruption Level" << endl;
                    cout << "5. Pay soldiers" << endl;
                    cout << "6. Exit " << endl;
                    cout << "Pick an option: ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                    {
                        cout << "Enter the number of soldiers you want to recruit: ";
                        cin >> amount;
                        army.recruit(amount);
                    }
                    break;
                    case 2:
                    {
                        cout << "Enter additional training hours: ";
                        cin >> amount;
                        army.train(amount);

                    }
                    break;
                    case 3:
                    {
                        cout << "Enter Morale change: ";
                        cin >> amount;
                        army.updateMorale(amount);
                    }
                    break;
                    case 4:
                    {
                        cout << "Enter corruption level change: ";
                        cin >> amount;
                        army.updateCorruptionLevel(amount);
                    }
                    break;
                    case 5:
                    {
                        army.paySoldiers(economy);
                    }
                    break;
                    case 6:
                        x = false;
                        cout << "Exiting Military Control.\n" << endl;
                        break;
                    default:
                        cout << "Invalid Option Input! " << endl;
                    }
                }
            }

                break;
            case 7:// Trigger event
            {
                cout << "Randomly triggering an event...." << endl;
                event.triggerEvent(population, economy, r1, army, s1);
            }

                break;
            case 8:// Save Game
            {
                ofstream outFile("game_save.txt", ios::app);
                if (outFile.is_open()) {
                    time_t now = time(0);
                    tm ltm;
                    localtime_s(&ltm, &now);

                    char timeStr[20];
                    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &ltm);

                    outFile << "[" << timeStr << "] Current Population: " << population.getPopulation() << endl;
                    outFile << "[" << timeStr << "] Current Treasury: " << economy.getTreasury() << endl;
                    outFile << "[" << timeStr << "] Current Resource (" << r1.getType() << ") Quantity: " << r1.getQuantity() << endl;
                    outFile << "[" << timeStr << "] Current Resource (" <<r2.getType()<<") Quantity: " << r2.getQuantity() << endl;
                    outFile << "[" << timeStr << "] Current Resource (" << r3.getType() << ") Quantity: " << r3.getQuantity() << endl;
                    outFile << "[" << timeStr << "] Current Army size: " << army.getSize() << endl;
                    outFile << "[" << timeStr << "] Current Happiness level(" <<s1.getName() << "): " << s1.getHappiness() << endl;
                    outFile << "[" << timeStr << "] Current Happiness level(" << s2.getName() << "): " << s2.getHappiness() << endl;
                    outFile << "[" << timeStr << "] Current Leader: " << currentLeader.getName() << endl;
                    outFile << "[" << timeStr << "] Popularity of current leader: " << currentLeader.getPopularity() << endl;
                    outFile << "                    ---------------------                           " << endl;
                    cout << endl;

                    outFile.close();
                    logScoreAndResource(economy.getTreasury(), r1.getType(), r1.getQuantity());

                    cout << "Game saved successfully." << endl;
                }
                else {
                    cout << "Error saving game." << endl;
                }
            }

                break;
            case 9:// Load Game
            {
                ifstream inFile("game_save.txt");
                if (inFile.is_open()) {
                    int pop, treasury, res, armySize, hap;
                    string leaderName;
                    int leaderPopularity;

                    inFile >> pop >> treasury >> res >> armySize >> hap;
                    inFile >> leaderName >> leaderPopularity;

                    population = Population(pop, pop, 0, 0);
                    economy = Economy(treasury, 20, 2, 0);
                    r1 = Resource("Food", res, 10);
                    army = Army(armySize, 80, 5, 0);
                    s1 = Social("Merchants", pop, 5000, 0, hap);
                    currentLeader = Leader(leaderName, leaderPopularity, 1, "None", 0);

                    inFile.close();
                    cout << "Game loaded successfully." << endl;
                }
                else {
                    cout << "Error loading game." << endl;
                }
            
            }

                break;
            case 10:// Run AI Turn
            {
                cout << "\n--- AI Turn Begins ---" << endl;
                ai.makeTaxDecision(economy, population);
                ai.mobilizeArmy(army, economy);
                ai.handleInternalConflict(population, economy);
                cout << "--- AI Turn Ends ---\n" << endl;
            }

            break;
            case 11:// Exit
            {
                running = false;
                cout << "Exiting game." << endl;
                break;
            }

                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        cout << "Hi";

        return 0;
    }
