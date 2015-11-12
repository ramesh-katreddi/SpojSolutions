#include<stdio.h>
int main()
{
int i=0;
do
{
scanf("%d",&i);
if(i==42) return 0;
else printf("%d\n",i);
}while(1);
return 0;
} 