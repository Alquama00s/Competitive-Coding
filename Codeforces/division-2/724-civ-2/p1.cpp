#include <bits/stdc++.h>

#include <iostream>

using namespace std;
int main() {
    int t, n, temp;
    bool ans;
    vector<int> data;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        data.clear();
        ans = true;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp < 0) {
                ans = false;
            }
            data.push_back(temp);
        }
        // vector<int>::iterator i = data.begin(), j;
        for (int i = 0; i < data.size() && ans && data.size() < 301; i++) {
            for (int j = i + 1; j < data.size() && data.size() < 301; j++) {
                if (find(data.begin(), data.end(), abs(data[i] - data[j])) ==
                    data.end()) {
                    data.push_back(abs(data[i] - data[j]));
                }
            }
        }
        if (ans) {
            cout << "yes"
                 << "\n";
            cout << data.size() << "\n";
            for (int i = 0; i < data.size(); i++) {
                cout << data[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "no"
                 << "\n";
        }
    }

    return 0;
}