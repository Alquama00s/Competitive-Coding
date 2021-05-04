#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int t,n;
    string s;
    char temp,*add;
    cin>>t;
    while (t-->0)
    {  
        cin>>n;
        cin>>s;
        for (size_t i = 0; i < n/4; i++)
        {  add=&(s.substr(i*4,4))[0];
            temp='a'+strtoull(add,NULL,2);
            cout<<temp;
        }
        cout<<"\n";
        
    }
    
    return 0;
}