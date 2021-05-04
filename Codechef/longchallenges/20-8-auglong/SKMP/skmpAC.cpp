#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<set>
//using std::string;

using namespace std;
void _erase(char c, multiset<char> &al){
    auto itra = al.find(c);
if(itra!=al.end()){
    al.erase(itra);
}
}
multiset<char> multi_conv(string sal){
      multiset<char> al;
    for(int i=0;i<sal.length();i++){
        al.insert(sal[i]);}
        return al;
}
void func(multiset<char> &s,string p){
    for(int i=0;i<p.length();i++){
    _erase(p[i],s);
    }

}    
void print(multiset<char> m,string p){
    string alpha="abcdefghijklmnopqrstuvwxyz";
    unordered_map<char,int> ualpha;
    for(int i=0;i<alpha.length();i++){
        ualpha[alpha[i]]=i;
    }
    char key=p[0];
    int i=0;
    while(p[i]==key&&i<p.length()){
        i++;
    }
    multiset<char>::iterator up=m.upper_bound(key);
    multiset<char>::iterator lo=m.lower_bound(key);
    multiset<char>::iterator it;
    if(ualpha[p[i]]<=ualpha[key]){
        
        for(it=m.begin();it!=lo;it++){
            cout<<*it;
        }
        cout<<p;
        for(it=lo;it!=m.end();it++){
            cout<<*it;
        }
    }
    else if(ualpha[p[i]]>ualpha[key]){
        for(it=m.begin();it!=up;it++){
            cout<<*it;
        }
        cout<<p;
        for(it=up;it!=m.end();it++){
            cout<<*it;
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
     
    //string alpha="abcdefghijklmnopqrstuvwxyz";
    int t;
    string s,p;
    multiset<char> ms,mp;
    cin>>t;
    while(t-->0){
    cin>>s>>p;
    ms=multi_conv(s);
    //cout<<"here"<<"\n";
    //cout<<s<<" "<<s[0]<<"\n";
    //cout<<p<<"\n";
    //cout<<s<<"\n";
    func(ms,p);
    print(ms,p);
    cout<<"\n";
    //cout<<insert(s,p)<<"\n";
    } 
       
}