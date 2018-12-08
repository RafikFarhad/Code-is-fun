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
//#define all(o)                                  o.begin(), o.end()
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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX INT_MAX
#define MOD 1000000007
#define MY 1<<30
int SET(int mask, int pos)
{
    mask = mask|(1<<pos);
    return mask;
}
bool CHK(int mask, int pos)
{
    return (1&(mask>>pos));
}

int n, x[20], y[20], dp[(1<<16)+10], all[20][20];
bool flag[(1<<16)+10];

bool COLINEAR(int i, int j, int k)
{
    return (x[i]*(y[j]-y[k]) + x[j]*(y[k]-y[i]) + x[k]*(y[i]-y[j]))==0;
}

int SOLVE(int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(flag[mask]) return dp[mask];
    flag[mask] = 1;
    int &ret = dp[mask], i, j, k;
    if(__builtin_popcount(mask)==n-1) return ret = 1;
    ret = MY;
    for(i=0; i<n; i++)
    {
        if(!CHK(mask, i)) break;
    }
    //for( ; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j) continue;
            if(CHK(mask, j)) continue;
           // deb(i, j);
            //deb(CHK(mask|all[i][j], 0), CHK(mask|all[i][j], 1), mask|all[i][j]);
            k = SOLVE(mask|all[i][j]) + 1;
            ret = min(ret, k);
        }
    }
    return ret;
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
    int i, t, j, k, l,  keis=0, c, d;// x, y;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
        {
            takei(x[i]);
            takei(y[i]);
        }
        CLR(flag);
        CLR(all);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j) continue;
                for(k=0; k<n; k++)
                {
                    if(COLINEAR(i, j, k))
                    {
                        all[i][j] = SET(all[i][j], k);
                    }
                }
            }
        }
        //deb(all[0][1]);
        csi;
        _(SOLVE(0));
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


