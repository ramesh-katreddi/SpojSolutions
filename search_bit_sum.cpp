#include<iostream>
using namespace std;
unsigned long long int arr[59];
int searchForIndex(unsigned long long int n)
{
	for(int i=0;i<60;i++)
	{
		if(n<arr[i]) 
			return i-1;
		else if(n == arr[i])
			return i;
	}
}
unsigned int getLeftmostBit (unsigned long long n)
{
   int m = 0;
   while (n  > 1)
   {
      n = n >> 1;
      m++;
   }
   return m;
}
 
/* Given the position of previous leftmost set bit in n (or an upper
   bound on leftmost position) returns the new position of leftmost
   set bit in n  */
unsigned int getNextLeftmostBit (unsigned long long n, int m)
{
   unsigned long long temp = 1 << m;
   while (n  < temp)
   {
      temp = temp >> 1;
      m--;
   }
   return m;
}
 
// The main recursive function used by countSetBits()
unsigned long long _countSetBits(unsigned long long n, int m);
 
// Returns count of set bits present in all numbers from 1 to n
unsigned long long countSetBits(unsigned long long n)
{
   // Get the position of leftmost set bit in n. This will be
   // used as an upper bound for next set bit function
   int m = getLeftmostBit (n);
 
   // Use the position
   return _countSetBits (n, m);
}
 
unsigned long long _countSetBits(unsigned long long n, int m)
{
    // Base Case: if n is 0, then set bit count is 0
    if (n == 0)
       return 0;
 
    /* get position of next leftmost set bit */
    m = getNextLeftmostBit(n, m);
 
    // If n is of the form 2^x-1, i.e., if n is like 1, 3, 7, 15, 31,.. etc, 
    // then we are done. 
    // Since positions are considered starting from 0, 1 is added to m
    if (n == ((unsigned long long)1<<(m+1))-1)
        return (unsigned long)(m+1)*(1<<m);
 
    // update n for next recursive call
    n = n - (1<<m);
    return (n+1) + countSetBits(n) + m*(1<<(m-1));
}

int main(){
	arr[0] = 0;
	arr[1] = 1;
	for(int i=2;i<60;i++)
	{
		arr[i] = (arr[i-1] / (i-1)) *i * 2;
	}
    int t;
    unsigned long long n, l, u, m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        int ind = searchForIndex(n);
		l = pow(2.0,ind); 
        u = n + 1;
        while(l != u)
        {
            m = (l + u ) / 2;
            if(countSetBits(m) >= n) u = m;
            else l = m + 1;
        }
        if(countSetBits(l) == n) 
            printf("%llu\n",l);
        else 
            printf("Does Not Exist.\n");
    }
}