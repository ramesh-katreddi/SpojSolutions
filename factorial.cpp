#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long number;
		cin>>number;
		long long count = 0;
		while(number > 0)
		{
			number = number/5;
			count += number;
		}
		cout<<count<<endl;
	}
	return 0;
}