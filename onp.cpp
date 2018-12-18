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

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	char a;
	
	map<char,int> dict;
	dict['(']=0;
	dict['+']=1;
	dict['-']=2;
	dict['*']=3;
	dict['/']=3;
	dict['^']=4;
	dict[')']=5;
	for(int t=0;t<T;t++)
	{
		string line;
		cin.ignore();
		getline(cin,line);
		stack<char> s;
		for(int i=0;i<line.size();i++)
		{		 
			a=line[i];
			if(a=='+' ||a =='-' || a=='*' || a=='^' || a=='/'|| a=='(' ||a==')')
			{
				 if(a==')')
				{
					while(!s.empty() && s.top()!='(')
					{
						cout<<s.top();
						s.pop();
					}
					if(!s.empty() &&s.top()=='(')
						s.pop();
				}				
				else if(!s.empty() && a!='(' && dict[s.top()]>dict[a])
				{	
					while( !s.empty() ||(!s.empty() && s.top()!='(') )
					{
						cout<<s.top();
						s.pop();
					}
					if(!s.empty() && s.top()=='(')
						s.pop();
					s.push(a);
				}
				
				else
					s.push(a);
					
			}
			else
				cout<<a;	
		}	
		while(!s.empty())
		{
			cout<<s.top();
			s.pop();
		}
		cout<<"\n";
	}		
	return 0;
}
