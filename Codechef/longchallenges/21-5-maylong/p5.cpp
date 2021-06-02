#include <bits/stdc++.h>

#include <vector>

//#include "debug.h"
#define ll long long
using namespace std;
vector<int> cf(int n) {
    vector<int> ans;
    for (int i = 1; i * i < n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
        }
    }
    for (int i = (int)sqrt(n); i >= 1; i--) {
        if (n % i == 0) {
            ans.push_back(n / i);
        }
    }
    return ans;
}
int Binary(vector<int> data, int key) {
    int s = 0, e = data.size() - 1,m;
    while (true) {
        m = (s + e) / 2;
        if (e == s + 1||e==s) {
            if (data[e] < key)
                return e+1;
            if(data[e]==key)
                return e;
            if(data[s]==key)
                return s;
            return s+1;
        }
        if (data[m] > key) {
            e=m;
        } else if (data[m] < key) {
            s=m;
        } else {
            return m;
        }
    }
}
int main() {
    int t, n, m, ans;
    cin >> t;
    vector<vector<int>> data;
    while (t-- > 0) {
        cin >> n >> m;
        data.clear();
        ans = 0;
        for (int i = 1; i <= m; i++) {
            data.push_back(cf(i));
        }
        for (int i = 1; i <= min(n,m); i++) {
            //cout<<Binary(data[(m-m%i)-1],i)<<"\n";
            ans+=Binary(data[(m-m%i)-1],i);
        }
        if(n>m){
            ans+=((n-1)*n-(m-1)*m)/2;
        }
        cout<<ans<<"\n";
    }

    return 0;
}