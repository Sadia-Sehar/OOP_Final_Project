#include "StrongHold2.h"

CommunicationSystem::CommunicationSystem()
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        messageCount[i] = 0;
    }
}

void CommunicationSystem::sendMessage(int senderId, int receiverId, const string& message)
{
    if (messageCount[receiverId] < MAX_MESSAGES)
    {
        messages[receiverId][messageCount[receiverId]++] = "From Player " + to_string(senderId) + ": " + message;
    }
}

void CommunicationSystem::displayMessages(int playerId)
{
    cout << "Messages for Player " << playerId << endl;
    for (int i = 0;i < messageCount[playerId];i++)
    {
        cout << messages[playerId][i] << endl;
    }
}