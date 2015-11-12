#include<iostream>
using namespace std;
int main()
{
	unsigned int t;
	scanf("%d",&t);
	for(unsigned int i=0;i<t;i++)
	{
		unsigned long long int n;
		scanf("%llu",&n);
		if(n%2 ==1) {
			printf("0\n");
			continue;
		}
		if(n==0) {
			printf("1\n");
		} else if (n==2) {
			printf("33\n");
		} else {
			unsigned long long int output = ((2*n)*(2*n +1)) + ((3*n +1) * (n+1)) - 2*n;
			printf("%llu\n",output);	
		}
	}
	return 0;
}

