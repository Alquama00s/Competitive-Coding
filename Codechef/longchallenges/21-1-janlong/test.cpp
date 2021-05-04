#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    vector<int> alp;
    long long a;
    alp.push_back(1);
    alp.push_back(2147483647);
    a=accumulate(alp.begin(),alp.end(),(long long)0);
    cout<<a;
    return 0;
}