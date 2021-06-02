#include <bits/stdc++.h>

#include <iostream>
#define ll long long
using namespace std;
int main() {
    int n, k;
    ll ans = 0L;
    cin>>n>>k;
    ans+=((k*(k+1))/2)*n;
    ans+=((n*(n+1))/2)*100*k;
    cout<<ans<<"\n";
    return 0;
}