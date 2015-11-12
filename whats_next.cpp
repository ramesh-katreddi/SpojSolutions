#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==0 && b==0 && c==0) return 0;
		if(2*b == a+c)
		{
			cout<<"AP "<<c+b-a<<endl;
		}
		else {
			cout<<"GP "<<c*(b/a)<<endl;
		}
	}
	
	return 0;
}
