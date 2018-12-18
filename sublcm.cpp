//c lang headers
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
#include<unistd.h>
#include<stdint.h> 
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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TREP(it,c) \
for (auto it = (c).begin(); it != (c).end(); it++)


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
class FastInput {
public:
    FastInput() {
        m_dataOffset = 0;
        m_dataSize = 0;
        m_v = 0x80000000;
    }
    uint32_t ReadNext() {
        if (m_dataOffset == m_dataSize) {
            int r = read(0, m_buffer, sizeof(m_buffer));
            if (r <= 0) return m_v;
            m_dataOffset = 0;
            m_dataSize = 0;
            int i = 0;
            if (m_buffer[0] < '0') {
                if (m_v != 0x80000000) {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                }
                for (; (i < r) && (m_buffer[i] < '0'); ++i);
            }
            for (; i < r;) {
                if (m_buffer[i] >= '0') {
                    m_v = m_v * 10 + m_buffer[i] - 48;
                    ++i;
                } else {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                }
            }
        }
        return m_data[m_dataOffset++];
    
    }
public:
    uint8_t m_buffer[32768];
    uint32_t m_data[16384];
    size_t m_dataOffset, m_dataSize;
    uint32_t m_v;
};
#define s 1000001
vector<bool> isprime(10000,true);
vector<int> prime;
int mark[s];
vector<int> fact[s];	
int main()
{
	//ios_base::sync_with_stdio(false);
	
	for(int i=2;i<10000;i++)
	{
		if(isprime[i])
		{
			for(int j=i+i;j<10000;j+=i)
				isprime[j]=false;
		}
	}
	for(int i=2;i<10000;i++)
		if(isprime[i])
		{	prime.push_back(i);
			//cout<<i<<"  ";
		}
	for(int i=2;i<s;i++)
	{	
		int p=i;
		for(int j=0;sqrt(p)>=prime[j];j++)
		if(p % prime[j]==0)
		{
			//cout<<"jii";
			while(p % prime[j]==0)
				p/=prime[j];
			fact[i].push_back(prime[j]);
		}
		if(p>1)
			fact[i].push_back(p);	
	}
			
		
	FastInput in;
	int T=in.ReadNext();
	for(int t=0;t<T;t++)
	{	
		int n=in.ReadNext();
		int a[n];
		
		for(int i=0;i<n;i++)
		{	a[i]=in.ReadNext();	
		}
		
		memset(mark,0,sizeof(mark));
		int lcm[n];
		memset(mark,0,sizeof(mark));
		lcm[0]=1;
		for(int j=0;j<fact[a[0]].size();j++)
		{
			mark[fact[a[0]][j]]=1;
		}
		for(int i=1;i<n;i++)
		{
			int ret_val=0;
			for(int j=0;j<fact[a[i]].size();j++)
			{
				ret_val=max(ret_val,mark[fact[a[i]][j]]);
				mark[fact[a[i]][j]]=i+1;
				
			}
			lcm[i]=min(i+1-ret_val,lcm[i-1]+1);			
		}
		int ans=*max_element(lcm,lcm+n);
		if(ans==1)
			cout<<"-1\n";
		else
			cout<<ans<<"\n";				
							
	}
	return 0;
}
