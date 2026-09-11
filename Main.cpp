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

	GameCharacter character;


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

		int damage = character.PlayerAttack + WeaponOnAttack(4, 1);

		cout << "\n" << character.name << " attacks!\n";

		enemyHealth -= damage;

		cout << "You dealt " << damage  << " damage!\n";

		cout << "Enemy health: " << enemyHealth << "\n";
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

	cout << "you did't die, i'm suprised";
	return 0;


}
