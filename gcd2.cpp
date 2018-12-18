#include<iostream>
#include<cstdio>
using namespace std;
inline void fastRead(int *a)
{
	register char c=0;
	while (c<33) c=getchar_unlocked();
	*a=0;
	while (c>33)
	{
	    *a=*a*10+c-'0';
	    c=getchar_unlocked();
	}
}
int gcd(int a,int b)
{
	if(b==0) 
		return a;
	else
		return gcd(b, a%b);
}
int mod(string b,int a)
{
	int r=0;
	for(int i=0;i<b.size();i++)
		r=(r*10+(b[i]-'0'))%a;	
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{	
		int  a;string b;
		cin>>a>>b;
		if(a==0)
			cout<<b<<"\n";
		else
		cout<<gcd(a,mod(b,a))<<"\n";
	}
	return 0;
}
