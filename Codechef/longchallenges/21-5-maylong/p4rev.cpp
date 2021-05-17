#include <math.h>
#include "debug.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    int t, x, o, winx, wino;
    vector<string> data(3, "");
    vector<int> cnt;
    string temp;
    cin >> t;
    while (t-- > 0) {
        /* code */
        // d1 = d2 = 0;
        cin >> data[0] >> data[1] >> data[2];
        temp = data[0] + data[1] + data[2];
        x = count(temp.begin(), temp.end(), 'X');
        o = count(temp.begin(), temp.end(), 'O');
        if (abs(x - o) == 1 || abs(x - o) == 0) {
            cnt = vector<int>(8, 0);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (data[i][j] == 'X') {
                        cnt[i]++;
                        cnt[j + 3]++;
                        if (i == j) cnt[6]++;
                        if (i + j == 2) cnt[7]++;
                    } else if (data[i][j] == 'O') {
                        cnt[i]--;
                        cnt[j + 3]--;
                        if (i == j) cnt[6]--;
                        if (i + j == 2) cnt[7]--;
                    }
                }
            }
            winx = count(cnt.begin(), cnt.end(), 3);
            wino = count(cnt.begin(), cnt.end(), -3);
            cout<<wino<<" "<<winx<<"\n";
            if ((winx > 0 && wino > 0)||(winx > 0 && abs(x-o)!=1)|| (wino > 0 && abs(x-o)!=0)) {
                cout << "3\n";
            } else if (winx > 0 || wino > 0 || x + o == 9) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }

        } else {
            cout << "3\n";
        }
        print(cnt);
    }

    return 0;
}
/*
3
XOX
XXO
O_O
XXX
OOO
___
XOX
OX_
XO_
2
3
1
*/