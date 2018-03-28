#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct point{
	int l;
	std::vector<int> V; // those who are near him
};

typedef struct Pair {
	int x;
	int y;
	int value;
} Pair;
int main()
{
	int n;
	int m; // m is n-1;
	//input:
	cin >> n;
	cin >> m;
	point *arr= new point[n]; //labels
	//bool *out = new bool[n-1];
	for (int i=0;i<m;i++)
	{
		int x,y;
		cin >> x;
		cin >> y;
		arr[x].V.push_back(y);
		arr[y].V.push_back(x);
	}
	//end of input
	
	for(int i=0;i<n;i++)
		if(arr[i].V.size
	arr[0] = 1;
	for(int i=0;i<arr[0].V.size();i++)
	{
		if((arr[0].V)[i] > 1)
		{
			arr[i] = n;
			
		}
	}


}