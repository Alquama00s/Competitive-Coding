#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t,n,k,x,y,c;
    vector<pair<int,int>> points;
    cin>>t;
    while (t-->0)
    {   points.clear();
        cin>>n>>k>>x>>y;
        c=y-x;
        if(c==0){
            points.push_back(make_pair(n,n));
            k=0;
        }else if(c>0){
            points.push_back(make_pair(0,c));
            points.push_back(make_pair(n-c,n));
            points.push_back(make_pair(n,n-c));
            points.push_back(make_pair(c,0));
            k=k%4;
        }else{
            points.push_back(make_pair(-c,0));
            points.push_back(make_pair(n,n+c));
            points.push_back(make_pair(n+c,n));
            points.push_back(make_pair(0,-c));
            k=k%4;
        }
        cout<<points[k].first<<" "<<points[k].second<<"\n";
    }
    
    return 0;
}