#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int a, b, t;
    cin >> t;
    while (t-- > 0) {
        cin >> a >> b;
        if((b&(b-1))==0){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }

    return 0;
}