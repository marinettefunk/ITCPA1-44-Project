#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>

using namespace std;

vector<vector<int> > rollHistory;

// Function to handle input errors.
void inputError(const string& errorMessage) {
    cin.clear(); // Clear the error flag.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all remaining input.
    cout << errorMessage << endl; // Display error message.
}

// Function to roll the dice.
void rollDice() {
    int times = 2;
    
    do {
        
        if (cin.fail()) {
            inputError("Invalid input. Please enter a positive integer.");
        } else if (times <= 0) {
            cout << "Invalid input. Please enter a positive integer." << endl;
        } else {
            break; // Exit loop when valid input is received.
        }
    } while (true);
     
    cout << "Rolling the dice " << times << " times..." << endl;
    
    vector<int> currentRoll;
    for (int i = 1; i <= times; i++) {
        int roll = 1 + (rand() % 6); // Generate a random number between 1 and 6.
        cout << "Dice " << i << " rolled: " << roll << endl;
        currentRoll.push_back(roll);
    }

    rollHistory.push_back(currentRoll); // Store the current roll in history.
    cout << endl;
}

// Function to display roll history.
void history() {
    cout << "Roll History:\n" << endl;

    if (rollHistory.empty()) {
        cout << "No dice have been rolled yet.\n" << endl;
    } else {
        for (int i = 0; i < rollHistory.size(); i++) {
            cout << "Roll " << i + 1 << ":" << endl;
            for (int j = 0; j < rollHistory[i].size(); j++) {
                cout << "Dice " << j + 1 << " rolled: " << rollHistory[i][j] << endl;
            }
            cout << endl;
        }
    }
}

// Function to display the menu.
void menu() {
    cout << "Menu:" << endl;
    cout << "1. Roll the dice" << endl;
    cout << "2. View history" << endl;
    cout << "3. Exit" << endl;
}

// Function to handle user choices.
void choice() {
    int userChoice;

    while (true) {
        menu();
        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << endl;

        // Check for input failure first.
        if (cin.fail()) {
            inputError("Invalid input. Please choose an option (1-3).");
        } else if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid input. Please choose an option (1-3)." << endl;
        } else {
            switch (userChoice) {
                case 1:
                    rollDice();
                    break;
                case 2:
                    history();
                    break;
                case 3:
                    cout << "Goodbye! Exiting Program..." << endl;
                    exit(0); // Exit the program.
                    break;
                default:
                    cout << "Invalid input. Please choose an option (1-3)." << endl;
            }
        }
    }
}