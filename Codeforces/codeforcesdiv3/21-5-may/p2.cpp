#include <math.h>

#include <iostream>
using namespace std;
int main() {
    int t, n, ans, temp, digits, one;
    cin >> t;
    while (t-- > 0) {
        ans = 0;
        one = 0;
        cin >> n;
        digits = 0;
        temp = n;
        while (temp != 0) {
            temp /= 10;
            digits++;
            one = one * 10 + 1;
        }
        ans = ((int)(n / (pow(10, (digits - 1)))) - 1) + 9 * (digits - 1);
        //cout<<one<<"\n";
        if ((int)(n / (pow(10, (digits - 1)))) * one <= n)
            ans++;

        cout<<ans<<"\n";
    }

    return 0;
}