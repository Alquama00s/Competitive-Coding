

#include <bits/stdc++.h>

#include <iostream>
using namespace std;
vector<pair<int, int>> data;
vector<vector<int>> mat, pre;
int t, n, m, k, t1, t2, ans;
int pre_mat(int i, int j) {
    if (i >= 0 && j >= 0) {
        return pre[i][j];
    } else {
        return 0;
    }
}
bool win(int point) {
    pre = mat = vector<vector<int>>(n, vector<int>(m, 0));
    
    for (int i = 0; i <= point; i++) {
        if (i % 2 == 0)
            mat[data[i].first - 1][data[i].second - 1] = 1;  // alice
        else
            mat[data[i].first - 1][data[i].second - 1] = -1;
    }
    int temp=0;
    for (int i = 0; i < m; i++) {
        temp+=mat[0][i];
        pre[0][i] = temp;
    }
    temp = mat[0][0];
    for (int i = 1; i < n; i++) {
        temp+=mat[i][0];
        pre[i][0] = temp;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]+mat[i][j];
        }
    }/*
    print(pre);
    cout<<"=----\n";
    print(mat);
    cout<<"end\n\n";*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(pre_mat(i, j) - pre_mat(i - k, j) - pre_mat(i, j - k) +
                    pre_mat(i-k, j-k)) == k*k) {
                return true;
            }
        }
    }
    return false;
}
int Binary(int min, int max) {
    if (max == min + 1 || max == min) {
        if (win(min))
            return min;
        else if (win(max)) {
            return max;
        } else {
            return -1;
        }
    }
    int mid = (min + max) / 2;
    if (win(mid)) {
        return Binary(min, mid);
    } else {
        return Binary(mid + 1, max);
    }
}
int main() {
    cin >> t;
    while (t-- > 0) {
        ans = 0;
        cin >> n >> m >> k;
        pre.clear();
        mat.clear();
        data.clear();

        for (int i = 0; i < n * m; i++) {
            cin >> t1 >> t2;
            //cout << t1 << " " << t2 <<" "<<i<< "\n";
            data.push_back(pair<int, int>(t1, t2));
            
        }
        ans = Binary(0, n * m - 1);

        //cout << ans << "\n";
        if (ans!=-1) {
            if (ans % 2 == 0) {
                cout << "alice\n";
            } else {
                cout << "bob\n";
            }
        } else {
            cout << "draw\n";
        }
    }

    return 0;
}