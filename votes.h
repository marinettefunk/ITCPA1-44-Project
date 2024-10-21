#ifndef VOTES_H
#define VOTES_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

void inputError ();
int numVoters();
bool confirmChoice(const std::string& message);
string voterFullName();
void vote(int numVoters, int& canidate1VoteCount, int& canidate2VoteCount, int& canidate3VoteCount, int& canidate4VoteCount);
void results(int canidate1VoteCount, int canidate2VoteCount, int canidate3VoteCount, int canidate4VoteCount);

#endif // VOTES_H