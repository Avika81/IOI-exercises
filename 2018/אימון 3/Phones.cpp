#include <iostream>
#include <vector>
#include <list>
#include <queue>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define D 0
using namespace std;
/*Avi Kadria 211991401
Hole, IOI Training 3 Q2 2018.
*/

/*Problem definition: Phones
input: x1,y1...xn,yn
N stations, Mercury need to keep them ordered, what is the minimum distance
output: the minimum need distance

Operation: */
/**/
typedef enum { G, R, NONE } color;
vector<vector<int>> graph;

vector<bool> v;

int N, M;
vector<color> res;

int bfsHelp(int u) //returns the num of reds
{
	int cntRed = 0;
	int cntInConnected = 1;
	queue<pair<int, color>> q;
	q.push(pair<int, color>(u, G));
	res[u] = G;
	v[u] = true;
	while (!q.empty()) {
		//get last element
		pair<int, color> f = q.front();
		q.pop();

		for (auto i = graph[f.first].begin(); i != graph[f.first].end(); i++) {
			if (!v[*i]) {
				cntInConnected++;
				v[*i] = true;
				switch (f.second) {
				case G:q.push(pair<int, color>(*i, R));  res[*i] = R; cntRed++; break;
				case R:q.push(pair<int, color>(*i, G)); res[*i] = G; break;
				}
			}
			else { //already saw this neighbor:
				   //if there is a green with red neighbor
				if (res[*i] == NONE)
					continue;
				else if (res[*i] == f.second) {
					return -1;
				}
			}
		}
	}
	return MIN(cntRed, cntInConnected - cntRed);
}

int bfs(int u) {
	int minReds = 0;
	int s;
	for (int u = 0; u <= N; u++)
	{
		if (!v[u]) {
			s = bfsHelp(u);
			if (s == -1)
				return -1;
			else
				minReds += s;
		}
	}
	return minReds;
}

void addEdge(int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

int main() {
	//getting input:
	std::ios::sync_with_stdio(false);
	//getting the input:

	cin >> N;
	cin >> M;
	graph.assign(N + 1, vector<int>());
	v.assign(N + 1, false);
	res.assign(N + 1, NONE);
	int u, v;
	for (int index = 0; index < M; index++) {
		cin >> u;
		cin >> v;
		addEdge(u, v);
	}
	//start the algorithm (most in the function bfs):

	int finalRes = bfs(1); // the start position doesn't matter
	if (finalRes == -1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		cout << finalRes << endl;
	}

	system("pause");
	return 0;
}