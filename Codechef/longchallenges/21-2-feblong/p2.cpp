#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, t, temp;
    vector<long long> data;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        data.clear();
        for (size_t i = 0; i < n; i++) {
            cin >> temp;
            data.push_back(temp);
        }
        sort(data.begin(), data.end());
        cout << 2 * (data[n - 1] - data[0]) << "\n";
    }
}