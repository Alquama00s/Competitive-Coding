#include<iostream>
#include<vector>
using namespace std;
class city{
    public:
    int prev;
    int next;
    int pop;
    int fruit;
    int day;
    void eat(int citypop,int thatday){
        if(fruit==0)
            return;
        fruit-=min(citypop,fruit);
        if(fruit==0)
            day=thatday;
    }
    void print(){
        cout<<next<<" :next\n";
        cout<<pop<<" :pop\n";
        cout<<fruit<<" :fruit\n";
        cout<<prev<<" :prev\n";
        cout<<day<<" :day\n";
        cout<<"-----------------\n";
    }
};
void cutoff(vector<city> &data,int city){
    data[data[city-1].next].prev=-1;
    data[data[city-1].prev].next=-1;
    data[city-1].next=-1;
    data[city-1].prev=-1;
}
void oper(vector<city> &data,int city,int thatday){
    int ref=city-1;
    while(ref!=-1){
        data[ref].eat(data[city-1].pop,thatday);
        ref=data[ref].next;
    }
    ref=city-1;
    while(ref!=-1){
        data[ref].eat(data[city-1].pop,thatday);
        ref=data[ref].prev;
    }
    cutoff(data,city);
}
int main(){
    
    int t,n,u,v,i,temp;
    vector<int> perm;
    vector<city> data;
    cin>>t;
    while (t-->0)
    {
        cin>>n;
        data.reserve(n);
        for(i=0;i<n;i++){
            data[i].prev=-1;
            data[i].next=-1;
            data[i].day=-1;
        }
        for(i=1;i<n;i++){
            cin>>u>>v;
            u=u-1;
            v=v-1;
            if(data[u].next!=-1){
                temp=u;
                u=v;
                v=temp;
            }
            data[u].next=v;
            data[v].prev=u;
        }
        for(i=0;i<n;i++){
            cin>>temp;
            perm.push_back(temp);
        }
        for(i=0;i<n;i++){
            cin>>data[i].pop;
        }
        for(i=0;i<n;i++){
            cin>>data[i].fruit;
        }
        //input done
        /*for(int i=0;i<n;i++){
            data[i].print();
        }*/
        for(i=1;i<=n;i++){
            oper(data,perm[i-1],i);
            //cout<<i<<" after---------------------------------------------- :day\n";
            /*for(int i=0;i<n;i++){
            data[i].print();
        }*/
        }
        //output
        for(i=0;i<n;i++){
            cout<<data[i].day<<" ";
        }cout<<"\n";
    }
    
    return 0;
}