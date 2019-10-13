#include <bits/stdc++.h>

#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define take(var) cin >> var
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define pb push_back
#define mp make_pair
#define ppp system("pause")
#define ok cout << "OKA" << endl;
#define pf printf
#define NL cout << endl;
#define PI 2 * acos(0)
#define all(o) o.begin(), o.end()
#define csi pf("Case %d: ", ++keis)
#define csii pf("Case %d:\n", ++keis)
#define _(o) pf("%d\n", o)
#define ll long long
#define ull unsigned long long
#define exx 2.7182818284590452353602875
#define xx first
#define yy second

///Helper
using namespace std;

template<class T1>
void __(T1 p) { cout << p << endl; }

void deb() {
    cout << endl;
}

template<typename T, typename... T1>
void deb(T s, T1... ts) {
    return (cout << s << " "), deb(ts...);
}

long int PowerUp(long long b, long long p) {
    if (p == 0) {
        return 1;
    }
    return b * PowerUp(b, p - 1);
}

int SET(int mask, int pos) { return mask | (1 << pos); }

bool CHK(int mask, int pos) { return (1 & (mask >> pos)); }

const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1}; // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1 << 31) - 1
#define MX
#define MOD
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

vector<pair<int, int> > GetIntersection(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    int dy = min(max(a.yy, c.yy), max(b.yy, d.yy));
    int uy = max(min(a.yy, c.yy), min(b.yy, d.yy));

    int lx = min(max(a.xx, c.xx), max(b.xx, d.xx));
    int rx = max(min(a.xx, c.xx), min(b.xx, d.xx));

    if (lx >= rx || dy >= uy) {
        return vector<pair<int, int>>{{0, 0},
                                      {0, 0}};
    }
    return vector<pair<int, int>>{{lx, dy},
                                  {rx, uy}};
}

ll GetArea(pair<int, int> a, pair<int, int> b) {
    return 1ll * (b.xx - a.xx) * (b.yy - a.yy);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifdef RAFIK_FARHAD
    freopen("../000.txt", "r", stdin);
    freopen("../111.txt", "w", stdout);
    clock_t ooo = clock();
#endif
    ///                                    MAIN
    int keis(0), l, t, x, y, z;
    pair<int, int> ar[10];
    while (cin >> ar[0].xx >> ar[0].yy >> ar[1].xx >> ar[1].yy >> ar[2].xx >> ar[2].yy >> ar[3].xx >> ar[3].yy
               >> ar[4].xx >> ar[4].yy >> ar[5].xx >> ar[5].yy) {
        auto common1 = GetIntersection(ar[0], ar[1], ar[2], ar[3]);
        auto common2 = GetIntersection(ar[0], ar[1], ar[4], ar[5]);
        ll totalArea = GetArea(ar[0], ar[1]);
        ll area1 = GetArea(common1[0], common1[1]);
        ll area2 = GetArea(common2[0], common2[1]);
        auto interSection = GetIntersection(common1[0], common1[1], common2[0], common2[1]);
        ll interArea = GetArea(interSection[0], interSection[1]);
        if (totalArea - area1 - area2 + interArea > 0) {
            deb("YES");
        } else {
            deb("No");
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifdef RAFIK_FARHAD
    fprintf(stderr, "\n\nTime Elapsed: %lu MS\n", (clock() - ooo));
#endif
    return 0;
}
