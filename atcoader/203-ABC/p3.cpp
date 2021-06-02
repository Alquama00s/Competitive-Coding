//incomplete

#include <bits/stdc++.h>

#include <iostream>
#include <map>
using namespace std;
#define ull long long
#define ld long double
int main() {
    map<ull, ull> gifts;
    ull n, k, tk, tv;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tv >> tk;
        gifts[tv] += tk;
    }
    map<ull, ull>::iterator it = gifts.begin();
    tv = 0;
    for (; it != gifts.end(); it++) {
        tk = k - (it->first - tv);
        if (tk < 0) {
            break;
        }
        k = tk;
        k = k + it->second;
        tv = it->first;
    }
    tv = tv + k;
    cout << tv << "\n";

    return 0;
}