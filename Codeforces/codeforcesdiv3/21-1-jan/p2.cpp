#include<iostream>
using namespace std;
int main(){
    int t,n,temp,one,two;
    cin>>t;
    while (t-->0)
    {   one=0;
        two=0;
        cin>>n;
        for (size_t i = 0; i < n; i++)
        {
            cin>>temp;
            if(temp==1){
                one++;
            }else
            {
                two++;
            }
            
        }
        if(one==0){
            if(two%2==0){
                cout<<"YES\n";
            }else{
              cout<<"NO\n";  
            }
        }
        else if(one%2!=0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
        
    }
    
    return 0;
}