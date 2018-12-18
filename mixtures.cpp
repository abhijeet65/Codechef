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
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	FastInput in;
	while(cin>>n)
	{	
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i]; 
		int sum[n][n];
		int smk[n][n];
		memset(sum,0,n*n*sizeof(int));
		memset(smk,0,n*n*sizeof(int));
		
		for(int i=0;i<n;i++)
		{
			sum[i][i]=a[i];
			smk[i][i]=0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				sum[i][j]=(sum[i][j-1]+a[j])%100;
			}
		}
		
		/*for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				cout<<sum[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int l=2;l<=n;l++)
		{
			for(int i=0;i<=n-l+1;i++)
			{
				
				int j=i+l-1;
				smk[i][j]=INT_MAX;
				for(int k=i;k<=j-1;k++)
				{
					
					int q=smk[i][k]+smk[k+1][j]+sum[i][k]*sum[k+1][j];
					if(q<smk[i][j])
						smk[i][j]=q;
				}
			}
		}
		/*for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				cout<<smk[i][j]<<" ";
			}
			cout<<endl;
		}*/
		cout<<smk[0][n-1]<<"\n";		
	}
	return 0;
}
