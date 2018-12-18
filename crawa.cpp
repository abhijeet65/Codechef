#include<iostream>
#include<cstdlib>


#define MOD 1000000007

using namespace std;


#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TREP(it,c) \
for (auto it = (c).begin(); it != (c).end(); it++)



	
int main()
{
	ios_base::sync_with_stdio(false);
	//FastInput in;
	int T;
	cin>>T;	
	for(int t=0;t<T;t++)
	{	
		int x,y;
		cin>>x>>y;
		if(x>=0)
		{
			if(x&1)
			{
				if(-1*x+1<=y && y<=x+1)
					cout<<"YES";
				else if(!(abs(y)&1))
					cout<<"YES";
				else
					cout<<"NO";	
			}
			else
			{
				if(y>0 && !(y&1) && y>x)
					cout<<"YES";
				else if(y<=0 && (!(abs(y)&1)) && abs(y)>=x)
					cout<<"YES";
				else
					cout<<"NO"; 
			}
		}
		if(x<0)
		{
			if(abs(x)&1)
			{
				if(!(abs(y)&1) && abs(x)<abs(y))
					cout<<"YES";
				else
					cout<<"NO";
			}
			else
			{
				if(abs(y)<=abs(x))
					cout<<"YES";
				else if(!(abs(y)&1))
					cout<<"YES";
				else
					cout<<"NO";
			}
		}
		cout<<"\n";	
	}
	return 0;
}
