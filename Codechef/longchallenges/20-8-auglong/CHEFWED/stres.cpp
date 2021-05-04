#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
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
long long inefficS=0,inefficL=0;
vector<int> family;
template<typename K, typename V>
void print_map(std::unordered_map<K,V> const &m)
{
	for (auto const& pair: m) {
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
}
//-------------------------------------lower-------------------------------------
class tableL{
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
        int result=0;
        tableL new_main,orig_table;
        orig_table.map=map;
        orig_table.in_ineff=in_ineff;
            new_main.add(a,index);
            int in=index-1;
            //cout<<in<<" index\n";
            while(new_main.map.find(f[in])==new_main.map.end()){
                //cout<<family[in]<<" :t\n";
                orig_table.transfer(f[in],new_main,in);
                in--;}
            result+=orig_table.in_ineff;
            result+=new_main.in_ineff;
            //cout<<result<<" :redcheck\n";
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
        return temp;
    }
    void transfer(int f,tableL &t,int index){
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
void redistL(int start,int end,tableL &in,tableL &fin){
    //cout<<start<<" "<<end<<" redist\n";
    for(int i=start;i<end;i++){
        //cout<<i<<" redist no\n";
        in.transfer(family[i],fin,i);
    }
}
void insertL(int f,vector<tableL> &t,int cost,int index){
    if(t.size()==0){
        tableL main;
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
            //print_map(t[last].map);
            //cout<<"redestributimg...\n";
            tableL new_main;
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
void fin_redist(vector<tableL> &t,vector<int> f){
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
//-------------------------------------super-------------------------------------
class tableS{
    public:
    unordered_map<int,int> map;
    int in_ineff=0;
    void add(int a){
        unordered_map<int,int>::iterator it;
        it=map.find(a);
        if(it!=map.end()){
            if(it->second==1)
                in_ineff++;
            it->second++;
            in_ineff++;}
        else
            map[a]=1;
    }
    int red_check(int a){
        int temp=in_ineff;
        int counter;
        unordered_map<int,int>::iterator it;
        for(it=map.begin();it!=map.end();it++){
            if(it->first!=a){
                if(it->second>1){
                    temp--;
                    if(it->second==1)
                        temp--;
                }
            }
        }
        return temp;
    
    }
    int check(int a){
        int temp=in_ineff;
        unordered_map<int,int>::iterator it;
        it=map.find(a);
        if(it!=map.end()){
            if(it->second==1)
                temp++;
            temp++;}
        return temp;
    }
    void transfer(int f,tableS &t){
        unordered_map<int,int>::iterator it;
        it=map.find(f);
        if(it!=map.end()){
            if(it->second>1){
                it->second--;
                t.add(f);
            if(it->second==1){
                in_ineff-=2;
            }
            else if(in_ineff!=0)
                in_ineff--;
            }
            
        }
    }
};
void redistS(int start,int end,tableS &in,tableS &fin){
    //cout<<start<<" "<<end<<" redist\n";
    for(int i=start;i<=end;i++){
        //cout<<i<<" redist no\n";
        in.transfer(family[i],fin);
    }
}
void insertS(int f,vector<tableS> &t,int cost,int index){
    if(t.size()==0){
        tableS main;
        main.add(f);
        t.push_back(main);
        return;
    }
    int last=t.size()-1;
    if(t[last].map.find(f)==t[last].map.end()){
        t[last].add(f);
        return;
    }else{
        if(t[last].check(f)<=cost){
            t[last].add(f);
            return;
        }else{
            if(t[last].red_check(f)+cost>t[last].check(f)){
                t[last].add(f);
                return;
            }
            tableS new_main;
            new_main.add(f);
            int in,fin=0;
            for(int i=0;i<=index;i++){
                if(t[last].map[family[i]]>1){
                    in=i;
                    break;
                }
            }
           /* for(int i=0;i<=index;i++){
                if(t[last].map[family[i]]>=t[last].map[family[fin]]){
                    fin=i;
                }
            }*/
            redistS(in,index,t[last],new_main);
            t.push_back(new_main);
        }
    }

}
int main(){
    //std::ios::sync_with_stdio(false);
    int t,n,k,temp;
    vector<tableS> Stables;
    vector<tableL> Ltables;
    //cin>>t;
    redirector r;
    r.redirect("cout.txt");
    //cout<<"inputs: \n";
    //t=rand()%10;
    //cout<<t<<" :t\n";
    cout<<"-----------------------------\n";
    t=1;
    while(true){
        //cin>>n>>k;
        n=rand()%10+1;
        k=rand()%1000+1;
        //n=31;
        //k=6;
        cout<<t<<": inputs: \n";
        t++;
        cout<<n<<" "<<k<<" :n k\n";
        family.clear();
        Stables.clear();
        Ltables.clear();
        family.reserve(n);
        for(int i=0;i<n;i++){
            //cin>>temp;
            temp=rand()%100+1;
            cout<<temp<<" ";
            family.push_back(temp);
        }
        //family.clear();
        //family={8 ,18 ,2 ,7 ,7 ,1 ,12 ,16 ,10 ,14 ,9 ,4, 16, 10, 13, 16, 12, 14, 5, 8, 8, 11, 12, 11, 14, 19, 18, 2, 4, 15, 12};
       /* for(int i=0;i<n;i++){
            //cin>>temp;
           // temp=rand()%20+1;
            cout<<family[i]<<" ";
            //family.push_back(temp);
        }*/
        cout<<" :family\n";
        //inputdone
        for(int i=0;i<family.size();i++){
            insertS(family[i],Stables,k,i);
        }
        inefficS=0;
        cout<<"-----superior-----\n";
        for(int i=0;i<Stables.size();i++){
            print_map(Stables[i].map);
            cout<<Stables[i].in_ineff<<" :end\n";
            inefficS+=Stables[i].in_ineff;
        }
        //cout<<"\n";
        inefficS+=Stables.size()*k;
        cout<<inefficS<<" :supirior\n";
        //--------lower
        for(int i=0;i<family.size();i++){
            insertL(family[i],Ltables,k,i);
        }
        fin_redist(Ltables,family);
        inefficL=0;
        cout<<"-----Lower------\n";
        for(int i=0;i<Ltables.size();i++){
            print_map(Ltables[i].map);
            cout<<Ltables[i].in_ineff<<" :end\n";
            cout<<Ltables[i].last_index<<" :index\n";
            inefficL+=Ltables[i].in_ineff;
        }
        //cout<<"\n";
        inefficL+=Ltables.size()*k;
        cout<<inefficL<<" :Lower\n";
        if(inefficL>inefficS){
            cout<<"---------**alert!!**--------------\n";
            cout<<inefficL<<" "<<inefficS<<" :lower super\n";
            break;
        }
        cout<<"--------------------------------------------------\n";
    }

    r.shell_direct();
    return 0;
}