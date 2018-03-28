
/*Avi Kadria 211991401
partheness, IOI Training 1 Q1 2018. 
*/

#include <iostream>
using namespace std;

/*
input : N, string in the size of N containing '(' and ')'
output: the length of the maximal valid sequence.
operation: start with a counter = 0, as long as I can make my 
	substring valid and longer I do so. f I can't I save the 
	current max. then operate no the same from the end to the
	start. 
*/
int main() {
	int counter = 0;
	int max = 0;
	int start = -1;
	int N;
	cin >> N;
	char* input = new char[N];
	cin >> input;
	for (int i = 0; i < N; i++)
	{
		if (input[i] == '(')
			counter++;
		if (input[i] == ')')
		{
			if (counter > 0)
				counter--;
			else {
				start = i;
			}
			if (counter == 0)
			{
				if (max < i - start)
				{
					max = i - start;
				}
			}
		}
	}
	
	//the reverse notation:
	start = N;
	counter = 0;
	for (int i = N-1; i >= 0 ; i--)
	{
		if (input[i] == ')')
			counter++;
		if (input[i] == '(')
		{
			if (counter > 0)
				counter--;
			else {	
				start = i;
			}
			if (counter == 0)
			{
				if (counter == 0) {
					if (max < start - i)
					{
						max = start - i;
					}
				}
			}
		}
	}
	
	cout << max << endl;
	delete(input);
	return 0;
}
