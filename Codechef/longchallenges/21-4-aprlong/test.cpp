#include <algorithm>
#include <iostream>
#include <vector>
#include "debug.h"
using namespace std;
int main() {
    int t, n, m, k, r, c;
    vector<vector<int>> data;
    vector<vector<bool>> dp;
    long long count;
    float temp;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> m >> k;
        data.clear();
        dp.clear();
        data = vector<vector<int>>(n, vector<int>(m, 0));
        dp = vector<vector<bool>>(n, vector<bool>(m, false));
        dp.push_back(vector<bool>(m, true));
        for (size_t i = 0; i < m; i++) {
            dp[i].push_back(true);
        }
        dp[n - 1][m - 1] = true;
        count = 0L;
        cout<<dp[n][m];
        print(data);
    }
    return 0;
}