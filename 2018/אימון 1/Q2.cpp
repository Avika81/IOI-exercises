/*Avi Kadria 211991401
partheness, IOI Training 1 Q2 2018.
*/

#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int N, M;
	int result = 0;
	cin >> N;
	cin >> M;
	
	int lengthOfValidSubsequence = 0;
	int* Farr = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> Farr[i];
		lengthOfValidSubsequence += Farr[i];
	}

	int* Rarr = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> Rarr[i];
	}

	unordered_map<int, int> runMap;
	for (int i = 0; i < M; i++) {
		runMap.emplace(Rarr[i], Farr[i]);
	}

	//finished initializing, now the real run:
	int left = 0;
	int input;
	int* Ainput = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> Ainput[i];
	}

	/*if (lengthOfValidSubsequence == 0) //if the length is 0, only empty substring is allowed
	{
		cout << 0 << endl;
		return 0;
	}*/

	for (int i = 0; i < N; i++) {
		if (i - left == lengthOfValidSubsequence)
			result++;

		if (runMap.count(Ainput[i]) == 0)//got to an error, start over.
		{
			for(;left<i;left++)
				runMap[Ainput[left]]++;
			left++;
		}
		else if (runMap[Ainput[i]] == 0) {
			if (i > left) { //if i = left, nothing should happen
				runMap[Ainput[left]]++;
				i--; // i-- because in the next iteration it will increase i, don't want to skip.
			}
			left++;
		}
		else{
			runMap[Ainput[i]]--;
		}
	}
	//if there is one which ends in the end of the sequence:
	if (N - left == lengthOfValidSubsequence)
		result++;
	
	//cout << "result is: ";
	cout << result << endl;
	//clearing memory:
	delete(Rarr);
	delete(Farr);
	delete(Ainput);

	return 0;
}
