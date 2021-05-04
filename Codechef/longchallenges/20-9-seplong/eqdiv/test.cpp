#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;
#define ll unsigned long long
#define sll long long
ll _pow(ll b,int e){
    ll res=1;
    for(int i=0;i<e;i++){
        res*=b;
    }
    return res;
}
ll _sum(int n,int k){
    ll ans;
    switch (k)
    {
    case 1:
        ans=(ll)n*(n+1)/2;
        break;
    case 2:
        ans=(ll)n*(n+1)/2;
        ans=ans*(2*n+1)/3;
        break;
    case 3:
        ans=(ll)n*(n+1)/2;
        ans=_pow(ans,2);
        break;
    case 4:
        ans=(ll)n*(n+1)/2;
        ans=ans*(2*n+1)/3;
        ans=ans*(3*n*n+3*n-1)/5;
        break;
    default:
        break;
    }
    return ans;
}
int part(ll sum,int n,int k){
    ll l=1,r=n;
    ll cs,mid;
    while (l<=r)
    {   mid=(l+r)/2;
        cs=_sum(mid,k);
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
bool check(int part,ll p1,ll p2,int k,int i){
    ll dif=llabs(p1-p2);
    if(part==1){
    if(dif>llabs(p1-p2-2*pow(i,k))){
        return true;
    }
    return false;
    }
    else{
        if(dif>llabs(p1-p2+2*pow(i,k))){
        return true;
        }
        return false;    
    }
}
void optimizer(int n,int k,int part_in,ll &p1,ll &p2,vector<int> &b){
    int dynpi=part_in;
    for(int i=1;i<part_in;i++){
        if(check(1,p1,p2,k,i)){
            p1=p1-pow(i,k);
            p2=p2+pow(i,k);
            b[i-1]=0;
            cout<<i<<" transfer 1->2\n";
        }
    }
    for(int i= part_in;i<=n;i++){
        if(check(2,p1,p2,k,i)){
            p1=p1+pow(i,k);
            p2=p2-pow(i,k);
            b[i-1]=1;
            cout<<i<<" transfer 2->1\n";
        }
    }
}
int get(ll d,int k,int ind){
    ll res;
    int l=1,r=ind,mid;
    while (l<=r)
    {   mid=(l+r)/2;
        cout<<mid<<" "<<l<<" "<<r<<" :mis\n";
        res=_pow(mid,k);
        cout<<_pow(mid,k)<<" \n";
        if(res==d){
            cout<<"mid\n";
            return mid;
        }
        else if(res>d){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return mid;
}
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<get(a,b,c);
    
    return 0;
}