#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main() {
    int t, x, y, count;
    vector<bool> check;
    cin >> t;
    while (t-- > 0) {
        count = 1;
        check.clear();
        cin >> x >> y;
        check = vector<bool>(x + 1, true);
        for (ll i = 2; i*i <= x && x-count>y; i++) {
            if (check[i]) {
                for (ll j = i * i; j <=x && x-count>y; j += i) {
                    if (check[j]) {
                        count++;
                        check[j] = false;
                    }
                }
            }
        }
        count=x-count;
        if(count<=y){
            cout<<"Chef\n";
        }else{
            cout<<"Divyam\n";
        }
    }
    return 0;
}