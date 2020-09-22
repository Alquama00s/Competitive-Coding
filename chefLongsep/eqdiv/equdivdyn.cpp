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
    vector<ll> bit,p;
    vector<vector<ll>> dyn;
    cin>>k>>t;
    while (t-->0)
    {   cin>>n;
        bit.clear();
        bit.resize(n+1,0);
        dyn.clear();
        p.clear();
        p.resize(n+1,0);
        fs=_sum(n,k);
        hs=fs/2;
        cout<<fs<<" "<<hs<<" :fs hs\n";
        dyn.resize(hs+1,vector<ll>(n+1,0));
        for(int i=0;i<=n;i++){
            p[i]=_pow(i,k);
        }
        for(int i=0;i<=n;i++){
            cout<<p[i]<<" ";
        }cout<<"\n";
        for(int i=1;i<=hs;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]>i){
                    dyn[i][j]=dyn[i][j-1];
                }
                else{
                    dyn[i][j]=max(dyn[i][j-1],dyn[i-p[j-1]][j-1]+p[j-1]);
                }
            }
        }
        // for(int i=0;i<dyn.size();i++){
        //     for(int j=0;j<dyn[i].size();j++){
        //         cout<<dyn[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";
        sll res=dyn[hs][n];
        sll j=hs;
        for(int i=n;i>0&&res>0;i--){
            if (res==dyn[j][i-1])
            {
                continue;
            }else{
                bit[i]=1;
                res=res-(sll)p[i];
                j=j-(sll)p[i];
            }
            
        }
        // int i=n;
        // ll j=hs;
        // while(i>0){
        //     if(j>=p[i]){
        //     if(dyn[j][i]-dyn[j-p[i]][i-1]==p[i]){
        //         bit[i]=1;
        //         i=i-1;
        //         j=j-p[i];
        //     }else{
        //         i=i-1;
        //     }
        //     }else{
        //         i=i-1;
        //     }
        //}
        
        p1=dyn[hs][n];
        p2=fs-p1;
        dif=llabs(p1-p2);
        cout<<dif<<"\n";
        for(int i=0;i<bit.size();i++){
            cout<<bit[i];
        }cout<<"\n";
    }

    return 0;
}