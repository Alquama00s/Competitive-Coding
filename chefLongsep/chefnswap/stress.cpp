#include<iostream>
#include<ctime>
#include<math.h>
#define ll unsigned long long
using namespace std;
int check(int a,int b,ll half_sum,ll part_sum){
    //a is of fist partition
    //part_sum is of first partition
    if((part_sum-a+b)==half_sum)
        return 1;
    return 0;
}
int part(ll sum){
    ll l=1,r=sum/2+1;
    ll cs,mid;
    while (l<=r)
    {   mid=(l+r)/2;
        cs=mid*(mid+1)/2;
        if(cs==sum){
            return mid;
        }
        else if(cs>sum){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return mid;
}
int noswap(int i){
    float a,d;
    int b;
    d=sqrt(1+2*(i*i+i));
    a=(d-1)/2;
    b=a;
    if((b-a)==0){
        return b;
    }
    else
    {
        return -1;
    }
    
}
int main(){
    srand((unsigned)time(0));
    ios_base::sync_with_stdio(0);
    int t,n,part_index,res;
    ll hs,ps;
    //cin>>t;
    t=1;
    //n=1;
    n=1003;
    while (n<=2000)
    {   //cin>>n;
        
        //n=rand()%100+1;
        cout<<n<<" :data\n";
        res=0;
        hs=n*(n+1)/2;
        if(hs%2==0){
             if(noswap(n)>0){
                cout<<"here\n";
            part_index=noswap(n);
            res+=part_index*(part_index-1)/2;
            part_index=n-part_index;
            res+=part_index*(part_index-1)/2;
            }
            hs=hs/2;
            part_index=part(hs);
            cout<<part_index<<":pi\n";
            ps=part_index*(part_index-1)/2;
            // if(ps==hs){
            //     //cout<<"here";
            //     int a=part_index-1;
            //     res+=a*(a-1)/2;
            //     a=n-part_index+1;
            //     res+=a*(a-1)/2;
            //     //cout<<res<<"res\n";
            // }
            // if(n==hs){
            //     res++;
            // }
            res+=(n-part_index);
            int dif=hs-ps;
            if((part_index-dif)>0)
                res++;
            // for (int i = 1; i < part_index; i++)
            // {
            //     if(check(i,part_index,hs,ps)==1){
            //         res++;
            //         //break;
            //     }
            // }
            // if(n==3){
            //     res++;
            // }
            //res+=check(1,part_index,hs,ps);
            cout<<"----------------------------\n";
            //----
            // hs=hs/2;
            // part_index=part(hs);
            // cout<<part_index<<":pi\n";
            // ps=part_index*(part_index-1)/2;
            ps=part_index*(part_index+1)/2;
            int res2=0;
            if(ps==hs){
                //cout<<"here";
                int a=part_index;
                res2+=a*(a-1)/2;
                a=n-part_index;
                res2+=a*(a-1)/2;
                //cout<<res<<"res\n";
            }
            // if(n==hs){
            //     res2++;
            // }
            for(part_index=2;part_index<n;part_index++){
                ps=part_index*(part_index-1)/2;
                cout<<part_index<<" :pi\n";
            for(int i=part_index;i<=n;i++){
                for(int j=1;j<part_index;j++){
                    if(check(j,i,hs,ps)==1){
                    cout<<i<<" "<<j<<" :swap\n";
                    res2++;
                    }
                }
            }
            }
            cout<<res2<<":----- brute result\n";
            cout<<res<<"-------------: prev result\n";
            if(res!=res2){
                cout<<"alert\n";
                break;
            }

        }else
        {
            cout<<0<<"\n";
        }
        n++;
    }
    
    return 0;
}