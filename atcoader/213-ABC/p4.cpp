//incomplete

#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int n, t1, t2;
    cin >> n;
    vector<vector<int>> al(n, vector<int>());
    for (int i = 0; i < n-1; i++) {
        cin >> t1 >> t2;
        al[t1 - 1].push_back(t2 - 1);
        al[t2 - 1].push_back(t1 - 1);
    }
    for (int i = 0; i < n; i++) {
        sort(al[i].begin(), al[i].end(), greater<int>());
    }

    stack<int> city;
    vector<int> visited(n, false);
    city.push(0);
    int temp;
    while (!city.empty()) {
        temp = city.top();
        city.pop();
        cout << temp + 1 << " ";
        if (!visited[temp]) {
            visited[temp] = true;
            if (al[temp].size() > 0) {
                for (int i = 0; i < al[temp].size(); i++) {
                    city.push(al[temp][i]);
                    city.push(temp);
                }
                city.pop();
            }
        }
    }
cout<<"\n";
    return 0;
}