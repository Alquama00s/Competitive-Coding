#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main() {
    int t, n, m, fact, prog, wt;
    vector<int> data;
    ll ans;
    cin >> t;
    while (t-- > 0) {
        /* code */
        cin >> n >> m;
        data = vector<int>(min(n, m), 0);
        ans = n - 1;  // pairs with one
        //cout<<ans<<"-\n";
        fact = 0;
        for (int i = 0; i < min(n, m); i++) {
            data[i] = m % (i + 1);
        }
        for (int i = data.size()-1; i >1; i--) {
            for (int j = i-1; j >0; j--) {
                if (data[i]%(j+1) == data[j]) ans++;
            }
        }

         //cout<<ans<<"-\n";
        /*
        for (int i = 2; i <= min(n, m); i++) {

            if (m % i == 0) fact++;
        }
        ans += (ll)fact * (fact - 1) / 2;  // pairs of two factors
        // cout<<ans<<"-\n";
        // pairs of prog of small no.excluding factors
        for (int i = 2; i < min(n + 1, m); i++) {
            fact = 0;
            prog = 0;
            if (m % i == 0)
                wt = 0;
            else
                wt = 1;
            for (int j = 2; i * j < min(n + 1, m); j++) {
                prog++;
                if (m % (i * j) == 0) fact++;
            }
            // cout<<prog<<"p\n"<<fact<<"f\n";
            ans += (ll)prog - fact * wt;
        }
        */
        // cout<<ans<<"-\n";
        if (n > m) {
            ans += (ll)(n - m) * (n - m - 1) / 2;  // pairs of big no.
            ans += (ll)(m - 1) * (n - m);          // pair of small and big no.
        }
        cout << ans << "\n";
    }

    return 0;
}