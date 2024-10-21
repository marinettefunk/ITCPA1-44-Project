#include <iostream>
#include <string>
#include <limits>
#include "canidates.h"

using namespace std;

void inputError (){
    cin.clear(); // Clear error flag.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all remaining input until new line.
}

// Function to handle the number of students who will vote.
int numVoters() {
    int numVoters;

    do {
        cout << "Enter the number of students who will vote: ";
        cin >> numVoters;
        cout << endl;

        if (cin.fail() || numVoters <= 0) {
            inputError();
            // Error handling for non-numeric and negative input.
            cout << "Invalid input. Please enter a positive whole number.\n" << endl; // Error message.
        } 
        else {
            // Valid input returns the number of students who will vote.
            return numVoters;
        }

    } while (true); // Continue the loop until valid input is received.
}

// Function to confirm user input with y/n or Y/N.
bool confirmChoice(const string& message) {
    char choice;
    do {
        
        cout << message;
        cin >> choice;

        if (cin.fail()) {
            inputError();
            cout << "Invalid input. Please enter y/n or Y/N.\n" << endl;
        } else if (choice == 'y' || choice == 'Y') {
            return true;
        } else if (choice == 'n' || choice == 'N') {
            return false;
        } else {
            cout << "Invalid input. Please enter y/n or Y/N.\n" << endl;
        }
    } while (true);
}

// Function to handle the name and surname of the student voting.
string voterFullName() {
    string name, surname;

    // Name validation loop.
    do {
        cout << "Enter your first name: ";
        cin >> name;


        if (name.empty()) {
            cout << "Invalid input. Name cannot be empty.\n" << endl;
        } else if (!isupper(name[0])) {
            cout << "Invalid input. The first letter of your name should be uppercase.\n" << endl;
        } else {
            break; // Exit loop if name input is valid.
        }
    } while (true);

    // Surname validation loop.
    do {
        cout << "Enter your surname: ";
        cin >> surname;

        if (surname.empty()) {
            cout << "Invalid input. Surname cannot be empty.\n" << endl;
        } else if (!isupper(surname[0])) {
            cout << "Invalid input. The first letter of your surname should be uppercase.\n" << endl;
        } else {
            break; // Exit loop if surname input is valid.
        }
    } while (true);

    if (!confirmChoice("Your full name is " + name + " " + surname + ". Is this correct? (y/n) or (Y/N): ")) {
        return voterFullName();
    }

    // Return full name (name and surname).
    return name + " " + surname;
}

// Function that handles the voter's input and to count votes.
void vote(int numVoters, int& canidate1VoteCount, int& canidate2VoteCount, int& canidate3VoteCount, int& canidate4VoteCount) {
    for (int i = 1; i <= numVoters; i++) {
        cout << "Voter " << i << ": " << endl;

        string fullname = voterFullName();

        bool voteConfirmed = false;
        
        do {
            int vote;
            cout << endl;
            canidates();
            cout << "Enter your vote (1-4): ";
            cin >> vote;
            

            if (cin.fail() || vote < 1 || vote > 4) {
                inputError();
                cout << "Invalid input. Please enter a number between 1 and 4.\n" << endl;
                continue;
            }

            // Votes counted.
            switch (vote) {
                case 1:
                    canidate1VoteCount++;
                    break;
                case 2:
                    canidate2VoteCount++;
                    break;
                case 3:
                    canidate3VoteCount++;
                    break;
                case 4:
                    canidate4VoteCount++;
                    break;
            }

            // Vote reset if confirmed n or N.
            if (!confirmChoice("Are you sure about your vote? (y/n) or (Y/N): ")) {
                switch (vote) {
                    case 1:
                        canidate1VoteCount--;
                        break;
                    case 2:
                        canidate2VoteCount--;
                        break;
                    case 3:
                        canidate3VoteCount--;
                        break;
                    case 4:
                        canidate4VoteCount--;
                        break;
                }
            } else {
                voteConfirmed = true;
                cout << "Thank you, " << fullname << ", for voting!\n" << endl; // Message to thank the student for voting.
            }
        } while (!voteConfirmed);
    }
}

// Function to display results of voting.
void results(int canidate1VoteCount, int canidate2VoteCount, int canidate3VoteCount, int canidate4VoteCount) {
    cout << "Vote Results:" << endl;
    cout << "John Parker: " << canidate1VoteCount << " votes" << endl;
    cout << "Jane Smith: " << canidate2VoteCount << " votes" << endl;
    cout << "Alice Johnson: " << canidate3VoteCount << " votes" << endl;
    cout << "Bob Williams: " << canidate4VoteCount << " votes" << endl;
    cout << endl;

    // Result displayed based on canidate with the highest number of votes.
    if (canidate1VoteCount > canidate2VoteCount && canidate1VoteCount > canidate3VoteCount && canidate1VoteCount > canidate4VoteCount) {
        cout << "John Parker is the new Class President!" << endl;
    } else if (canidate2VoteCount > canidate1VoteCount && canidate2VoteCount > canidate3VoteCount && canidate2VoteCount > canidate4VoteCount) {
        cout << "Jane Smith is the new Class President!" << endl;
    } else if (canidate3VoteCount > canidate1VoteCount && canidate3VoteCount > canidate2VoteCount && canidate3VoteCount > canidate4VoteCount) {
        cout << "Alice Johnson is the new Class President!" << endl;
    } else if (canidate4VoteCount > canidate1VoteCount && canidate4VoteCount > canidate2VoteCount && canidate4VoteCount > canidate3VoteCount) {
        cout << "Bob Williams is the new Class President!" << endl;
    } else {
        cout << "It is a tie!" << endl;
    }
}