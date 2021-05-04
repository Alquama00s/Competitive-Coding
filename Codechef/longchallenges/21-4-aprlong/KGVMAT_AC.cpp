#include <algorithm>
#include <iostream>
#include <vector>
#define ll unsigned long long
using namespace std;
ll t, n, m, k;
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
/*
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
}*/
ll binCount(int i, int j, int tmin, int tmax, int maxn) {
    int tmid = (tmin + tmax) / 2;
    //cout<<i<<" "<<j<<" "<<tmin<<" "<<tmax<<" :\n";
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
        return binCount(i, j, tmin, tmid,maxn);
    } else {
        return binCount(i, j, tmid, tmax,maxn);
    }
}

/*ll sqmt(int i, int j) {
    ll ans = 0;
    int maxv = n - max(i,j) + 1;
    ll mid, min = i;
    if (sum(i, j, 1) >= k) {
        ans = maxv;
        return ans;
    } else {
        mid = (min + maxv) / 2;
        while (true) {
            if (sum(i, j, mid) >= k * mid*mid && sum(i, j, mid - 1) < k * (mid-1)*(mid-1)) {
                ans = n - mid + 1;
                return ans;
            } else {
                if (sum(i, j, mid) >= k * mid*mid) {
                    maxv=mid;
                    mid = (mid + min) / 2;
                } else {
                    min=mid;
                    mid = (mid + maxv) / 2;
                }
            }
        }
    }
}*/
int main() {
    ll temp, ans;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> m >> k;
        data.clear();
        dp.clear();
        for (int i = 0; i < n; i++) {
            data.push_back(vector<ll>());
            for (int j = 0; j < m; j++) {
                cin >> temp;
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
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout<<i<<" "<<j<<endl;
                ans += binCount(i, j, 1, min(n - i, m - j),min(n - i, m - j));
                //cout<<ans<<" :ans\n";
            }
        }
        cout << ans << "\n";
    }

    return 0;
}