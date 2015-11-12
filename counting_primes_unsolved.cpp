#include<iostream>
#include<cmath>
#define MAX 100000
using namespace std;
int main()
{
	bool *prime = new bool[MAX+1];
	for(int i=0;i<=MAX;i++) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1]= false;
	int rootMAX = sqrt(double(MAX));
	for(int i=2;i<=rootMAX;i++){
		if(prime[i]){
    		for(int j=2;j*i<=MAX;j++){
				prime[j*i] = false;
			}
		}
	}
	unsigned int  t;
	scanf("%d",&t);
	for(int i=0; i<t; i++) {
		printf("Case %d:",i+1);
		int n,q;
		scanf("%d %d",&n,&q);
		unsigned int *numbers = new unsigned int[n];
		for(int j=0;j<n;j++) {
			scanf("%d",&numbers[j]);
		}
		for(int k=0;k<q;k++) {
			int op;
			scanf("%d",&op);
			if(op) {
				int x,y;
				scanf("%d %d",&x,&y);
				int count = 0;
				for(int l=x-1;l<=y-1;l++)
				{
					if(prime[numbers[l]]) {
						count++;
					}
				}
				cout<<count<<endl;
			} else {
				int x,y;
				unsigned int v;
				scanf("%d %d %d",&x,&y,&v);
				for(int p=x-1;p<=y-1;p++)
				{
					numbers[p] = v;
				}
			}
		}
	}

	return 0;
}