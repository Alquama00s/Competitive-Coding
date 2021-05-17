#include<iostream>
#include<bitset>
#include<string>
#define m 1000000007
using namespace std;
int main(){
    int t,n;
    int p,v,trail;
    string a;
    cin>>t;
    while (t-->0)
    {
        /* code */
        cin>>n;
        a=bitset<32>(n-1).to_string();
        //trail=__builtin_clz(n);
        v=1;
        p=2;
        for(int i=31;i>=0;i--){
            if(a[i]=='1'){
                v=((long long)v*p)%m;
            }
            p=((long long)p*p)%m;
        }
        cout<<v<<"\n";
    }
    
    return 0;
}