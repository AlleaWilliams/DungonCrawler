#include "BattleMechanics.h"
#include "EnemyDetails.h"
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


	void Attack(int& enemyHealth) {

		int damage = character.PlayerAttack + WeaponOnAttack(Stash.Material, Stash.Weapon);

		cout << "\n" << character.name << " attacks!\n";

		enemyHealth -= damage;

		cout << "You dealt " << damage << " damage!\n";

		cout << "Enemy health: " << enemyHealth << "\n";
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

//void LevelUp() {
//
//	character.Dungonlevel++;
//
//	cout << "\nYou are now on level " << character.Dungonlevel << "!\n";
//}


int main() {
	srand(time(NULL)); //GAMBLING

	//// Making A character Skit

	string StartGame;

	Player User1;

	SmallMonsters enemy;

	enemy.GetMonsterType();

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
