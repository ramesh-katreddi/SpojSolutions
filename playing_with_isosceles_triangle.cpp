#include<iostream>
using namespace std;
#define NUMBER 1000000
int main()
{
	int n;
	cin>>n;
	bool arr[NUMBER];
	for(int i=0; i < NUMBER ;i++)
		arr[i] = false;
	for(int i=1; i<=1000; i++)
	{
		for(int j=1; j<=1000; j++)
		{
			if(i == j) continue;
			int k = i*i + j*j;
			if(k <= NUMBER) {
				if(arr[k]) continue;
				int mult = NUMBER/k;
				for(int  p = 1; p <= mult; p++)
				{
					arr[k*p] = true;
				}
			} else {
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{			
		int input;
		cin>>input;
		if(arr[input]) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}