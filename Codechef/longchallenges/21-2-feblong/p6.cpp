#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
#define ll long long
using namespace std;
int main() {
    int t, x, y, count,temp;
    vector<int> dp;
    cin >> t;
    while (t-- > 0) {
        dp.clear();
        count=0;
        cin >> x >> y;
        temp=ceil((double)x/2)-1;
        dp = vector<int>(temp+1, 0);
        dp[0]=1;
        for (int i=1; i<dp.size(); i ++) {
            temp=2*i+3;
            if ((temp + 1) % 6 == 0 || (temp - 1) % 6 == 0) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1];
            }
            if (dp[i] > y) {
                count=dp[i];
                break;
            }
        }
        count=max(count,dp[dp.size()-1]);
        if (count <= y) {
            cout << "Chef\n";
        } else {
            cout << "Divyam\n";
        }
    }
    return 0;
}