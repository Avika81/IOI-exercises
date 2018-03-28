#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define NUMER_TOWERS 3
#define NUMBER_LOSING_STATES 8
/*
* Put here any data structures you may need, as global variables.
*/
vector<int> myTowers;
vector<int> myTowersm6;
int towerRes[NUMER_TOWERS]; //1 = first, 2 = second
vector<int> nextMove(2);
int losingStates[NUMBER_LOSING_STATES][NUMER_TOWERS];
int init(vector<int> towers) {
	/*
	* This function will be called once, at the beginning.
	* Use it to initialize your data structures. The parameter "towers"
	* is a vector with exactly 3 integers (indexed 0, 1, 2). Each integer
	* is between 0 and 10^9. There will always be at least one non-empty
	* tower in the beginning.
	*
	* The function must return 1 or 2:
	* 1 if you want to be first.
	* 2 if you want to be second.
	*/
	for (int i = 0; i <= 5; i++) {
		losingStates[i][0] = 0; losingStates[i][1] = i; losingStates[i][2] = i;
	}

	losingStates[6][0] = 1; losingStates[6][1] = 4; losingStates[6][2] = 5;
	losingStates[7][0] = 1; losingStates[7][1] = 2; losingStates[7][2] = 3;

	myTowers = towers;
	myTowersm6 = towers;
	
	for (int i = 0; i < NUMER_TOWERS; i++) {
		myTowersm6[i] %= 6;
	}
	sort(myTowersm6.begin(), myTowersm6.end());
	
	int retValue = 1;
	for (int i = 0; i < NUMBER_LOSING_STATES; i++) {
		bool b1 = myTowersm6[0] == losingStates[i][0];
		bool b2 = myTowersm6[1] == losingStates[i][1];
		bool b3 = myTowersm6[2] == losingStates[i][2];
		if (b1&&b2&&b3)
			retValue = 2;
	}
	return retValue;
}

void system_move(int tower, int cubes) {
	/*
	* This function will be called after the system makes a move.
	* Use it to update your data structures. The parameter "tower" is
	* the index of the tower the system chooses (0 or 1 or 2).
	* The parameter "cubes" is the number of cubes to remove from it.
	*
	* Assume the system's move is legal.
	*/
	myTowers[tower] -= cubes;
}

vector<int> player_move() {
	/*
	* This function will be called when it is your turn.
	* You must return a vector with exactly 2 elements:
	* - Element 0 is the tower you choose (0 or 1 or 2).
	* - Element 1 is the number of cubes (must be a power of a prime).
	*
	* The tower must contain at least the number of cubes you wish to remove
	* from it. If you make an invalid move, the program will terminate
	* and get no points.
	*
	* Remember to update your data structures according to your chosen move!
	*/
	vector<int> t;
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < NUMER_TOWERS; j++) {
			t = myTowers;
			nextMove[0] = j;
			nextMove[1] = i;
			
			t[nextMove[0]] -= nextMove[1]; // applying the move.
			if (t[j] < 0) {
				continue;
			}

			for (int k = 0; k < NUMER_TOWERS; k++) {
				t[k] %= 6;
			}
			sort(t.begin(), t.end());
			
			for (int k = 0; k < NUMBER_LOSING_STATES; k++) {
				bool b1 = t[0] == losingStates[k][0];
				bool b2 = t[1] == losingStates[k][1];
				bool b3 = t[2] == losingStates[k][2];
				if (b1&&b2&&b3) {
					myTowers[nextMove[0]] -= nextMove[1];
					return nextMove;
				}
			}
		}
	}
	return nextMove;
}
