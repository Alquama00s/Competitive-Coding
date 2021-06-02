#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t, n, r, c, temp;
    vector<vector<int>> data;
    cin >> t;
    while (t-- > 0) {
        data.clear();
        cin >> n;
        if (n == 2) {
            cout << -1 << "\n";
        } else {
            data = vector<vector<int>>(n, vector<int>(n, 0));
            for (int i = 0; i < n; i++) {
                data[i][i] = i + 1;
            }
            temp = n + 1;
            for (int i = n - 1; i > 0; i--) {
                r = 0;
                c = n - i;
                for (int k = 0; k < i; k++) {
                    data[r][c] = temp;
                    data[c][r] = temp + i;
                    temp++;
                    r++;
                    c++;
                }
                temp+=i;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << data[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}