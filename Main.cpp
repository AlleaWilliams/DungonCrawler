#include "BattleMechanics.h"
#include "EnemyDetails.h"
#include "Weapons&Damage.h"
#include <iostream>
#include <string>
using namespace std;



int main() {

	srand(time(NULL)); //GAMBLING

	//// Making A character Skit

	string StartGame;

	Player User1;

	SmallMonsters enemy;

	enemy.GetMonsterType();

	int EnemyHealth = 80;
	int EnemyHit = 10;


	cout << "Are you willing to risk it (y/n): ";
	cin >> StartGame;

	cout << "I don't really care about what you put, you're playing :)\n\n";


	User1.SetGameCharacter();


	// LORE?!?!?!?!?!?!?!

	cout << "\n\nYou, a not so proud child of the former hero, was kidnapped.";

	ContinueStory();


	cout << "\nThey put you in a sack and hauled you off, into:";
	cout << "\nTHE PIT OF NO RETURN";

	ContinueStory();


	cout << "\nYou must fight for your life to make it out of this hell,";
	cout << "\nor die being the loser son of the former hero.";

	ContinueStory();

	FightStyle(User1, enemy);

	cout << "\nyou did't die, i'm suprised";

	return 0;

}
