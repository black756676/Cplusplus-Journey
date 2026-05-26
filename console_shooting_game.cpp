#include <iostream>//lets gooo
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int playerHealth = 100;
    int enemyHealth = 100;
    int bullets = 5;
    int maxBullets = 5;
    int choice;

    srand(time(0));

    cout << "===== Console Shooting Game =====" << endl;

    while (playerHealth > 0 && enemyHealth > 0) {
        cout << endl;
        cout << "Player Health: " << playerHealth << endl;
        cout << "Enemy Health: " << enemyHealth << endl;
        cout << "Bullets: " << bullets << "/" << maxBullets << endl;

        cout << endl;
        cout << "1. Shoot" << endl;
        cout << "2. Reload" << endl;
        cout << "3. Heal" << endl;
        cout << "4. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            if (bullets <= 0) {
                cout << "No bullets! Reload first." << endl;
                continue;
            }

            int damage = rand() % 21 + 10;
            enemyHealth = enemyHealth - damage;
            bullets--;

            cout << "You shot enemy for " << damage << " damage!" << endl;

        } else if (choice == 2) {
            bullets = maxBullets;
            cout << "Reloaded! Bullets are full." << endl;

        } else if (choice == 3) {
            playerHealth = playerHealth + 20;

            if (playerHealth > 100) {
                playerHealth = 100;
            }

            cout << "You healed. Health is now " << playerHealth << endl;

        } else if (choice == 4) {
            cout << "You quit the game." << endl;
            break;

        } else {
            cout << "Wrong choice." << endl;
            continue;
        }

        if (enemyHealth <= 0) {
            cout << endl;
            cout << "You defeated the enemy!" << endl;
            break;
        }

        int enemyDamage = rand() % 16 + 5;
        playerHealth = playerHealth - enemyDamage;

        cout << "Enemy attacked you for " << enemyDamage << " damage!" << endl;
    }

    if (playerHealth <= 0) {
        cout << endl;
        cout << "Game Over! Enemy won." << endl;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
