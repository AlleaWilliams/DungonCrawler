#include "Weapons&Damage.h"
#include <iostream>
#include <string>
using namespace std;

void ContinueAtk() {
	cout << "\nPress Enter to continue...\n";
	cin.ignore();
	cin.get();

}
void ContinueStory() {
	cout << "\nPress Enter to continue...\n";
	cin.get();
	
}


class Player {
private:

	struct GameCharacter {
		string name;
		int health = 100;
		int Dungonlevel = 1;
		int PlayerAttack = 10;
	};

	struct Inventory {
		int HPpotions = 0;
		int MPpotions = 0;
		int Material = Iron;
		int Weapon = dagger;
	};

	GameCharacter character;
	Inventory Stash;


public:

	void SetGameCharacter() {

		// Setting character name, health and level in THE SYSTEM
		cout << "\nWhat will your player be named: \n";
		cin >> character.name;

		cout << "You're starting on level " << character.Dungonlevel;

		cout << "\nYou have " << character.health << " health. Don't die.";

		ContinueStory();
	}


	void Attack(int& enemyHealth) {

		int damage = character.PlayerAttack + WeaponOnAttack(Stash.Material, Stash.Weapon);

		cout << "\n" << character.name << " attacks!\n";

		enemyHealth -= damage;

		cout << "You dealt " << damage  << " damage!\n";

		cout << "Enemy health: " << enemyHealth << "\n";
	}

	void PissYourSelf(){
		character.health = character.health - 2;

		cout << "\n--- YOUR TURN ---\n";
		cout << "Pissed your pants in fear\n";

		cout << character.name << " took " << "2 damage!\n";

		cout << "Your health: " << character.health << "\n";

	}


	void TakeDamage(int damage) {

		character.health -= damage;

		cout << "\n" << character.name << " took " << damage << " damage!\n";

		cout << "Your health: " << character.health << "\n";
	}


	int GetHealth() {

		return character.health;

	}

};

//void LevelUp() {
//
//	character.Dungonlevel++;
//
//	cout << "\nYou are now on level " << character.Dungonlevel << "!\n";
//}

void FightStyle(Player User1, int EnemyHealth, int EnemyHit) {
	// TURN-BASED COMBAT

	while (User1.GetHealth() > 0 && EnemyHealth > 0) {

		// PLAYER TURN
		int PVBChoice;

		cout << "\n--- YOUR TURN ---\n";


		cout << "1) Attack\n2) Defend\n";
		cin >> PVBChoice;

		if (PVBChoice == 1) {

			User1.Attack(EnemyHealth);

			// Check if enemy died
			if (EnemyHealth <= 0) {
				EnemyHealth = 0;
				cout << "\nThe undead has been defeated!\n";
				break;



			}


			// ENEMY TURN
			int EnemyAttack = EnemyHit;

			cout << "\n--- ENEMY TURN ---\n";

			User1.TakeDamage(EnemyAttack);

			ContinueAtk();
		}
		else if (PVBChoice == 2) {

			cout << "\n\n--- ENEMY TURN ---\n\n";

			cout << "Attack was ineffective\n ";

			ContinueAtk();
		}
		else {// make more elseifs to get word input to givew pissyourself

			User1.PissYourSelf();

			// ENEMY TURN
			int EnemyAttack = EnemyHit;

			cout << "\n--- ENEMY TURN ---\n";

			User1.TakeDamage(EnemyAttack);

			ContinueAtk();
		}






		// Check if player died

		if (User1.GetHealth() <= 0) {

			cout << "\nYou have died.\n";
			break;

		}



	}

}



int main() {

	//// Making A character Skit

	string StartGame;

	Player User1;

	int EnemyHealth = 80;
	int EnemyHit = 10;


	cout << "Are you willing to risk it (y/n): ";
	cin >> StartGame;

	cout << "I don't really care about what you put, you're playing :)\n\n";


	User1.SetGameCharacter();


	// LORE?!?!?!?!?!?!?!

	cout << "\n\nYou, a not so proud child of the former hero, was kidnapped.";

	ContinueStory();


	cout << "\nThey put you in a sack and hauled you off, into:";
	cout << "\nTHE PIT OF NO RETURN";

	ContinueStory();


	cout << "\nYou must fight for your life to make it out of this hell,";
	cout << "\nor die being the loser son of the former hero.";

	ContinueStory();


	cout << "\nA undead jumps out of the darkness!\n";

	ContinueStory();

	FightStyle(User1, EnemyHealth, EnemyHit);

	cout << "\nyou did't die, i'm suprised";


	return 0;


}
