#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b||a==c||b==c){
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }
    
    return 0;
}