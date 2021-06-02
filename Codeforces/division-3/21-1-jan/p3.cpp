#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t,n,temp,res,j;
    vector<int> a;
    cin>>t;
    while (t-->0)
    {   res=0;
        cin>>n;
        a.clear();
        for (size_t i = 0; i < n; i++)
        {
            cin>>temp;
            a.push_back(temp);
        }
        for (size_t i = 0; i < n; i++)
        {   temp=0;
            j=i;
            while (j<a.size())
            {
                temp+=a[j];
                j+=a[j];
            }
            if(res<temp){
                res=temp;
            }
            
        }
        cout<<res<<"\n";
        
    }
    
    return 0;
}