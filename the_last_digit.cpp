#include<iostream>
using namespace std;
void p(int k){cout<<k<<endl;}
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
int a;
long b;
cin>>a>>b;
int d = b%4;
if(b==0){if(a!=0) {p(1);} else {p(0);}} 
else {
int c=a%10;
if(c==0 || c==1 ||c==5 ||c==6){p(c);} 
else if(c==2 || c==8){if(d==0) {p(6);}else if(d==1){p(c);} else if(d==2) {p(4);} else if(d==3) {if(c==2)p(8);else p(2);}}
else if(c==3 || c==7){if(d==0) {p(1);}else if(d==1){p(c);} else if(d==2) {p(9);} else if(d==3) {if(c==3)p(7);else p(3);}} 
else if(c==4 || c==9){if(b%2 == 0){ if(c==4)p(6);else p(1);}else p(c);} 
}
}
return 0;
}
