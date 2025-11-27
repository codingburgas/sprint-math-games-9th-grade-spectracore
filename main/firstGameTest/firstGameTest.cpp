#include <iostream>
#include <string>
using namespace std;

void clearScreen() {
	system("cls"); //clear the console screen
}

void showMainMenu(const string & title, const string & playerName) {
	clearScreen();
	cout << title << endl;
	cout << "By SpectralCore Games\n";
	cout << "------------------------\n\n";
	cout << "Welcome to the game, " << playerName << "!\n\n";

	cout << "\033[33mGame menu\033[0m\n";
	cout << "Guide\n";
	cout << "Language\n";
	cout << "Game difficulty\n";
	cout << "Graphics settings\n";
	cout << "Sound settings\n";
	cout << "Start Game\n\n";
	cout << "\033[34mEnter menu:\033[0m ";
}

void showGuideMenu() {
	clearScreen();
	cout << R"(
  _______  __    __   __   _______   _______ 
 /  _____||  |  |  | |  | |       \ |   ____|
|  |  __  |  |  |  | |  | |  .--.  ||  |__   
|  | |_ | |  |  |  | |  | |  |  |  ||   __|  
|  |__| | |  `--'  | |  | |  '--'  ||  |____ 
 \______|  \______/  |__| |_______/ |_______|
	)";
    cout << endl;
    cout << "Welcome to the GUIDE menu! Here is how to play the game:" << endl;
	cout << "1. Go back to the main menu." << endl;
	cout << "2. Select your preferred language by typing *Language* to enter the language menu (if needed)" << endl;
	cout << "3. Choose your desired game difficulty by typing *Game difficulty* to enter the difficulty menu." << endl;
	cout << "4. Type *Start Game* to start the game" << endl;
	cout << "You will see how long the word is and the attempts you have. All you have to do is to write letters to try to guess the word. You will see if you have guessed or have to try again." << endl;
    cout << endl;
	cout << "\033[33mTo go back to the GAME MENU enter - GM\033[0m" << endl;
	cout << "\033[34mYour input:\033[0m ";
}

void showLanguageMenu() {
	clearScreen(); 
	cout << R"(
 __          ___      .__   __.   _______  __    __       ___       _______  _______ 
|  |        /   \     |  \ |  |  /  _____||  |  |  |     /   \     /  _____||   ____|
|  |       /  ^  \    |   \|  | |  |  __  |  |  |  |    /  ^  \   |  |  __  |  |__   
|  |      /  /_\  \   |  . `  | |  | |_ | |  |  |  |   /  /_\  \  |  | |_ | |   __|  
|  `----./  _____  \  |  |\   | |  |__| | |  `--'  |  /  _____  \ |  |__| | |  |____ 
|_______/__/     \__\ |__| \__|  \______|  \______/  /__/     \__\ \______| |_______|

	)";
	cout << "Please select your preferred language for the word:" << endl;
	cout << "1. English" << endl;
	cout << "2. Bulgarian" << endl;
    cout << "3. Deutsch" << endl;
    cout << endl;
    cout << "\033[33mLanguage(digit) >> \033[0m";

}
void showLanguageMenuPart2() {
    cout << "\033[33mTo go back to the GAME MENU enter - GM\033[0m" << endl;
    cout << "\033[34mYour input:\033[0m ";
}

void showDifficultyMenu() {
	clearScreen();
	cout << R"(
  _______      ___      .___  ___.  _______        _______   __   _______  _______  __    ______  __    __   __      .___________.____    ____
 /  _____|    /   \     |   \/   | |   ____|      |       \ |  | |   ____||   ____||  |  /      ||  |  |  | |  |     |           |\   \  /   /
|  |  __     /  ^  \    |  \  /  | |  |__         |  .--.  ||  | |  |__   |  |__   |  | |  ,----'|  |  |  | |  |     `---|  |----` \   \/   / 
|  | |_ |   /  /_\  \   |  |\/|  | |   __|        |  |  |  ||  | |   __|  |   __|  |  | |  |     |  |  |  | |  |         |  |       \_    _/  
|  |__| |  /  _____  \  |  |  |  | |  |____       |  '--'  ||  | |  |     |  |     |  | |  `----.|  `--'  | |  `----.    |  |         |  |    
 \______| /__/     \__\ |__|  |__| |_______|      |_______/ |__| |__|     |__|     |__|  \______| \______/  |_______|    |__|         |__|    
	)";
    cout << "Please select your prefered difficulty" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Normal" << endl;
    cout << "3. Hard" << endl;
    cout << "3. Extreme" << endl;
    cout << endl;
    cout << "Select difficulty (digit) >>";
}
void showDifficultyMenuPart2(){
    cout << "\033[33mTo go back to the GAME MENU enter - GM\033[0m" << endl;
    cout << "\033[34mYour input:\033[0m ";
}

int main() {
	string title = R"(
         _______..______    _______   ______ .___________..______          ___       __                                                       
        /       ||   _  \  |   ____| /      ||           ||   _  \        /   \     |  |                                                      
       |   (----`|  |_)  | |  |__   |  ,----'`---|  |----`|  |_)  |      /  ^  \    |  |                                                      
        \   \    |   ___/  |   __|  |  |         |  |     |      /      /  /_\  \   |  |                                                      
    .----)   |   |  |      |  |____ |  `----.    |  |     |  |\  \----./  _____  \  |  `----.                                                 
    |_______/    | _|      |_______| \______|    |__|     | _| `._____/__/     \__\ |_______|                                                 
                                                                                                                                          
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
        if (input == "Guide" || input == "guide") {

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
        else if (input == "Language" || input == "language") {
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
        else if (input == "Game difficulty" || input == "difficulty" || input == "Game Difficulty" || input == "game difficulty" || input == "GAME DIFFICULTY") {
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
        else if (input == "Start Game" || input == "start game" || input == "Start game") {
            clearScreen();
            cout << "Starting the game..." << endl;
            break; // тук може да стартираш логика на играта
        }

        else {
            cout << "Invalid menu option. Try again." << endl;
        }
    }
    return 0;
};