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

void GetMonsterType() {

	srand(time(NULL)); //GAMBLING
	int MosterTypeRNG = rand() % 4;


}

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

int GetLoot(){
	int RandLoot1;
	int RandLoot2;
	int RandLoot3;
	srand(time(NULL)); //GAMBLING
	int LootAmount = rand() % 3 + 1;

	if (LootAmount == 1) {
		
	}
	else if (LootAmount == 2) {
	
	}
	else if (LootAmount == 3) {
	
	}

}



