#pragma once
#include "EnemyDetails.h"
#include "Weapons&Damage.h"
#include <iostream>
#include <string>
using namespace std;



void FightStyle(Player User1, int EnemyHealth, int EnemyHit) {
	while (User1.GetHealth() > 0 && EnemyHealth > 0) {

		// PLAYER TURN
		int PVBChoice;

		cout << "\n--- YOUR TURN ---\n";
		cout << "1) Attack\n2) Defend\n";

		cin >> PVBChoice;

		if (PVBChoice == 1) {

			User1.Attack(EnemyHealth);

			// Check if enemy died
			if (EnemyHealth <= 0) {
				EnemyHealth = 0;
				cout << "\nThe undead has been defeated!\n";
				break;



			}


			// ENEMY TURN
			int EnemyAttack = EnemyHit;

			cout << "\n--- ENEMY TURN ---\n";

			User1.TakeDamage(EnemyAttack);

			ContinueAtk();
		}
		else if (PVBChoice == 2) {

			cout << "\n\n--- ENEMY TURN ---\n\n";

			cout << "Attack was ineffective\n ";

			ContinueAtk();
		}
		else {// make more elseifs to get word input to givew pissyourself

			User1.PissYourSelf();

			// ENEMY TURN
			int EnemyAttack = EnemyHit;

			cout << "\n--- ENEMY TURN ---\n";

			User1.TakeDamage(EnemyAttack);

			ContinueAtk();
		}






		// Check if player died

		if (User1.GetHealth() <= 0) {

			cout << "\nYou have died.\n";
			break;

		}



	}