#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    int t,n;
    set<char> data;
    string a,ans;
    cin>>t;
    while (t-->0)
    {
        data.clear();
        cin>>n;
        cin>>a;
        ans="YES";
        for(int i=0;i<n;i++){
            if(data.find(a[i])==data.end()||a[i-1]==a[i]){
                data.insert(a[i]);
            }else{
                ans="NO";
                break;
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}