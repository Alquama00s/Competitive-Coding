//incomplete
#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;
int main() {
    int t, x, beg, ones, temp, l;
    // string o ="1";
    // stringstream a;
    cin >> t;
    while (t-- > 0) {
        cin >> x;
        while (x > 11) {
            l = ceil(log10(x));
            beg = x / pow(10, l - 1);

            ones = 11;
            for (int i = 2; i < l; i++) {
                ones = ones * 10 + 1;
            }

            if (beg * ones <= x) {
                x -= beg * ones;
            } else {
                x -= (beg - 1) * ones;
            }
            //cout << x << "--\n";
        }
        if (x == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}