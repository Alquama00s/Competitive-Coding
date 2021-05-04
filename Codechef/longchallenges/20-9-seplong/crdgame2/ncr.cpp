// // C++ program to answer queries 
// // of nCr in O(1) time. 
// #include <bits/stdc++.h> 
// #define ll long long 
// const int L = 1000001; 
// using namespace std; 

// // array to store inverse of 1 to N 
// ll inv[L + 1]; 

// // array to precompute inverse of 1! to N! 
// ll factinv[L + 1]; 

// // array to store factorial of first N numbers 
// ll fact[L + 1]; 

// // Function to precompute inverse of numbers 
// void InverseofNumber(ll mod) 
// { 
// 	inv[0] =1,inv[1] = 1; 
// 	for (int i = 2; i <= L; i++) 
// 		inv[i] = inv[mod % i] * (mod - mod / i) % mod; 
// } 
// // Function to precompute inverse of factorials 
// void InverseofFactorial(ll mod) 
// { 
// 	factinv[0] =1, factinv[1] = 1; 

// 	// precompute inverse of natural numbers 
// 	for (int i = 2; i <= L; i++) 
// 		factinv[i]=(inv[i]*factinv[i-1])%mod; 
// } 

// // Function to calculate factorial of 1 to N 
// void factorial(ll mod) 
// { 
// 	fact[0] = 1; 

// 	// precompute factorials 
// 	for (int i = 1; i <= L; i++) { 
// 		fact[i]=(fact[i-1]*i)%mod; 
// 	} 
// } 

// // Function to return nCr % p in O(1) time 
// ll Binomial(ll N, ll R, ll mod) 
// { 
// 	// n C r = n!*inverse(r!)*inverse((n-r)!) 
// 	ll ans = ((fact[N]*factinv[R])%mod*factinv[N-R])%mod; 
// 	return ans; 
// } 

// // Driver Code 

////////////////////////
#include <bits/stdc++.h> 
#define ll long long 
const int L = 1000001;
ll mod =1000000007; 
using namespace std;
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
	return ans; 
}
int main() 
{ 
	// Calling functions to precompute the 
	// required arrays which will be required 
	// to answer every query in O(1) 
	prestart(); 

	// 1st query 
	ll N = 2; 
	ll R = 100; 
	cout << c2(N) << endl; 

	// // 2nd query 
	// N = 20; 
	// R = 3; 
	// cout << c(N, R) << endl; 

	return 0; 
} 