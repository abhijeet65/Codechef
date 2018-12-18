#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
long max(int a,int b)
{
return a>b?a:b;
 
}
long knapsack(long k,long *cost,long* weight,int n)
{
if(k==0||n==0)
return 0;
if(cost[n-1]>k)
return knapsack(k,cost,weight,n-1);
return max(weight[n-1]+knapsack(k-cost[n-1],cost,weight,n-1),knapsack(k,cost,weight,n-1));
}
 
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
int n;
long k;
cin>>n>>k;
long *cost=new long [n];
long *weight=new long [n];
for(int j=0;j<n;j++)
{
cin>>cost[j]>>weight[j];
}
long mxweight=knapsack(k,cost,weight,n);
cout<<mxweight<<"\n";
delete cost ;
delete weight;
}
return 0;
}