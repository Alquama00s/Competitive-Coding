//v1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n,index;
long long day, no, x;
vector<long long> pop;
long long les_bin(long long x, int i, int f)
{
    int mid = (i + f) / 2;
    if (f == i + 1)
    {   index=i;
        return std::min(pop[i], pop[f]);
    }
    else if (pop[mid] == x)
        return x;
    else if (pop[mid] < x)
    {
        i = mid;
        return les_bin(x, i, f);
    }
    else
    {
        f = mid;
        return les_bin(x, i, f);
    }
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
void remove(long long k,vector<long long>& b)
{ 
    for(int i=0;i<b.size();i++){
    if(b[i]==k){
        b.erase(b.begin()+i);
        break;
    }
    }
}
void print(vector<long long> a){
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{int prex;
        long long tempd;
        long long temp;
    scanf("%lld", &t);
    while (t-- > 0)
    {
        scanf("%d", &n);
        cin>>ws;
        scanf("%d", &x);
        
        cin >> ws;
        pop.clear();
        pop.reserve(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &temp);
            pop.push_back(temp);
        }
        sort(pop.begin(),pop.end());
        day=0;
        
        start:
        if(pop[pop.size()-1]>x){
            no=les_bin(x,0,(pop.size()-1));
            st:
            prex=x;
            tempd=tday(no);
            if(prex>x){
                no=pop[index+1];
                x=prex;
                goto st;
            }else{
                day=day+tempd;
                remove(no,pop);
                goto start;
            }
        }else{
            day=day+pop.size();
        }
        printf("%lld\n",day);
    }
}