#include<iostream>
using namespace std;
#define max 1000000
#define mod 1000000007

int main()
{
	unsigned long long int *arr = new unsigned long long int[max+1];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for(long i=3;i<=max;i++) {
		arr[i] = (arr[i-1] * (arr[i-1] + 1)) % mod;
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{	
		long n;
		scanf("%d",&n);
		printf("%llu\n",arr[n]);
	}

	return 0;
}