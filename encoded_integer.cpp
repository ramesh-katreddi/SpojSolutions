#include<iostream>
using namespace std;
int min(int a, int b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{	
		long n;
		scanf("%ld",&n);
		if(n==0 ||n==1) 
		{
			if(n==0) n=10;
			printf("%d\n",n);
			continue;
		}
		long output = 0;
		int z[10];
		for(int q=0;q<10;q++)
			z[q]=0;
		while(n%2 == 0)
		{
			n = n/2;
			z[2]++;
		}
		while(n!=1 && n%3 == 0)
		{
			n = n/3;
			z[3]++;
		}
		
		while(n!=1 && n%5 == 0)
		{
			n = n/5;
			z[5]++;
		}
		while(n!=1 && n%7 == 0)
		{
			n = n/7;
			z[7]++;
		}
		if(n>1) {
			printf("-1\n");
		} else {
			z[9] = z[3]/2;
			z[3] = z[3]%2;
			z[8] = z[2]/3;
			z[2] = z[2]%3;
			z[6] = min(z[2],z[3]);
			z[2] -=z[6];
			z[3] -=z[6];
			z[4] = z[2] /2;
			z[2] = z[2] %2;
			for(int s=2;s<10;s++)
			{
				for(int l=0;l<z[s];l++)
				{
					printf("%d",s);
				}
			}
			printf("\n");
		}
	}

	return 0;
}