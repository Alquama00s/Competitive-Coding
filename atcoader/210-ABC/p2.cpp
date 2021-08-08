#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    string data;
    int n, i;
    cin >> n >> data;
    for (i = 0; i < n; i++) {
        if (data[i] == '1') {
            if (i % 2 != 0) {
                cout << "Aoki";

            } else {
                cout << "Takahashi";
            }
            break;
        }
    }

    return 0;
}