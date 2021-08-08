#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t, r, c, g, temp, n, k;
    vector<int> s, ans;
    cin >> t;
    map<int, int> arr;
    while (t-- > 0) {
        cin >> n >> k;
        s.clear();
        for (int i = 0; i < n; i++) {
            cin >> temp;
            s.push_back(temp);
        }
        ans = vector<int>(n, 0);
        r = 0;
        c = 0;
        g = 0;

        for (int i = 0; i < s.size(); i++) {
            arr[s[i]]++;
            if(arr[s[i]]<=k)
            ans[i]=arr[s[i]];
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }cout<<"\n";
        
    }
    return 0;
}