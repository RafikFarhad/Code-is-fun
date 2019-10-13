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

int main() {
    ios_base::sync_with_stdio(false);
#ifdef RAFIK_FARHAD
    freopen("../000.txt", "r", stdin);
    freopen("../111.txt", "w", stdout);
    clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, j, k, keis(0), l, t, x, y, z;
    ll ar[200005], br[200005];
    ll sum, a, b, gcd;
    int n;
    while (cin >> n) {
        a = -1;
        for (i = 0; i < n; ++i) {
            take(ar[i]);
            a = max(a, ar[i]);
        }
        l = 0;
        sum = 0;
        for (i = 0; i < n; ++i) {
            if (a - ar[i]) {
                br[l++] = a - ar[i];
                sum += br[l-1];
            }
        }
        gcd = br[0];
        for (i = 1;  i<l ; i++) {
            gcd = __gcd(gcd, br[i]);
        }
        deb(sum/gcd, gcd);

    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifdef RAFIK_FARHAD
    fprintf(stderr, "\n\nTime Elapsed: %lu MS\n", (clock() - ooo));
#endif
    return 0;
}
