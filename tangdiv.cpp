#include<iostream>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void * b)
{
	return *(int*)a-*(int*)b;
}
int cmp(const void *a,const void *b)
{
	int p=*(int*)a ;
	int q= *(int*)b;
	if(p<q) return -1;
	else if(q<p) return 1;
	else return 0;
}
int main()
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int n,k,p;
		cin>>n>>k>>p;
		int a[p],b[p];
		int l[k],r[k];
		for(int i=0;i<k;i++)
			cin>>l[i]>>r[i];
		for(int i=0;i<p;i++)
			cin>>a[i]>>b[i];
		qsort(l,k,sizeof(int),comp);	
		bool f=true;
		for(int i=0;i<p;i++)
		{	
			if(bsearch(&a[i],l,k,sizeof(int),cmp)==NULL)
			{
				f=false;
				break;
			}	
		}
		if(f)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;		
	}

}