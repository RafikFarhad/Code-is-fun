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

ll prime[(int) (MX / 64)];
int check[100005];
int noOfPrime = 0;

void Seieve() {
    CLR(check);
    int sqroot = (int) sqrt(MX);
    for (int i = 3; i < sqroot; i += 2) {
//        prime[i/63] = SET(prime[i/63], i%63);
        for (int j = i * 2; j < sqroot; j += i) {
            prime[j / 63] = SET(prime[j / 63], j % 63);
        }
    }
    check[noOfPrime++] = 2;
    for (int i = 3; i < sqroot; i += 2) {
        if (!CHK(prime[i / 63], i % 63)) {
            check[noOfPrime++] = i;
        }
    }
}

bool PrimeCheck(ll a) {
    for (int i = 0; i < noOfPrime; i++) {
        if (a % check[i] == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
#ifdef RAFIK_FARHAD
    freopen("../000.txt", "r", stdin);
    freopen("../111.txt", "w", stdout);
    clock_t ooo = clock();
#endif
    ///                                    MAIN
    ll a, b, n, c, d, i, j, k, keis(0), l, t, x, y, z;
    Seieve();
    take(a);
    while (a--) {
        cin >> x >> y;
        if (x - y == 1) {
            deb("NO");
            continue;
        }
            deb("YES");
//        deb(check[noOfPrime-1]);
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifdef RAFIK_FARHAD
    fprintf(stderr, "\n\nTime Elapsed: %lu MS\n", (clock() - ooo));
#endif
    return 0;
}
