#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t, temp, n;
    vector<int> datae, datao;
    cin >> t;
    while (t-- > 0) {
        datae.clear();
        datao.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp % 2 == 0)
                datae.push_back(temp);
            else
                datao.push_back(temp);
        }
        for (int i=0; i < datae.size(); i++) {
            cout << datae[i] << " ";
        }
        for (int i=0 ; i < datao.size(); i++) {
            cout << datao[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}