#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t,d,D,A,B,C;
    cin >> t;
    while (t-- > 0) {
        cin>>d>>D>>A>>B>>C;
        if(D*d>=42){
            cout<<C<<"\n";
        }else if(D*d>=21){
            cout<<B<<"\n";
        }else if(d*D>=10){
            cout<<A<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
    return 0;
}