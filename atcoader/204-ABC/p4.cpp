//incomplete
#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int n, dif, temp;
    vector<int> a, b, data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        /* code */
        cin >> temp;
        data.push_back(temp);
    }
    dif=0;
    for (int i = 0; i < n; i++)
    {
        if(dif+data[i]<=abs(dif-data[i])){
            a.push_back(data[i]);
            dif+=data[i];
        }else{
            b.push_back(data[i]);
            dif=abs(dif-data[i]);
        }
    }
    cout<<max(accumulate(a.begin(),a.end(),0),accumulate(b.begin(),b.end(),0));
    return 0;
}