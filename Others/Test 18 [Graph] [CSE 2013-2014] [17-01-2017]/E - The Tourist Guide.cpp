/*De La Grandi Mephistopheles*/


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
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-01-17-23.03 _ Tuesday      */
/****************************************************/
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
#define csii                                     pf("Case %d:\n", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
#define SIZE 400
int n, par[SIZE], source, sink;

class DATA
{
public:
    int u, v, w;
    DATA(int _u, int _v, int _w) :u(_u), v(_v), w(_w) {};
    bool operator < (const DATA a) const
    {
        return w > a.w;
    }
};

void INIT()
{
    for(int i=0; i<=n; i++)
        par[i] = i;
    return;
}

int CHECK_PAR(int k)
{
    if(par[k] == k) return k;
    return par[k] = CHECK_PAR(par[k]);
}

void JOIN(int x, int y)
{
    par[x] = y;
    return;
}

int MST(vector<DATA> p)
{
    int po = p.size(), i, u, v, cow = 0, total = 0, x, y;
    int w;
    for(i=0; i<po; i++)
    {
        u = p[i].u;
        v = p[i].v;
        w = p[i].w;
        x = CHECK_PAR(u);
        y = CHECK_PAR(v);
        if(x!=y)
        {
            JOIN(x, y);
            if(CHECK_PAR(source)==CHECK_PAR(sink)) return w;
        }
    }
    return -11;
}
int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/RafikFarhad/Desktop/000.txt","r",stdin);
    //freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    vector <DATA> v;
    while(sf("%d %d", &n, &a)==2 and n+a)
    {
        v.clear();
        while(a--)
        {
            takei(b);
            takei(c);
            takei(d);
            v.pb(DATA(b, c, --d));
            //v.pb(DATA(c, b, d));
        }
        sf("%d %d %d", &source, &sink, &t);
        int ans = 0;
        INIT();
        sort(all(v));
        ans = MST(v);
        //deb(ans, t);
        pf("Scenario #%d\nMinimum Number of Trips = %d\n\n", ++keis, (ans+t-1)/ans);

    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}

