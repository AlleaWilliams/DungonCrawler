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
			if (amount > 1) {
				cout << amount << " Pelvises";
			}
			else {
				cout << amount << " Pelvis";
			}
			break;
		case 1:
			Inventory[boneMarrow] += amount;
				cout << amount << " Bone marrow";
			break;
		case 2:
			Inventory[sturdyFemur] += amount ;
			if(amount > 1) {
				cout << amount << " Sturdy femurs";
			}
			else {
				cout << amount << " Sturdy femur";
			}
			break;
		case 3:
			Inventory[Mune] += amount * 5;
			cout << amount + 6 << " mune";
			break;

		}
	}

	void GetZombieLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 4)
		{
		case 0: Inventory[ballOfWorms] += amount;
			if(amount > 1) {
				cout << amount << " Balls of worms";
			}
			else {
				cout << amount << " Ball of worms";
			}
			break;
		case 1: Inventory[massOfRottenOrgans] += amount;
			if(amount > 1) {
				cout << amount << " Masses of rotten organs";
			}
			else {
				cout << amount << " Mass of rotten organs";
			}
			break;
		case 2: Inventory[aRib] += amount; 
			if(amount > 1) {
				cout << amount << " Ribs";
			}
			else {
				cout << amount << " Rib";
			}
			break;
		case 3: Inventory[Mune] += amount;
			cout << amount + 6 << " mune";
			break;

		}
	}

	void GetGhoulLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 5)
		{
		case 0: Inventory[skull] += amount; 
			if (amount > 1) {
				cout << amount << " Skulls";
			}
			else {
				cout << amount << " Skull";
			}
			break;
		case 1: Inventory[brownCloth] += amount; 
			if(amount > 1) {
				cout << amount << " Brown cloths";
			}
			else {
				cout << amount << " Brown cloth";
			}
			break;
		case 2: Inventory[claws] += amount; 
			if(amount > 1) {
				cout << amount << " Claws";
			}
			else {
				cout << amount << " Claw";
			}
			break;
		case 3: Inventory[icyBlueEyes] += amount;
			if(amount > 1) {
				cout << amount << " Icy blue eyes";
			}
			else {
				cout << amount << " Icy blue eye";
			}
			break;
		case 4: 
			Inventory[Mune] += amount * 5;
			cout << amount + 6 << " mune";
			break;
		}
	}

	void GetGoblinLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 5)
		{
		case 0: Inventory[goldenTooth] += amount; 
			if(amount > 1) {
				cout << amount << " Golden teeth";
			}
			else {
				cout << amount << " Golden tooth";
			}
			break;
		case 1: Inventory[goblinEar] += amount; 
			if(amount > 1) {
				cout << amount << " Goblin ears";
			}
			else {
				cout << amount << " Goblin ear";
			}
			break;
		case 2: Inventory[loinCloth] += amount; 
			if(amount > 1) {
				cout << amount << " Loin cloths";
			}
			else {
				cout << amount << " Loin cloth";
			}
			break;
		case 3: Inventory[hPPotion] += amount; 
			if(amount > 1) {
				cout << amount << " HP potions";
			}
			else {
				cout << amount << " HP potion";
			}
			break;
		case 4:
			Inventory[Mune] += amount * 5;
			cout << amount + 6 << " mune";
			break;
		}
	}

	void GetMindGoblinLoot()
	{
		int amount = rand() % 3 + 1;

		switch (rand() % 5)
		{
		case 0: Inventory[mindGoblinEar] += amount;
			if(amount > 1) {
				cout << amount << " Goblin ears";
			}
			else {
				cout << amount << " Goblin ear";
			}
			break;
		case 1: Inventory[hPPotion] += amount;
			if(amount > 1) {
				cout << amount << " HP potions";
			}
			else {
				cout << amount << " HP potion";
			}
			break;

		case 2: Inventory[brainMatter] += amount;
			if(amount > 1) {
				cout << amount << " Brain matters";
			}
			else {
				cout << amount << " Brain matter";
			}
			break;

		case 3: Inventory[deezNUTS]++;
			if(amount > 1) {
				cout << amount << " DEEZNUTS";
			}
			else {
				cout << amount << " DISNUT";
			}
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