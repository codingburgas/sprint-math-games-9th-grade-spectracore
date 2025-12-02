#include <iostream>
#include "menu.h"
using namespace std;

void clearScreen() {
	system("cls"); //clear the console screen
}

void showMainMenu(const string& title, const string& playerName) {
	clearScreen();
	cout << title << endl;
	cout << "By SpectraCore Games" << endl;
	cout << "------------------------" << endl;
	cout << endl;
	cout << "Welcome to the game, " << playerName << "!" << endl;
	cout << endl;
	cout << "\033[33mGame menu\033[0m" << endl;
	cout << "------------------------" << endl;
	cout << "1. Guide" << endl;
	cout << "2. Language" << endl;
	cout << "3. Game difficulty" << endl;
	cout << "4. Start Game" << endl;
	cout << "5. Quit Game" << endl;
	cout << "6. Credits" << endl;
	cout << endl;
	cout << "\033[34mEnter menu (You can use a digit too):\033[0m ";
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
	cout << "4. Extreme" << endl;
	cout << endl;
	cout << "Select difficulty (digit) >>";
}
void showDifficultyMenuPart2() {
	cout << "\033[33mTo go back to the GAME MENU enter - GM\033[0m" << endl;
	cout << "\033[34mYour input:\033[0m ";
}

void showCreditsMenu() {
	clearScreen();
	cout << R"(
    ______ .______       _______  _______   __  .___________.    _______.
   /      ||   _  \     |   ____||       \ |  | |           |   /       |
  |  ,----'|  |_)  |    |  |__   |  .--.  ||  | `---|  |----`  |   (----`
  |  |     |      /     |   __|  |  |  |  ||  |     |  |        \   \    
  |  `----.|  |\  \----.|  |____ |  '--'  ||  |     |  |    .----)   |   
   \______|| _| `._____||_______||_______/ |__|     |__|    |_______/  
    )";
	cout << endl;
	cout << "Game developed by SpectraCore Games." << endl;
	cout << "Lead Developer: [Your Name]" << endl;
	cout << "Graphics Designer: [Designer Name]" << endl;
	cout << "Special Thanks to: [Special Thanks Names]" << endl;
	cout << endl;
	cout << "\033[33mTo go back to the GAME MENU enter - GM\033[0m" << endl;
	cout << "\033[34mYour input:\033[0m ";
}

