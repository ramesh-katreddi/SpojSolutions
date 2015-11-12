#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		unsigned long long n=0;
		scanf("%llu",&n);
		int count = 0;
		unsigned long long backup = n;
		unsigned long long o=1;
		while(n)
		{
			n = n&(n-1);
			o = o<<1;
			count++;
		}
		printf("%llu %llu\n",(backup+1)-o,o);
	}

	return 0;
}