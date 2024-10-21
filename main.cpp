#include <iostream>
#include "canidates.h"
#include "votes.h"
using namespace std;

int main() {
    cout << "Welcome to the Class President Voting System" << endl; // Program title.
    cout <<endl;
    canidates(); // Display canidates menu.
    cout<<endl;

    // Display and get the number of students voting.
    int numStudents = numVoters();

    // Number of votes for each canidate initialised to zero.
    int john = 0, jane = 0, alice = 0, bob = 0;
    // Student/voter input their full name and cast their vote. The votes for the canidates are counted. 
    vote(numStudents, john, jane, alice, bob); 

    // Voting results are displayed.
    results(john, jane, alice, bob); 

    return 0;
}