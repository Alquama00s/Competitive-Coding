#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#define ll unsigned long long
#define sll long long
using namespace std;
ll mod=1000000007; 
ll _pow(ll base,ll expo){
    ll res=1;
    ll two=base;
    while(expo>0){
    if(expo&1){
        res=(res*two)%mod;
    }
    expo=expo>>1;
    two=(two*two)%mod;
    }
    return res;
}
ll c2(int n){
    ll ans=1;
    ll div=1;
    for(int i=1,j=((n/2)+1);i<=(n/2);i++,j++){
        div=((ll)j*_pow((ll)i,mod-2))%mod;
        ans=(ans*div)%mod;
    }  
    return ans;
}
int main(){
    int t,n;
    vector<int> data;
    ll all_comb;
    ll draw;
    ll temp;
    cin>>t;
    while (t-->0)
    {
        cin>>n;
        data.clear();
        data.resize(n,0);
        for(int i=0;i<n;i++){
            cin>>data[i];
            //data[i]=rand()%10+1;
            //cout<<data[i]<<" ";
        }//cout<<"\n";
        //input
        all_comb=_pow((ll)2,(ll)n);
        sort(data.begin(),data.end());
        // for(int i=0;i<n;i++){
        //     cout<<data[i]<<" ";
        // }cout<<"\n";
        draw=0;
        temp=0;
        temp=count(data.begin(),data.end(),data[n-1]);
        //cout<<temp<<" :L\n";
        if(temp%2==0){
            draw+=c2(temp);
            //temp=temp-2;
            //cout<<temp<<" :(\n";
            draw*=_pow((ll)2,(ll)(n-temp));
            //draw=(draw*2)%mod;
        }
        //cout<<all_comb<<" "<<draw<<" :all drea\n";
        draw%=mod;
        all_comb%=mod;
        cout<<((all_comb-draw)%mod+mod)%mod<<"\n";
    }
    return 0;
}