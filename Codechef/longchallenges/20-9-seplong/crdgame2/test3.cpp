#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#define ll unsigned long long
#define sll long long
using namespace std;
ll mod=1000000007; 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
int modInverse(int b, int m) 
{ 
    int x, y; // used in extended GCD algorithm 
    int g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
int modDivide(int a, int b, int m) 
{ 
    a = a % m; 
    int inv = modInverse(b, m); 
    if (inv == -1){
        return -1;
    } 
       //cout << "Division not defined"; 
    else{
        return (inv*a)%m;
    }
       //cout << "Result of division is " << (inv * a) % m; 
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll c2(int n){
    ll ans=1;
    ll div=1;
    for(int i=1,j=((n/2)+1);i<=(n/2);i++,j++){
        div=(j*_pow(i,mod-2));
        ans%=mod;
    }  
    return ans;
}
int main(){
    int y=5;
    y&1;
    cout<<c2(200);
    return 0;
}