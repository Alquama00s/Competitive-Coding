#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t,n,k,d,sum,temp;
    cin>>t;
    while (t-->0)
    {
        cin>>n>>k>>d;
        sum=0;
        for (size_t i = 0; i < n; i++)
        {   cin>>temp;
            sum+=temp;
        }
        cout<<min((sum/k),d)<<"\n";
        
    }
    
    return 0;
}