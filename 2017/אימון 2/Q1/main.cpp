//Rectangle Cutting Problem
#include <iostream>
#define MAX(a,b) ((a)<(b))?(b):(a)
#define MIN(a,b) ((a)<(b))?(a):(b)
using namespace std;
int calcIndex(int i,int j,int N)
{
	if (i > j)
		return i*N + j;
	else
		return j*N + i;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;//input
	int max = MAX(N, M);
	int min = -1; // will be used later
	max++;
	int t;
	int* mat = new int[(max +1)*(max +1)];
	for (int i = 0; i < (max + 1)*(max + 1); i++) // initializing
		mat[i] = -1;
	//fill the matrix
	for (int j = 1; j <= max; j++)
	{
		for (int i = j; i <= max; i++)
		{
			if (i % j == 0 || j % i == 0)
				mat[calcIndex(i, j, max)] = i / j - 1;
			else
			{
				min = -1;
				for (int k = 1; k < i; k++)
				{
					t = mat[calcIndex(k, j, max)] + mat[calcIndex(i - k, j, max)] + 1;
					//if(t==-1) // t == 0
					if (min != -1)
						min = MIN(t, min);
					else
						min = t;
				}
				for (int k = 1; k < j; k++)
				{
					t = mat[calcIndex(k, i, max)] + mat[calcIndex(j - k, i, max)] + 1;
					//if(t==-1) // t == 0
					if (min != -1)
						min = MIN(t, min);
					else
						min = t;
				}
				mat[calcIndex(i, j, max)] = min;
			}
		}
	}
	/*for (int i = 1; i <= max; i++)
	{
		for (int j = 1; j <= max; j++)
			cout << mat[calcIndex(i, j, max)] << " ,";
		cout << endl;
	}*/
	cout << mat[calcIndex(N, M, max)];
	return 0;
}