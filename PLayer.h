#include "EnemyDetails.h"
#include "Weapons&Damage.h"
#include <iostream>
#include <string>

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
		///////Loot////////////////////////////////////////////////////
		int _Pelvis = 0;
		int Bone_Marrow = 0;
		int Strudy_Femur = 0;
		int Ball_Of_Worms = 0;
		int Mass_Of_Rotten_Organs = 0;
		int _Rib = 0;
		int _Skull = 0;
		int Brown_Cloth = 0;
		int _Claws = 0;
		int Icy_Blue_Eyes = 0;
		int Golden_Tooth = 0;
		int Goblin_Ear = 0;
		int Loin_Cloth = 0;
		int Brain_Matter = 0;
		int DEEZ_NUTS = 0;

	};

	class BankAccount
	{
	private:
		int balance = 0;
	public:
		void deposit(int amount) {
			balance += amount;
		}
		void withdraw(int amount) {
			balance -= amount;
		}
		int GetBalance() {
			return balance;

		}

	};

	GameCharacter character;
	Inventory Stash;
	BankAccount Mune;


public:


	void SetGameCharacter() {

		// Setting character name, health and level in THE SYSTEM
		cout << "\nWhat will your player be named: \n";
		cin >> character.name;

		cout << "You're starting on level " << character.Dungonlevel;

		cout << "\nYou have " << character.health << " health. Don't die.";

		ContinueStory();
	}


	int Attack(int enemyHealth) {

		return character.PlayerAttack += WeaponOnAttack(Stash.Material, Stash.Weapon);
	}

	void PissYourSelf() {
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
