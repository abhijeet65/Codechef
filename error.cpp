    #include<iostream>
    #include<string>
    #include<cstring>
    using namespace std;
    int main()
    {
    int t;
    cin>>t;
    char* g[]={"010","101"};
    string s;
    const char * c;
    const char * pos;
    for(int i=0;i<t;i++)
    {
    cin>>s;
    c=s.c_str();
    pos=strstr(c,g[0]);
    if(pos!=NULL)
    {cout<<"Good"<<endl; continue;}
    pos=strstr(c,g[1]);
    if(pos!=NULL)
    {cout<<"Good"<<endl; continue;}
    cout<<"Bad"<<endl;
    }
     
     
     
    } 
