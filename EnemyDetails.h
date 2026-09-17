#include "Weapons&Damage.h"
#include <iostream>
#include <string>
/// <summary>
/// Monster Type to spawn
/// </summary>

enum MonsterType
{
	Skelleton,
	Zombie,
	Ghoul,
	Goblin,
	MindGoblin
};


/// <summary>
/// Monster Loot
/// </summary>
enum SkelletonLoot
{
	Pelvis,
	BoneMarrow,
	StrudyFemur,
	WeaponWeilded,
	mune
};
enum ZombieLoot
{
	BallOfWorms,
	MassOfRottenOrgans,
	ARib,
	WeaponWeilded,
	mune

};
enum GhoulLoot
{
	Skull,
	BrownCloth,
	Claws,
	IcyBlueEyes,
	mune
};
enum GoblinLoot
{
	GoldenTooth,
	GoblinEar,
	LoinCLoth,
	HPPotion,
	WeaponWeilded,
	mune
};
enum MindGoblinLoot
{
	GoblinEar,
	HPPotion,
	BrainMatter,
	DEEZNUTS
};

enum ItemType
{
	Pelvis,
	BoneMarrow,
	SturdyFemur,
	SkeletonWeapon,

	BallOfWorms,
	MassOfRottenOrgans,
	ARib,
	ZombieWeapon,

	Skull,
	BrownCloth,
	Claws,
	IcyBlueEyes,

	GoldenTooth,
	GoblinEar,
	LoinCloth,
	HPPotion,
	GoblinWeapon,

	BrainMatter,
	DEEZNUTS,

	ItemCount
};
int Inventory[ItemCount] = { 0 };



class SmallMonsters {
private:
	struct SmallMonsterDetails {
		string name;
		int health;
		int damage;
	};

	SmallMonsterDetails SmallEnemy;
	MonsterType MonsterTypeSelected;

	void GetSkeletonLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 4)
		{
		case 0:
			Inventory[Pelvis] += amount;

			break;
		case 1:
			Inventory[BoneMarrow] += amount;

			break;
		case 2:
			Inventory[SturdyFemur] += amount;

			break;
		case 3:
			Inventory[SkeletonWeapon]++;

			break;
		}
	}

	void GetZombieLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 3)
		{
		case 0: Inventory[BallOfWorms] += amount; 
			cout << amount << " Ball of worm(s)";
			break;
		case 1: Inventory[MassOfRottenOrgans] += amount;
			cout << amount << " Mass of rotten organs";
			break;
		case 2: Inventory[ARib] += amount; 
			cout << amount << " Rid(s)";
			break;
		case 3: Inventory[ZombieWeapon]++; 
			cout << amount << " ill get here eventually";
			break;
		}
	}

	void GetGhoulLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 4)
		{
		case 0: Inventory[Skull] += amount; 
			cout << amount << " Skull(s)";
			break;
		case 1: Inventory[BrownCloth] += amount; 
			cout << amount << " Brown cloth(s)";
			break;
		case 2: Inventory[Claws] += amount; 
			cout << amount << " Claws(s)";
			break;
		case 3: Inventory[IcyBlueEyes] += amount; 
			cout << amount << " Icy blue eye(s)";
			break;
		}
	}

	void GetGoblinLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 4)
		{
		case 0: Inventory[GoldenTooth] += amount; 
			cout << amount << " Golden tooth(s)";
			break;
		case 1: Inventory[GoblinEar] += amount; 
			cout << amount << " Goblin ear(s)";
			break;
		case 2: Inventory[LoinCloth] += amount; 
			cout << amount << " Loin cloth(s)";
			break;
		case 3: Inventory[HPPotion] += amount; 
			cout << amount << " HP potion(s)";
			break;
		case 4: Inventory[GoblinWeapon]++;
			cout << amount << " ill get here eventually";
			break;
		}
	}

	void GetMindGoblinLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 4)
		{
		case 0: Inventory[GoblinEar] += amount;
			cout << amount << " GoblinEar(s)";
			break;
		case 1: Inventory[HPPotion] += amount;
			cout << amount << " HP potion(s)";
			break;

		case 2: Inventory[BrainMatter] += amount;
			cout << amount << " Brain matter(s)";
			break;

		case 3: Inventory[DEEZNUTS]++;
			cout << amount << " DEEZNUTS(s)";
			break;
		}
	}



public:
	void GetMonsterType() {

		SmallMonsterDetails SmallEnemy;

		switch (MonsterType(rand() % 5)) {

		case Skelleton:
			SmallEnemy.name = "Skelleton";
			SmallEnemy.health = 90;
			SmallEnemy.damage = 10;
			break;
		case Zombie:
			SmallEnemy.name = "Zombie";
			SmallEnemy.health = 110;
			SmallEnemy.damage = 20;
			break;
		case Ghoul:
			SmallEnemy.name = "Ghoul";
			SmallEnemy.health = 150;
			SmallEnemy.damage = 30;
			break;
		case Goblin:
			SmallEnemy.name = "Goblin";
			SmallEnemy.health = 100;
			SmallEnemy.damage = 10;
			break;
		case MindGoblin:
			SmallEnemy.name = "Mind goblin";
			SmallEnemy.health = 120;
			SmallEnemy.damage = 15;
			break;

		}
	}

	void GetLoot()
	{
		switch ()
		{
		case Skelleton:
			cout << SmallEnemy.name << " droped:\n";
			GetSkeletonLoot();
			break;

		case Zombie:
			cout << SmallEnemy.name << " droped:\n";
			GetZombieLoot();
			break;

		case Ghoul:
			cout << SmallEnemy.name << " droped:\n";
			GetGhoulLoot();
			break;

		case Goblin:
			cout << SmallEnemy.name << " droped:\n";
			GetGoblinLoot();
			break;

		case MindGoblin:
			cout << SmallEnemy.name << " droped:\n";
			GetMindGoblinLoot();
			break;
		}
	}
		
	
};
