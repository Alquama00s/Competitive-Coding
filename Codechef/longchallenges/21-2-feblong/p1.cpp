#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i = 10; i >= 1; i--)
    {
        if(n%i==0){
            cout<<i<<"\n";
            break;
        }
    }
    
    return 0;
}