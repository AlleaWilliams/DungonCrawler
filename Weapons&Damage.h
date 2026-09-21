#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;


class WeaponMaterial {
protected:
	string weaponMaterialName;
	int weaponMaterialOnAtk;
public:
	virtual ~WeaponMaterial() = default;

	const string& getWeaponMaterialName() const { return weaponMaterialName; }// chnges the string name to a const reference to avoid unnecessary copying
	void setWeaponMaterialName(const string& name) { weaponMaterialName = name; }

	virtual int GetDamage() const = 0; // each material will have its own damage value, so we make this a pure virtual function

};

class WoodMaterial : public WeaponMaterial {
public:
	WoodMaterial() {
		weaponMaterialName = "Wood";
		weaponMaterialOnAtk = 1; // Wood adds 1 damage
	}
	int GetDamage() const override {
		return weaponMaterialOnAtk;
	}
};

class StoneMaterial : public WeaponMaterial {
public:
	StoneMaterial() {
		weaponMaterialName = "Stone";
		weaponMaterialOnAtk = 2; // Stone adds 2 damage
	}
	int GetDamage() const override {
		return weaponMaterialOnAtk;
	}
};

class copperMaterial : public WeaponMaterial {
public:
	copperMaterial() {
		weaponMaterialName = "Copper";
		weaponMaterialOnAtk = 2; // Copper adds 2 damage
	}
	int GetDamage() const override {
		return weaponMaterialOnAtk;
	}
};

class bronzeMaterial : public WeaponMaterial {
public:
	bronzeMaterial() {
		weaponMaterialName = "Bronze";
		weaponMaterialOnAtk = 3; // Bronze adds 3 damage
	}
	int GetDamage() const override {
		return weaponMaterialOnAtk;
	}
};

class IronMaterial : public WeaponMaterial {
public:
	IronMaterial() {
		weaponMaterialName = "Iron";
		weaponMaterialOnAtk = 4; // Iron adds 4 damage
	}
	int GetDamage() const override {
		return weaponMaterialOnAtk;
	}
};

class steelMaterial : public WeaponMaterial {
public:
	steelMaterial() {
		weaponMaterialName = "Steel";
		weaponMaterialOnAtk = 5; // Steel adds 5 damage
	}
	int GetDamage() const override {
		return weaponMaterialOnAtk;
	}
};

class daimondMaterial : public WeaponMaterial {
public:
	daimondMaterial() {
		weaponMaterialName = "Daimond";
		weaponMaterialOnAtk = 6; // Daimond adds 6 damage
	}
	int GetDamage() const override {
		return weaponMaterialOnAtk;
	}
};

class adamantineMaterial : public WeaponMaterial {
public:
	adamantineMaterial() {
		weaponMaterialName = "Adamantine";
		weaponMaterialOnAtk = 7; // Adamantine adds 7 damage
	}
	int GetDamage() const override {
		return weaponMaterialOnAtk;
	}
};











class Weapon {
public:
	enum class Type { Dagger, ShortBlade, BattleAxe, WarHammer, HeroBlade };

	struct AttackMove {
		string name;
		int bonusDamage;
	};

private:
	Type currentWeapon;
	const WeaponMaterial* material;

public:
	Weapon(Type type, const WeaponMaterial& weaponMaterial)
		: currentWeapon(type), material(&weaponMaterial) {}

	void SetType(Type type) { currentWeapon = type; }
	Type GetType() const { return currentWeapon; }

	void SetMaterial(const WeaponMaterial& weaponMaterial) {
		material = &weaponMaterial;
	}

	const string& GetMaterialName() const {
		return material->getWeaponMaterialName();
	}

	vector<AttackMove> GetRandomAttackMoves() const {
		vector<AttackMove> moves;

		switch (currentWeapon) {
		case Type::Dagger:
			moves = { { "Quick Stab", 1 }, { "Backstab", 3 }, { "Knife Throw", 2 },
				{ "Slice", 1 }, { "Vital Strike", 4 }, { "Shadow Jab", 2 } };
			break;
		case Type::ShortBlade:
			moves = { { "Slash", 1 }, { "Double Cut", 2 }, { "Parrying Strike", 2 },
				{ "Lunge", 3 }, { "Pommel Hit", 1 }, { "Blade Dance", 4 } };
			break;
		case Type::BattleAxe:
			moves = { { "Cleave", 3 }, { "Heavy Chop", 4 }, { "Axe Hook", 2 },
				{ "Whirlwind", 3 }, { "Skull Splitter", 5 }, { "Brutal Swing", 4 } };
			break;
		case Type::WarHammer:
			moves = { { "Crushing Blow", 4 }, { "Ground Slam", 3 }, { "Hammer Toss", 2 },
				{ "Armor Break", 4 }, { "Thunder Strike", 5 }, { "Heavy Smash", 3 } };
			break;
		case Type::HeroBlade:
			moves = { { "Hero Slash", 4 }, { "Radiant Strike", 5 }, { "Blazing Arc", 4 },
				{ "Champion's Lunge", 6 }, { "Sky Cleaver", 5 }, { "Last Stand", 7 } };
			break;
		}

		static mt19937 randomEngine(random_device{}());
		shuffle(moves.begin(), moves.end(), randomEngine);
		moves.resize(3);
		return moves;
	}

	int GetDamage() const {
		int typeDamage = 0;

		switch (currentWeapon) {
			case Type::Dagger:
				typeDamage = 1;
				break;
			case Type::ShortBlade:
				typeDamage = 2;
				break;
			case Type::BattleAxe:
				typeDamage = 3;
				break;
			case Type::WarHammer:
				typeDamage = 4;
				break;
			case Type::HeroBlade:
				typeDamage = 5;
				break;
		}

		return typeDamage + material->GetDamage();
	}
};

















////////////////////////
//					  //
//	  W/ Enchants     //	
//					  //
////////////////////////

