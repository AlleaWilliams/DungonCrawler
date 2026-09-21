#pragma once

#include "EnemyDetails.h"
#include "Weapons&Damage.h"
#include <iostream>
#include <string>
#include <fstream>
#include <memory>

inline void ContinueAtk() {
	cout << "\nPress Enter to continue...\n";
	cin.ignore();
	cin.get();

}
inline void ContinueStory() {
	cout << "\nPress Enter to continue...\n";
	cin.get();

}

class Player {
private:

	struct GameCharacter {
		string name;
		int health = 100;
		int Dungonlevel = 1;
		int PlayerAttack = 10; // The player's base damage before weapon damage.
	};

	struct Inventory {
		int HPpotions = 0;
		int MPpotions = 0;
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
		bool TryWithdraw(int amount) {
			if (amount < 0 || balance < amount) {
				return false;
			}

			balance -= amount;
			return true;
		}
		int GetBalance() const {
			return balance;
		}
		void SetBalance(int amount) { balance = amount; }

	};

	GameCharacter character;
	unique_ptr<WeaponMaterial> equippedMaterial = make_unique<WoodMaterial>();
	Weapon equippedWeapon{ Weapon::Type::Dagger, *equippedMaterial };
	
	BankAccount Mune;

	Inventory Stash;

	unique_ptr<WeaponMaterial> CreateMaterial(const string& materialName) const {
		if (materialName == "Wood") return make_unique<WoodMaterial>();
		if (materialName == "Stone") return make_unique<StoneMaterial>();
		if (materialName == "Copper") return make_unique<copperMaterial>();
		if (materialName == "Bronze") return make_unique<bronzeMaterial>();
		if (materialName == "Iron") return make_unique<IronMaterial>();
		if (materialName == "Steel") return make_unique<steelMaterial>();
		if (materialName == "Daimond") return make_unique<daimondMaterial>();
		if (materialName == "Adamantine") return make_unique<adamantineMaterial>();

		return nullptr;
	}

public:
	void SaveGame() const {
		ofstream saveFile("savegame.txt");
		if (!saveFile.is_open()) {
			cout << "\nCould not save the game.\n";
			return;
		}

		saveFile << character.name << '\n';
		saveFile << character.health << '\n';
		saveFile << character.Dungonlevel << '\n';
		saveFile << character.PlayerAttack << '\n';
		saveFile << static_cast<int>(equippedWeapon.GetType()) << '\n';
		saveFile << equippedWeapon.GetMaterialName() << '\n';
		saveFile << Mune.GetBalance() << '\n';
		saveFile << Stash.HPpotions << '\n';
		cout << "\nGame saved!\n";
	}

	bool LoadGame() {
		ifstream saveFile("savegame.txt");
		if (!saveFile.is_open()) return false;

		string savedName;
		int savedHealth;
		int savedLevel;
		int savedBaseAttack;
		int savedWeaponType;
		string savedMaterialName;
		int savedMune;
		int savedHealthPotions;

		getline(saveFile, savedName);
		saveFile >> savedHealth >> savedLevel >> savedBaseAttack >> savedWeaponType;
		saveFile >> ws;
		getline(saveFile, savedMaterialName);
		saveFile >> savedMune >> savedHealthPotions;

		if (!saveFile || savedWeaponType < 0 ||
			savedWeaponType > static_cast<int>(Weapon::Type::HeroBlade)) return false;

		unique_ptr<WeaponMaterial> loadedMaterial = CreateMaterial(savedMaterialName);
		if (!loadedMaterial) return false;

		character.name = savedName;
		character.health = savedHealth;
		character.Dungonlevel = savedLevel;
		character.PlayerAttack = savedBaseAttack;
		Mune.SetBalance(savedMune);
		Stash.HPpotions = savedHealthPotions;
		equippedMaterial = move(loadedMaterial);
		equippedWeapon.SetType(static_cast<Weapon::Type>(savedWeaponType));
		equippedWeapon.SetMaterial(*equippedMaterial);

		cout << "\nSave loaded! Welcome back, " << character.name << ".\n";
		return true;
	}

	void AddMune(int amount) {
		Mune.deposit(amount);
	}

	bool SpendMune(int amount) {
		return Mune.TryWithdraw(amount);
	}

	int GetMune() const {
		return Mune.GetBalance();
	}

	void AddHealthPotion() {
		Stash.HPpotions++;
	}

	int GetHealthPotionCount() const {
		return Stash.HPpotions;
	}
	
	//void UseHPPotion()
	//{
	//	if (Inventory[HPpotion] > 0)
	//	{
	//		if (character.health >= 100)
	//		{
	//			cout << "\nYour health is already full!\n";
	//			return;
	//		}

	//		Inventory[hPPotion]--;

	//		character.health += 20;

	//		if (character.health > 100)
	//		{
	//			character.health = 100;
	//		}
	//		cout << "\nYou used an HP potion!";
	//		cout << "\nYour health is now: "
	//			<< character.health << "\n";
	//	}
	//	else
	//	{
	//		cout << "\nYou don't have any HP potions!\n";
	//	}
	//}

	void SetGameCharacter() {

		// Setting character name, health and level in THE SYSTEM
		const size_t maxNameLength = 12;

		while (true) {
			cout << "\nWhat will your player be named (max 12 characters): \n";
			getline(cin >> ws, character.name);

			if (character.name.length() <= maxNameLength) {
				break;
			}

			cout << "That name is too long. Please try again.\n";
			character.name.clear();
		}

		cout << "You're starting on level " << character.Dungonlevel;

		cout << "\nYou have " << character.health << " health. Don't die.";

		ContinueStory();
	}


	vector<Weapon::AttackMove> GetAttackMoves() const {
		return equippedWeapon.GetRandomAttackMoves();
	}

	int Attack(int moveBonusDamage) const {
		// Do not use += here: weapon damage should not grow after every hit.
		return character.PlayerAttack + equippedWeapon.GetDamage() + moveBonusDamage;
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
