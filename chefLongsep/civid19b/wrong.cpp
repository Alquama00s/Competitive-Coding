#include<iostream>
#include<vector>
#include<set>
using namespace std;
int dfs(vector<set<int>> g, int ref,vector<bool> &visit,int &a){
    int ans=a;
    set<int>::iterator it;
    if(visit[ref]==false){
        visit[ref]=true;
        ans+=g[ref].size()+1;
        for(it=g[ref].begin();it!=g[ref].end();it++){
            dfs(g,*it,visit,ans);
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t,n,mina,maxa,ans,temp;
    int check;
    vector<int> data;
    vector<set<int>> infect;
    vector<bool> vis; 
    cin>>t;
    while (t-->0)
    {   cin>>n;
        data.clear();
        infect.clear();
        data.resize(n,0);
        infect.resize(n,set<int>());
        for(int i=0;i<n;i++){
            cin>>data[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((data[i]!=data[j])&&(j!=i)){
                    check=((j-i)*(data[i]-data[j]));
                    if(check>=0){
                       infect[i].insert(j);
                       infect[j].insert(i);
                    }
                }
            }
            // ans++;
            // infect[i]=ans;
            // // maxa=max(maxa,ans);
            // // mina=min(mina,ans);
            // ans=0;
        }
        set<int>::iterator j;
        // for(int i=0;i<infect.size();i++){
        //     for (j = infect[i].begin(); j != infect[i].end(); j++){
        //         cout<<*j<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";
        mina=6;maxa=1;
        for(int i=0;i<n;i++){
            vis.clear();
            vis.resize(n,false);
            ans=0;
            temp=dfs(infect,i,vis,ans);
            maxa=max(maxa,temp);
            mina=min(mina,temp);
        }

        cout<<mina<<" "<<maxa<<"\n";
    }
    
    return 0;
}