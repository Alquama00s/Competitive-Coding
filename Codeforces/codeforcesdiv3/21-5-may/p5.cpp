#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int t,n,ans,len,k,templen,inds,indl,tinds,tindl;
    string a;
    vector<int> ai;
    cin>>t;
    while (t-->0)
    {
        cin>>n;
        cin>>a;
        templen=0;
        len=0;
        k=0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]=='*'){
                if(len==0){
                    tinds=i;
                    tindl=i;
                }
                else
                    tindl=i;
                len++;
            }else{
                if(len>templen){
                    templen=len;
                    inds=tinds;
                    indl=tindl;
                }
                len=0;
            }
        }
        ans=0;
        for (int i = ai.size()-1; i >0; i--)
        {
            ans+=(ai[i]-ai[i-1]-1);
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}