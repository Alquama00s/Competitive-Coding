#include<iostream>
int digit(int sum){
    int x;
    x=(sum-(sum%9))/9;
    if(sum%9!=0)
        x++;
    return x;
}
int main(){
    int t,pc,pr,nr,nc;
    scanf("%d",&t);
    while (t-->0)
    {
        scanf("%d%d",&pc,&pr);
        nr=digit(pr);
        nc=digit(pc);
        if(nc<nr){
            printf("%d %d\n",0,nc);
        }
        else{
            printf("%d %d\n",1,nr);
        }
        
    }
    

    return 0;
}