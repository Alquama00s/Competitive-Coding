#include <iostream>
#include <vector>
using namespace std;
class time {
    string T;
    string mer;
    int conv() {
        int min;
        int h = stoi(T.substr(0, 2));
        int m = stoi(T.substr(3, 2));
        if (h == 12) {
            h = 0;
        }
        if (mer == "AM") {
            min = h * 60 + m;
        } else {
            min = (h + 12) * 60 + m;
        }
        return min;
    }

   public:
    int input() {
        clear();
        cin >> T >> mer;
        return conv();
    }
    void clear(){
        T="";
        mer="";
    }
};
int main() {
    class time x;
    int n, t, ref, st, en;
    cin >> t;
    while (t-- > 0) {
        ref = x.input();
        cin >> n;
        for (size_t i = 0; i < n; i++) {
            st = x.input();
            en = x.input();
            if (ref >= st && ref<=en) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout<<"\n";
    }
}