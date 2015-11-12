#include<iostream>
using namespace std;
int hob (unsigned long long int num)
{
    if (!num)
    	return 0;

    int ret = 1;

    while (num >>= 1)
    	ret += 1;

    return ret;
}
int main()
{
	unsigned int t;
	scanf("%d",&t);
	unsigned long long int output = 0,init,max;
	scanf("%llu",&init);
	output = init;
	max = init;
	for(unsigned int i =1; i<t ;i++)
	{
		unsigned long long int n;
		scanf("%llu",&n);
		if(max<n) {
			max = n;
		}
		output &=n;
	}
	int h = 0;
	if (output == 0) h = hob(max);
	else h = hob(output);
	unsigned long long int mask = 0;
	for(int i=0 ; i<h;i++) {
		mask = (mask <<1) | 1;
	}
	unsigned long long int realOutput = output ^ mask;
	printf("%llu",realOutput);
	return 0;
}