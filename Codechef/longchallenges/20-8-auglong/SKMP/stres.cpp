#include<iostream>
#include<string>
#include<bits/stdc++.h>
//using std::string;
using namespace std;
class redirector{
streambuf* out;
fstream file;
public: 
void redirect(string a){
    file.open(a, ios::out); 
    string line;  
    out = cout.rdbuf(); 
    streambuf* stream_buffer_file = file.rdbuf(); 
    cout.rdbuf(stream_buffer_file);
}
void shell_direct(){
    cout.rdbuf(out); 
    cout << "redirected to shell\ndone" << endl; 
    file.close();
}
};
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
        }
        res=res+s[0];
        s.erase(0,1);
    }
    res=res+p;
    return res;
}
string randstr(int n,string ref){
    int temp;
    string st="";
    for(int i=0;i<n;i++){
        temp=rand()%ref.size();
        st=st+ref[temp];
    }
    return st;
}
string randstrun(int n,string &ref){
    int temp;
    string st="";
    for(int i=0;i<n;i++){
        temp=rand()%ref.size();
        st=st+ref[temp];
        ref.erase(temp,1);
        //cout<<ref<<"* *"<<st<<"\n";
    }
    return st;
}
int main(){
    std::ios::sync_with_stdio(false);
    redirector r;
    r.redirect("cout.txt");
    string alpha="abcdefghijklmnopqrstuvwxyz";
    int t;
    string s,p,test,result,beta;
    cin>>t;
    while(t-->0){
    cout<<t<<"------------------\n";
    //cin>>s>>p;
    s=randstr(1000,alpha);
    test=s;
    beta=s;
    p=randstrun(100,beta);
    cout<<s<<" :#string\n";
    cout<<p<<" :#pattern\n";
    sort(s.begin(),s.end());
    func(s,p);
    result=insert(s,p);
    cout<<insert(s,p)<<" :#answer\n";
    cout<<"--report--\n";
    sort(test.begin(),test.end());
    cout<<test<<" :#orignal sorted\n";
    sort(result.begin(),result.end());
    cout<<result<<" :#result sorted\n";
    if(test!=result)
        cout<<"*****false******\n";

    }   
    r.shell_direct();
}