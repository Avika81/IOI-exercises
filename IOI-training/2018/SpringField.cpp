/*Avi Kadria 211991401
SpringField, IOI Training 4 Q3 2018.
*/

#include <iostream>
#include <vector>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))
/*
Problem   : whether I can choose some edges such those will touch odd time in each node.

input     : T - number of testcased, N vertices and M edges in each case.

output    : -1 if can't get this. if possible K - number of edges needed and those K edges.

operation : runs a DFS over the graph , and on the way back, each vertex makes sure he is connected to odd
number of fast lines. (bye taking the one from him to his parent). returns -1 iff there is a connected component of odd size

*/
vector<vector<int>> graph;
vector<bool> visited;
vector<bool> handled;
vector <pair<int, int>> Edges;
int N, M;

void addEdge(int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

int DFSUtil(int u, int from)
{
	int numberInConnected = 1;
	visited[u] = true;
	for (int i = 0; i < graph[u].size(); i++)
		if (visited[graph[u][i]] == false) {
			numberInConnected += DFSUtil(graph[u][i], u);
		}
	if (!handled[u]) {
		handled[u] = true;
		if (from != -1) //is not the start
		{
			handled[from] = !handled[from];
			Edges.push_back(pair<int, int>(u, from));
		}
	}
	return numberInConnected;
}

void DFS()
{
	int r;
	visited.assign(N, false);
	handled.assign(N, false);
	Edges = vector<pair<int, int>>();
	for (int u = 0; u < N; u++) {
		if (visited[u] == false) // new connectivity
		{
			r = DFSUtil(u, -1);
			if (r % 2 == 1) {
#ifdef DEBUG
				cout << "OUTPUT!!" << endl;
#endif // DEBUG

				cout << -1 << endl;
				return;
			}
		}
	}
	//output:
	int s = Edges.size();
#ifdef DEBUG
	cout << "OUTPUT!!" << endl;
	cout << "size :";
#endif // DEBUG

	cout << s << endl;
	// print the edges
	for (int i = 0; i < s; i++) {
		cout << Edges[i].first + 1 << endl << Edges[i].second + 1 << endl;
	}
}

void  SpringFold() {
	int u, v;
	//getting input
	cin >> N;
	cin >> M;
	graph.assign(N, vector<int>());
	for (int i = 0; i < M; i++) {
		cin >> u;
		cin >> v;
		addEdge(u - 1, v - 1);
	}
	//The DFS function contains the outputs and such
	DFS();
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int iiii = 0; iiii < T; iiii++)
		SpringFold();
	system("pause");
}
