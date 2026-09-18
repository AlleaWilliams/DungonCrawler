#include"Player.h"
#include "EnemyDetails.h"
#include "Weapons&Damage.h"
#include <iostream>
using namespace std;



//void FightStyle(Player User1,SmallMonsters Enemy) {
//	Enemy.GetMonsterType();
//	cout << "A fight starts with the local monsters.";
//
//	while (User1.GetHealth() > 0 && Enemy.GetEnemyHealth() > 0) {
//
//		cout << "\n Enemy: " << Enemy.GetEnemyName()
//			<< "\nHealth: " << Enemy.GetEnemyHealth()
//			<< "\n";
//
//
//		// PLAYER TURN
//		int EnemyHealth = Enemy.GetEnemyHealth();
//		int PVBChoice;
//
//		cout << "\n--- YOUR TURN ---\n";
//		cout << "1) Attack\n2) Defend\n";
//
//		cin >> PVBChoice;
//
//		if (PVBChoice == 1) { ////////////////////PLAYER ATTACK
//
//			User1.Attack(EnemyHealth);
//
//			// Check if enemy died
//			if (EnemyHealth <= 0) {
//				EnemyHealth = 0;
//				cout << "\nThe undead has been defeated!\n";
//				break;
//
//
//
//			}
//
//
//			// ENEMY TURN
//			int EnemyAttack = Enemy.GetEnemyDamage();
//
//			cout << "\n--- ENEMY TURN ---\n";
//
//			User1.TakeDamage(EnemyAttack);
//
//			ContinueAtk();
//
//
//		}
//		else if (PVBChoice == 2) {/////////////////PLAYER BLOCK
//
//			cout << "\n\n--- ENEMY TURN ---\n\n";
//
//			cout << "Attack was ineffective\n ";
//
//			ContinueAtk();
//
//
//
//
//		}
//		else if (PVBChoice > 2 || PVBChoice < 1) {//////////////////// Other num Blocker || need a letter blocker
//
//			User1.PissYourSelf();
//		}
//		else {
//			User1.PissYourSelf();
//
//		}
//
//		// ENEMY TURN
//		int EnemyAttack = Enemy.GetEnemyDamage();
//
//		cout << "\n--- ENEMY TURN ---\n";
//
//		User1.TakeDamage(EnemyAttack);
//
//		ContinueAtk();
//
//		// Check if player died
//
//		if (User1.GetHealth() <= 0) {
//
//			cout << "\nYou have died.\n";
//			break;
//
//		}
//
//	}
//	
//}

void FightStyle(Player& User1, SmallMonsters& Enemy)
{
    cout << "A fight starts with the local monsters.\n";

    while (User1.GetHealth() > 0 &&
        Enemy.GetEnemyHealth() > 0)
    {
        cout << "\nEnemy: " << Enemy.GetEnemyName()
            << "\nHealth: " << Enemy.GetEnemyHealth()
            << "\n";

        int choice;
        bool defending = false;

        cout << "\n--- YOUR TURN ---\n";
        cout << "1) Attack\n2) Defend\n";
        cin >> choice;

        if (choice == 1)
        {
            int damage = User1.Attack(Enemy.GetEnemyHealth());
            Enemy.EnemyTakeDamage(damage);

            cout << "\nYou dealt " << damage << " damage!\n";

            if (Enemy.GetEnemyHealth() <= 0)
            {
                cout << "\nThe monster has been defeated!\n";
                Enemy.GetLoot();
                break;
            }
        }
        else if (choice == 2)
        {
            defending = true;
            cout << "\nYou prepare to defend!\n";
        }
        else
        {
            cout << "\nInvalid choice. Try again.\n";
            continue;
        }

        // ENEMY TURN: happens only once
        int enemyAttack = Enemy.GetEnemyDamage();

        if (defending)
        {
            enemyAttack /= 2;
        }

        cout << "\n--- ENEMY TURN ---\n";
        User1.TakeDamage(enemyAttack);

        if (User1.GetHealth() <= 0)
        {
            cout << "\nYou have died.\n";
            break;
        }

        ContinueAtk();
    }
}