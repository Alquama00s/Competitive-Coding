#include <time.h>
#include "debug.h"
#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int t, n, m, k;
vector<vector<ll>> data;
vector<vector<ll>> dp;
ll sum(int x, int y, int l) {
    ll a = 0;
    if (x == 0 && y == 0) {
        a += dp[x + l - 1][y + l - 1];
    } else if (x == 0) {
        a += dp[x + l - 1][y + l - 1] - dp[x + l - 1][y - 1];

    } else if (y == 0) {
        a += dp[x + l - 1][y + l - 1] - dp[x - 1][y + l - 1];

    } else {
        a += dp[x + l - 1][y + l - 1] + dp[x - 1][y - 1] - dp[x + l - 1][y - 1] - dp[x - 1][y + l - 1];
    }
    return a;
}

ll count(int i, int j) {
    ll ans = 0;
    ll t = 1;
    while (sum(i, j, t) < k * t * t) {
        t++;
        if (t > min(n - i, m - j)) {
            t--;
            break;
        }
    }
    if (sum(i, j, t) >= k * t * t) {
        ans = min(n - i, m - j) - t + 1;
    } else {
        ans = 0;
    }
    return ans;
}
ll binCount(int i, int j, int tmin, int tmax, int maxn) {
    int tmid = (tmin + tmax) / 2;
    //cout << i << " " << j << " " << tmin << " " << tmax << " :\n";
    if (tmax - tmin <= 1) {
        if (sum(i, j, tmin) >= k * tmin * tmin) {
            return (ll)maxn - tmin + 1;
        }
        if (sum(i, j, tmax) >= k * tmax * tmax) {
            return (ll)maxn - tmax + 1;
        } else {
            return 0;
        }
    }
    if (sum(i, j, tmid) >= k * tmid * tmid && sum(i, j, tmid - 1) < k * (tmid - 1) * (tmid - 1)) {
        return (ll)maxn - tmid + 1;
    } else if (sum(i, j, tmid) >= k * tmid * tmid) {
        return binCount(i, j, tmin, tmid, maxn);
    } else {
        return binCount(i, j, tmid, tmax, maxn);
    }
}

int main() {
    srand(time(0));
    ll temp, ans, ans2;
    //cin >> t;
    t = 0;
    while (true) {
        //cin >> n >> m >> k;
        n = rand() % 100+1;
        m = rand() % 100 + n;
        k = rand() % 10+1;
        data.clear();
        dp.clear();
        temp = 0;
        data.push_back(vector<ll>());
        for (int i = 0; i < m; i++) {
            temp = rand() % 10 + temp;
            data[0].push_back(temp);
        }
        for (int i = 1; i < n; i++) {
            data.push_back(vector<ll>());
            temp = rand() % 10 + data[i - 1][0];
            data[i].push_back(temp);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                temp = rand() % 10 + data[i - 1][j]+data[i][j-1];
                data[i].push_back(temp);
            }
            
        }
        dp = vector<vector<ll>>(n, vector<ll>(m, 0L));
        dp[0][0] = data[0][0];
        for (int i = 1; i < m; i++) {
            dp[0][i] = dp[0][i - 1] + data[0][i];
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + data[i][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + data[i][j];
            }
        }
        ans = 0L;
        ans2 = 0L;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout << i << " " << j << endl;
                ans += binCount(i, j, 1, min(n - i, m - j), min(n - i, m - j));
                ans2 += count(i, j);
                //cout << ans << " " << ans2 << " :ans ans2\n";
            }
        }
        
        t++;
        //cout<<t<<"\n";
        if (ans != ans2) {
            cout << "----------------------------" << t << "----------------\n";
            cout<<n<<" "<<m<<" "<<k<<" :n m k\n";
            print(data);
            print(dp);
            cout << ans <<" "<<ans2<<"\n";
            break;
        }
    }

    return 0;
}