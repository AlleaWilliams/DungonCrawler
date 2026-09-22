#pragma once

#include "ConsoleInput.h"
#include "PLayer.h"

class Shop {
private:
	static int GetSellPrice(ItemType item) {// Returns the sell price for a given item type
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

	static const char* GetItemName(ItemType item) {// Returns the name of the item type as a string
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

	void BuyHealthPotion(Player& player) const {// Handles the purchase of a health potion by the player
		const int healthPotionPrice = 10;

		if (!player.SpendMune(healthPotionPrice)) {// Check if the player has enough currency to buy a health potion
			std::cout << "\nYou need " << healthPotionPrice << " mune to buy a health potion.\n";
			return;
		}

		player.AddHealthPotion();
		std::cout << "\nYou bought a health potion. You now have "
			<< player.GetHealthPotionCount() << ".\n";
	}

	void SellLoot(Player& player) const {// Handles the selling of monster loot by the player
		static const ItemType lootItems[] = {
			pelvis, boneMarrow, sturdyFemur, ballOfWorms, massOfRottenOrgans,
			aRib, skull, brownCloth, claws, icyBlueEyes, goldenTooth, goblinEar,
			loinCloth, hPPotion, mindGoblinEar, brainMatter, deezNUTS
		};
		const int lootItemCount = static_cast<int>(sizeof(lootItems) / sizeof(lootItems[0]));// Calculate the number of loot items

		std::cout << "\n--- SELL MONSTER LOOT ---\n";
		for (int index = 0; index < lootItemCount; index++) {// Display the available loot items for sale
			ItemType item = lootItems[index];
			std::cout << index + 1 << ") " << GetItemName(item)// Display the item name, quantity, and sell price
				<< " x" << Inventory[item] << " - " << GetSellPrice(item) << " mune\n";
		}
		std::cout << lootItemCount + 1 << ") Back\n";

		int choice = ReadFromConsole("Choose loot to sell: ", 1, lootItemCount + 1);
		if (choice == lootItemCount + 1) return;

		ItemType selectedItem = lootItems[choice - 1];// Get the selected item type based on the player's choice
		if (Inventory[selectedItem] <= 0) {
			std::cout << "You do not have that item.\n";
			return;
		}

		Inventory[selectedItem]--;
		int price = GetSellPrice(selectedItem);
		player.AddMune(price);
		std::cout << "Sold " << GetItemName(selectedItem) << " for " << price << " mune.\n";
	}

	void ShowInventory() const {
		static const ItemType lootItems[] = {
			pelvis, boneMarrow, sturdyFemur, ballOfWorms, massOfRottenOrgans,
			aRib, skull, brownCloth, claws, icyBlueEyes, goldenTooth, goblinEar,
			loinCloth, hPPotion, mindGoblinEar, brainMatter, deezNUTS
		};
		const int lootItemCount = static_cast<int>(sizeof(lootItems) / sizeof(lootItems[0]));
		bool hasLoot = false;

		std::cout << "\n--- YOUR LOOT INVENTORY ---\n";
		for (int index = 0; index < lootItemCount; index++) {
			ItemType item = lootItems[index];
			int amount = Inventory[item];
			if (amount <= 0) continue;

			std::string itemName = GetItemName(item);
			if (amount > 1) {
				itemName.append("s");
			}

			std::cout << amount << " " << itemName << "\n";
			hasLoot = true;
		}

		if (!hasLoot) {
			std::cout << "You do not have any monster loot yet.\n";
		}
	}

public:
	void Open(Player& player) const {// Opens the shop interface for the player
		while (true) {
			std::cout << "\n--- SHOP ---\n"
				<< "Mune: " << player.GetMune() << "\n"
				<< "1) Buy health potion (10 mune)\n"
				<< "2) Sell monster loot\n"
				<< "3) Show loot inventory\n"
				<< "4) Leave shop\n";

			int choice = ReadFromConsole("Choose: ", 1, 4);
			if (choice == 1) BuyHealthPotion(player);
			else if (choice == 2) SellLoot(player);
			else if (choice == 3) ShowInventory();
			else return;
		}
	}
};
