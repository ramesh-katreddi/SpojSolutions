#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t;i++)
	{
		unsigned int x,y;
		cin>>x>>y;
		if((x==0 && y==0) || (x==1 && y==1))
		{
			cout<<x<<endl;
		}
		else if(x==0 || x==1 || x<0 || y<0) {
			cout<<"No Number"<<endl;
		}
		else if(y==x || y== x-2) {
			if(x%2 == 0) {
				cout<<x+y<<endl;
			} else {
				cout<<x+y-1<<endl;
			}
		}
		else {
			cout<<"No Number"<<endl;
		}	
	}
	return 0;
}