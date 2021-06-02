#include <iostream>
using namespace std;
int main()
{
    int n, res, t, w, h;
    cin >> t;
    while (t-- > 0)
    {
        res = 1;
        cin >> w >> h >> n;
        while (w % 2 == 0 || h % 2 == 0)
        {
            if (w % 2 == 0 && h % 2 == 0)
            {
                res = 4 * res;
                w /= 2;
                h /= 2;
            }
            if (w % 2 == 0)
            {
                res = 2 * res;
                w /= 2;
            }
            if (h % 2 == 0)
            {
                res = 2 * res;
                h /= 2;
            }
            if(res>=n){
                break;
            }
        }
        if(res>=n){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}