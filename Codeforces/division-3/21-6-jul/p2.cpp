#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    int t, r, c,g;
    string s;
    cin >> t;
    while (t-- > 0) {
        cin >> s;
        r = 0;
        c = 0;g=0;
        int arr[26] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            arr[s[i]-97]++;
            
        }
        for (int i = 0; i < 26; i++)
        {
            if(arr[i]==1){
                if(c<=0){
                    r++;
                    c++;
                }else{
                    g++;
                    c--;
                }
            }else if(arr[i]>=2){
                r++;
                g++;
            }
            
        }
        cout<<min(r,g)<<"\n";
    }
    return 0;
}