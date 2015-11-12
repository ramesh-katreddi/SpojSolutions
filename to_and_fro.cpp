#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0) return 0;
		char str[200];
		cin>>str;
		int len = strlen(str);
		int rows = len/n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<rows;j++)
			{
				if(j%2 == 0) {
					cout<<str[i+j*n];
				} else {
					cout<<str[(j+1)*n - i -1];
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

