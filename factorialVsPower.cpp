#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
long double *ar = new long double[2718275];;
int ans;
void bin_search(long double *ar,int st,int end,int a)
{
    if(st>=end)
    {
        if(ar[st]< log10(a) * st)
        {
            ans = st+1;return;
        }
        else
        {
            ans=st;return;
        }
    }
    int half = (st+end)/2;
    long double gn = log10(a) * half;
    if(ar[half]< gn)
    {
        bin_search(ar,half+1,end,a);
    }
    else if(ar[half]>gn)
    {
        bin_search(ar,st,half-1,a);
    }
    else if(ar[half]==gn)
    {
        ans = half+1;
        return;
    }
}
int main()
{
    long double sum=0;
    ar[0]=0;
    //prerocessing
    for(int i=1;i<=2718274;i++)
    {
        sum +=log10(i);
        ar[i]=sum;
    }
    int t;
    scanf("%d",&t);
    int a;
    while(t--)
    {
        scanf("%d",&a);
        bin_search(ar,0,2718274,a);
        printf("%d\n",ans);
    }
}
