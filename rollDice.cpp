#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>

using namespace std;
vector<vector<int> > rollHistory;

void menu(){
    cout << endl;
    cout << "Menu:" << endl;
    cout << "1. Roll the dice" << endl;
    cout << "2. History" << endl;
    cout << "3. Exit" << endl;
}

void rollDice();
void history();

void choice (){
    int choice;

    while (true){
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if (cin.fail()){ // Check if input is an integer an not a character or sting.
            cout << "Invalid input. Please choose an option (1-3) from the menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else if (choice < 1 || choice > 3) {
            cout << "Invalid input. Please choose an option (1-3) from the menu.\n";
        } else {
            if (choice == 1){
                rollDice();
            } else if (choice == 2){
                cout << "History" << endl;
                history();
            } else if (choice == 3){
                exit(0);
            }
        }
    }
}


void rollDice(){
 cout << "How many times would you like to roll the dice? ";
    int times;
    
    while (!(cin >> times) || times <= 0) {
        if (cin.fail()) {
            cout << "Invalid input. Please enter a positive integer.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "How many times would you like to roll the dice?\n";
        } else if (times <= 0) {
            cout << "Invalid input. Please enter a positive integer." << endl;
            cout << endl;
            cout << "How many times would you like to roll the dice? ";
            cout << endl;
        }
    }
    cout << "Rolling the dice " << times << " times..." << endl;
    cout << endl;

    vector<int> currentRoll;
    for (int i = 1; i <= times; i++){
        int roll = 1 + (rand() % 6);
        cout << "Dice " << i << " rolled: " << roll << endl;
                currentRoll.push_back(roll);
    }
    rollHistory.push_back(currentRoll);
}

void history (){
    cout << "Roll History:" << endl;
    cout << endl;
    for (int i = 0; i < rollHistory.size(); i++) {
        cout << "Roll " << i + 1 << ":" << endl;
        for (int j = 0; j < rollHistory[i].size(); j++) {
            cout << "Dice " << j + 1 << " rolled: " << rollHistory[i][j] << endl;
        }
    }
}

