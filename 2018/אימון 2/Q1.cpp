#include <iostream>
#include <vector>
#include <list>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define D 0
using namespace std;
/*Avi Kadria 211991401
Hole, IOI Training 2 Q1 2018.
*/

/*Problem definition:
input: A1,...,An
	N bytes, each contains a number between 1 to 10^9.
	Dani wants to buy k sequence Bytes, 1 of them he should give his brother(the minimum 1).
output: the maximum value of k-1 Bytes(total) value Dani can get.

Operation: */
/**/

int main() {
	//getting input:
	std::ios::sync_with_stdio(false);
	/*
	list<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	int c = test.back();
	test.pop_back();
	*/
	int N, k;
	cin >> N;
	cin >> k;
	int *input = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	//starting the algorithm
	long long TotalValueMax;
	list<pair<int, int>> minVector;
	pair<int, int> tempPair;
	minVector.push_back(pair<int,int>(input[0],0));
	long long sumOfTotalK = input[0];
	bool inserted;
	for (int i = 1; i < k; i++) {

		//maintaining the sum:
		sumOfTotalK += input[i];
		tempPair = pair<int, int>(input[i], i);
		
		//if Im large than te largest min, go to last.
		if (minVector.back().first < input[i]) {
			minVector.push_back(tempPair);
		}
		else {
			inserted = false;
			for (int j = minVector.size() - 1; j >= 0; j--) {
				if (minVector.back().first >= input[i])//if I am smaller than the value in the array, remove him:
				{
					minVector.pop_back();
				}
				else // I am bigger than him, so inserting self to the vector(after him).
				{
					minVector.push_back(tempPair);
					inserted = true;
					break;
				}
			}
			if (!inserted) //if I am the smallest I still counts
				minVector.push_back(tempPair);
		}
	}
	
	TotalValueMax = sumOfTotalK - minVector.front().first; // the first result. (first k elements. 
	
	for (int i = k; i < N; i++) {
		//maintaining the sum:
		sumOfTotalK += input[i] - input[i-k];
		tempPair = pair<int, int>(input[i], i);

		//if Im large than te largest min, go to last.
		if (minVector.back().first < input[i]) {
			minVector.push_back(tempPair);
		}
		else {
			inserted = false;
			for (int j = minVector.size() - 1; j >= 0; j--) {
				if (minVector.back().first >= input[i])//if I am smaller than the value in the array, remove him:
				{
					minVector.pop_back();
				}
				else // I am bigger than him, so inserting self to the vector(after him).
				{
					minVector.push_back(tempPair);
					inserted = true;
					break;
				}
			}
			if (!inserted) //if I am the smallest I still counts
				minVector.push_back(tempPair);
		}

		while (i - k >= minVector.front().second) { //remove "dead" items. (their time have passed)
			minVector.pop_front();
		}
		TotalValueMax = MAX(TotalValueMax, sumOfTotalK - minVector.front().first);
	}

	cout << TotalValueMax << endl;
	
	delete(input);
	system("pause");
	return 0;

}