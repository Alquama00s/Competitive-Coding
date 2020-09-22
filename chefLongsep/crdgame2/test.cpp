#include<iostream>
#include<queue>
#define ll unsigned long long
#include<algorithm>
using namespace std;
void print(queue<int> a,queue<int> b){
    while (a.size()!=0||b.size()!=0)
    {
        if(a.size()!=0){
            cout<<a.front();
            a.pop();
        }else{
            cout<<" ";
        }
        cout<<" ";
        if(b.size()!=0){
            cout<<b.front();
            b.pop();
        }else{
            cout<<" ";
        }
        cout<<"\n";
    }
    cout<<"------------------------\n";
    
}
int main(){
    queue<int> one,two,t1,t2;
    int o,t,resp,resi;
    //cin>>t;
    int no=rand()%20+1;
    int f=no/2;
    no=no-f;
    t=100;
    while (t-->0)
    {   o=rand()%50+1;
        //cin>>o;
        one.push(o);
        cout<<o<<" ";
    }
    while (f-->0)
    {
        one.push(52);
        cout<<52<<" ";
    }cout<<"\n";
    t=100;
    //cin>>t;
    while (t-->0)
    {   o=rand()%50+1;
        //cin>>o;
        two.push(o);
        cout<<o<<" ";
    }
    while (no-->0)
    {
        two.push(52);
        cout<<52<<" ";
    }cout<<"\n";
    
    cout<<"------------------------\n";
    while (one.size()!=0&&two.size()!=0)
    {   t1=one;
        t2=two;
        o=one.front();
        one.pop();
        t=two.front();
        two.pop();
        if(o==t){
            one.push(o);
            two.push(o);
        }
        else if(o>t){
            t--;
            one.push(o);
            if(t>=0)
                one.push(t);
        }
        else{
            o--;
            two.push(t);
            if(o>=0)
                two.push(o);
        }
        print(one,two);
        if(one==two||(t1==one&&t2==two)){
            ll s1=0,s2=0;
            while (one.size()!=0)
            {
                s1+=one.front();
                one.pop();
            }
            while (two.size()!=0)
            {
                s2+=two.front();
                two.pop();
            }
            if(s1==s2){
                resp=0;
            cout<<"draw!\n";}
            else if(s1>s2){
                resp=1;
              cout<<"one wins!\n";  
            }
            else{
                resp=2;
              cout<<"two wins!\n";  
            }
            break;
        }
        
    }
    if((f+no)%2==0){
            if(resp!=0){
                cout<<"alert!\n";
            }
        }
    return 0;
}