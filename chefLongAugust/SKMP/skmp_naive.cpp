#include<iostream>
#include<string>
#include<bits/stdc++.h>
//using std::string;

using namespace std;
int find(string s,char key){
    for(int i=0;i<s.length();i++){
        if(key==(s[i])){
            return i;
        }
    }

}
void func(string &s,string p){
    for(int i=0;i<p.length();i++){
    int k=find(s,p[i]);
    s.erase(k,1);
    }

}
string insert(string s,string p){
    string alpha="abcdefghijklmnopqrstuvwxyz";
    string res="";
    while(s.length()>0){
        if(find(alpha,p[0])<find(alpha,s[0])){
            res=res+p;
            p.erase();
            res=res+s;
            s.erase();
            return res;
        }else if(find(alpha,p[0])==find(alpha,s[0])){
            char ref=p[0];
            int i=0;
            while(p[i]==ref||i>p.length()-1){
                i++;
            }
            if(i==p.length()){
                res=res+p;
                p.erase();
                res=res+s;
                s.erase();
                return res;
            }
            if(find(alpha,p[i])<find(alpha,s[0])){
            res=res+p;
            p.erase();
            res=res+s;
            s.erase();
            return res;}
            else{
                while (s[0]==ref||s.length()==0)
                {
                    res=res+s[0];
                    s.erase(0,1);
                }
                res=res+p;
                p.erase();
                res=res+s;
                s.erase();
                return res;
            }
        }
        res=res+s[0];
        s.erase(0,1);
        //cout<<s.length()<<"\n";
    }
    res=res+p;
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
     
    //string alpha="abcdefghijklmnopqrstuvwxyz";
    int t;
    string s,p;
    cin>>t;
    while(t-->0){
    cin>>s>>p;
    //cout<<"here"<<"\n";
    //cout<<s<<" "<<s[0]<<"\n";
    //cout<<p<<"\n";
    sort(s.begin(),s.end());
    //cout<<s<<"\n";
    
    func(s,p);
    
    cout<<insert(s,p)<<"\n";
    } 
       
}