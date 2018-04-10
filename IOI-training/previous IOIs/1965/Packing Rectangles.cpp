#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define N 4
#define INPUT_FILE "INPUT.TXT"
#define OUTPUT_FILE "OUTPUT.TXT"
#define MIN(a,b) ((a)<(b)?a:b)
#define MAX(a,b) ((a)<(b)?b:a)

vector<vector<int>> minValue;

void ToAdd(vector<int> tRes) {
	if (minValue.size() == 0) {
		minValue.push_back(tRes);
	}
	else if (minValue[0][0] < tRes[0]) {
	return;
	}
	else if(minValue[0][0] == tRes[0]) {
		minValue.push_back(tRes);
	}
	else if (minValue[0][0] > tRes[0]) {
		minValue.assign(1, tRes); //only the new should be in the results.
	}
}

int main() {
	ifstream inFile;
	ofstream outFile;
	inFile.open(INPUT_FILE);
	outFile.open(OUTPUT_FILE);
	vector<pair<int, int>> input(N);
	int x, y;
	for (int i = 0; i < N; i++) {
		inFile >> x;
		inFile >> y;
		input[i] = pair<int, int>(x, y);
	}
	vector<vector<int>> minValue;
	int maxX=input[0].first, maxY= input[0].second;
	int sumX = 0, sumY = 0;
	for (int i = 0; i < N; i++) {
		sumX += input[i].first;
		maxX = MAX(maxX, input[i].first);
		sumY += input[i].second;
		maxY = MAX(maxY, input[i].second);
	}
	
	vector<int> tRes(3);
	//all the x's one bye one.
	tRes[0] = sumX*maxY;
	tRes[1] = MIN(sumX, maxY);
	tRes[2] = MAX(sumX, maxY);
	ToAdd(tRes);
	
	//all the y's one bye one.
	tRes[0] = sumY*maxX;
	tRes[1] = MIN(maxX,sumY); 
	tRes[2] = MAX(maxX,sumY);
	ToAdd(tRes);

		
	for (int i = 0; i < N; i++) {

	}
}