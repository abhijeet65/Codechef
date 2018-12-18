#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
int main()
{
	set<int> s;
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++)
		s.insert(i);
	for(int i=0;i<n;i++)
	{
		cin>>k;
		if(present(s,k))
			s.erase(k);
	}
	tr(s,it)
	{
		cout<<*it<<" ";	
	}
	return 0;
}