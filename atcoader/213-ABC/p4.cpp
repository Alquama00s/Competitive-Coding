// incomplete

#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int n, t1, t2;
    cin >> n;
    vector<vector<int>> al(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        al[t1 - 1].push_back(t2 - 1);
        al[t2 - 1].push_back(t1 - 1);
    }
    for (int i = 0; i < n; i++) {
        sort(al[i].begin(), al[i].end(), greater<int>());
    }

    stack<int> city, parent;
    vector<int> visited(n, false);
    int ctemp=0, ptemp=0;
    parent.push(0);
    do {
        if (ctemp == ptemp) {
            ctemp = parent.top();
              
        } else {
            parent.push(ptemp);
        }
        cout << ctemp + 1 << " ";
        ptemp = ctemp;

        visited[ctemp] = true;

        for (int i = 0; i < al[ctemp].size(); i++) {
            if (!visited[al[ctemp][i]]) {
                ctemp = al[ctemp][i];
                break;
            }
        }

        
    } while (!parent.empty());
    cout << "\n";
    return 0;
}