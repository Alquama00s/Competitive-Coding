#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    map<int, int> in;
    int n, temp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        in[temp] = i;
    }
    map<int,int>::iterator it =in.end();
    it--;it--;
    cout<<(it->second)<<"\n";

    return 0;
}