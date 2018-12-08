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
/******************************************/
/** Author      : Rafik Farhad            */
/** Mail to     : rafikfarhad@gmail.com   */
/******************************************/
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
int SET(int mask, int pos){return mask|(1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN
ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
ll MULTIPLY(ll a,ll b)      ///(a*b)%MOD
{
    ll res=0ll;
    while(b)
    {
        if(b&1ll)
        {
            res=(res+a);
            if(res>=MOD) res-=MOD;
        }
        b>>=1ll;
        a=(a+a);
        if(a>=MOD) a-=MOD;
    }
    return res;
}

ll ncr[1001][1001];

void CALC_NCR(int n)
{
    ll ncrMOD = MOD;
    int i, j;
    for(i = 0 ; i <= n; i++) ncr[i][0] = 1ll;

    for(int i = 1; i <= n; i++)
    {
        ncr[i][i] = 1;
        ncr[i][1] = i;
    }

    for(i = 3; i <= n; i++)
    {
        for(j = 2; j < i; j++)
        {
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]);
            ncr[i][j] %= ncrMOD;
        }
    }
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
    CALC_NCR(1000);
    ll fact[1005], ans, in;
    fact[0] = 1;
    for(i=1; i<=1000; i++)
        fact[i] = (i*fact[i-1])%MOD;
    int n, m;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        takei(k);
        in = fact[n-k];
//        deb(n-k, in);
        for(i=1; i<=m-k; i++)
        {
//            deb(m-k, i, n-k-i);
            if(i&1)
            {
                in = in - (ncr[m-k][i]*fact[n-k-i]);
            }
            else
                in = in + ncr[m-k][i]*fact[n-k-i];
            in%=MOD;
            if(in<0)
                in+=MOD;
        }
        //deb(in, ncr[m][k]);
        csi;
        pf("%lld\n", (in*ncr[m][k])%MOD);
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



