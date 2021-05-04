#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
int main(){
    int t,n,k,temp,res;
    vector<int> p;
    scanf("%d",&t);
    while(t-->0){
        scanf("%d%d",&n,&k);
        p.clear();
        p.reserve(n);
        res=-1;
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            p.push_back(temp);
        }
        for(int i=0;i<n;i++){
            //std::cout<<p[i]<<" "<<k<<" "<<res<<'\n';
            if(((std::max(p[i],k))%(std::min(k,p[i])))==0){
                if((std::max(res,k)/std::min(res,k))>(std::max(p[i],k)/std::min(k,p[i]))||res<0){
                    res=p[i];}
            }
        }
        printf("%d\n",res);
    }
    return 0;
}