//Poker Program version 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printTable(int handNumber, int currentPlayer, int bigBlindPlayer, int smallBlindPlayer, const vector<string>& playerName,
    const vector<int>& playerStack, const vector<int>& playerFoldCount,
    const vector<int>& playerRaiseCount, const vector<int>& playerCallCount,
    const vector<int>& playerHandCount, const vector<int>& playerWinCount) {
    cout << endl;
    cout << "  ________________________________________________________________|" << endl;
    cout << " |                     Hand #" << handNumber << " - Player #" << currentPlayer << "  " << endl;
    cout << " |----------------------------------------------------------------|" << endl;
    for (size_t i = 0; i < playerName.size(); i++) {
        string playerStatus = "";
        if (i + 1 == currentPlayer)
            cout << "---->";
        playerStatus;
        if (i + 1 == bigBlindPlayer)
            playerStatus += "  - Big Blind";
        if (i + 1 == smallBlindPlayer)
            playerStatus += "  - Small Blind";

        cout << " |  " << playerName[i] << playerStatus << ": " << endl;
        cout << " |  Folds: " << playerFoldCount[i] << "     (Folds %: " << ((double)playerFoldCount[i] / playerHandCount[i]) * 100 << ")" << endl;
        cout << " |  Raise: " << playerRaiseCount[i] << "     (Raise %: " << ((double)playerRaiseCount[i] / playerHandCount[i]) * 100 << ")" << endl;
        cout << " |  Calls: " << playerCallCount[i] << "     (Calls %: " << ((double)playerCallCount[i] / playerHandCount[i]) * 100 << ")" << endl;
        cout << endl;
        cout << " |  Wins: " << playerWinCount[i] << "     (Wins %: " << ((double)playerWinCount[i] / (handNumber - 1)) * 100 << ")" << endl;
        cout << " |----------------------------------------------------------------|" << endl;
    }
    cout << " |________________________________________________________________|" << endl;
    cout << endl;
}

int main() {
    int numPlayers;
    cout << "Enter the number of players: ";
    cin >> numPlayers;

    int handNumber = 1;

    vector<string> playerName(numPlayers, "Player");
    for (int i = 0; i < numPlayers; i++) {
        playerName[i] += " " + to_string(i + 1);
    }

    vector<int> playerStack(numPlayers, 1000);
    vector<int> playerFoldCount(numPlayers, 0);
    vector<int> playerRaiseCount(numPlayers, 0);
    vector<int> playerCallCount(numPlayers, 0);
    vector<int> playerHandCount(numPlayers, 0);
    vector<int> playerWinCount(numPlayers, 0);
    vector<bool> playerInHand(numPlayers, true);

    // Create copies of the states for the undo operation
    vector<string> playerNamePrev = playerName;
    vector<int> playerStackPrev = playerStack;
    vector<int> playerFoldCountPrev = playerFoldCount;
    vector<int> playerRaiseCountPrev = playerRaiseCount;
    vector<int> playerCallCountPrev = playerCallCount;
    vector<int> playerHandCountPrev = playerHandCount;
    vector<int> playerWinCountPrev = playerWinCount;
    vector<bool> playerInHandPrev = playerInHand;

    int currentPlayer = 1;
    int bigBlindPlayer = 2;
    int smallBlindPlayer = 1;
    int playersInCurrentHand = numPlayers;

    // Save the state before starting the game
    playerNamePrev = playerName;
    playerStackPrev = playerStack;
    playerFoldCountPrev = playerFoldCount;
    playerRaiseCountPrev = playerRaiseCount;
    playerCallCountPrev = playerCallCount;
    playerHandCountPrev = playerHandCount;
    playerWinCountPrev = playerWinCount;
    playerInHandPrev = playerInHand;

    while (true) {
        printTable(handNumber, currentPlayer, bigBlindPlayer, smallBlindPlayer, playerName, playerStack, playerFoldCount, playerRaiseCount, playerCallCount, playerHandCount, playerWinCount);
        cout << "Enter your choice: ";
        string action;
        cin >> action;

        // If undo operation, replace current states with previous states and skip the rest of the loop
        if (action == "U" || action == "u") {
            playerName = playerNamePrev;
            playerStack = playerStackPrev;
            playerFoldCount = playerFoldCountPrev;
            playerRaiseCount = playerRaiseCountPrev;
            playerCallCount = playerCallCountPrev;
            playerHandCount = playerHandCountPrev;
            playerWinCount = playerWinCountPrev;
            playerInHand = playerInHandPrev;
            continue;
        }
        if (action == "C" || action == "c") {
            cout << playerName[currentPlayer - 1] << " called." << endl;
            playerStack[currentPlayer - 1] -= 10;
            playerCallCount[currentPlayer - 1]++;
            playerHandCount[currentPlayer - 1]++;
        }
        else if (action == "R" || action == "r") {
            cout << playerName[currentPlayer - 1] << " raised." << endl;
            playerStack[currentPlayer - 1] -= 20;
            playerRaiseCount[currentPlayer - 1]++;
            playerHandCount[currentPlayer - 1]++;
        }
        else if (action == "F" || action == "f") {
            cout << playerName[currentPlayer - 1] << " folded." << endl;
            playerFoldCount[currentPlayer - 1]++;
            playerHandCount[currentPlayer - 1]++;
            playerInHand[currentPlayer - 1] = false;
            playersInCurrentHand--;
        }
        else if (action == "B" || action == "b") {
            cout << playerName[currentPlayer - 1] << " is now the big blind." << endl;
            bigBlindPlayer = currentPlayer;
        }
        else if (action == "S" || action == "s") {
            cout << playerName[currentPlayer - 1] << " is now the small blind." << endl;
            smallBlindPlayer = currentPlayer;
        }
        else if (action == "M" || action == "m") {
            cout << playerName[currentPlayer - 1] << " is now you." << endl;
            playerName[currentPlayer - 1] = "You";
        }


        else if (action == "G" || action == "g") {
            cout << playerName[currentPlayer - 1] << " reversing direction." << endl;
            do {
                currentPlayer = (currentPlayer + numPlayers - 2) % numPlayers + 1;
            } while (!playerInHand[currentPlayer - 1]);
            continue;
        }

        else if (action == "V" || action == "v") {
            cout << playerName[currentPlayer - 1] << " is skipped." << endl;
            currentPlayer = currentPlayer % numPlayers + 1;
            continue;
        }
        else if (action == "X" || action == "x") {
            cout << playerName[currentPlayer - 1] << " is eliminated." << endl;
            playerName.erase(playerName.begin() + currentPlayer - 1);
            playerStack.erase(playerStack.begin() + currentPlayer - 1);
            playerFoldCount.erase(playerFoldCount.begin() + currentPlayer - 1);
            playerRaiseCount.erase(playerRaiseCount.begin() + currentPlayer - 1);
            playerCallCount.erase(playerCallCount.begin() + currentPlayer - 1);
            playerHandCount.erase(playerHandCount.begin() + currentPlayer - 1);
            playerWinCount.erase(playerWinCount.begin() + currentPlayer - 1);
            playerInHand.erase(playerInHand.begin() + currentPlayer - 1);
            numPlayers--;
            playersInCurrentHand--;
        }
        else if (action == "N" || action == "n") {
            string newName;
            cout << "Enter the new name for player " << currentPlayer << ": ";
            cin >> newName;
            playerName[currentPlayer - 1] = newName;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        // Update the previous states to current states after each action
        playerNamePrev = playerName;
        playerStackPrev = playerStack;
        playerFoldCountPrev = playerFoldCount;
        playerRaiseCountPrev = playerRaiseCount;
        playerCallCountPrev = playerCallCount;
        playerHandCountPrev = playerHandCount;
        playerWinCountPrev = playerWinCount;
        playerInHandPrev = playerInHand;

        if (playersInCurrentHand <= 1) {
            for (int i = 0; i < numPlayers; i++) {
                if (playerInHand[i]) {
                    playerWinCount[i]++; // this player wins the hand.
                    cout << playerName[i] << " won the hand." << endl;
                    break;
                }
            }

            cout << "Hand ended. Moving blinds and starting new hand..." << endl;
            smallBlindPlayer = bigBlindPlayer % numPlayers + 1;
            bigBlindPlayer = smallBlindPlayer % numPlayers + 1;
            currentPlayer = bigBlindPlayer % numPlayers + 1;
            playersInCurrentHand = numPlayers;
            fill(playerInHand.begin(), playerInHand.end(), true);
            handNumber++;
        }
        else {
            do {
                currentPlayer = currentPlayer % numPlayers + 1;
            } while (!playerInHand[currentPlayer - 1]);
        }

    }
}
