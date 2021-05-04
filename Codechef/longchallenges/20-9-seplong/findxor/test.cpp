#include<iostream>
using namespace std;
int main(){
    int a,b,k;
    a=52,b=78,k=44;
    //int x=(a+b+k)-2*((a&b)&k);
    cout<<(a^k)+(b^k)<<" :raw"<<((a+b)^k)<<" :dist  XOR\n";
    cout<<(a&k)+(b&k)<<" :raw"<<((a+b)&k)<<" :dist  and\n";
    cout<<(a|k)+(b|k)<<" :raw"<<((a+b)|k)<<" :dist  or\n";
    //cout<<(a^k)+(b^k)<<" :raw"<<((a+b)^k)<<" :dist  XOR\n";
    return 0;
}