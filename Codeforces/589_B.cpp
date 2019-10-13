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

#define MOD 1000000007

void deb() {
    cout << endl;
}

template<typename T, typename... T1>
void deb(T s, T1... ts) {
    return (cout << s << " "), deb(ts...);
}

long int PowerUp(long long b, long long p) {
    if (p == 0) {
        return 1ll;
    }
    return (b * PowerUp(b, p - 1)) % MOD;
}
//int SET(int mask, int pos) { return mask | (1 << pos); }

//bool CHK(int mask, int pos) { return (1 & (mask >> pos)); }
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};

const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1}; // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1 << 31) - 1
#define MX
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

int main() {
    ios_base::sync_with_stdio(false);
#ifdef RAFIK_FARHAD
    freopen("../000.txt", "r", stdin);
    freopen("../111.txt", "w", stdout);
    clock_t ooo = clock();
#endif
    ///                                    MAIN

    int h, w, r[1003], c[1003], ar[1003][1003];

    while (cin >> h >> w) {
        CLR1(ar);
        ll sum = 0, possible = 1;
        for (int i = 0; i < h; ++i) {
            take(r[i]);
            for (int j = 0; j < r[i]; j++) {
                ar[i][j] = 1;
            }
            ar[i][r[i]] = 0;
        }
        for (int i = 0; i < w; ++i) {
            take(c[i]);
            for (int j = 0; j < c[i]; j++) {
                if (ar[j][i] == 0) {
                    possible = 0;
                }
                ar[j][i] = 1;
            }
            if (ar[c[i]][i] == 1) {
                possible = 0;
            }
            ar[c[i]][i] = 0;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (ar[i][j] == -1) {
                    sum++;
                }
            }
        }
//        deb("->", possible, sum);
        if (!possible) {
            __(0);
            continue;
        }
        __(PowerUp(2ll, (ll) sum));
    }


    /* Coding is FUN  */
    ///                                    ENDD
#ifdef RAFIK_FARHAD
    fprintf(stderr, "\n\nTime Elapsed: %lu MS\n", (clock() - ooo));
#endif
    return 0;
}

