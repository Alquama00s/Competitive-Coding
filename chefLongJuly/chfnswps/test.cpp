#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
#include <chrono> 
using namespace std;
using namespace std::chrono; 
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

    void print(vector<int> a){
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}
void remove(int k,vector<int>& b)
{for(int i=0;i<b.size();i++){
    //cout<<"here\n";
    if(b[i]==k){
        cout<<"yes!!\n";
        b.erase(b.begin()+i);
        break;
    }
    //return b;
}
}
vector<int> stInput(){
    vector<int> a;
    string temp="",mstr;
    cin>>ws;
    getline(cin,mstr);
    for(int i=0;i<mstr.size();i++){
        if(mstr[i]==' '){
            a.push_back(stoi(temp));
            temp="";
        }else{
            temp=temp+mstr[i];
        }
        
    }
    a.push_back(stoi(temp));
        return a;
}
vector<int> fstInput(){
    vector<int> a;
    string S, T; 
    getline(cin, S); 
    stringstream X(S); 
    while (getline(X, T, ' ')) { 
        a.push_back(stoi(T)); 
    } 
}
int main(){
    string temp;
    int n;
    vector<int> a,c,da,dc;
   /* for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }*/
    auto start = high_resolution_clock::now(); 
    getline(cin,temp);
    printf("%s",temp);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function:----------------------------- "
         << duration.count() << " microseconds" << endl; 
    /*c=intInput(2);
    da=a;
    dc=c;
    for(int i=0;i<2;i++){
            remove(a[i],dc);
            remove(c[i],da);
        }*/
    //a.push_back(2);
    //da.erase(da.begin()+1);
    //remove(1,da);
    print(a);
    /*print(c);
    print(da);
    print(dc);*/
}