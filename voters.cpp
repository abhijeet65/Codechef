#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
 
//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>
 
//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>
 
 
//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>

#define MOD 1000000007

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
bool comp(int a,int b)
{
	return a>b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n1,n2,n3;
	
	cin>>n1>>n2>>n3;
	int arr[n1+n2+n3];	
	for(int t=0;t<n1;t++)
		cin>>arr[t];
	for(int t=n1;t<n1+n2;t++)
		cin>>arr[t];
	for(int t=n1+n2;t<n1+n2+n3;t++)
		cin>>arr[t];
	priority_queue<int, vector<int>, greater<int> > q(arr,arr+n1+n2+n3);
	
	vector<int> res;
	int a=q.top();
	q.pop();
	int b=q.top();
	q.pop();
	while(!q.empty())
	{ 	
		if(a==b)
		{	res.push_back(a);
			if(!q.empty() && a==q.top())
				q.pop();
			if(!q.empty())
			{			
				a=q.top();
				q.pop();
			}
			if(!q.empty())
			{
				b=q.top();
				q.pop();
			}			
		}
		else
		{	
			a=b;
			if(!q.empty())
			{
				b=q.top();	
				q.pop();
			}	
		}					
	}
	if(a==b)
			res.push_back(a);
	cout<<res.size()<<"\n";
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<"\n";	
	return 0;
}
