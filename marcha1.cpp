    #include<iostream>
    using namespace std;
    int main()
    {
    int t,n,m;
    cin>>t;
    int *a;
    for(int i=0;i<t;i++)
    {
    cin>>n>>m;
    a=new int[n];
    for(int j=0;j<n;j++)
    cin>>a[j];
    if(n>20)
    {
    cout<<"No"<<endl;
    continue;
    }
    int sum=0;
    for(int j=1;j<(1<<n);j++)
    { sum=0;
    for(int k=0;k<n;k++)
    {
    int mask=1<<k;
    if((j& mask)!=0)
    {sum=sum+a[k];
    }
    }
    // cout<<j<<sum<<endl;
    if(sum==m)
    {cout<<"Yes"<<endl;
    //cout<<sum<<endl;
    goto end;
    }
    }
    cout<<"No"<<endl;
    //cout<<sum<<endl;
    end:
    delete[] a;
    }
     
     
     
    } 