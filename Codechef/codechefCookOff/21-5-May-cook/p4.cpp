#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t, n, k, temp,ans;
    long long sum;
    vector<int> data;
    cin >> t;
    while (t-- > 0) {
        data.clear();
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            data.push_back(temp);
        }
        temp=sum=accumulate(data.begin(),data.begin()+(k-1),0LL);
        ans=0;
        for (int i = 0; i+k < n; i++)
        {
            if(data[i+k]!=data[i]){
                ans++;
                data[i+k]=data[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}