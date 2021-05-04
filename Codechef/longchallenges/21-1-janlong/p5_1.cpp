#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#define ll long long
using namespace std;
void print(vector<int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
vector<int> subsetSum(vector<int> &el, int sum) {
    vector<vector<int>> dp, dp2;
    vector<int> temp(sum + 1, 0);
    vector<int> res;
    vector<int>::iterator it;
    sort(el.begin(), el.end());
    for (size_t i = 0; i <= el[0]; i++) {
        temp[i] = 1;
    }
    dp.push_back(temp);
    dp2.push_back(temp);
    for (size_t i = 1; i < el.size(); i++) {
        dp.push_back(dp[i - 1]);
        dp2.push_back(dp2[i - 1]);
        for (int j = el[i - 1] + 1; j <= sum; j++) {
            if (j <= el[i]) {
                dp[i][j] = 1;
                dp2[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - el[i]];
                dp2[i][j] = (dp2[i - 1][j - el[i]] + 1) * dp[i][j];
            }
        }
    }
    // for (size_t i = 0; i < dp.size(); i++) {
    //     print(dp[i]);
    // }
    // cout << "\n\n";
    // for (size_t i = 0; i < dp.size(); i++) {
    //     print(dp2[i]);
    // }
    int timp = el.size();
    int i = 0;
    for (int k = 0; k < el.size(); k++) {
        if (dp2[k][sum] != 0) {
            if (timp > dp2[k][sum]) {
                timp = dp2[k][sum];
                i = k;
            }
        }
    }
    int j = sum;
    if (dp2[i][j] != 0) {
        while (j >= el[i] && i>=0) {
            it = el.begin() + i;
            res.push_back(el[i]);
            el.erase(it);
            j = j - el[i];
            i--;
        }
        res.push_back(el[i]);
        it = el.begin() + i;
        el.erase(it);
    }
    /*cout<<"\n";
    print(res);
    cout<<"\n";
    print(el);*/
    return res;
}
int main() {
    int t, n, k, temp;
    vector<int> h, res1, res2;
    vector<int>::iterator it;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> k;
        h.clear();
        for (size_t i = 0; i < n; i++) {
            cin >> temp;
            h.push_back(temp);
        }
        res1 = subsetSum(h, k);
        if (res1.size() > 0) {
            res2 = subsetSum(h, k);
        }
        if (res1.size() == 0 || res2.size() == 0) {
            cout << -1 << "\n";
        } else {
            cout << res1.size() + res2.size() << "\n";
        }
        // print(h);
    }

    return 0;
}