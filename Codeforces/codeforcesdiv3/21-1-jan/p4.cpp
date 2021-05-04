#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t, n, temp, m, res, a, b; //a-e
    ll suma, sumb;
    vector<int> A, B;
    cin >> t;
    while (t-- > 0)
    {
        res = 0;
        cin >> n;
        A.clear();
        B.clear();
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2 == 0)
            {
                A.push_back(temp);
            }
            else
            {
                B.push_back(temp);
            }
        }
        a = A.size();
        b = B.size();
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        m = min(a, b);
        suma = accumulate(A.begin(), A.begin() + m, (ll)0);
        sumb = accumulate(B.begin(), B.begin() + m, (ll)0);
        if (suma > sumb)
        {
            if (b > a + 1)
            {
                if (sumb + B[m + 1] > suma)
                {
                    cout << "bob\n";
                }
                else
                {
                    cout << "alice\n";
                }
            }
            else
            {
                cout << "alice\n";
            }
        }
        else if (suma < sumb)
        {
            if (a > b)
            {
                if (suma + A[m] > sumb)
                {
                    cout << "alice\n";
                }
                else
                {
                    cout << "bob\n";
                }
            }
            else
            {
                cout << "bob\n";
            }
        }
        else
        {
            if (a > b)
            {
                cout << "alice\n";
            }
            else if (a < b + 1)
            {
                cout << "bob\n";
            }
            else
            {
                cout << "tie\n";
            }
        }
    }

    return 0;
}