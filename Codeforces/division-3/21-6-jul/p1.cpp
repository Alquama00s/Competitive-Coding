#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t, n, t1, t2, c1, c2;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        t1 = n / 3;
        c1 = t1;
        c2 = t1;
        if (n - 3*t1 == 1)
            c1 += 1;
        else if (n - 3*t1 == 2) {
            c2 += 1;
        }
        cout << c1 << " " << c2 << "\n";
    }
    return 0;
}