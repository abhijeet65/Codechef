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
long long ncr(int n,int r)
{
	if(r==0)
		return 1;
	if(n==r)
		return 1;
	if(r==1)
		return n;
	r=min(r,n-r);
	int *a=new int[r+1];
	
	int res;
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=min(r,i);j>0;j--)
			a[j]=a[j]+a[j-1];
	}
	res=a[r];
	delete a;
	return res;
}
long long gcd(long long m,long long n)
{
	if(m<n)
		swap(m,n);
	long long  r;
	do
	{
		r=m%n;
		m=n;
		n=r;
	}while(r!=0);
	return m;

} 
long long NCR(long long n,long long  r)
{
	if(r==0)
		return 1LL;
	if(n==r)
		return 1LL;
	if(r==1)
		return n;	
	r=min(r,n-r);
	long long res=1;
	for(register long long i=1;i<=r;i++,n--)
	{
		if(n%i==0)
			res*=(n/i);
		else if(res%i==0) 
			res=(res/i)*n;
		else
		{
			int g=gcd(n,i);
			assert(g!=0);
			//cout<<g<<" ";
			 res=(res/(i/g))*(n/g);
		}
	}
	return res;
}

	
int main()
{
	ios_base::sync_with_stdio(false);
	/*int N=1000000;
	long long **a=new long long* [N+1];
	for(int i=0;i<=N;i++)
		a[i]=new long long[N+1];
	//memset(a,0,(N+1)*(N+1)*sizeof(long long));
	
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=min(N,i);j++)
		{
			if(j==0 || i==j)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}*/
	FastInput in;
	int T=in.ReadNext();
	for(int t=0;t<T;t++)
	{	
		int n=in.ReadNext(),k=in.ReadNext();
		
		cout<<NCR(n-1,n-k)<<"\n";
	}
	return 0;
}
