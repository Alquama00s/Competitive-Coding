#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
//#define ll long long
using namespace std;
void print(vector<int> a){
    for (size_t i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }cout<<"\n";
    
}
int main(){
    int t,n,m,temp,res,swaps,i;
    int dif;
    vector<int>n_p,m_p;
    cin>>t;
    while (t-->0)
    {   res=0;
        cin>>n>>m;  
        n_p.clear();
        m_p.clear();
        for (size_t i = 0; i < n; i++)
        {
            cin>>temp;
            n_p.push_back(temp);
        }
        for (size_t i = 0; i < m; i++)
        {
            cin>>temp;
            m_p.push_back(temp);
        }
        dif=accumulate(m_p.begin(),m_p.end(),0)-accumulate(n_p.begin(),n_p.end(),0);
        if(dif>=0){
            res=-1;
            sort(n_p.begin(),n_p.end());
            sort(m_p.begin(),m_p.end(),greater<int>());
            swaps=min(n_p.size(),m_p.size());
            i=0;
            while(swaps-->0 && dif>=0){
                dif-=2*(m_p[i]-n_p[i]);
                i++;
                //cout<<dif<<" dif\n";
            }
            if(dif<0){
                res=i;
            }
        }
        cout<<res<<"\n";
    }
    
    return 0;
}