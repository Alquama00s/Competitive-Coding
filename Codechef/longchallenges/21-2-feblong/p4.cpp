#include <iostream>
#include <map>
#include<math.h>
#include<vector>
using namespace std;
void printMap(map<int,int> m){
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    cout<<'\n';
}
int main() {
    map<int, int> len, ind;
    vector<int> data;
    int t, n, temp,jump;
    cin >> t;
    while (t-- > 0) {
        jump=0;
        data.clear();
        len.clear();
        ind.clear();
        cin >> n;
        for (size_t i = 0; i < n; i++) {
            cin >> temp;
            data.push_back(temp);
            ind[temp] = i;
        }
        for (int i=0;i<n;i++) {
            cin>>temp;
            len[data[i]]=temp;
        }

        auto j =ind.begin();
        auto i =ind.begin();
        j++;
        for (;j!=ind.end();i++,j++)
        {
            if(j->second<i->second){
                temp=ceil(((double)(i->second+1-j->second)/len[j->first]));
                jump+=temp;
                j->second+=temp*len[j->first];
            }
        }
        cout<<jump<<"\n";
        printMap(ind);
    }

    return 0;
}