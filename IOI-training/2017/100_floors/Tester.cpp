#include <iostream>
#include <vector>
#include <cstdlib>
#include "100_towers.h"

using namespace std;

int main(void) {
    // Initial towers. You can change this to play different games.
    int towers[100] = {36, 6, 30, 27, 14, 0, 26, 9, 46, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Global cubes counter. The game is over when it hits 0.
    int total_cubes = 0;

    // Random seed for system moves.
    srand(1);

    // Initialize towers vector and total_cubes.
    vector<int> user_towers(100, 0);
    for(int i = 0; i < 100; i++) {
        user_towers[i] = towers[i];
        total_cubes += towers[i];
    }
    
    // Call init() and validate.
    int user_init = init(user_towers);
    if(user_init != 1 && user_init != 2) {
        cout << "Your init function must return 1 or 2." << endl;
        return 0;
    };

    cout << "You chose to be player " << user_init << "." << endl;
    bool user_turn = (user_init == 1);

    int turn_counter = 0;

    // Game loop.
    while(total_cubes > 0) {
        turn_counter++;
        cout << "(" << turn_counter << ")  ";
        
        // User's turn.
        if(user_turn) {
            // Get user's turn and validate.
            vector<int> user_move = your_move();
            if(user_move.size() != 2) {
                cout << "You made an illegal move." << endl;
                return 0;
            };
            int user_tower = user_move[0];
            int user_cubes = user_move[1];

            if(user_tower < 0 || user_tower >= 100 || user_cubes < 1 || user_cubes > 3 || towers[user_tower] < user_cubes) {
                cout << "You made an illegal move." << endl;
                return 0;
            }

            cout << "Your move:     remove " << user_cubes << " cubes from tower " << user_tower << ", its new height is " << towers[user_tower] - user_cubes << "." << endl;

            // Update according to user's move.
            towers[user_tower] -= user_cubes;
            total_cubes -= user_cubes;
        }

        // System's move.
        else {
            // Choose a random non-empty tower, and a random number of cubes.
            int start = rand() % 10;
            int system_tower, system_cubes;
            for(int i = 0; i < 100; i++) {
                int j = (i + start) % 100;
                if(towers[j] > 0) {
                    system_tower = j;

                    // Number of cubes is limited by 3, and by the height of this tower.
                    int max_cubes = min(3, towers[j]);
                    system_cubes = 1 + (rand() % max_cubes);
                    break;
                }
            }


            // Inform user of the system's move.
            cout << "System's move: remove " << system_cubes << " cubes from tower " << system_tower << ", its new height is " << towers[system_tower] - system_cubes << "." << endl;
            enemy_move(system_tower, system_cubes);

            // Update according to the system's move.
            towers[system_tower] -= system_cubes;
            total_cubes -= system_cubes;
        }
        
        user_turn = !user_turn;
    }

    // Player who is left with no cubes has lost.
    if(user_turn) {
        cout << "You lost the game." << endl;
    }
    else {
        cout << "You won the game." << endl;
    }

    return 0;
}