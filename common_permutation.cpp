#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char in1[1000],in2[1000];
	while( scanf("%s\n%s",in1,in2) != EOF )
	{
		int len1 = strlen(in1);
		int len2 = strlen(in2);
		int a[26],b[26];
		for(int i=0;i<26;i++)
		{
			a[i] = 0;
			b[i] = 0;
		}
		for(int i=0;i<len1;i++)
		{
			int local = in1[i] - 'a';
			a[local]++;
		}
		for(int i=0;i<len2;i++)
		{
			int local = in2[i] - 'a';
			b[local]++;
		}
		for(int i=0 ; i<26;i++)
		{
			int min = a[i];
			if(b[i] < min) min = b[i];
			for(int j=0;j<min;j++)
			{
				cout<<char('a'+i);
			}
		}
		cout<<endl;
	}
	return 0;
}