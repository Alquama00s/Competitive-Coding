#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int x, y, ans;
    cin >> x >> y;
    if (x == y)
        ans = x;
    else
        ans = (max(x, y) + abs(x-y)) % 3;
    cout<<ans<<"\n";
    return 0;
}