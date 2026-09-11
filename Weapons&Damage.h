#include <iostream>
#include <string>
using namespace std;

enum Weapons {
	dagger,
	ShortBlade,
	BattelAxe,
	WarHammer,
	HeroBlade,
};
enum Material {
	Wood,
	Stone,
	Copper,
	Bronze,
	Iron,
	Steel,
	Daimond,
	Adamantine
};

int WeaponOnAttack(int WeaponMaterial, int WeaponAtk) {
	switch (WeaponMaterial) {
	case Wood:
		switch (WeaponAtk) {
		case dagger:
			return 4;
			break;
		case ShortBlade:
			return 6;
			break;
		case BattelAxe:
			return 8;
			break;
		case WarHammer:
			return 6;
			break;
		}
		break;
	case Stone:
		switch (WeaponAtk) {
		case dagger:
			return 5;
			break;
		case ShortBlade:
			return 7;
			break;
		case BattelAxe:
			return 8;
			break;
		case WarHammer:
			return 7;
			break;
		}
		break;
	case Copper:
		switch (WeaponAtk) {
		case dagger:
			return 6;
			break;
		case ShortBlade:
			return 8;
			break;
		case BattelAxe:
			return 9;
			break;
		case WarHammer:
			return 8;
			break;
		}
		break;
	case Bronze:
		switch (WeaponAtk) {
		case dagger:
			return 7;
			break;
		case ShortBlade:
			return 9;
			break;
		case BattelAxe:
			return 10;
			break;
		case WarHammer:
			return 9;
			break;
		}
	case Iron:
		switch (WeaponAtk) {
		case dagger:
			return 8;
			break;
		case ShortBlade:
			return 10;
			break;
		case BattelAxe:
			return 11;
			break;
		case WarHammer:
			return 10;
			break;
		}
		break;
	case Steel:
		switch (WeaponAtk) {
		case dagger:
			return 9;
			break;
		case ShortBlade:
			return 11;
			break;
		case BattelAxe:
			return 12;
			break;
		case WarHammer:
			return 11;
			break;
		}
		break;
	case Daimond:
		switch (WeaponAtk) {
		case dagger:
			return 10;
			break;
		case ShortBlade:
			return 12;
			break;
		case BattelAxe:
			return 13;
			break;
		case WarHammer:
			return 12;
			break;
		}
		break;
	case Adamantine:
		switch (WeaponAtk) {
		case dagger:
			return 11;
			break;
		case ShortBlade:
			return 13;
			break;
		case BattelAxe:
			return 14;
			break;
		case WarHammer:
			return 13;
			break;
		}
		break;

	};

}
////////////////////////
//					  //
//	  W/ Enchants     //	
//					  //
////////////////////////

