//https://codeforces.com/contest/455/problem/A
#include<iostream>
#include<algorithm>
#define _max 100001
using namespace std;
int main(){
    int a[_max]={0};
    int n,temp;
    cin>>n;
    while (n-->0)
    {
        cin>>temp;
        a[temp]++;
    }
    unsigned long long even=0L,odd=0L;
    for (int i = 0; i < _max; i+=2)
    {
        even+=(i*a[i]);
    }
    for (int i = 1; i < _max; i+=2)
    {
        odd+=(i*a[i]);
    }
    cout<<max(even,odd);
        
    return 0;
}