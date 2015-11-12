#include<iostream>
#include<cmath>
using namespace std;
#define mod 1000000007

unsigned long long int fast_exp(int base, long long exp)
{
	if(exp==0) 
		return 1;
    if(exp==1)
    return base;
    else
    {
        if(exp%2 == 0)
        {
            unsigned long long int base1 = pow(fast_exp(base, exp/2),2.0);
            if(base1 >= mod)
            return base1%mod;
            else
            return base1;
        }
        else
        {
            unsigned long long int ans = (base*  pow(fast_exp(base,(exp-1)/2),2.0));
            if(ans >= mod)
            return ans%mod;
            else
            return ans;
        }
    }
}
int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t;i++)
	{
		unsigned long long m;
		cin>>m;
		if(m<=3) {
			cout<<m<<endl; 
			continue;
		}
		unsigned long long nOf3s = m/3;
		int proOf2s = 1;
		if(m%3 == 1) {
			nOf3s -=1;
			proOf2s = 4;
		} else if (m%3 == 2) {
			proOf2s =2;
		}
		//long result = pow(3.0,(double)nOf3s) + pow(2.0,(double)nOf2s);
		unsigned long long result = proOf2s;
		result = fast_exp(3,nOf3s);
		result = (result*proOf2s) % mod;
		cout<<result<<endl;
		
	}
	return 0;
}