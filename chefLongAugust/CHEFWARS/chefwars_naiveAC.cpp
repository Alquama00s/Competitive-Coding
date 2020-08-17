#include<iostream>
#include<math.h>
using namespace std;
int main(){
int t;
int p,h,n;
scanf("%d",&t);
while (t-->0)
{scanf("%d%d",&h,&p);
    while(p>0&&h>0){
        h=h-p;
        if(h<=0 || p<=0)
        {//cout<<h<<" "<<p<<"\n";
                break;}
        p=floor((double)p/2);
        
    }
    if(p>0)
        printf("1\n");
    else
        printf("0\n");
}

return 0;
}