#include<iostream>
#include<cstring>
using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  unsigned long long int r;
  while(b!=0)
  {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main()
{
	while(1)
	{
		char str[22];
		cin>>str;
		if(str[0] =='*') return 0;
		int len = strlen(str);
		unsigned long long int curLcm = 1;
		for(int i=0;i<len;i++)
		{
			if(str[i] == 'Y')
			{
				curLcm = (curLcm * (i+1)) / gcd(curLcm,i+1);
			}
		}
		int i =0;
		bool failed = false;
		for(;i<len;i++)
		{
			if(str[i] == 'N')
			{
				if(curLcm % (i+1) ==0) {
					cout<<-1<<endl;
					failed = true;
					break;
				}
			}
		}
		if(!failed) {
			cout<<curLcm<<endl;
		}
	}
}