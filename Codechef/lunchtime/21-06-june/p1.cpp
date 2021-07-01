#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t;
    string n, ans;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        if (n[0] == '1') {
            ans = "10";
            ans.append(n.substr(1, n.length() - 1));
        }else{
            ans="1";
            ans.append(n);
        }
        cout<<ans<<"\n";
    }

    return 0;
}