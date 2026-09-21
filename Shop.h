#pragma once

#include "ConsoleInput.h"
#include "PLayer.h"

class Shop {
private:
	static int GetSellPrice(ItemType item) {
		switch (item) {
		case pelvis: return 3;
		case boneMarrow: return 2;
		case sturdyFemur: return 5;
		case ballOfWorms: return 2;
		case massOfRottenOrgans: return 4;
		case aRib: return 3;
		case skull: return 5;
		case brownCloth: return 2;
		case claws: return 4;
		case icyBlueEyes: return 6;
		case goldenTooth: return 7;
		case goblinEar: return 3;
		case loinCloth: return 2;
		case hPPotion: return 5;
		case mindGoblinEar: return 6;
		case brainMatter: return 8;
		case deezNUTS: return 10;
		default: return 0;
		}
	}

	static const char* GetItemName(ItemType item) {
		switch (item) {
		case pelvis: return "Pelvis";
		case boneMarrow: return "Bone marrow";
		case sturdyFemur: return "Sturdy femur";
		case ballOfWorms: return "Ball of worms";
		case massOfRottenOrgans: return "Mass of rotten organs";
		case aRib: return "Rib";
		case skull: return "Skull";
		case brownCloth: return "Brown cloth";
		case claws: return "Claws";
		case icyBlueEyes: return "Icy blue eyes";
		case goldenTooth: return "Golden tooth";
		case goblinEar: return "Goblin ear";
		case loinCloth: return "Loin cloth";
		case hPPotion: return "Found health potion";
		case mindGoblinEar: return "Mind goblin ear";
		case brainMatter: return "Brain matter";
		case deezNUTS: return "DEEZ NUTS";
		default: return "Unknown item";
		}
	}

	void BuyHealthPotion(Player& player) const {
		const int healthPotionPrice = 10;

		if (!player.SpendMune(healthPotionPrice)) {
			std::cout << "\nYou need " << healthPotionPrice << " mune to buy a health potion.\n";
			return;
		}

		player.AddHealthPotion();
		std::cout << "\nYou bought a health potion. You now have "
			<< player.GetHealthPotionCount() << ".\n";
	}

	void SellLoot(Player& player) const {
		static const ItemType lootItems[] = {
			pelvis, boneMarrow, sturdyFemur, ballOfWorms, massOfRottenOrgans,
			aRib, skull, brownCloth, claws, icyBlueEyes, goldenTooth, goblinEar,
			loinCloth, hPPotion, mindGoblinEar, brainMatter, deezNUTS
		};
		const int lootItemCount = static_cast<int>(sizeof(lootItems) / sizeof(lootItems[0]));

		std::cout << "\n--- SELL MONSTER LOOT ---\n";
		for (int index = 0; index < lootItemCount; index++) {
			ItemType item = lootItems[index];
			std::cout << index + 1 << ") " << GetItemName(item)
				<< " x" << Inventory[item] << " - " << GetSellPrice(item) << " mune\n";
		}
		std::cout << lootItemCount + 1 << ") Back\n";

		int choice = ReadFromConsole("Choose loot to sell: ", 1, lootItemCount + 1);
		if (choice == lootItemCount + 1) return;

		ItemType selectedItem = lootItems[choice - 1];
		if (Inventory[selectedItem] <= 0) {
			std::cout << "You do not have that item.\n";
			return;
		}

		Inventory[selectedItem]--;
		int price = GetSellPrice(selectedItem);
		player.AddMune(price);
		std::cout << "Sold " << GetItemName(selectedItem) << " for " << price << " mune.\n";
	}

public:
	void Open(Player& player) const {
		while (true) {
			std::cout << "\n--- SHOP ---\n"
				<< "Mune: " << player.GetMune() << "\n"
				<< "1) Buy health potion (10 mune)\n"
				<< "2) Sell monster loot\n"
				<< "3) Leave shop\n";

			int choice = ReadFromConsole("Choose: ", 1, 3);
			if (choice == 1) BuyHealthPotion(player);
			else if (choice == 2) SellLoot(player);
			else return;
		}
	}
};

