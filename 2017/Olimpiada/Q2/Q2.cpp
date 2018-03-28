#include <iostream>

using namespace std;

struct point{
	int n;
	int l;
	list::list<int> E; // those who are near him
}

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
	point *arr_l= new point[n]; //labels
	bool *out = new bool[n-1];
	Pair *arr_pa = new Pair[m]; 
	for (int i=0;i<m;i++)
	{
		int x,y;
		cin >> x;
		cin >> y;
		arr_l[x].E.insert(y);
		arr_l[y].E.insert(x);
	}
	
}













