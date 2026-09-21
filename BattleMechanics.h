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
            vector<Weapon::AttackMove> attackMoves = User1.GetAttackMoves();

            cout << "\nChoose an attack:\n";
            for (int index = 0; index < 3; index++) {
                cout << index + 1 << ") " << attackMoves[index].name
                    << " (+" << attackMoves[index].bonusDamage << " damage)\n";
            }

            int moveChoice = ReadFromConsole("Choose attack: ", 1, 3);
            Weapon::AttackMove selectedMove = attackMoves[moveChoice - 1];
            int damage = User1.Attack(selectedMove.bonusDamage);
            Enemy.EnemyTakeDamage(damage);

            cout << "\nYou used " << selectedMove.name << " and dealt "
                << damage << " damage!\n";

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
            cout << "\nYou defend!\n";
            cout << "Use A health potion? (y/n)";
            cin >> Healing;
            if (Healing == "y") {
                /*User1.UseHPPotion();*/
            }

  
        }
        else
        {
            User1.PissYourSelf();
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
