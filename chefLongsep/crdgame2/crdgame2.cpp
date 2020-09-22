#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#define ll unsigned long long
#define sll long long
using namespace std;
ll mod=1000000007;
const int L = 1000001;
//global
ll inv[L + 1];
ll factinv[L + 1];  
ll fact[L + 1];
void prestart(){
    inv[0] =1,inv[1] = 1; 
	for (int i = 2; i <= L; i++){ 
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;} 
    factinv[0] =1, factinv[1] = 1; 
	for (int i = 2; i <= L; i++){ 
		factinv[i]=(inv[i]*factinv[i-1])%mod;} 
    fact[0] = 1; 
	for (int i = 1; i <= L; i++) { 
		fact[i]=(fact[i-1]*i)%mod; 
	}
}
ll c2(ll n) 
{   ll r=n/2; 
	ll ans = ((fact[n]*factinv[r])%mod*factinv[n-r])%mod;
    //cout<<ans<<" ncr\n"; 
	return ans; 
} 
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

int main(){
    prestart();
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
            draw*=_pow(2,(n-temp));
            //draw=(draw*2)%mod;
        }
        //cout<<all_comb<<" "<<draw<<" :all drea\n";
        draw%=mod;
        all_comb%=mod;
        cout<<(all_comb-draw)%mod<<"\n";
    }
    return 0;
}