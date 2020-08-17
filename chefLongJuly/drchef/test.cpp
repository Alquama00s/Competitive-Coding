#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;
long long t,day,no,x;
vector<long long> pop;
//int i=0,f=pop.size()-1,mid=(i+f)/2;;
long long les_bin(long long x,int i,int f){
    int mid=(i+f)/2;
    if(f==i+1){ 
        if(x<std::min(pop[i],pop[f]))
            return std::min(pop[i],pop[f]);
        return std::max(pop[i],pop[f]);
    }
    else if(pop[mid]==x)
        return x;
    else if(pop[mid]<x){
        i=mid;
        return les_bin(x,i,f);
    }
    else{
        f=mid;
        return les_bin(x,i,f);
    }

}
void print(vector<long long> a){
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}
long long tday(long long affected)
{
    long long cure=0,day = 0,popul=affected;
    while (affected > 0)
    {       cure=x;
        if(cure>popul)
            cure=affected;
        affected = affected - x;
        x=2*cure;
        if(2*affected<popul)
            affected = 2 * affected;
        else
            affected=popul;
        day++;
    }
    return day;
}
long long ntday(long long affected)
{   if(x>=affected)
        return 1;
    if(x>=(affected/2))
        return 2;
    return (ceil(log((affected * 1.0)/(2*x))/log(2))+2);
}
int main(){
    scanf("%lld",&x);
    scanf("%d",&n);
    long long temp;
    //cin>>ws;
    /*for (int i = 0; i < n; i++)
    {
        scanf("%lld",&temp);
        pop.push_back(temp);
    }*/
    /*pop.push_back(1);
    pop.push_back(2);
    pop.push_back(3);
    pop.push_back(4);
    pop.push_back(5);
    pop.push_back(7);
    pop.push_back(9);
    pop.push_back(11);
    pop.push_back(14);
    pop.push_back(20);*/
    //print(pop);
    //cout<<mid;
    //no=les_bin(x,0,pop.size());
    day=ntday(n);
    printf("%lldnew\n",day);
    day=tday(n);
    printf("%lldold\n",day);
    //printf("%lld\n",no);
    printf("%lld\n",x);
    //printf("%lld\n",n);
    //printf("%lld\n",t);
}