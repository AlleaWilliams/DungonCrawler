#pragma once
#include "Main.cpp"
#include "EnemyDetails.h"
#include "Weapons&Damage.h"
#include <iostream>
#include <string>
using namespace std;



void FightStyle(Player User1, SmallMonsters Enemy) {
	Enemy.GetMonsterType();
	cout << "A fight starts with the local monsters.";

	while (User1.GetHealth() > 0 && Enemy.GetEnemyHealth() > 0) {

		cout << "\n Enemy: " << Enemy.GetEnemyName()
			<< "\nHealth: " << Enemy.GetEnemyHealth()
			<< "\n";


		// PLAYER TURN
		int EnemyHealth = Enemy.GetEnemyHealth();
		int PVBChoice;

		cout << "\n--- YOUR TURN ---\n";
		cout << "1) Attack\n2) Defend\n";

		cin >> PVBChoice;

		if (PVBChoice == 1) { ////////////////////PLAYER ATTACK

			User1.Attack(EnemyHealth);

			// Check if enemy died
			if (EnemyHealth <= 0) {
				EnemyHealth = 0;
				cout << "\nThe undead has been defeated!\n";
				break;



			}


			// ENEMY TURN
			int EnemyAttack = Enemy.GetEnemyDamage();

			cout << "\n--- ENEMY TURN ---\n";

			User1.TakeDamage(EnemyAttack);

			ContinueAtk();


		}
		else if (PVBChoice == 2) {/////////////////PLAYER BLOCK

			cout << "\n\n--- ENEMY TURN ---\n\n";

			cout << "Attack was ineffective\n ";

			ContinueAtk();




		}
		else if (PVBChoice > 2 || PVBChoice < 1) {//////////////////// Other num Blocker || need a letter blocker

			User1.PissYourSelf();
		}
		else {
			User1.PissYourSelf();

		}

		// ENEMY TURN
		int EnemyAttack = Enemy.GetEnemyDamage();

		cout << "\n--- ENEMY TURN ---\n";

		User1.TakeDamage(EnemyAttack);

		ContinueAtk();

		// Check if player died

		if (User1.GetHealth() <= 0) {

			cout << "\nYou have died.\n";
			break;

		}

	}
	
}

