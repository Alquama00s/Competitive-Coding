#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
//v3
using namespace std;
void print(vector<long long> a){
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}
void remove(int k,vector<long long>& b)
{ 
    for(int i=0;i<b.size();i++){
    if(b[i]==k){
        b.erase(b.begin()+i);
        break;
    }
}
}
vector<long long> und;
void Frequency(vector<long long> vec) 
{ und.clear();
    map<int, int> M;  
    for (int i = 0; i<vec.size(); i++) { 
        if (M.find(vec[i]) == M.end()) { 
            M[vec[i]] = 1; 
        } 
        else { 
            M[vec[i]]++; 
        } 
    }
    
    for (auto& it:M) { 
        und.push_back(it.first); 
    } 
}  
int count(int k, vector<long long> a){
    int temp=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==k){
            temp++;
        }
    }
    return temp;
}
int main()
{
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL); 
    vector<long long> a, b, da, db, unda, undb;
    int t, n;
    bool cant;
    //vector<int>::iterator ip;
    scanf("%d",&t);
    while (t-- > 0)
    {
        scanf("%d",&n);
        a.clear();
        b.clear();
        da.clear();
        //da.resize(n);
        db.clear();
        //db.resize(n);
        a.reserve(n);
        b.reserve(n);
    long long temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&temp);
        a.push_back(temp);
    }
    cin>>ws;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&temp);
        b.push_back(temp);
    }
        
        da.reserve(n);
        db.reserve(n);
        copy(a.begin(),a.end(),back_inserter(da));
        copy(b.begin(),b.end(),back_inserter(db));
        for(int i=0;i<n;i++){
            remove(a[i],db);
            remove(b[i],da);
        }
        Frequency(da);
        unda=und;
        Frequency(db);
        undb=und;
        cant=false;
        for(int i=0;i<unda.size();i++){
            if(count(unda[i],da)%2!=0){
                cant=true;
                break;
            }
        }
        for(int i=0;i<undb.size();i++){
            if(count(undb[i],db)%2!=0 || cant==true){
                cant=true;
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b)
            printf("%d\n",0);
        else if(cant==true)
            printf("%d\n",-1);
        else{
            if(da.size()!=db.size())
                printf("%d\n",-1);
            else{
                int ans=0;
                int swpr;
                swpr=std::min(a[0],b[0]);
                sort(da.begin(),da.end());
                sort(db.begin(),db.end(),greater<int>());
                for(int i=0;i<da.size();i+=2){
                    if(2*swpr<std::min(da[i],db[i]))
                        ans=ans+(2*swpr);
                    else
                        ans=ans+std::min(da[i],db[i]);
                    
                }
                printf("%d\n",ans);
            }
        
            
        }
        /*print(a);
        print(b);
        print(da);
        print(db);
        print(unda);
        print(undb);*/
    }
    return 0;
}