#include<iostream>
#include<set>
//#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int t,n,res;
    //vector<int> data;
    set<int> d;
    set<int>::iterator it;
    cin>>t;
    while (t-->0)
    {
        cin>>n;
        //data.clear();
        d.clear();
        for(int i=0;i<n;i++){
            cin>>res;
            //data.push_back(res);
            d.insert(res);
        }
        d.erase(0);
        //input
        // res=0;
        // while (d.size()>1)
        // {   it=d.begin();
        //     it++;
        //     large=*(it);
            
            
        // }
        cout<<d.size()<<"\n";
    }
    
    return 0;
}