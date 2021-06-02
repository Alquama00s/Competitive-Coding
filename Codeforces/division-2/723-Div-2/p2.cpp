#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t, x, ans;
    cin >> t;
    while (t-- > 0) {
        cin >> x;
        if (x > 1099) {
            cout << "yes\n";
        } else {
            ans = 0;
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j <= 181; j++) {
                    if (x == i * 111 + j * 11) {
                        ans=1;
                        cout << "yes\n";
                        break;
                    }
                }
                if (ans != 0) break;
            }
            if (ans == 0) cout << "no\n";
        }
    }
    return 0;
}