#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 100000
int main()
{
	char str[SIZE];
	while(scanf("%s",&str) != EOF) 
	{
		unsigned int len = strlen(str);
		unsigned int arr[10] ={0};
		for(unsigned int i=0;i<len;i++)
		{
			arr[str[i]-'0']++;	
		}
		unsigned int min= 1;
		for(unsigned int i=2;i<10;i++)
		{
			if(arr[i]<arr[min]) min=i;
		}
		if(arr[0] == 0) printf("0\n");
		else
		{
			for(unsigned int i=0;i<arr[min]+1;i++)
			{
				printf("%d",min);
			}
			printf("\n");
		}
		memset(str, 0, sizeof(str));
	}
	return 0;
}