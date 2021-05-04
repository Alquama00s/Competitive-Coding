#include<iostream>
#include<vector>
#include<set>
//#include<ctime>
using namespace std;
// int dfs(vector<set<int>> g, int ref,vector<bool> &visit,int &a){
//     int ans=a;
//     set<int>::iterator it;
//     if(visit[ref]==false){
//         visit[ref]=true;
//         ans+=g[ref].size()+1;
//         for(int i=0;i<visit.size();i++){
//             cout<<visit[i]<<" ";
//         }cout<<ref<<" "<<ans<<" :ref ans dfs\n";
//         for(it=g[ref].begin();it!=g[ref].end();it++){
//             dfs(g,*it,visit,ans);
//         }
//     }
//     return ans;
// }
int dfsb(vector<set<pair<int,float>>> g,float time, int ref,vector<bool> &visit,int &a){
    int ans=a;
    set<pair<int,float>>::iterator it;
    if(visit[ref]==false){
        visit[ref]=true;
        ans++;
        // for(int i=0;i<visit.size();i++){
        //     cout<<visit[i]<<" ";
        // }cout<<ref<<" "<<ans<<" :ref ans dfsb\n";
        for(it=g[ref].begin();it!=g[ref].end();it++){
            if(time<it->second){
            ans=dfsb(g,it->second,it->first,visit,ans);
            }
        }
    }
    return ans;
}
int main(){
    //srand((unsigned)time(0));
    ios_base::sync_with_stdio(0);
    int t,n,ans,temp,m2,m3;
    float check;
    vector<int> data;
    vector<set<pair<int,float>>> infect;
    vector<bool> vis; 
    pair<int,float> p;
    cin>>t;
    //t=1;
    while ((t-->0))
    {   cin>>n;
        //n=rand()%3+1;
        //n=5;
        data.clear();
        infect.clear();
        data.resize(n,0);
        infect.resize(n,set<pair<int,float>>());
        for(int i=0;i<n;i++){
            cin>>data[i];
            //data[i]=rand()%5+1;
            //cout<<data[i]<<" ";
        }//cout<<" :data\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((data[i]!=data[j])&&(j!=i)){
                    check=((j-i)/float(data[i]-data[j]));
                    //cout<<i<<" "<<j<<" "<<check<<" :ijcheck\n";
                    if(check>=0){
                        p.first=j;
                        p.second=check;
                       infect[i].insert(p);
                       p.first=i;
                       infect[j].insert(p);
                    }
                }
            }
            // ans++;
            // infect[i]=ans;
            // // maxa=max(maxa,ans);
            // // mina=min(mina,ans);
            // ans=0;
        }
        set<pair<int,float>>::iterator j;
        cout.precision(5);
        // for(int i=0;i<infect.size();i++){
        //     for (j = infect[i].begin(); j != infect[i].end(); j++){
        //         p=*j;
        //         cout<<"("<<p.first<<" "<<p.second<<")"<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";
        // mina=6;maxa=1;
        m3=6;m2=1;
        for(int i=0;i<n;i++){
            // vis.clear();
            // vis.resize(n,false);
            // ans=0;
            // temp=dfs(infect,i,vis,ans);
            // cout<<i<<" "<<temp<<" :dfs\n";
            // maxa=max(maxa,temp);
            // mina=min(mina,temp);
            vis.clear();
            vis.resize(n,false);
            ans=0;
            temp=dfsb(infect,0,i,vis,ans);
            //cout<<i<<" "<<temp<<" :dfsb\n";
            m2=max(m2,temp);
            m3=min(m3,temp);
        }

        //cout<<mina<<" "<<maxa<<" :dfs\n";
        cout<<m3<<" "<<m2<<"\n";
        // if((mina!=m3)||(maxa!=m2)){
        //     cout<<"alert\n";
        //     break;
        // }
    }
    
    return 0;
}