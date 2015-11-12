#include<iostream>
#include<cmath>
using namespace std;
#define SIEVE_LIMIT 100000

int main()
{
	int t;
	cin>>t;
	bool *arr = new bool[SIEVE_LIMIT];
	for(int i=0;i<SIEVE_LIMIT;i++)
	{
		arr[i] = true;
	}
	arr[0] =arr[1] = false;
	int rootSieve = sqrt(double(SIEVE_LIMIT));
	for(int i=2 ;i<=rootSieve;)
	{
		if(arr[i]) {
			int mult = SIEVE_LIMIT/i;
			for(int j=2;j<=mult;j++)
			{
				arr[i*j] = false;
			}
		}
		if(i ==2) i++;
		else i+=2;

	}
	//now arr contains the int's
	for(int i=0; i<t;i++)
	{
		long long m,n;
		cin>>m;
		cin>>n;
		if(n<=SIEVE_LIMIT || m<=SIEVE_LIMIT)
		{
			int localN;
			if(n<= SIEVE_LIMIT) localN = n;
			else localN = SIEVE_LIMIT;
			
			for(int p=m;p<=localN;p++)
			{
				if(arr[p]) cout<<p<<endl;
			}
			if(n<=SIEVE_LIMIT) continue;
		}
		if(m < SIEVE_LIMIT) m = SIEVE_LIMIT;
		bool *arrOutput = new bool[n-m+1]; // to store the bools for all m-n m included
		for(int index=0;index<n-m+1;index++)
		{
			arrOutput[index] = true;
		}
		
		int localsqrt = sqrt((double)n);
		for(long k=2 ;k<localsqrt;) {
			if(arr[k])
			{
				long begin,end;
				if(m%k == 0) {
					arrOutput[0]= false;
				}
				begin= m/k +1;
				end = n/k;
				for(long j=begin;j<=end;j++)
				{
					arrOutput[(k*j) - m] = false;
				}
			}
			if(k ==2) k++;
			else k += 2;
		}
		for(int finalIndex=0;finalIndex<n-m+1;finalIndex++)
		{
			if(arrOutput[finalIndex]) cout<<finalIndex+m<<endl;
		}
		cout<<endl;
	}
	return 0;
}