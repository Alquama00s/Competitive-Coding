#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,x,y;
    long long ans;
    cin>>n>>a>>x>>y;
    ans=(long long)min(n,a)*x;
    n=n-a;
    if(n>0) ans+=n*y;
    cout<<ans;
 return 0;
}