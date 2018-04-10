#include <iostream>
using namespace std;
#define MAX_LENGTH 20

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	int numFriends=0;
	cin >> N;
	char first, second;
	char input[MAX_LENGTH];
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < strlen(input) - 1; j++) {
			first = input[j];
			second = input[j + 1];
			if (first == 'c' && second == 'h')
			{
				numFriends++;
				break;
			}
			if (first == 'h' && second == 'e')
			{
				numFriends++;
				break;
			}
			if (first == 'e' && second == 'f')
			{
				numFriends++;
				break;
			}
		}
	}
	cout << numFriends << endl;
	//system("pause");
}