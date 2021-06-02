//incomplete
#include <bits/stdc++.h>
//#include "debug.h"
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, temp, ans, p, zero;
    vector<int> datan, datap;
    cin >> t;
    while (t-- > 0) {
        datan.clear();
        datap.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp > 0) {
                datap.push_back(temp);
            } else {
                datan.push_back(temp);
            }
        }

        // zero = count(datan.begin(), datan.end(), 0);
        sort(datan.begin(), datan.end());
        sort(datap.begin(), datap.end());
        if(datan.size()>0){
            if(datan.size()>1){
                temp = abs(datan[0] - datan[1]);
            }else{
                temp=abs(datan[0] - datap[0]);
            }
        }
        for (int i = 0; i < datan.size() - 1; i++) {
            if (temp > abs(datan[i] - datan[i + 1]))
                temp = abs(datan[i] - datan[i + 1]);
        }

        if (datap.size() > 0 && temp >= datap[0]) {
            ans = datan.size() + 1;
        } else {
            ans = datan.size();
        }

        cout << ans << "\n";
    }
    return 0;
}