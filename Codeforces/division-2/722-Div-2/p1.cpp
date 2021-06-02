#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t, n, temp;
    vector<int> data;
    cin >> t;
    while (t-- > 0) {
        data.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            data.push_back(temp);
        }
        sort(data.begin(),data.end());
        cout<<data.size()-count(data.begin(),data.end(),data[0])<<"\n";
    }
    return 0;
}