#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void print(vector<int> a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
vector<int> subsetSum(vector<int> &el, int sum)
{
    vector<vector<int>> dp;
    vector<int> temp(sum + 1, 0);
    vector<int> res(2, 0);
    vector<int>::iterator it;
    temp[0] = 1;
    if (el[0] > sum)
    {
        return res;
    }
    temp[el[0]] = 1;
    dp.push_back(temp);
    for (size_t i = 1; i < el.size(); i++)
    {
        dp.push_back(dp[i - 1]);
        for (int j = el[i]; j <= sum; j++)
        {
            if (dp[i][j] == 0)
                dp[i][j] = dp[i - 1][j - el[i]];
        }
    }
    // for (size_t i = 0; i < dp.size(); i++)
    // {
    //     print(dp[i]);
    // }
    int i = el.size() - 1;
    int j = sum;
    while (dp[i][j] != 1)
    {
        j--;
    }
    res[1] = sum - j;
    while (i != 0 || j != 0)
    {
        if (i == 0)
        {
            it = el.begin();
            el.erase(it);
            res[0]++;
            break;
        }
        if (j == 0)
        {
            break;
        }
        if (dp[i - 1][j] == 1)
        {
            i = i - 1;
        }
        else
        {
            j = j - el[i];
            it = el.begin() + i;
            el.erase(it);
            i = i - 1;
            res[0]++;
        }
    }
    // print(el);
    // print(res);
    // cout << " res half work\n";
    return res;
}
int main()
{
    int t, n, k, temp;
    vector<int> h, res1(2,0), res2(2,0);
    vector<int>::iterator it;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n >> k;
        h.clear();
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            h.push_back(temp);
        }
        sort(h.begin(), h.end());
        if (k <= h[n - 1])
        {   
            res1[0] = 1;
            res1[1] = 0;
            it = h.begin() + (n - 1);
            h.erase(it);
        }
        else
        {
            res1 = subsetSum(h, k);
        }
        n = h.size();
        if (n > 0)
        {
            if (k <= h[n - 1])
            {
                res2[0] = 1;
                res2[1] = 0;
                it = h.begin() + n - 1;
                h.erase(it);
            }
            else
            {
                res2 = subsetSum(h, k);
            }
        }
        else
        {
            res2[0] = -1;
            res2[1] = 0;
        }
        if (res1[1] > 0)
        {
            temp = h.size() - 1;
            while (temp >= 0 && res1[1] > 0)
            {
                res1[1] -= h[temp];
                res1[0]++;
                it = h.begin() + temp;
                h.erase(it);
                temp--;
            }
            if (res1[1] > 0)
            {
                res1[0] = -1;
            }
        }
        if (res2[1] > 0)
        {
            temp = h.size() - 1;
            while (temp >= 0 && res2[1] > 0)
            {
                res2[1] -= h[temp];
                res2[0]++;
                it = h.begin() + temp;
                h.erase(it);
                temp--;
            }
            if (res2[1] > 0)
            {
                res2[0] = -1;
            }
        }
        if (res1[0] < 0 || res2[0] < 0)
        {
            temp = -1;
        }
        else
        {
            temp = res1[0] + res2[0];
        }
        cout << temp << "\n";
        //print(h);
    }

    return 0;
}