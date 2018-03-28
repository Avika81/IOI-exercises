#include <iostream>
#include <algorithm>
#define N (num+1)
using namespace std;

int BSearch(int arr[], int n, int search)
{
	// https://codescracker.com/cpp/program/cpp-program-binary-search.htm ,from here
	register int first = 0;
	register int last = n-1;
	register int middle = (first+last)/2;
	while (first <= last)
	{
		if(arr[middle] < search)
		{
			first = middle + 1;

		}
		else if(arr[middle] == search)
		{
			return middle+1;
			break;
		}
		else
		{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if(first > last)
	{
		return 0;
	}
}

int main()
{
	//input
	int num;
	cin >> num;
	int *arr = new int[N];
	bool *out = new bool[2*num];
	int t;
	for(register int i=0;i<N;i++)
		cin>>arr[i];
	//end Of input
	
	
	//sorting: (NLOGN)
		sort(arr,arr+num+1);
	
	//case the min is 1 or 2:
	if(arr[0] == 1)
	{
		cout << arr[0] << " " <<arr[1] <<endl;
		return 0;
	}
	else if(arr[0] == 2)
		for (register int i=1/*the first is 2*/ ; i<N;i++)
			if(arr[i] %2 == 0)
			{
				cout << arr[0] << " "<<arr[i] <<endl;
				return 0;
			}
	//now we know the smallest is bigger than 2 (2<arr[0]<=num)
	
	//NLOGN:
	//else if(arr[0]>num/15/*could be diffrent number*/)
	{
		for(int i=0;arr[i]<num;i++)
		{
			for(int j=2;j<15;j++)
			{
				if(!out[arr[i]*j])//this is a valid number
				{
					t = BSearch(arr,N,arr[i]*j);

					if(t)
					{
						cout << arr[i] << " " << arr[t-1] << endl;
						return 0;
					}
					else
						out[arr[i]*j] = true;
				}
			}
			out[arr[0]] = true;
		}
	}
	//finished: (not found)
	return -1;
}












