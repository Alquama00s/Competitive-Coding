#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int t, n, m, r, c, ri, ci, fi, fj;
    vector<vector<int>> data;
    vector<vector<bool>> dp;
    bool ok;
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
        dp.clear();
        dp = vector<vector<bool>>(n, vector<bool>(m, false));
        dp.push_back(vector<bool>(m + 1, true));
        for (size_t i = 0; i < n; i++) {
            dp[i].push_back(true);
        }
        dp[n - 1][m - 1] = true;
        r=n-1;
        c=m-1;
        for (int j = 0; j < n + m - 1; j++) {
            ri = r;
            ci = c;
            ok=false;
            while (ri < n && ci < m && ci >= 0) {
                if (dp[ri][ci]) {
                    if (data[ri][ci] >= k) {
                        ok=true;
                        count++;
                        temp=data[ri][ci];
                        if (ri >= 1)
                            dp[ri - 1][ci] = dp[ri][ci] && dp[ri][ci + 1] && dp[ri - 1][ci + 1];
                        if (ci >= 1)
                            dp[ri][ci - 1] = dp[ri + 1][ci - 1] && dp[ri + 1][ci] && dp[ri][ci];
                        for (int i = 1; i < n; i++) {
                            fi=ri-i;
                            fj=ci;
                            if(fi<0||fj<i){
                                break;
                            }
                            for (int si = 1; si < 2 * i+2; si++) {
                                temp+=data[fi][fj];
                                if(si<i+1){
                                    fj--;
                                }else{
                                    fi++;
                                }
                            }
                            if(temp>=k*(i+1)*(i+1)){
                                count++;
                            }else{
                                break;
                            }
                        }
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
            if(!ok){
                break;
            }
        }

        cout << count << '\n';
    }
    return 0;
}