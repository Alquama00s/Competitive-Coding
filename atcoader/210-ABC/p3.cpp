#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int n, k, temp, i, j, _max;
    set<int> curr;
    vector<int> data;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        data.push_back(temp);
    }

    i = j = 1;
    curr.insert(data[0]);
    _max = 1;
    for (int k = 1; k < n; k++) {
        if (curr.find(data[k]) != curr.end()) {
            for (int l = i - 1; data[l] != data[k]; l++) {
                curr.erase(data[l]);
                i++;
            }
            curr.erase(data[k]);
            i++;
        }
        curr.insert(data[k]);
        j++;
        _max = max(_max, j - i + 1);
        cout<< i << j <<" \n";
    }
    cout << min(_max,k);
    return 0;
}