#include <iostream>
#include <vector>
#include <list>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define D 0
#define M 0
using namespace std;
/*Avi Kadria 211991401
Hole, IOI Training 3 Q1 2018.
*/

/*Problem definition: Mercury
input: x1,y1...xn,yn
N stations, Mercury need to keep them ordered, what is the minimum distance
output: the minimum need distance

Operation: Dinamic programming, I save the result of the minimum travel from i to the end. (from each location)
	+ some tricks to reduce it from N*K^2 to N^2 (the only llocations that matters is the ones who appears in the input
*/
vector<vector<int>> Rx; //[1...N][1....2*K][min,x,y] (caught him via x ray)
vector<vector<int>> Ry; //[1...N][1....2*K][min,x,y] (caught him via y ray)
vector<vector<int>> V;
vector<int> lx; // reserves all the Ks I ever saw in an input (there is a range of -K to K but only 2K can show)
vector<int> ly; // reserves all the Ks I ever saw in an input (there is a range of -K to K but only 2K can show)

int N, K;

void init() {
	Rx.assign(2, vector<int>(lx.size()));
	Ry.assign(2, vector<int>(ly.size()));
	for (int i = 0; i < lx.size(); i++) {
		Rx[(N - 1) % 2][i] = 0;
		Ry[(N - 1) % 2][i] = 0;
	}
}

void f(int n) {
	int dx, dy, rx, ry;
	if (D) cout << "x:" << endl;
	for (int i = 0; i < lx.size(); i++) {
		dx = abs(lx[i] - V[n + 1][0]);
		dy = abs(V[n][1] - V[n + 1][1]);

		rx = Rx[(n + 1) % 2][i] + dy;
		ry = Ry[(n + 1) % 2][n] + dx;
		Rx[n % 2][i] = MIN(rx, ry);
		if (D) cout << lx[i] << ": " << Rx[n % 2][i] << endl;
	}

	if (D) cout << "y:" << endl;
	for (int i = 0; i < ly.size(); i++) {
		dx = abs(V[n][0] - V[n + 1][0]);
		dy = abs(ly[i] - V[n + 1][1]);

		rx = Rx[(n + 1) % 2][n] + dy;
		ry = Ry[(n + 1) % 2][i] + dx;
		Ry[n % 2][i] = MIN(rx, ry);
		if (D) cout << ly[i] << ": " << Ry[n % 2][i] << endl;
	}
}

int main() {
	//getting input:
	std::ios::sync_with_stdio(false);
	//getting the input:
	cin >> N;
	V.assign(N, vector<int>(4));
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cin >> y;
		V[i][0] = x;
		V[i][1] = y;
		lx.push_back(x);
		ly.push_back(y);
	}
	lx.push_back(0);
	ly.push_back(0);
	init();
	for (int i = N - 2; i >= 0; i--)
		f(i);
	int dx;
	int dy;

	int res = MIN(Rx[0][N] + abs(ly[0]), Ry[0][N] + abs(lx[0]));

	cout << res << endl;
	system("pause");
}