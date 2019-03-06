
/*Ghost Return*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iterator>
/******************************************/
/** Author      : Rafik Farhad            */
/** Mail to     : rafikfarhad@gmail.com   */
/** Created     :  2018-12-12             */
/******************************************/
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
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
#define ll long long
#define ull unsigned long long
#define exx 2.7182818284590452353602875
#define xx first
#define yy second
#define debArr(o)                                                  \
    copy(o.begin(), o.end(), ostream_iterator<short>(cout, "->")); \
    cout << endl;
///Helper
using namespace std;
template <class T>
T MAX(T a, T b) { return a > b ? a : b; }
template <class T>
T MIN(T a, T b) { return a < b ? a : b; }
template <class T1>
void __(T1 p) { cout << p << endl; }
template <class T1>
void deb(T1 p) { cout << "Debugging: " << p << endl; }
template <class T1, class T2>
void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q << endl; }
template <class T1, class T2, class T3>
void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl; }
template <class T1, class T2, class T3, class T4>
void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl; }
long long int POOW(long long b, long long p)
{
    if (p == 0)
        return 1;
    return b * POOW(b, p - 1);
}
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1}; // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1 << 31) - 1
#define MX
#define MOD
#define EPS 1e-10
//#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
int dp[55][55], n, l, ar[55];

int CALC(int a, int b)
{
    if (a == b - 1)
    {
        return 0;
    }
    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }
    int p, i, pp, qq;
    p = LT;
    // deb(p);
    for (i = a + 1; i < b; i++)
    {
        pp = CALC(a, i);
        qq = CALC(i, b);
        // deb(a, i, pp);
        // deb(i, b, qq);
        // deb(pp+ qq);
        // if(a==0 and b == 5)
        // {
            // deb(a, i, b, p);
            // deb(pp, qq, pp + qq);
        // }
        p = min(pp + qq, p);
    }
    // deb(a , b, p, p + ar[b] - ar[a]);
    dp[a][b] = p + ar[b] - ar[a];
    return dp[a][b];
}

int main()
{
    //  ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("/home/rafikfarhad/Desktop/000.txt","r",stdin);
    freopen("000.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l, keis(0);
    int a, b, c, d, e;
    //    fgets(pp, 100, stdin);
    while (scanf("%d", &l) && l)
    {
        takei(n);
        CLR1(dp);
        ar[0] = 0;
        dp[0][1] = 0;
        dp[n][n+1] = 0;
        for (i = 1; i <= n; i++)
        {
            takei(ar[i]);
            dp[i][i + 1] = 0;
        }
        ar[n + 1] = l;
        pf("The minimum cutting is %d.\n", CALC(0, n + 1));
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    // pf("-------ENDS OF OUTPUT------\n\n");
    pf("Time Elapsed: %lu\n", (clock() - ooo));
#endif
    return 0;
}
