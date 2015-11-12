#include<iostream>
using namespace std;
int giveLast2power (unsigned long long int a)
{
	if(a == 0) return 1;
	else if(a%4 == 0) { return 6;} 
	else if(a%4 == 1) { return 2;} 
	else if(a%4 == 2) { return 4;} 
	else if(a%4 == 3) { return 8;} 
}
int findLast(unsigned long long int n)
{
	if(n==0 || n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 6;
	if(n==4) return 4;
	if(n==5) return 2;
	unsigned long long int k = n/5;
	int rem = n % 5;
	int product = giveLast2power(k) * findLast(k) * findLast(rem);
	int reminder=0;
	do
	{
		reminder = product %10;
		product = product/10;
	}while(reminder==0);
	return reminder;
}
int main()
{
	unsigned long long int n;
	while(cin>>n)
	{
		cout<<findLast(n)<<endl;
		n = 0;
	}
	return 0;
}