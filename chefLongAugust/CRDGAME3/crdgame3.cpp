#include<iostream>
int main(){
    int t,pc,pr,nc,nr;
    scanf("%d",&t);
    while (t-->0)
    {
        scanf("%d%d",&pc,&pr);
        nc=0;
        nr=0;
        while (pc>0||pr>0)
        {if(pc>0){
            pc=pc-9;
          nc++;}
          if(pr>0){
          pr=pr-9;  
            nr++;}
            //std::cout<<pc<<" "<<nc<<" "<<pr<<' '<<nr<<"\n";
        }
        if(nc<nr){
            printf("%d %d\n",0,nc);
        }
        if(nr<=nc){
            printf("%d %d\n",1,nr);
        }
        
    }
    

    return 0;
}