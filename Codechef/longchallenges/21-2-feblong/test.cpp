#include<iostream>
#include<string>
using namespace std;
class time{
string T;
string mer;
public:
int conv(){
    int min;
    int h=stoi(T.substr(0,2));
    int m=stoi(T.substr(3,2));
    if(h==12){
        h=0;
    }
    if(mer=="AM"){
        min=h*60+m;
    }else{
        min=(h+12)*60+m;
    }
    return min;
}
void input(){
    cin>>T>>mer;
}
};
int main(){
    time x;
    x.input();
    cout<<x.conv()<<"\n";
}