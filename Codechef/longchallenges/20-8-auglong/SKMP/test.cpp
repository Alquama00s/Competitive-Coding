#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<unordered_map>
#include<set>
#include<chrono>
using namespace std;
using namespace std::chrono;
string a(){
    int a=10;
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
string string_conv(multiset<char> al){
      string sal="";
      multiset <char> :: iterator itr;
    for (itr = al.begin(); itr != al.end(); ++itr) 
    { 
        sal=sal+*itr;
    } 
        return sal;
}
int main(){
    string alpha="abcdefghijklmnopqrstuvwxyz";
    string sal="abbbbcde";
    //sal=randstr(100000,alpha);
    multiset<char> al;
    al=multi_conv(sal);
    multiset<char>::iterator up=al.upper_bound('b');
    cout<<*up<<"\n";
    multiset<char>::iterator lo=al.lower_bound('b');
    lo--;
    cout<<*lo;
  


}