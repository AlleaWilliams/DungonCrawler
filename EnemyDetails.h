#pragma once
#include <iostream>
#include <string>
using namespace std;
#define ENEMYDETAILS_H
#include "Weapons&Damage.h" // moved down to keep include order consistent (no functional change)
#include "Weapons&Damage.h"
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
	skellMune
};
enum ZombieLoot
{
	BallOfWorms,
	MassOfRottenOrgans,
	ARib,
	zomMune,
	
};
enum GhoulLoot
{
	Skull,
	BrownCloth,
	Claws,
	IcyBlueEyes,
	goMune
};
enum GoblinLoot
{
	GoldenTooth,
	GoblinEar,
	LoinCLoth,
	HPpotion,
	gobMune,
	

};
enum MindGoblinLoot
{
	MindGoblinEar,
	HPPotion,
	BrainMatter,
	DEEZNUTS,
	mindMune
};

enum ItemType
{
	pelvis,
	boneMarrow,
	sturdyFemur,
	Mune,

	

	ballOfWorms,
	massOfRottenOrgans,
	aRib,


	skull,
	brownCloth,
	claws,
	icyBlueEyes,

	goldenTooth,
	goblinEar,
	loinCloth,
	hPPotion,

	mindGoblinEar,
	brainMatter,
	deezNUTS,

	ItemCount
};
extern int Inventory[ItemCount];



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
			Inventory[pelvis] += amount;
			cout << amount << " Pelvis";
			break;
		case 1:
			Inventory[boneMarrow] += amount;
			cout << amount << " Bone marrow";
			break;
		case 2:
			Inventory[sturdyFemur] += amount ;
			cout << amount << " Sturdy fremur(s)";
			break;
		case 3:
			Inventory[Mune] += amount * 5;
			cout << amount + 6 << " mune(s)";
			break;

		}
	}

	void GetZombieLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 4)
		{
		case 0: Inventory[ballOfWorms] += amount; 
			cout << amount << " Ball of worm(s)";
			break;
		case 1: Inventory[massOfRottenOrgans] += amount;
			cout << amount << " Mass of rotten organs";
			break;
		case 2: Inventory[aRib] += amount; 
			cout << amount << " Rid(s)";
			break;
		case 3: Inventory[Mune] += amount;
			cout << amount + 6 << " mune(s)";
			break;

		}
	}

	void GetGhoulLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 5)
		{
		case 0: Inventory[skull] += amount; 
			cout << amount << " Skull(s)";
			break;
		case 1: Inventory[brownCloth] += amount; 
			cout << amount << " Brown cloth(s)";
			break;
		case 2: Inventory[claws] += amount; 
			cout << amount << " Claws(s)";
			break;
		case 3: Inventory[icyBlueEyes] += amount; 
			cout << amount << " Icy blue eye(s)";
			break;
		case 4: 
			Inventory[Mune] += amount * 5;
			cout << amount + 6 << " mune(s)";
			break;
		}
	}

	void GetGoblinLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 5)
		{
		case 0: Inventory[goldenTooth] += amount; 
			cout << amount << " Golden tooth(s)";
			break;
		case 1: Inventory[goblinEar] += amount; 
			cout << amount << " Goblin ear(s)";
			break;
		case 2: Inventory[loinCloth] += amount; 
			cout << amount << " Loin cloth(s)";
			break;
		case 3: Inventory[hPPotion] += amount; 
			cout << amount << " HP potion(s)";
			break;
		case 4:
			Inventory[Mune] += amount * 5;
			cout << amount + 6 << " mune(s)";
			break;
		}
	}

	void GetMindGoblinLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 5)
		{
		case 0: Inventory[mindGoblinEar] += amount;
			cout << amount << " GoblinEar(s)";
			break;
		case 1: Inventory[hPPotion] += amount;
			cout << amount << " HP potion(s)";
			break;

		case 2: Inventory[brainMatter] += amount;
			cout << amount << " Brain matter(s)";
			break;

		case 3: Inventory[deezNUTS]++;
			cout << amount << " DEEZNUTS(s)";
			break;
		case 4:
			Inventory[Mune] += amount * 5;
			cout << amount + 6 << " mune(s)";
			break;
		}
	}


public:

	void GetMonsterType()
	{
		MonsterTypeSelected = MonsterType(rand() % 5);

		switch (MonsterTypeSelected)
		{
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

	int GetEnemyHealth() {
		return SmallEnemy.health;
	}

	int GetEnemyDamage() {

		return SmallEnemy.damage;
	}
	string GetEnemyName() {
		return SmallEnemy.name;
	}
	void EnemyTakeDamage(int damage) {
		SmallEnemy.health -= damage;

		if (SmallEnemy.health < 0) {
			SmallEnemy.health = 0;
		}
	}
	void GetLoot()
	{

		cout << SmallEnemy.name << " droped:\n";
		switch (MonsterTypeSelected)
		{

		case Skelleton:
			
			GetSkeletonLoot();
			break;

		case Zombie:
			
			GetZombieLoot();
			break;

		case Ghoul:
			
			GetGhoulLoot();
			break;

		case Goblin:
			
			GetGoblinLoot();
			break;

		case MindGoblin:
			
			GetMindGoblinLoot();
			break;
		}
	}


};

