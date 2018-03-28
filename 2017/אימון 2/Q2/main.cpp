//Argazoids
#include <iostream>
using namespace std;
#define MAX(a,b) ((a)<(b))?(b):(a)
#define MIN(a,b) ((a)<(b))?(a):(b)

int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	bool found = false;
	int numOfPiles;
	int t;
	cin >> N;
	int *piles = new int[N + 1]; //  N is the max num of piles possible
	//for (int i = 0; i <= N; i++)
	//	piles[i] = 0;
	int *arr = new int[N + 1];
	//for (int i = 0; i <= N; i++)
	//	arr[i] = 0;
	//so far O(N) initialize arrays
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		arr[t]++;
	}

	//calculations:

	for (int i = 0; i <= N; i++)//over arr
	{
		if (arr[i] > 0)
		{
			for (int j = 0; j < N && arr[i] != 0; j++) // over piles
			{
				t = MIN((i + 1 - piles[j]), arr[i]);//i+1 because we count the number in the pile (Natural numbers starts from 1)
				piles[j] += t;
				arr[i] -= t;
			}
		}
	}
	/* Debugging:
	for (int i = 0; i <= N; i++)
		cout << arr[i] << ",";
	cout << endl;
	for (int i = 0; i <= N; i++)
		cout << piles[i] << ",";
	cout << endl << endl;
	*/
	for (int i = 0; i <= N; i++)
	{		if (piles[i] == 0)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}