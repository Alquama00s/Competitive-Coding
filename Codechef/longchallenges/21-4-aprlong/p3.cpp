#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,k,t,count;
    string given, match;
    cin>>t;
    while (t-->0)
    {   count=0;
        cin>>n>>k;
        cin>>given;
        for (size_t i = 0; i < given.size(); i++)
        {
            if(given[i]=='*'){
                count++;
                if(count>=k){
                    cout<<"yes\n";
                    count=-1;
                    break;
                }
            }else{
                count=0;
            }
        }
        if(count!=-1){
            cout<<"no\n";
        }
        
    }
    
    return 0;
}