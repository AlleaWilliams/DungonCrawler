#include"Player.h"
#include "EnemyDetails.h"
#include "Weapons&Damage.h"
#include "ConsoleInput.h"
#include <iostream>
using namespace std;



void FightStyle(Player& User1, SmallMonsters& Enemy)
{
    cout << "A fight starts with the local monsters.\n";

    while (User1.GetHealth() > 0 &&
        Enemy.GetEnemyHealth() > 0)
    {
        cout << "\nEnemy: " << Enemy.GetEnemyName()
            << "\nHealth: " << Enemy.GetEnemyHealth()
            << "\n";

        bool defending = false;
        string Healing;

        int choice = ReadFromConsole(
            "\n--- YOUR TURN ---\n1) Attack\n2) Defend\nChoose: ", 1, 2);

        if (choice == 1)
        {
			vector<Weapon::AttackMove> attackMoves = User1.GetAttackMoves(); // Get the player's attack moves

			cout << "\nChoose an attack:\n";// Display the attack moves
            for (int index = 0; index < 3; index++) {
                cout << index + 1 << ") " << attackMoves[index].name
                    << " (+" << attackMoves[index].bonusDamage << " damage)\n";
            }

			int moveChoice = ReadFromConsole("Choose attack: ", 1, 3); // Get the player's choice of attack move
            Weapon::AttackMove selectedMove = attackMoves[moveChoice - 1];
            int damage = User1.Attack(selectedMove.bonusDamage);
            Enemy.EnemyTakeDamage(damage);

            cout << "\nYou used " << selectedMove.name << " and dealt "
                << damage << " damage!\n";

			if (Enemy.GetEnemyHealth() <= 0)// Check if the enemy is defeated
            {
                cout << "\nThe monster has been defeated!\n";
                Enemy.GetLoot();
                break;
            }
        }
        else if (choice == 2)
        {
            defending = true;
            cout << "\nYou defend!\n";
            cout << "Use A health potion? (y/n)";
            cin >> Healing;
			if (Healing == "y") {
				User1.UseHealthPotion();
            }

  
        }
        else
        {
			User1.PissYourSelf();// Invalid choice, player takes damage || may make this a random event that happens if the player does not choose a valid option
            continue;
        }

        // ENEMY TURN: happens only once
		int enemyAttack = Enemy.GetEnemyDamage();// Get the enemy's attack damage

		if (defending)// If the player defended, reduce the enemy's attack damage
        {
            enemyAttack /= 3;
        }

		cout << "\n--- ENEMY TURN ---\n";// Display the enemy's turn
        User1.TakeDamage(enemyAttack);

		if (User1.GetHealth() <= 0)// Check if the player is dead
        {
            cout << "\nYou have died.\n";
            break;
        }

        ContinueAtk();
    }
}
