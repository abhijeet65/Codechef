#include<iostream>
#include<string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		string s;
		cin>>s;
		int count=0;
		int c=0;
		int open=0;
		for (unsigned int i=0;i<s.size();i++)
		{
			if(s[i]=='<')
			{
				open++;

			}
			else if(s[i]=='>' )
			{	
				if(open>0)
				{	
					open--;
					c+=2;
					if(open==0)
					{
						count+=c;
						c=0;
					}	
				}
				else 
				{
					break;
				}	
			}	
			
		}
		cout<<count<<endl;		
	}
	return 0;
}