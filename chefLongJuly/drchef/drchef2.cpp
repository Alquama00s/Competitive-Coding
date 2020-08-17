//v2
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int t, n;
long long day, no, x;
vector<long long> pop;
long long les_bin(long long x, int i, int f)
{
    int mid = (i + f) / 2;
    if (f == i + 1)
    {
        if (x <= std::min(pop[i], pop[f]))
            return std::min(pop[i], pop[f]);
        return std::max(pop[i], pop[f]);
    }
    else if (pop[mid] == x)
        return x;
    else if (pop[mid] < x)
    {
        i = mid;
        return les_bin(x, i, f);
    }
    else
    {
        f = mid;
        return les_bin(x, i, f);
    }
}
long long tday(long long affected)
{   if(x>=affected){
        x=2*affected;
        return 1;
    }
    if(x>=(affected/2)){
        x=2*affected;
        return 2;
    }
    int tempx;
    tempx=x;
    x=2*affected;
    return (ceil(log((affected * 1.0)/(2*tempx))/log(2))+2);
}
void remove(long long k, vector<long long> &b)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == k)
        {
            b.erase(b.begin() + i);
            break;
        }
    }
}
void print(vector<long long> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    scanf("%lld", &t);
    while (t-- > 0)
    {
        scanf("%d", &n);
        cin >> ws;
        scanf("%d", &x);
        long long temp;
        cin >> ws;
        pop.clear();
        pop.reserve(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &temp);
            pop.push_back(temp);
        }
        sort(pop.begin(), pop.end());
        day = 0;
    st:
        if (pop.size() > 0)
        {
            while (x < pop[pop.size() - 1])
            {
                no = les_bin(x, 0, (pop.size() - 1));
                day = day + tday(no);
                remove(no, pop);
            }
            day = day + pop.size();
        }
        printf("%lld\n", day);
    }
}