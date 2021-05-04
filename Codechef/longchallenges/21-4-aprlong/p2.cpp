#include<iostream>
#include<math.h>
using namespace std;
int main(){
    float k1,k2,k3,v,ans,r;
    int t;
    cin>>t;
    while (t-->0)
    {
        cin>>k1>>k2>>k3>>v;
        ans=k1*k2*k3*v;
        ans=100/ans;
        r=(ans*100)-(int)(ans*100);
        r=ceil(r-0.5);
        ans=(int)(ans*100);
        ans=ans+r;
        if(ans<958){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
    return 0;
}