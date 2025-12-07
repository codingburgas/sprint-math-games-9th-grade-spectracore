#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cctype>

using namespace std;
void clearScreen();
struct GuessResult {
	string guess;
	string feedback;
};
int getMaxAttemtsts(int difficulty);
string pickRandomWord(const string& language, int difficulty);
string makeFeedback(const string& secret, const string& guess);
void renderBoard(const vector<GuessResult>& history, int attemptsLeft);
void playWordle(const string& language, int difficulty);





































