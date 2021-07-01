//incomplete

#include <bits/stdc++.h>

#include <iostream>
using namespace std;
vector<pair<int, int>> data;
vector<vector<int>> mat, pre;
int t, n, m, k, t1, t2, ans;
int pre_mat(int i,int j){
    if (i>=0 && j>=0){
        return pre[i][j];
    }else{
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
    for (int i = 0; i < n; i++) {
        pre[0][i] = mat[0][i];
    }
    for (int i = 1; i < m; i++) {
        pre[i][0] = mat[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; i < m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(abs(pre_mat(i,j)-pre_mat(i-1,j)-pre_mat(i,j-1)+pre_mat(i,j))==4){
                return true;
            }
        }
        
    }
    return false;
}
int Binary(int min, int max) {
    if (max == min + 1 || max == min) {
        if(win(min))
            return min;
        else if(win(max)){
            return max;
        }else{
            return -1;
        }
    }
    int mid = (min+max)/2;
    if(win(mid)){
        return Binary(min,mid);
    }else{
        return Binary(mid+1,max);
    }
}
int main() {
    cin>>t;
    while (t-- > 0) {
        cout<<"start\n";
        ans = 0;
        cin >> n >> m >> k;
        pre.clear();
        mat.clear();
        data.clear();
        for (int i = 0; i < n * m; i++) {
            cin >> t1 >> t2;
            data.push_back(pair<int, int>(t1, t2));
        }
        ans = Binary(0,n*m-1);
        cout<<ans<<"\n";
        if(ans){
            if(ans%2==0){
                cout<<"alice\n";
            }else{
                cout<<"bob\n";
            }
        }else{
            cout<<"draw\n";
        }
    }

    return 0;
}