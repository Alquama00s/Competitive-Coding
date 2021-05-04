#include<iostream>
#include<math.h>
#include<ctime>
#define ll unsigned long long
#define sll long long
using namespace std;
int part(ll sum,int n){
    ll l=1,r=n;
    ll cs,mid;
    while (l<=r)
    {   mid=(l+r)/2;
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
int noswap(int i){
    double a,d;
    int b;
    d=sqrt(1+2*((ll)i*i+i));
    a=(d-1)/2;
    b=a;
    if((b-a)==0){
        return b;
    }
    else
    {
        return -1;
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    int t,n,part_index;
    ll res;
    ll hs,ps;
    cin>>t;
    while (t-->0)
    {   cin>>n;
        res=0;
        hs=(ll)n*(n+1)/2;
        if(hs%2==0){
            if(noswap(n)>0){
                //cout<<"here";
            part_index=noswap(n);
            res+=(ll)part_index*(part_index-1)/2;
            part_index=n-part_index;
            res+=(ll)part_index*(part_index-1)/2;
            }
            hs=hs/2;
            part_index=part(hs,n);
            ps=(ll)part_index*(part_index-1)/2;
            res+=(n-part_index);
            sll dif=hs-ps;
            //cout<<part_index<<"\n";
            if(((sll)part_index-dif)>0){
                //cout<<"added\n";
                res++;}
            cout<<res<<"\n";
        }else
        {
            cout<<0<<"\n";
        }     
    }
    
    return 0;
}