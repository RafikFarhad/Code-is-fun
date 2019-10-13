#include <bits/stdc++.h>

using namespace std;
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
#define NL printf("\n")
#define PI 2 * acos(0)
#define all(o) o.begin(), o.end()
#define csi pf("Case %d: ", ++keis)
#define csii pf("Case %d:\n", ++keis)
#define _(o) pf("%d\n", o)
#define exx 2.7182818284590452353602875
#define xx first
#define yy second
typedef long long ll;
typedef unsigned long long ull;
///Helper

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

ll SET(ll mask, int pos) { return mask | (1ll << pos); }

bool CHK(ll mask, int pos) { return (1ll & (mask >> pos)); }

const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1}; // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4

#define LT (1 << 31) - 1
#define MX 1e9
#define MOD (ll)(1e9+7)

ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {
    ll res = 1ll;
    while (power) {
        if (power & 1)res = (res * base) % MOD;
        base = (base * base) % MOD;
        power >>= 1;
    }
    return res % MOD;
}

int mem[200005], p[200005], h, n, on;

int Start(int now) {
    if (now == n) {
        return 0;
    }
    if (on - p[now] >= 2){
        on -= 2;
        return 1 + Start(now);
    }
    if (on - p[now] == 1){
        on -= 2;
        return 1 + Start(now);
    }
        return 5;
}


int main() {
    ios_base::sync_with_stdio(false);
#ifdef RAFIK_FARHAD
    freopen("../000.txt", "r", stdin);
    freopen("../111.txt", "w", stdout);
    clock_t ooo = clock();
#endif
    ///                                    MAIN
    ll a, b, c, d, i, j, k, keis(0), l, t, x, y, z;
    take(keis);
    while (keis--) {
        take(h);
        take(n);
        for (int i = 0; i < n; ++i) {
            take(p[i]);
            mem[i] = INT_MAX;
        }
        on = h;
        deb(Start(0));
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifdef RAFIK_FARHAD
    fprintf(stderr, "\n\nTime Elapsed: %lu MS\n", (clock() - ooo));
#endif
    return 0;
}
