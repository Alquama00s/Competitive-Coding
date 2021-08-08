#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    map<int, int> r, c;
    vector<pair<int, int>> points;
    int hr, wc, n, tempr, tempc;
    cin >> hr >> wc >> n;
    /*for (int i = 1; i <= hr; i++) {
        r[hr] = 0;
    }
    for (int i = 1; i <= wc; i++) {
        c[wc] = 0;
    }*/
    for (int i = 1; i <= n; i++) {
        cin >> tempr >> tempc;
        points.push_back(pair<int, int>(tempr, tempc));
        r[tempr] = -1;
        c[tempc] = -1;
    }
    map<int, int>::iterator it = r.begin();
    int i = 1;
    for (; it != r.end(); it++) {
        it->second = i;
        i++;
    }
    it = c.begin();
    i = 1;
    for (; it != c.end(); it++) {
        it->second = i;
        i++;
    }
    for (int i = 0; i < n; i++) {
        cout << r[points[i].first] << " " << c[points[i].second] << "\n";
    }

    return 0;
}