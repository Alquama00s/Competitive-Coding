#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t,n,ans;
    vector<int> a;
    cin>>t;
    while (t-->0)
    {
        cin>>n;
        a=vector<int>(n,0);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        ans=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(a[j]-a[i]==j-i)
                    ans++;
            }
            
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}