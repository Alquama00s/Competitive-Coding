#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, q, temp, type, a, b, mx,si,ei;
long long ans;
vector<int> h, t,ind;
int count(int k){
    int temp=0;
    for(int i=si;i<=ei;i++){
        if(h[i]==k){
            temp++;
        }
    }
    return temp;
}
int max_search()
{
    int max = h[a-1];
        for (int i = si; i <= ei; i++)
        {
            if (h[i] > max)
                max = h[i];
        }
    return max;
}
void print(vector<int> a){
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}
void index(int minh)
{       ind.clear();
        for (int i = si+1; i < ei; i++)
        {
            if (h[i]>minh)
                ind.push_back(i);
        }
}

int main()
{
    scanf("%d", &n);
    cin >> ws;
    scanf("%d", &q);
    cin >> ws;
    h.clear();
    h.reserve(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        h.push_back(temp);
    }
    cin >> ws;
    t.clear();
    t.reserve(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        t.push_back(temp);
    }
    while (q-- > 0)
    {   cin>>ws;
        scanf("%d%d%d", &type, &a, &b);
        if(a>b){
            si=b-1;
            ei=a-1;
        }else{
            si=a-1;
            ei=b-1;
        }
        if (type == 2)
        {   if(h[a-1]<=h[b-1])
                ans=-1;
            else{
            mx = max_search();
            if (mx == h[a - 1]&&count(mx)==1){
                ans=0;
                index(h[b-1]);
                for(int i=0;i<ind.size();i++){
                    ans=ans+t[ind[i]];
                }
                ans=ans+t[si];
                ans=ans+t[ei];
            }else
                ans= -1;
            }
            printf("%lld\n",ans);
        }else{
            t[a-1]=b;
        }
    }
}