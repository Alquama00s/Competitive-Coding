#include <bits/stdc++.h>

#include <iostream>
#define ull long long
using namespace std;
ull fun(int x, int y) { return ((ull)x + y - 2) * (x + y - 1) / 2 + x; }
int main() {
    int t, x1, y1, x2, y2;
    ull ans;
    cin >> t;
    while (t-- > 0) {
        ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        while (x1 < x2) {
            //cout<<fun(x1,y1)<<"=\n";
            ans += fun(x1, y1);
            x1++;
        }
        while (y1 < y2) {
            //cout<<fun(x1,y1)<<"=\n";
            ans += fun(x1, y1);
            y1++;
        }
        ans+=fun(x2,y2);
        cout<<ans<<"\n";
    }
    return 0;
}