#include <iostream>
#include <string>
using namespace std;

enum Weapons {
	Hand,
	dagger,
	ShortBlade,
	BattelAxe,
	WarHammer,
	HeroBlade,
};
enum Material {
	Flesh,
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
		case 00:
			return 4;
			break;
		case 1:
			return 6;
			break;
		case 2:
			return 8;
			break;
		case 3:
			return 6;
			break;
		}
		break;
	case Stone:
		switch (WeaponAtk) {
		case 0:
			return 5;
			break;
		case 1:
			return 7;
			break;
		case 2:
			return 8;
			break;
		case 3:
			return 7;
			break;
		}
		break;
	case Copper:
		switch (WeaponAtk) {
		case 0:
			return 6;
			break;
		case 1:
			return 8;
			break;
		case 2:
			return 9;
			break;
		case 3:
			return 8;
			break;
		}
		break;
	case Bronze:
		switch (WeaponAtk) {
		case 0:
			return 7;
			break;
		case 1:
			return 9;
			break;
		case 2:
			return 10;
			break;
		case 3:
			return 9;
			break;
		}
	case Iron:
		switch (WeaponAtk) {
		case 0:
			return 8;
			break;
		case 1:
			return 10;
			break;
		case 2:
			return 11;
			break;
		case 3:
			return 10;
			break;
		}
		break;
	case Steel:
		switch (WeaponAtk) {
		case 0:
			return 9;
			break;
		case 1:
			return 11;
			break;
		case 2:
			return 12;
			break;
		case 3:
			return 11;
			break;
		}
		break;
	case Daimond:
		switch (WeaponAtk) {
		case 0:
			return 10;
			break;
		case 1:
			return 12;
			break;
		case 2:
			return 13;
			break;
		case 3:
			return 12;
			break;
		}
		break;
	case Adamantine:
		switch (WeaponAtk) {
		case 0:
			return 11;
			break;
		case 1:
			return 13;
			break;
		case 2:
			return 14;
			break;
		case 3:
			return 13;
			break;
		}
		break;
	case Flesh:
		switch (WeaponAtk) {
		case Hand:
			return 0;
		}

	};

}
////////////////////////
//					  //
//	  W/ Enchants     //	
//					  //
////////////////////////

