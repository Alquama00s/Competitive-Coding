#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int t,n,tog,res;
    vector<ll> data;
    cin>>t;
    string s;
    while (t-->0)
    {
        cin>>n;
        data.resize(n,0L);
        //for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>data[j];
                //data[0][j]=j+1;
            }
            for(int i=n;i<n*n;i++){
            cin>>s;
            }
        //}
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<data[i][j];
        //     }
        // }
        //input
        res=0;tog=0;//tog=0-->correct
        for(int i=1;i<n;i++){
            if((data[i]!=i+1)&&(tog==0)){//transition form correct to incorrect
                if(i==1){
                    res+=1;
                }else{
                    res+=2;
                }
                tog=1;
                
            }
            if((data[i]==i+1)&&(tog==1)){//transition from incorrect to correct
                tog=0;
            }
        }
        cout<<res<<"\n";

    }
    
    return 0;
}