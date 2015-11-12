#include<iostream>
#include<cmath>
#define MAX 10000000
using namespace std;
int main()
{
	int *prime = new int[MAX+1];
	for(int i=0;i<=MAX;i++) {
		prime[i] = 0;
	}
	prime[0] =1;
	prime[1]=1;
	for(int i=2;i<=MAX;i++){
		if(!prime[i]){
            prime[i]=i;
			for(int j=2;j*i<=MAX;j++){
				if(!prime[j*i])prime[j*i]=i;
			}
		}
	}
	unsigned int  a;
	while(scanf("%d", &a)!=EOF)
	{
		printf("1");
		while(a>1) {
			printf(" x %d",prime[a]);
			a = a/prime[a];
		}
		printf("\n");

	}

	return 0;
}

