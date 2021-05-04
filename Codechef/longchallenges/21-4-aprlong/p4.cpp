#include<iostream>
using namespace std;
int main(){
    long long t,n,f,l,ans;
    int nl[4]={0,20,36,51};
    cin>>t;
    while (t-->0)
    {   
        cin>>n;
        f=n/4;
        l=n%4;
        ans=f==0?nl[l]:(f*44)+(4*(4-l))+nl[l];
        cout<<ans<<"\n";
    }
    
    return 0;
}