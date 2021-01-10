/**
 * Author    : De_La_Grandi_Mephstophls
 * Time      : 2020-11-18 19:41:30
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, c0, c1, h, i, j, ans = 0;
        cin >> n >> c0 >> c1 >> h;
        string aa;
        cin >> aa;
        for(auto p:aa) {
            if(p == '0') {
                ans += min(c0, h+c1);
            } else {

                ans += min(c1, h+c0);}
        }
        cout << ans << endl;
    }


    return 0;
}
