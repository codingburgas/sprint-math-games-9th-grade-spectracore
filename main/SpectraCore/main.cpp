#include <iostream> 
#include <string>
#include <vector>
#include <ctime>
#include <cctype>
#include "menu.h"
using namespace std;


int getMaxAttempts(int difficulty) {
    switch (difficulty) {
    case 1: return 8; // Easy
    case 2: return 6; // Normal
    case 3: return 5; // Hard
    case 4: return 4; // Extreme
    default: return 6;
    }
}

string pickRandomWord(const string& language, int difficulty) {

    static const vector<string> enEasy = {
        "apple", "chair", "table", "mouse", "house",
        "green", "light", "water", "phone", "pizza"
    };

    static const vector<string> enNormal = {
        "cable", "world", "train", "frame", "cloud",
        "dream", "sugar", "metal", "coast", "storm"
    };

    static const vector<string> enHard = {
        "crypt", "glyph", "knock", "squad", "jelly",
        "flame", "sharp", "pride", "brave", "score"
    };

    static const vector<string> enExtreme = {
        "zebra", "quake", "vivid", "xenon", "jazzy",
        "fjord", "whack", "nymph", "glyph", "azure"
    };


    static const vector<string> deEasy = {
        "apfel", "stuhl", "lampe", "tisch", "wolke",
        "radio", "farbe", "essen", "reise", "licht"
    };

    static const vector<string> deNormal = {
        "wolke", "reise", "asche", "traum", "konto",
        "radio", "licht", "nacht", "stern", "hafen"
    };

    static const vector<string> deHard = {
        "druck", "strom", "klang", "griff", "spalt",
        "blatt", "sturm", "pferd", "kabel", "boden"
    };

    static const vector<string> deExtreme = {
        "zebra", "qualm", "vital", "joker", "fjord",
        "rauch", "maske", "verwirrt", "punkt", "quarz"
    };


    const vector<string>* list = nullptr;

    if (language == "English") {
        switch (difficulty) {
        case 1: list = &enEasy;    break;
        case 2: list = &enNormal;  break;
        case 3: list = &enHard;    break;
        case 4: list = &enExtreme; break;
        default: list = &enNormal; break;
        }
    }
    else if (language == "German") {
        switch (difficulty) {
        case 1: list = &deEasy;    break;
        case 2: list = &deNormal;  break;
        case 3: list = &deHard;    break;
        case 4: list = &deExtreme; break;
        default: list = &deNormal; break;
        }
    }
    else {
        switch (difficulty) {
        case 1: list = &enEasy;    break;
        case 2: list = &enNormal;  break;
        case 3: list = &enHard;    break;
        case 4: list = &enExtreme; break;
        default: list = &enNormal; break;
        }
    }

    int idx = rand() % list->size();
    return (*list)[idx];
}


string makeFeedback(const string& secret, const string& guess) {
    int n = secret.size();
    string fb(n, '_');

    vector<int> usedSecret(n, 0);
    for (int i = 0; i < n; ++i) {
        if (guess[i] == secret[i]) {
            fb[i] = 'G';
            usedSecret[i] = 1;
        }
    }

    vector<int> freq(26, 0);
    for (int i = 0; i < n; ++i) {
        if (!usedSecret[i]) {
            char c = secret[i];
            if (c >= 'a' && c <= 'z') {
                freq[c - 'a']++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (fb[i] == 'G') continue;
        char c = guess[i];
        if (c >= 'a' && c <= 'z') {
            int idx = c - 'a';
            if (freq[idx] > 0) {
                fb[i] = 'Y';
                freq[idx]--;
            }
        }
    }

    return fb;
}

struct GuessResult {
    string guess;
    string feedback;
};

void renderBoard(const vector<GuessResult>& history, int attemptsLeft) {
    cout << "Attempts left: " << attemptsLeft << endl;
    cout << "------------------------" << endl;

    for (const auto& gr : history) {
        for (size_t i = 0; i < gr.guess.size(); ++i) {
            char c = toupper(static_cast<unsigned char>(gr.guess[i]));
            char f = gr.feedback[i];

            if (f == 'G') {
                cout << "\033[42m " << c << " \033[0m ";
            }
            else if (f == 'Y') {
                cout << "\033[43m " << c << " \033[0m ";
            }
            else {
                cout << "\033[47m " << c << " \033[0m ";
            }
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
}

void playWordle(const string& language, int difficulty) {
    const int WORD_LENGTH = 5;
	int streak = 0;
    int maxAttempts = getMaxAttempts(difficulty);
    string secret = pickRandomWord(language, difficulty);
    vector<GuessResult> history;
    int attemptsLeft = maxAttempts;

	time_t startTime = time(0);

    while (attemptsLeft > 0) {
        clearScreen();

        cout << "====== WORDLE ======" << endl;
        cout << "(Secret word is " << WORD_LENGTH << " letters)" << endl;
        cout << "(Type 'exit' to give up)" << endl << endl;

        renderBoard(history, attemptsLeft);

        cout << "Enter your guess: ";
        string guess;
        getline(cin, guess);
        string cleaned;
        for (char ch : guess) {
            if (!isspace(static_cast<unsigned char>(ch)))
                cleaned.push_back(tolower(static_cast<unsigned char>(ch)));
        }
        guess = cleaned;

        if (guess == "exit") {
            cout << "You gave up! The word was: " << secret << endl;
            cout << "Press Enter to return to the menu...";
            string temp;
            getline(cin, temp);
            return;
        }

        if ((int)guess.size() != WORD_LENGTH) {
            cout << "Your guess must be exactly " << WORD_LENGTH << " letters. Press Enter to try again...";
            string temp;
            getline(cin, temp);
            continue;
        }

        string fb = makeFeedback(secret, guess);
        history.push_back({ guess, fb });

        if (guess == secret) {
			time_t endTime = time(0);
			int elapsed = endTime - startTime;
            streak++;

            clearScreen();

            renderBoard(history, attemptsLeft - 1);
         
            cout << "Congratulations! You guessed the word: " << secret << endl;
            cout << "Time taken: " << elapsed << " seconds" << endl;
            cout << "Current wining streak: " << streak << endl;

            cout << "Press Enter to return to the menu...";
            string temp;
            getline(cin, temp);
            return;
        }

        attemptsLeft--;
    }

    clearScreen();
    renderBoard(history, 0);
	streak = 0;
    cout << "No attempts left. The word was: " << secret << endl;
	cout << "Your streak has been reset." << endl;
    cout << "Press Enter to return to the menu...";
    string temp;
    getline(cin, temp);

}


int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    string title = R"(
 $$$$$$\  $$$$$$$\  $$$$$$$$\  $$$$$$\ $$$$$$$$\ $$$$$$$\   $$$$$$\   $$$$$$\   $$$$$$\  $$$$$$$\  $$$$$$$$\ 
$$  __$$\ $$  __$$\ $$  _____|$$  __$$\\__$$  __|$$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  _____|
$$ /  \__|$$ |  $$ |$$ |      $$ /  \__|  $$ |   $$ |  $$ |$$ /  $$ |$$ /  \__|$$ /  $$ |$$ |  $$ |$$ |      
\$$$$$$\  $$$$$$$  |$$$$$\    $$ |        $$ |   $$$$$$$  |$$$$$$$$ |$$ |      $$ |  $$ |$$$$$$$  |$$$$$\    
 \____$$\ $$  ____/ $$  __|   $$ |        $$ |   $$  __$$  $$  __$$ |$$ |      $$ |  $$ |$$  __$$< $$  __|   
$$\   $$ |$$ |      $$ |      $$ |  $$\   $$ |   $$ |  $$ |$$ |  $$ |$$ |  $$\ $$ |  $$ |$$ |  $$ |$$ |      
\$$$$$$  |$$ |      $$$$$$$$\ \$$$$$$  |  $$ |   $$ |  $$ |$$ |  $$ |\$$$$$$  | $$$$$$  |$$ |  $$ |$$$$$$$$\ 
 \______/ \__|      \________| \______/   \__|   \__|  \__|\__|  \__| \______/  \______/ \__|  \__|\________|
                                                                                                             
                                                                                                                                                                                                                         
$$\      $$\  $$$$$$\  $$$$$$$\  $$$$$$$\  $$\       $$$$$$$$\                                               
$$ | $\  $$ |$$  __$$\ $$  __$$\ $$  __$$\ $$ |      $$  _____|                                              
$$ |$$$\ $$ |$$ /  $$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |                                                    
$$ $$ $$\$$ |$$ |  $$ |$$$$$$$  |$$ |  $$ |$$ |      $$$$$\                                                  
$$$$  _$$$$ |$$ |  $$ |$$  __$$< $$ |  $$ |$$ |      $$  __|                                                 
$$$  / \$$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |                                                    
$$  /   \$$ | $$$$$$  |$$ |  $$ |$$$$$$$  |$$$$$$$$\ $$$$$$$$\                                               
\__/     \__| \______/ \__|  \__|\_______/ \________|\________|  
    )";

    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);

    string input;

    string language = "English";
    int difficulty = 2; // normal difficulty by default

    while (true) {

        // Show main menu
        clearScreen();
        showMainMenu(title, playerName);

        getline(cin, input);

        // ----- GUIDE -----
        if (input == "Guide" || input == "guide" || input == "1") {

            while (true) {
                showGuideMenu();
                getline(cin, input);

                if (input == "GM" || input == "gm" || input == "Gm") {
                    break;
                }

                cout << "Unknown command. Try again." << endl;
            }
        }

        // ----- LANGUAGE -----
        else if (input == "Language" || input == "language" || input == "2") {
            clearScreen();
            showLanguageMenu();
            while (true) {
                getline(cin, input);
                if (input == "GM" || input == "gm" || input == "Gm") {
                    break;
                }
                else if (input == "1") {
                    language = "English";
                    cout << "Language set to English." << endl;
                    showLanguageMenuPart2();
                }
                else if (input == "2") {
                    language = "German";
                    cout << "Sprache auf Deutsch eingestellt." << endl;
                    showLanguageMenuPart2();
                }
                else {
                    cout << "Unknown command. Try again." << endl;
                }
            }
        }

        // ----- DIFFICULTY -----
        else if (input == "Game difficulty" || input == "difficulty" || input == "Game Difficulty" || input == "game difficulty" || input == "GAME DIFFICULTY" || input == "3") {
            clearScreen();
            showDifficultyMenu();
            while (true) {
                getline(cin, input);
                if (input == "GM" || input == "gm" || input == "Gm") {
                    break;
                }
                else if (input == "1") {
                    difficulty = 1;
                    cout << "Difficulty set to easy" << endl;
                    showDifficultyMenuPart2();
                }
                else if (input == "2") {
                    difficulty = 2;
                    cout << "Difficulty set to normal" << endl;
                    showDifficultyMenuPart2();
                }
                else if (input == "3") {
                    difficulty = 3;
                    cout << "Difficulty set to hard" << endl;
                    showDifficultyMenuPart2();
                }
                else if (input == "4") {
                    difficulty = 4;
                    cout << "Difficulty set to extreme" << endl;
                    showDifficultyMenuPart2();
                }
                else {
                    cout << "Unknown command. Try again." << endl;
                }
            }
        }

        // start game
        else if (input == "Start Game" || input == "start game" || input == "Start game" || input == "4") {
            clearScreen();
            cout << "Starting the game..." << endl;
            playWordle(language, difficulty);
        }

        // ----- QUIT GAME -----
        else if (input == "Quit Game" || input == "quit game" || input == "Quit game" || input == "5") {
            clearScreen();
            cout << "Quitting the game. Goodbye, " << playerName << "!" << endl;
            break;
        }

        // ----- CREDITS -----
        else if (input == "Credits" || input == "credits" || input == "6") {
            clearScreen();
            showCreditsMenu();
            while (true) {
                getline(cin, input);
                if (input == "GM" || input == "gm" || input == "Gm") {
                    break;
                }
                cout << "Unknown command. Try again." << endl;
            }
        }

        else {
            cout << "Invalid menu option. Try again." << endl;
        }
    }
    return 0;
}