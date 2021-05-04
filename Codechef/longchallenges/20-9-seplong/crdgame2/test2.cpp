#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#define ll unsigned long long
#define sll long long
using namespace std;
ll mod=1000000007; 
ll fact(int a){
    ll res=1;
    for(int i=1;i<=a;i++){
        res=((res*i)%mod);
    }
    return res;
}
int power(int x, unsigned int y, int p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
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
ll c2(int n){
    ll ans=1;
    ll div=1;
    for(int i=1,j=((n/2)+1);i<=(n/2);i++,j++){
        //cout<<i<<" "<<j<<"\n";
        div=(j*_pow(i,mod-2))%mod;
        ans*=div;
        ans%=mod;
    }  
    return ans;
}
int main(){
    int y=5;
    cout<<c2(1000)<<" "<<_pow(2,100000);
    return 0;
}