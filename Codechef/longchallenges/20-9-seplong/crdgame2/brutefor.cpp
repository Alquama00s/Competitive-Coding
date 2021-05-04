#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#define ll unsigned long long
#define sll long long
using namespace std;
int main(){
    int t,n;
    vector<int> data,one,two;
    set<int> dat;
    set<int>::iterator it;
    sll all_comb;
    sll draw;
    int temp;
    cin>>t;
    while (t-->0)
    {
        cin>>n;
        data.clear();
        data.resize(n,0);
        for(int i=0;i<n;i++){
            cin>>data[i];
            dat.insert(data[i]);
        }
        //input
        all_comb=pow(2,data.size());
        one.clear();
        two.clear();
        for(int i=0;i<n;i++){
            one=data;
            two[i]=one[i];
            one[i]=-1;

        }
        draw=0;
        temp=1;
        for(it=dat.begin();it!=dat.end();it++){
            if(count(data.begin(),data.end(),*it)%2!=0){
                temp=0;
                break;
            }
        }
        if(temp==1){
            draw+=(2*(sll)dat.size());
        }
        cout<<all_comb-draw<<"\n";
    }
    return 0;
}