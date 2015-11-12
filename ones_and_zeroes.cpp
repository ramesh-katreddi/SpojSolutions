#include<iostream>
#include<queue>
using namespace std;

 
int main()
{
	unsigned int iter;
	cin>>iter;		
	for (int i = 0 ; i<iter; i++)
	{
		std::queue<unsigned long long> s;
		s.push(1);
		unsigned long int N;
		cin>>N;
		unsigned long long result = 0;
		while(s.size() > 0)
		{
			long curVal = s.front();
			s.pop();
			if (curVal % N == 0)
			{
				result = curVal;
				break;
			}
			s.push(curVal*10);
			s.push(curVal*10 +1);
		}
		cout<<result<<endl;
	}

	return 0;
}
