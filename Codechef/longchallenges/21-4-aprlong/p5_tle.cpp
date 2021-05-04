#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int t, n, m, r, c, ri, ci, fi, fj;
    vector<vector<int>> data;
    vector<vector<bool>> dp;
    long long count, temp, k;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> m >> k;
        data.clear();
        count = 0L;
        for (size_t i = 0; i < n; i++) {
            data.push_back(vector<int>());
            for (size_t j = 0; j < m; j++) {
                cin >> temp;
                data[i].push_back((int)temp);
            }
        }
        for (int i = 1; i <= m; i++) {
            dp.clear();
            dp = vector<vector<bool>>(n, vector<bool>(m, false));
            dp.push_back(vector<bool>(m + 1, true));
            for (size_t i = 0; i < n; i++) {
                dp[i].push_back(true);
            }
            dp[n - 1][m - 1] = true;
            fi = fj = -1;
            r = n - 1;
            c = m - 1;
            for (int j = 0; j < n + m - 1; j++) {
                ri = r;
                ci = c;
                while (ri < n && ci < m) {
                    if ((ri - i + 1 >= 0) && (ci - i + 1 >= 0) && dp[ri][ci] && (ri > fi || ci > fj)) {
                        temp = 0L;
                        for (int row = 0; row < i; row++) {
                            for (int col = 0; col < i; col++) {
                                temp += data[ri - i + row + 1][ci - i + col + 1];
                            }
                        }

                        if (temp >= k * i * i) {
                            count++;
                            if (ri >= 1)
                                dp[ri - 1][ci] = dp[ri][ci] && dp[ri][ci + 1] && dp[ri - 1][ci + 1];
                            if (ci >= 1)
                                dp[ri][ci - 1] = dp[ri + 1][ci - 1] && dp[ri + 1][ci] && dp[ri][ci];
                        } else {
                            if (fi < ri)
                                fi = ri;
                            if (fj < ci)
                                fj = ci;
                        }
                    }
                    ri++;
                    ci--;
                }
                if (r != 0) {
                    r--;
                } else {
                    c--;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}