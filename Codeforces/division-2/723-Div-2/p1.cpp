//incomplete
#include <bits/stdc++.h>

#include <iostream>

#include "debug.h"
using namespace std;
vector<int> testa;
void printans(deque<int> a) {
    testa.clear();
    deque<int>::iterator i;
    for (i = a.begin(); i != a.end(); i++) {
        cout << *i << " ";
        testa.push_back(*i);
    }
    cout << "\n";
}
bool test() {
    int ans = 1;
    int n = testa.size();
    for (int i = 0; i < 2 * n; i++) {
        if (2 * testa[i % n] == testa[(i - 1) % n] + testa[(i + 1) % n]) {
            ans = 0;
            break;
        }
    }
    if (ans) {
        cout << "True\n";
        return true;
    } else {
        cout << "False\n";
        return false;
    }
}
vector<int> generate() {
    vector<int> gen;
    for (int i = 0; i < 25; i++) {
        gen.push_back(rand());
    }
    return gen;
}
int main() {
    srand(time(0));
    int t, temp, n, front, back, frontdif, backdif;
    vector<int> data;
    deque<int> ans;
    //cin >> t;
    while (true) {
        // cin >> n;
        // n = 25;
        data.clear();
        ans.clear();
        /*for (int i = 0; i < 2 * n; i++) {
            cin >> temp;
            data.push_back(temp);
        }*/
        data = generate();
        print(data);
        n = data.size() / 2;
        // sort(data.begin(), data.end());
        front = data[0];
        ans.push_front(data[0]);
        data.erase(data.begin());
        back = data[0];
        ans.push_back(data[0]);
        data.erase(data.begin());
        frontdif = backdif = abs(front - back);
        int i = 0;

        while (!data.empty()) {
            // print(data);
            if (abs(data[i] - front) != frontdif) {
                frontdif = abs(data[i] - front);
                ans.push_front(data[i]);
                front = data[i];
                data.erase(data.begin() + i);
            } else if (abs(data[i] - back) != backdif) {
                backdif = abs(data[i] - back);
                ans.push_back(data[i]);
                back = data[i];
                data.erase(data.begin() + i);
            } else {
                i++;
            }
            if (!data.empty()) {
                i = i % data.size();
            }
        }
        cout<<"\n\n";
        printans(ans);
        if(!test()) break;
        cout<<"\n\n";
        cout<<"\n\n";
    }
    return 0;
}