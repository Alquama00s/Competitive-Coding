#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int main() {
    int t, count, res;
    string temp;
    map<string, set<string>> data, revdata;
    cin >> t;
    while (t-- > 0) {
        cin >> count;
        data.clear();
        revdata.clear();
        res = 0;
        for (size_t i = 0; i < count; i++) {
            cin >> temp;
            data[temp.substr(0, 1)].insert(temp.substr(1, temp.length() - 1));
            revdata[temp.substr(1, temp.length() - 1)].insert(
                temp.substr(0, 1));
        }
        auto i = data.begin();
        auto next = i;
        for (; i != data.end(); i++) {
            next++;
            for (auto j = next; j != data.end(); j++) {
                for (auto k : i->second) {
                    if (*(revdata[k].find(j->first)) != j->first) {
                        for (auto n : j->second) {
                            if (*(revdata[n].find(i->first)) != i->first) {
                                res +=2;
                            }
                        }
                    }
                }
            }
        }
        cout << res << "\n";
    }
}