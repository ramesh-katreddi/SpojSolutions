#include<iostream>
using namespace std;
int gcd (unsigned long long int a, unsigned long long int b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}


int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t;i++)
	{
		unsigned long long int a,b;
		cin>>a>>b;
		unsigned long long int c;
		c = gcd(a,b);
		cout<<b/c<<endl<<a/c<<endl;
	}

	return 0;
}