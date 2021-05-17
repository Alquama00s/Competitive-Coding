#include<iostream>
using namespace std;
int main(){
    int t,x,a,b,ans;
    cin>>t;
    while (t-->0)
    {
        /* code */
        cin>>x>>a>>b;
        ans=a+(100-x)*b;
        ans*=10;
        cout<<ans<<"\n";
    }
    
    return 0;
}