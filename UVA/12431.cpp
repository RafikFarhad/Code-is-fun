#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/*****************************************/
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
#define mp                                      make_pair
#define ppp                                     system("pause")
#define ok                                      cout << "OKA" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d: ", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)
#define _(o)                                    pf("%d", o)

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
#define ll long long
//#define mod 100000000
ll b, n, d, m;
ll MUL(ll a, ll ba, ll mod)
{
    ll ans=0;
    a%=mod;
    while(ba)
    {
        //deb(b, ans);
        if(ba&1)
        {
            ans = ans+a;
            if(ans>=mod) ans-=mod;
            ba--;
        }
        if(!ba) break;
        a<<=1;
        a%=mod;
        ba>>=1;
    }
    return ans;
}

ll BIGMOD(ll base, ll pow, ll mod)
{
    ll ans = 1ll;
    while(pow)
    {
        if(pow&1)
        {
            ans  = MUL(ans, base, mod);
        }
        pow >>=1;
        base = MUL(base, base, mod);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t, keis=0;

    takei(t);
    ll up, down;
    while(t--)
    {
        takell(n);
        takell(b);
        takell(d);
        takell(m);
        up = BIGMOD(b, n, (b-1)*m);
        up = (up + (b-1)*m - 1)/(b-1);
        //down = b-1;
        //up = up/down;
        up = MUL(up, d, m);
        pf("Case %d: %lld\n",++keis, up);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

/* 20

876899634 40 3 997705235
567827744 36 12 959975837
725315722 82 59 2003108480
1736253619 91 43 1903115688
1569380559 63 4 1589293676
1290123438 61 1 420979925
834330925 91 44 180018372
720498052 74 2 473032148
728984369 16 4 734217230
368900737 29 1 926861353
1877943251 85 68 1207829792
954973927 69 24 565524756
1564085686 72 12 1075955472
1263186484 56 43 1461763647
1389697299 75 58 365978895
162264776 2 1 389427707
670354355 86 11 1560109386
1121973274 53 32 40577608
64385581 75 50 2133471549
558847439 91 74 171662449*/
