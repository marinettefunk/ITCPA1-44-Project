#ifndef VOTES_H
#define VOTES_H

#include <iostream>
#include <string>
#include <limits>

void inputError();
int numVoters();
bool confirmChoice(const std::string& message);
std::string voterFullName();
void vote(int numVoters, int& candidate1VoteCount, int& candidate2VoteCount, int& candidate3VoteCount, int& candidate4VoteCount);
void results(int candidate1VoteCount, int candidate2VoteCount, int candidate3VoteCount, int candidate4VoteCount);

#endif // VOTES_H