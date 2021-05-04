#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;
#define ll unsigned long long
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
int get(ll d,int k,int ind){
    ll res;
    int l=1,r=ind,mid;
    while (l<=r)
    {   mid=(l+r)/2;
        res=_pow(mid,k);
        if(res==d){
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
ll optimizer(int n,int k,int part_in,ll &p1,ll &p2,int t,vector<int> &b){
    ll dif=llabs(p1-p2);
    ll hdif=dif/2;
    //cout<<hdif<<" "<<k<<" "<<n<<"\n";
    ll ind=get(hdif,k,n);
    ll tempdif1=dif,tempdif2=dif;
    if(t==1){
        if(b[ind-1]==1){
            tempdif1=llabs(dif-(2*_pow(ind,k)));
        }
        if((b[ind]==1)&&(ind<n)){
            tempdif2=llabs(dif-(2*_pow(ind+1,k)));
        }
        if(tempdif1<tempdif2){
            b[ind-1]=0;
            dif=tempdif1;
            p1=p1-_pow(ind,k);
            p2=p2+_pow(ind,k);
        }
        if(tempdif1>tempdif2){
            b[ind]=0;
            dif=tempdif2;
            p1=p1-_pow(ind+1,k);
            p2=p2+_pow(ind+1,k);
        }
        return dif;
    }
    else{
        if(b[ind-1]==0){
            tempdif1=llabs(dif-(2*_pow(ind,k)));
            
        }
        if((b[ind]==0)&&(ind<n)){
            tempdif2=llabs(dif-(2*_pow(ind+1,k)));
        }
        if(tempdif1<tempdif2){
            b[ind-1]=1;
            dif=tempdif1;
            p2=p2-_pow(ind,k);
            p1=p1+_pow(ind,k);
        }
        if(tempdif1>tempdif2){
            b[ind]=1;
            dif=tempdif2;
            p2=p2-_pow(ind+1,k);
            p1=p1+_pow(ind+1,k);
        }
        return dif;
    }
}
int main(){
    int t,k,part_in,transfer;
    ll n,hs,fs,p1,p2,dif;
    vector<int> bit;
    //vector<vector<ll>> dyn;
    vector<vector<ll>> al_sum;
    cin>>k>>t;
    while (t-->0)
    {   cin>>n;
        bit.clear();
        bit.resize(n,0);
        // dyn.clear();
        // dyn.resize(n+2,vector<ll>(n+1,0));
        al_sum.clear();
        al_sum.resize(n,vector<ll>(n,0));
        fs=_sum(n,k);
        hs=fs/2;
        ll tempsum=0;
        int fi=0,fj=0;
        for(int i=0;i<n;i++){
            al_sum[i][i]=_pow(i+1,k);
            if((al_sum[i][i]>tempsum)&&(al_sum[i][i]<=hs)){
                tempsum=al_sum[i][i];
                fi=i;
                fj=i;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                al_sum[i][j]=_pow(j+1,k)+al_sum[i][j-1];
                if((al_sum[i][j]>tempsum)&&(al_sum[i][j]<=hs)){
                tempsum=al_sum[i][j];
                fi=i;
                fj=j;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                al_sum[j][i]=_pow(j+1,k)+al_sum[0][i];
                if((al_sum[j][i]>tempsum)&&(al_sum[j][i]<=hs)){
                tempsum=al_sum[j][i];
                fi=j;
                fj=i;
                }
            }
        }
        if(fj>=fi){
            for(int i=fi;i<=fj;i++){
                bit[i]=1;
            }
        }else{
            for(int i=0;i<=fj;i++){
                bit[i]=1;
            }
            bit[fi]=1;
        }
        p1=al_sum[fi][fj];
        p2=fs-p1;
        dif=llabs(p1-p2);
        cout<<dif<<"\n";
        for(int i=0;i<bit.size();i++){
            cout<<bit[i];
        }cout<<"\n";
    }

    return 0;
}