#include <iostream>
#include <string>
#include "menu.h"
using namespace std;

int main() {
	string title = R"(
         _______..______    _______   ______ .___________..______          ___                                                        
        /       ||   _  \  |   ____| /      ||           ||   _  \        /   \                                                      
       |   (----`|  |_)  | |  |__   |  ,----'`---|  |----`|  |_)  |      /  ^  \                                                      
        \   \    |   ___/  |   __|  |  |         |  |     |      /      /  /_\  \                                                       
    .----)   |   |  |      |  |____ |  `----.    |  |     |  |\  \----./  _____  \                                                   
    |_______/    | _|      |_______| \______|    |__|     | _| `._____/__/     \__\                                             
                                                                                                                                          
    ____    __    ____  ______   .______       _______          _______  __    __   _______     _______.     _______. __  .__   __.   _______ 
    \   \  /  \  /   / /  __  \  |   _  \     |       \        /  _____||  |  |  | |   ____|   /       |    /       ||  | |  \ |  |  /  _____|
     \   \/    \/   / |  |  |  | |  |_)  |    |  .--.  |      |  |  __  |  |  |  | |  |__     |   (----`   |   (----`|  | |   \|  | |  |  __  
      \            /  |  |  |  | |      /     |  |  |  |      |  | |_ | |  |  |  | |   __|     \   \        \   \    |  | |  . `  | |  | |_ | 
       \    /\    /   |  `--'  | |  |\  \----.|  '--'  |      |  |__| | |  `--'  | |  |____.----)   |   .----)   |   |  | |  |\   | |  |__| | 
        \__/  \__/     \______/  | _| `._____||_______/        \______|  \______/  |_______|_______/    |_______/    |__| |__| \__|  \______| 
    )";
    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName); // !!!!!

    string input;

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
                    cout << "Language set to English." << endl;
                    showLanguageMenuPart2();
                }
                else if (input == "2") {
                    cout << "Language set to Bulgarian." << endl;
                    showLanguageMenuPart2();
                }
                else if (input == "3") {
                    cout << "Sprache auf Deutsch eingestellt." << endl;
                    showLanguageMenuPart2();
                }
				else
                cout << "Unknown command. Try again." << endl;
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
                else if(input == "1"){
                    cout << "Difficulty set to easy" << endl;
                    showDifficultyMenuPart2();
                }
                else if (input == "2") {
                    cout << "Difficulty set to normal" << endl;
                    showDifficultyMenuPart2();
                }
                else if (input == "3") {
                    cout << "Difficulty set to hard" << endl;
                    showDifficultyMenuPart2();
                }
                else if (input == "4") {
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
            break; 
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
};