#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,temp,ans=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        if(temp>10){
            ans+=(temp-10);
        }
    }
    cout<<ans<<"\n";
 return 0;
}