#include<iostream>
#include<math.h>
int main(){
int t;
int p,h,n;
scanf("%d",&t);
while (t-->0)
{scanf("%d%d",&h,&p);
    n=(h-(h%p))/p;
    h=h-n*p;
    p=ceil(p/(pow(2,n)));
    if(p>=h)
        printf("1\n");
    else
        printf("0\n");
}

return 0;
}