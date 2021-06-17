#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int n, m, t1, t2;
    queue<int> left;
    set<pair<int,int>> ans;
    cin >> n >> m;
    vector<vector<int>> AL(n + 1, vector<int>());
    vector<bool> visits;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        AL[t1].push_back(t2);
    }
    for (int i = 1; i <= n; i++) {
        visits = vector<bool>(n + 1, false);
        left.push(i);
        ans.insert(pair<int,int>(i,i));
        while (!left.empty()) {
            t1 = left.front();
            left.pop();
            visits[t1]=true;
            for (int j = 0; j < AL[t1].size(); j++) {
                /* code */
                ans.insert(pair<int,int>(i,AL[t1][j]));
                if(!visits[AL[t1][j]])left.push(AL[t1][j]);
            }
        }
    }
    cout<<ans.size();
}