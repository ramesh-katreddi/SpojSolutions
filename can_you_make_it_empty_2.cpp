#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	long t;
	scanf("%d",&t);
	for(long k=0;k<t;k++) 
	{
		char str[120000];
		scanf("%s",str);
		long len = strlen(str);
		if(len % 3 != 0 || str[0] == '0')  {		
			printf("Case %d: no\n",k+1);
		} 
		else 
		{
			long noOfZeroes = 0;
			long noOfOnes = 0;
			long i=0;
			for(i=len-1; i>=0;i--)
			{
				if(str[i]=='1') {
					noOfOnes++;
				} else {
					noOfZeroes++;	
				}
				if(noOfZeroes < noOfOnes*2)
				{
					printf("Case %d: no\n",k+1);
					break;
				}
			}
			if(i==-1) 
			{
				if(noOfZeroes == noOfOnes * 2) {
					printf("Case %d: yes\n",k+1);
				}
				else printf("Case %d: no\n",k+1);	
			}
		}
	}
	return 0;
}