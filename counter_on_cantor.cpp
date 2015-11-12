#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t;i++)
	{
		long n;
		cin>>n;
		long b24ac = 1+ (8*n);
		long x = ((sqrt((double)b24ac) - 1)/2 );
		long rem = n - (x* (x+1))/2;
		if(rem!=0) {
			x= x+1;
		
			if(x%2 == 0) {
				cout<<"TERM "<<n<<" IS "<<rem <<"/"<<x+1-rem<<endl;
			} else {
				cout<<"TERM "<<n<<" IS "<<x+1-rem <<"/"<<rem<<endl;
			}
		} else {
			if(x%2==0) {
				cout<<"TERM "<<n<<" IS "<<x<<"/"<<1<<endl;
			} else {
				cout<<"TERM "<<n<<" IS "<<1<<"/"<<x<<endl;
			}
		}
	}
	return 0;
}