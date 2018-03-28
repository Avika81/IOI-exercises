#include "100_towers.h"

using namespace std;

/*
* Put here any data structures you may need, as global variables.
*/
vector<int> _towers;
int state = 0;
bool once = false;
bool TT;
vector<int> nextMove(2);
int c[4];
int init(vector<int> towers) {
	/*
	* This function will be called once, at the beginning.
	* Use it to initialize your data structures. The parameter "towers"
	* is a vector with exactly 100 integers (indexed 0-99). Each integer
	* is between 0 and 1000. There will always be at least one non-empty
	* tower in the beginning.
	*
	* The function must return 1 or 2:
	* 1 if you want to be the first player.
	* 2 if you want to be the second player.
	*/
	for (int i = 0; i < 4; i++)
		c[i] = 0;

	_towers = towers; //copying?
	for (int i = 0; i < 100; i++)
		c[_towers[i] % 4]++; // counts modulus in 4 of the floors (the ammount)

	if (c[1] % 2 == 0 && c[2] % 2 == 0 && c[3] % 2 == 0)
		return 2;

	else if (c[1] % 2 == 1 && c[2] % 2 == 0 && c[3] % 2 == 0)
	{
		for (int i = 0; i < 100; i++)
		{
			if (_towers[i] == 1)
			{
				nextMove[0] = i;
				nextMove[1] = 1;
				return 1;
			}
		}
	}

	else if (c[1] % 2 == 0 && c[2] % 2 == 1 && c[3] % 2 == 0)
	{
		for (int i = 0; i < 100; i++)
		{
			if (_towers[i] % 4 == 2)
			{
				nextMove[0] = i;
				nextMove[1] = 2;
				return 1;
			}
		}
	}

	else if (c[1] % 2 == 0 && c[2] % 2 == 0 && c[3] % 2 == 1)
	{
		for (int i = 0; i < 100; i++)
		{
			if (_towers[i] % 4 == 3)
			{
				nextMove[0] = i;
				nextMove[1] = 3;
				return 1;
			}
		}
	}

	else if (c[1] % 2 == 1 && c[2] % 2 == 1 && c[3] % 2 == 0)
	{
		for (int i = 0; i < 100; i++)
		{
			if (_towers[i] % 4 == 2)
			{
				nextMove[0] = i;
				nextMove[1] = 1;
				return 1;
			}
		}
	}

	else if (c[1] % 2 == 1 && c[2] % 2 == 0 && c[3] % 2 == 1)
	{
		for (int i = 0; i < 100; i++)
		{
			if (_towers[i] % 4 == 3)
			{
				nextMove[0] = i;
				nextMove[1] = 2;
				//= 2;
				return 1;
			}
		}
	}

	else if (c[1] % 2 == 0 && c[2] % 2 == 1 && c[3] % 2 == 1)
	{
		for (int i = 0; i < 100; i++)
		{
			if (_towers[i] % 4 == 3)
			{
				nextMove[0] = i;
				nextMove[1] = 1;
				return 1;
			}
		}
	}

	else if (c[1] % 2 == c[2] % 2 == c[3] % 2 == 1)//all even numbers, will use c in the future;
	{
		once = true;
		return 2;
	}
	TT = true;
	return 1;
}

void enemy_move(int tower, int cubes) {
	/*
	* This function will be called after the system makes a move.
	* Use it to update your data structures. The parameter "tower" is
	* the index of the tower the system chooses (an integer between 0 and 99).
	* The parameter "cubes" is the number of cubes to remove from it
	* (an integer between 1 and 3).
	*
	* You can assume the system's move is legal.
	*/
	if (_towers[tower] >= 4)
	{
		//_towers[tower] -= 4;
		nextMove[0] = tower;
		nextMove[1] = 4 - cubes;
		_towers[tower] -= cubes;
		return;
	} //just cause;

	else if (once || TT)
	{
		once = false;
		//TT = false;
		c[_towers[tower] % 4]--;
		_towers[tower] -= cubes;
		c[_towers[tower] % 4]++;

		if (c[1] % 2 == 1 && c[2] % 2 == 0 && c[3] % 2 == 0)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 1)
				{
					nextMove[0] = i;
					nextMove[1] = 1;
					//-;
					return;
				}
			}
		}

		else if (c[1] % 2 == 0 && c[2] % 2 == 1 && c[3] % 2 == 0)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 2)
				{
					nextMove[0] = i;
					nextMove[1] = 2;
					//= 2;
					return;
				}
			}
		}

		else if (c[1] % 2 == 0 && c[2] % 2 == 0 && c[3] % 2 == 1)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 3)
				{
					nextMove[0] = i;
					nextMove[1] = 3;
					//= 3;
					return;
				}
			}
		}

		else if (c[1] % 2 == 1 && c[2] % 2 == 1 && c[3] % 2 == 0)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 2)
				{
					nextMove[0] = i;
					nextMove[1] = 1;
					//-;
					return;
				}
			}
		}

		else if (c[1] % 2 == 1 && c[2] % 2 == 0 && c[3] % 2 == 1)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 3)
				{
					nextMove[0] = i;
					nextMove[1] = 2;
					//= 2;
					return;
				}
			}
		}

		else if (c[1] % 2 == 0 && c[2] % 2 == 1 && c[3] % 2 == 1)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 3)
				{
					nextMove[0] = i;
					nextMove[1] = 1;
					//-;
					return;
				}
			}
		}

		else
			for (int i = 0; i<100; i++)
				if (_towers[i] > 0)
				{
					nextMove[0] = i;
					nextMove[1] = 1;
					c[_towers[i] % 4]--;
					c[_towers[i] % 4 - 1]++;
				}
	}

	else //making life EZ
	{
		for (int i = 0; i < 100; i++)
		{
			if (_towers[i] % 4 == _towers[tower] && i != tower)
			{
				nextMove[0] = i;
				nextMove[1] = cubes;
				_towers[tower] -= cubes;
				return;
			}
		}
	}
}

vector<int> your_move() {
	/*
	* This function will be called when it is your turn.
	* You must return a vector with exactly 2 elements:
	* - Element 0 is the tower you choose (an integer between 0 and 99).
	* - Element 1 is the number of cubes (an integer between 1 and 3).
	*
	* The tower must contain at least the number of cubes you wish to remove
	* from it. If you make an invalid move, the program will terminate
	* and get no points.
	*
	* Remember to update your data structures according to your chosen move!
	*/
	if (TT)
	{
		TT = false;

		if (c[1] % 2 == 1 && c[2] % 2 == 0 && c[3] % 2 == 0)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 1)
				{
					nextMove[0] = i;
					nextMove[1] = 1;
					//-;
					break;
				}
			}
		}

		else if (c[1] % 2 == 0 && c[2] % 2 == 1 && c[3] % 2 == 0)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 2)
				{
					nextMove[0] = i;
					nextMove[1] = 2;
					//= 2;
					break;
				}
			}
		}

		else if (c[1] % 2 == 0 && c[2] % 2 == 0 && c[3] % 2 == 1)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 3)
				{
					nextMove[0] = i;
					nextMove[1] = 3;
					//= 3;
					break;
				}
			}
		}

		else if (c[1] % 2 == 1 && c[2] % 2 == 1 && c[3] % 2 == 0)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 2)
				{
					nextMove[0] = i;
					nextMove[1] = 1;
					//-;
					break;
				}
			}
		}

		else if (c[1] % 2 == 1 && c[2] % 2 == 0 && c[3] % 2 == 1)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 3)
				{
					nextMove[0] = i;
					nextMove[1] = 2;
					//= 2;
					break;
				}
			}
		}

		else if (c[1] % 2 == 0 && c[2] % 2 == 1 && c[3] % 2 == 1)
		{
			for (int i = 0; i < 100; i++)
			{
				if (_towers[i] % 4 == 3)
				{
					nextMove[0] = i;
					nextMove[1] = 1;
					//-;
					break;
				}
			}
		}

		else
			for (int i = 0; i < 100; i++)
				if (_towers[i] > 0)
				{
					nextMove[0] = i;
					nextMove[1] = 1;
					c[_towers[i] % 4]--;
					c[_towers[i] % 4 - 1]++;
				}
	}
	_towers[nextMove[0]] -= nextMove[1];
	return nextMove; // setting it in the last move or befor ;)
}
