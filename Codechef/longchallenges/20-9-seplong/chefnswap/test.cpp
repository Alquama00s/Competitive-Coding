#include<iostream>
#include<cmath>
#define ll unsigned long long
#define sll long long
using namespace std;
int part(ll sum){
    ll l=1,r=sum/2+1;
    ll cs,mid;
    while (l<=r)
    {   mid=(l+r)/2;
    cout<<l<<" "<<r<<" :l r\n";
        cout<<mid<<" :mid\n";
        cs=mid*(mid+1)/2;
        if(cs==sum){
            return mid;
        }
        else if(cs>sum){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return mid;
}
int main(){
    ll a=1000000000;
    ll b=a*a;
    double s=sqrt(1+2*(a*a+a));
    int ab=(s-1)/2; 
    cout<<a+10<<"\n";
    if(s-ab==0)
        cout<<"apply\n";
    cout<<ab<<' '<<s<<"\n";
}