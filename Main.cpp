#include "BattleMechanics.h"
#include "Shop.h"
#include "EnemyDetails.h"
#include "Weapons&Damage.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


int Inventory[ItemCount] = { 0 };

int main() {
	/////////////         MAKE GENDER FUNCTION THING		 /////////////
	srand(static_cast<unsigned int>(time(nullptr))); //GAMBLING
	//// Making A character Skit
	char PlayerName = tolower(static_cast<unsigned char>(name));

	Shop shop;

	string StartGame;

	Player User1;

	SmallMonsters enemy;

	enemy.GetMonsterType();

	cout << "Are you willing to risk it (y/n): ";
	cin >> StartGame;*/

	cout << "I don't really care about what you put, you're playing :)\n\n";
	

	char loadSave;
	cout << "Load your old save? (y/n): ";
	cin >> loadSave;

	if (loadSave == 'y' || loadSave == 'Y') {
		if (!User1.LoadGame()) {
			cout << "No save found. Starting a new game.\n";
			User1.SetGameCharacter();
		}
	}
	else {
		cout << "Starting a brand-new game.\n";
		User1.SetGameCharacter();
	}


	// LORE?!?!?!?!?!?!?!

	cout << "\n\nYou, a not so proud child of the former hero, was kidnapped.";

	ContinueStory();


	cout << "\nThey put you in a sack and hauled you off, into:";
	cout << "\nTHE PIT OF NO RETURN";

	ContinueStory();


	cout << "\nYou must fight for your life to make it out of this hell,";
	cout << "\nor die being the loser son of the former hero.";

	cout << "\n\nVenture out "<< PlayerName <<" if for nothing then for the truth of this place.\n"

	ContinueStory();

	FightStyle(User1, enemy);
	if (User1.GetHealth() > 0) {
		string restChoice;
		cout << "\nYou have survived the fight, Rest and recover your health? (y/n)\n";	
		cin >> restChoice;

		if (restChoice == "y" || restChoice == "Y") {
			User1.PlayerRest();
		}

	}
	User1.SaveGame();

	cout << "\nyou did't die, i'm suprised";

	return 0;

}