#include<iostream>
using namespace std;
int main()
{
	int Test;
	cin>>Test;
	for(int i=0;i<Test;i++)
	{
		long num1,num2;
		cin>>num1>>num2;
long power=1;
			
		if(num1<num2){	
			long temp=num1;
			while(temp!=0){
				temp=temp/10;
				if(temp!=0) power=power*10;
			}
			int Temp=num2;
			while(Temp/power!=0){
				power=power*10;
				num1=num1*10;
			} 
			num1=num1/10;		
		}
		else{	
			long temp=num2;
			while(temp!=0){
				temp=temp/10;
				if(temp!=0) power=power*10;
			}
			int Temp=num1;
			while(Temp/power!=0){
				power=power*10;
				num2=num2*10;
			} 
			num2=num2/10;		
 
		}
		power=power/10;
		long answer=0;		
		int carry=0;
		int flag1=0,flag2=0;		
		while(power!=0)
		{
			long a=num1/power;
			long b=num2/power;
			if(flag1==1) a=0;
			if(flag2==1) b=0;		
			int mult;			
			if(a+b+carry<10)
			{
				mult=a+b+carry;
 
				carry=0;
			}
			else
			{
				mult=(a+b+carry)%10;
				carry=(a+b+carry)/10;
 
			}
		if(power>1)	answer=answer+(mult*power);
		else if(carry!=0) answer=(answer+mult)*10+carry;
		else answer=answer+mult;
		if(flag1==1) flag1=0;
		else num1=(num1) %power;
		if(flag2==1) flag2=0; 
		else num2=(num2) %power;
		if(power>1)
		if(num1<power/10) flag1=1;
		else if(num2<power/10) flag2=1;
		power=power/10;
/*cout<<"num1 "<<num1<<"  num2  "<<num2<<" a "<<a<<"  b "<<b<<"  answer "<<answer<<"  power "<<power<<" mult "<<mult<<" carry "<<carry<<" flag1 "<<flag1<<" flag2 "<<flag2<<endl;		
*/		}
		while(answer>10 && answer%10==0)
		answer=answer/10;	
		cout<<answer<<endl;
			
	} 
return 0;
}
 