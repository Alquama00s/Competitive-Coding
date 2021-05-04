#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<bits/stdc++.h>
#include<ctime>
using namespace std;
long long ineffic=0;
class redirector{
streambuf* out;
fstream file;
public: 
void redirect(string a){
    file.open(a, ios::out); 
    string line;  
    out = cout.rdbuf(); 
    streambuf* stream_buffer_file = file.rdbuf(); 
    cout.rdbuf(stream_buffer_file);
}
void shell_direct(){
    cout.rdbuf(out); 
    cout << "redirected to shell\ndone" << endl; 
    file.close();
}
};
vector<int> family;
template<typename K, typename V>
void print_map(std::unordered_map<K,V> const &m)
{
	for (auto const& pair: m) {
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
}
class table{
    public:
    unordered_map<int,int> map;
    int in_ineff=0;
    int last_index=-1;
    void add(int a,int index){
        unordered_map<int,int>::iterator it;
        it=map.find(a);
        if(it!=map.end()){
            if(it->second==1)
                in_ineff++;
            it->second++;
            in_ineff++;}
        else
            map[a]=1;
        if(last_index>index||last_index==-1)
            last_index=index;
    }
    int red_check(int a,int index,vector<int> f){
        cout<<"------inside_redcheck---------\n";
        int result=0;
        table new_main,orig_table;
        orig_table.map=map;
        orig_table.in_ineff=in_ineff;
            new_main.add(a,index);
            int in=index-1;
            cout<<"before virtual redist\n";
            print_map(orig_table.map);
            cout<<orig_table.in_ineff<<"\n";
            print_map(new_main.map);
            cout<<new_main.in_ineff<<"\n";
            cout<<in<<" index from trans\n";
            while(new_main.map.find(f[in])==new_main.map.end()){
                cout<<f[in]<<" :ting\n";
                orig_table.transfer(f[in],new_main,in);
                print_map(orig_table.map);
                cout<<"----\n";
                print_map(new_main.map);
                cout<<"----\n";
                in--;}
            cout<<"after virtual redist\n";
            print_map(orig_table.map);
            cout<<orig_table.in_ineff<<"\n";
            print_map(new_main.map);
            cout<<new_main.in_ineff<<"\n";
            result+=orig_table.in_ineff;
            result+=new_main.in_ineff;
            cout<<result<<" :redcheck out!\n";
            return result;
    }
    int check(int a){
        int temp=in_ineff;
        unordered_map<int,int>::iterator it;
        it=map.find(a);
        if(it!=map.end()){
            if(it->second==1)
                temp++;
            temp++;}
        cout<<temp<<" :check\n";
        return temp;
    }
    void transfer(int f,table &t,int index){
        unordered_map<int,int>::iterator it;
        it=map.find(f);
        if(it!=map.end()&&in_ineff>0){
            if(it->second>0){
                it->second--;
                t.add(f,index);
            if(it->second!=0){
            if(it->second==1){
                in_ineff-=2;
            }
            else if(in_ineff!=0)
                in_ineff--;
            }}
            
        }
    }
};
void redist(int start,int end,table &in,table &fin){
    //cout<<start<<" "<<end<<" redist\n";
    for(int i=start;i<end;i++){
        //cout<<i<<" redist no\n";
        in.transfer(family[i],fin,i);
    }
}
void insert(int f,vector<table> &t,int cost,int index){
    if(t.size()==0){
        table main;
        main.add(f,index);
        t.push_back(main);
        return;
    }
    int last=t.size()-1;
    if(t[last].map.find(f)==t[last].map.end()){
        t[last].add(f,index);
        return;
    }else{
        if(t[last].check(f)<=cost){
            t[last].add(f,index);
            return;
        }else{
            if(t[last].red_check(f,index,family)+cost>t[last].check(f)){
                t[last].add(f,index);
                return;
            }
            print_map(t[last].map);
            cout<<"redestributing...\n";
            table new_main;
            new_main.add(f,index);
            int in=index-1;
            //cout<<in<<" index\n";
            while(t[last].map[family[in]]>1){
                //cout<<family[in]<<" :t\n";
                t[last].transfer(family[in],new_main,in);
                in--;}
            t.push_back(new_main);
        }
    }

}
void fin_redist(vector<table> &t,vector<int> f){
    int last=t.size()-1;
    while(last>0){
    int in=t[last].last_index-1;
    while(t[last].map.find(f[in])==t[last].map.end()){
        cout<<f[in]<<"transfering finally\n";
        t[last-1].transfer(f[in],t[last],in);
        in--;
    }
    last--;
    }
}
int merge_check(table last, table prev){
    int fin=prev.in_ineff;
    for(auto i:last.map){
        if(prev.map.find(i.first)==prev.map.end()||prev.map[i.first]==0){
            prev.map[i.first]=i.second;
                if(i.second!=1)
                    fin+=i.second;
        }else{
            if(prev.map[i.first]==1)
                fin++;
        prev.map[i.first]+=i.second;
        fin+=i.second;
        }
    }
    return fin;
}
void merge(vector<table> &t,int i){
    cout<<i<<" merging\n";
    vector<table>::iterator it;
    it=t.begin();
    for(auto j:t[i].map){
        if(t[i-1].map.find(j.first)==t[i-1].map.end()||t[i-1].map[j.first]==0){
            t[i-1].map[j.first]=j.second;
                if(j.second!=1)
                    t[i-1].in_ineff+=j.second;
        }else{
            if(t[i-1].map[j.first]==1)
                t[i-1].in_ineff++;
        t[i-1].map[j.first]+=j.second;
        t[i-1].in_ineff+=j.second;
        }
    }
    t.erase(it+i);
}
void fin_merge(vector<table> &t,int cost){
int i=0,j=1;
while(i<t.size()&&j<=t.size()-1){
    if(merge_check(t[j],t[i])<t[j].in_ineff+t[i].in_ineff+cost){
        merge(t,j);
        cout<<"----------after merge-------\n";
        for(int i=0;i<t.size();i++){
            print_map(t[i].map);
            cout<<t[i].in_ineff<<" :ineffic\n";
            cout<<t[i].last_index<<" :lastindex\n";
            //ineffic+=tables[i].in_ineff;
        }
    }else{
    i++;
    j++;}
}
}
bool mapcheck(unordered_map<int,int> m){
    if(m.empty())
        return true;
    for(auto i:m){
        if(i.second>0)
            return false;
    }
    return true;
}
int main(){
    //srand(time(NULL));
    std::ios::sync_with_stdio(false);
    int t=0,n,k,temp;
    vector<table> tables,tabmerge;
    //cin>>t;
    int i2;
    redirector r;
    r.redirect("cout2.txt");
    //std::cout.setstate(std::ios_base::failbit);
    while(true){
        //cin>>n>>k;
        
        n=rand()%10+1;
        k=rand()%50+1;
        //n=9;
        //k=2;
        t++;
        family.clear();
        tables.clear();
        family.reserve(n);
        //family={1,5,5,9,7,4,4,2,2};
        for(int i=0;i<n;i++){
            //cin>>temp;
            temp=rand()%100+1;
            family.push_back(temp);
            cout<<family[i]<<" ";
        }cout<<" :family\n";
        //inputdone
        for(int i=0;i<family.size();i++){
            cout<<i<<" "<<family[i]<<" :inserting\n";
            insert(family[i],tables,k,i);
        }
        fin_redist(tables,family);
        ineffic=0;
        for(int i=0;i<tables.size();i++){
            if(!mapcheck(tables[i].map))
                ineffic+=tables[i].in_ineff;
            else
            {
                tables.erase(tables.begin()+i);
            }
            
        }
        ineffic+=tables.size()*k;
        tabmerge=tables;
        fin_merge(tabmerge,k);
        i2=0;
        for(int i=0;i<tabmerge.size();i++){
            if(!mapcheck(tabmerge[i].map))
                i2+=tabmerge[i].in_ineff;
            else
            {
                tabmerge.erase(tabmerge.begin()+i);
            }
            
        }
        i2+=tabmerge.size()*k;
        if(i2!=ineffic){
             std::cout.clear();
            cout<<"------------------------inputs--------------\n";
            cout<<t<<" "<<n<<" "<<k<<" "<<" :t n k\n";
            for(int i=0;i<n;i++){
            //cin>>temp;
            //temp=rand()%100+1;
            //family.push_back(temp);
            cout<<family[i]<<" ";
        }cout<<" :family\n";
                    cout<<"---------------------------summary no merge-----------------\n";
        for(int i=0;i<tables.size();i++){
            print_map(tables[i].map);
            cout<<tables[i].in_ineff<<" :ineffic\n";
            cout<<tables[i].last_index<<" :lastindex\n";
        }
        cout<<"\n";
        cout<<ineffic<<"\n";
        cout<<"---------------------------summary merge-----------------\n";
        for(int i=0;i<tabmerge.size();i++){
            print_map(tabmerge[i].map);
            cout<<tabmerge[i].in_ineff<<" :ineffic\n";
            cout<<tabmerge[i].last_index<<" :lastindex\n";
        }
        cout<<"\n";
        cout<<i2<<" :merged\n";
            break;
        }
        //break;
    }
    r.shell_direct();
    return 0;
}