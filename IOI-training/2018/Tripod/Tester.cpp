#include <iostream>
#include <vector>

using namespace std;

int init(vector<int> towers);
void system_move(int tower, int cubes);
vector<int> player_move();

int main() {
	cout << "This is a sample program to test your implementation for technical errors." << endl << endl;
	cout << "IMPORTANT: this program does *not* verify that your move is a valid power of a prime!" << endl;
	cout << "You must do that yourself." << endl << endl;

	cout << "This program is not smart: it will always take 1 cube from the first non-empty tower." << endl;
	cout << "But when you submit your code, you will be playing against an optimal player." << endl << endl;

	// Initial towers. You can change this to play different games.
	int towers[3] = { 10, 2002, 300 };

	// Global cubes counter. The game is over when it hits 0.
	long long total_cubes = 0;

	// Initialize towers vector and total_cubes.
	vector<int> user_towers(3, 0);
	for (int i = 0; i < 3; i++) {
		user_towers[i] = towers[i];
		total_cubes += towers[i];
	}

	// Call init() and validate.
	int user_init = init(user_towers);
	if (user_init != 1 && user_init != 2) {
		cout << "Your init function must return 1 or 2." << endl;
		system("pause");
		return 0;
	};

	cout << "You chose to be player " << user_init << "." << endl;
	bool user_turn = (user_init == 1);

	int turn_counter = 0;

	// Game loop.
	while (total_cubes > 0) {
		turn_counter++;
		cout << endl << "Towers: " << towers[0] << ", " << towers[1] << ", " << towers[2] << endl;
		cout << "Turn " << turn_counter << ": ";
		if (turn_counter == 336) {
			int c = 3;
		}
		// User's turn.
		if (user_turn) {
			// Get user's turn and validate.
			vector<int> user_move = player_move();
			if (user_move.size() != 2) {
				cout << "You made an illegal move." << endl;
				cout << "The vector you return must contain exactly two integers." << endl;
				system("pause");
				return 0;
			};
			int user_tower = user_move[0];
			int user_cubes = user_move[1];

			if (user_tower < 0 || user_tower > 2 || user_cubes < 1 || towers[user_tower] < user_cubes) {
				cout << "You made an illegal move." << endl;
				cout << "You wanted to take " << user_cubes << " cube(s) from tower " << user_tower << "." << endl;
				system("pause");
				return 0;
			}

			cout << "Your move:     remove " << user_cubes << " cube(s) from tower " << user_tower << ", its new height is " << towers[user_tower] - user_cubes << "." << endl;

			// Update according to user's move.
			towers[user_tower] -= user_cubes;
			total_cubes -= user_cubes;
		}

		// System's move.
		else {
			// Take 1 from some non-empty tower.
			int system_tower;
			for (int i = 0; i < 3; i++) {
				if (towers[i] > 0) {
					system_tower = i;
					break;
				}
			}

			// Inform user of the system's move.
			cout << "System's move: remove 1 cube(s) from tower " << system_tower << ", its new height is " << towers[system_tower] - 1 << "." << endl;
			system_move(system_tower, 1);

			// Update according to the system's move.
			towers[system_tower] -= 1;
			total_cubes -= 1;
		}

		user_turn = !user_turn;
	}

	cout << endl;

	// Player who is left with no cubes has lost.
	if (user_turn) {
		cout << "You lost the game." << endl;
	}
	else {
		cout << "You won the game." << endl;
	}
	system("pause");
	return 0;
}