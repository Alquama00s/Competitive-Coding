#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main() {
    int t, g, p, v_left,days,p_left, in, ax;
    ll temp;
    vector<int> data;
    cin >> t;
    while (t-- > 0) {
        data.clear();
        cin >> g >> p;
        for (int i = 0; i < 10; i++) {
            cin >> temp;
            data.push_back(temp);
        }
        temp = accumulate(data.begin() + g, data.end(), 0LL);
        // cout << temp << "acc\n";

        if (p <= temp) {
            v_left = temp % p;
            days = ceil((float)temp / p);
        } else {
            days = 1;
            v_left = p - temp;
        }
        if (v_left > 0) {
            in = days;
        } else {
            in = days + 1;
        }
        p_left = data[g - 1] - v_left;
        if(p_left>p){
        ax = days + ceil((float)p_left / p);
        }else if(p_left>0){
            ax=days+1;
        }else{
            ax=days;
        }
        cout << in << " " << ax << "\n";
    }
    return 0;
}