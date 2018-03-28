//Monotone Path
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1000000
#define CALC_INDEX(i,j,M) (i)*(M)+(j)
using namespace std;
struct arc
{
	int dst;
	int w;
};

struct Point
{
public:
	vector<arc> e;
};

int Binary_search(const std::vector<int>& vec, int start, int end, int key)
{
	// Termination condition: start index greater than end index
	if (start > end)
	{
		return -1;
	}

	// Find the middle element of the vector and use that for splitting
	// the array into two pieces.
	const int middle = start + ((end - start) / 2);

	if (vec[middle] == key)
	{
		return middle;
	}
	else if (vec[middle] > key)
	{
		return Binary_search(vec, start, middle - 1, key);
	}

	return Binary_search(vec, middle + 1, end, key);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	int M;
	cin >> N >> M;
	Point* arr = new Point[N + 1];
	vector<vector<int>> mat(N+1, vector<int>(2));
	vector<int> wArr(M+1);
	int minW = MAX + 1;
	//input:
	for (int i = 0; i < M; i++)
	{
		int t, p, w;
		arc a;
		cin >> t >> p >> w;
		a.dst = p;
		a.w = w;
		arr[t].e.push_back(a);
		a.dst = t;
		arr[p].e.push_back(a);
		wArr[i] = w;
		if (minW > w)
			minW = w;
	}
	sort(wArr.begin(), wArr.end());
	//end Input
	int c = 0;
	for (int i = M;i >= 0; i--)
	{
		c++;
		for (int j = 1; j <= N; j++)
		{
			int t = 0;
			int max = 0;
			for (unsigned int k = 0; k < arr[j].e.size(); k++)
			{
				if (arr[j].e[k].w > wArr[i])
				{
					arr[j].e[k].w = -1;
					//int y = Binary_search(wArr, 0, M,arr[j].e[k].w);
					t = 1 + mat[arr[j].e[k].dst][(c+1)%2];
					if (t > max)
						max = t;
				}
			}
			mat[j][c%2] = max;
			if (mat[j][(c + 1) % 2] > mat[j][c % 2])
				mat[j][c % 2] = mat[j][(c + 1) % 2];

			cout << mat[j][0] << "," << mat[j][1] << endl;
		}
		cout << endl << endl;
	}
	int max2 = 0;
	for (int i = 1; i <= N; i++)
	{
		//for (int j = 0; j < M; j++)
		//	cout << mat[i][j] << ",";
		cout << mat[i][0] <<"," << mat[i][1]<<endl;
		if (max2 < mat[i][0])
			max2 = mat[i][0];

		if (max2 < mat[i][1])
			max2 = mat[i][1];
	}
	cout << max2;
	return 0;
}