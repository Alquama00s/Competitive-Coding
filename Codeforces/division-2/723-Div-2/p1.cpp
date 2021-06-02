#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t, n, temp;
    vector<int> data, ans;
    cin >> t;
    while (t-- > 0) {
        data.clear();
        ans.clear();
        cin >> n;
        for (size_t i = 0; i < 2 * n; i++) {
            cin >> temp;
            data.push_back(temp);
        }
        sort(data.begin(), data.end());
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
            cout << data[i + n] << " ";
        }
        cout << "\n";
    }
    return 0;
}