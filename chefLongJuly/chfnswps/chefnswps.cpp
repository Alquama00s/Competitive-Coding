#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
//v2
using namespace std;
vector<int> intInput(int n)
{
    vector<int> a;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    return a;
}
void remove(int k,vector<int>& b)
{ 
    for(int i=0;i<b.size();i++){
    if(b[i]==k){
        b.erase(b.begin()+i);
        break;
    }
}
}
vector<int> und,fre;
void Frequency(vector<int> vec) 
{ und.clear();
fre.clear();
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
    for (auto& it:M) { 
        fre.push_back(it.second); 
    } 
}  
void print(vector<int> a){
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{
    vector<int> a, b, ca, cb, da, db, unda, undb;
    int t, n, ads, bds;
    bool cant;
    vector<int>::iterator ip;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n;
        a.clear();
        b.clear();
        da.clear();
        //da.resize(n);
        db.clear();
        //db.resize(n);
        a=intInput(n);
        b=intInput(n);
        //int temp;
        //temp=a.at(0);
        //cout<<temp;
        da=a;
        db=b;
        /*for(auto i=a.begin();i!=a.end();++i)
        da.push_back(*i);
        for(auto i=b.begin();i!=b.end();++i)
        db.push_back(*i);*/
        //cout<<"dg";
        for(int i=0;i<n;i++){
            remove(a[i],db);
            remove(b[i],da);
        }
        Frequency(da);
        unda=und;
        ca=fre;
        Frequency(db);
        undb=und;
        cb=fre;
        
        /*unda=da;
        undb=db;
        ip = std::unique(unda.begin(), unda.begin() + unda.size()); 
        ip = std::unique(undb.begin(), undb.begin() + undb.size()); 
        unda.resize(std::distance(unda.begin(), ip));
        undb.resize(std::distance(undb.begin(), ip));*/
        //ca.clear();
        //cb.clear()
        //ca=Frequency(a);
        //cb=Frequency(b);
        cant=false;
        ads=0;
        for(int i=0;i<ca.size();i++){
            if(ca[i]%2!=0){
                cant=true;
                break;
            }else{
                ads=ads+ca[i];
            }
        }
        bds=0;
        for(int i=0;i<cb.size();i++){
            if(cb[i]%2!=0 || cant==true){
                cant=true;
                break;
            }else{
                bds=bds+cb[i];
            }
        }
        if(da.size()+db.size()==0)
            cout<<0<<"\n";
        else if(cant==true)
            cout<<-1<<"\n";
        else{
            if(ads!=bds)
                cout<<-1<<"\n";
            else{
                int ans=0;
                int swpr;
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
                swpr=std::min(a[0],b[0]);
                sort(da.begin(),da.end());
                sort(db.begin(),db.end(),greater<int>());
                for(int i=0;i<da.size();i+=2){
                    if(2*swpr<std::min(da[i],db[i]))
                        ans=ans+(2*swpr);
                    else
                        ans=ans+std::min(da[i],db[i]);
                    
                }
                cout<<ans<<"\n";
            }
        
            
        }
        /*print(a);
        print(b);
        print(da);
        print(db);
        print(unda);
        print(undb);
        print(ca);
        print(cb);*/
    }
    return 0;
}