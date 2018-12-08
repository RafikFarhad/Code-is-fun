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
#define csi                                     pf("Case %d:\n", ++keis)
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
#define LT (1<<31)-1
#define MX 50004
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
vector <int> v[MX];
int n, par[MX], src, dest, level[MX], ans;
bool flag[MX];

void BFS(int x, int dst)
{
    queue <int> qu;
    level[x] = 0;
    par[x] = -2;
    qu.push(x);
    ans = 1<<29;
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            int vv = v[u][i];
//            if(level[u]+1==level[vv])
//            {
//                par[vv] = min(par[vv], u);
//                level[vv] = level[u] + 1;
//                qu.push(vv);
//            }
            if(level[u]+1<level[vv])
            {
                level[vv] = level[u] + 1;
                par[vv] = u;
                qu.push(vv);
            }
            if(vv==dest)
            {
                break;
                ans = level[vv];
            }
            //if(ans+2==level[vv]) break;
        }
    }
    return;
}

void PRINT_ANSWER(int x)
{
    if(par[x]==-2)
    {
        pf("%d", x);
        return;
    }
    PRINT_ANSWER(par[x]);
    pf(" %d", x);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    takei(t);
    while(t--)
    {
        takei(n);
        takei(b);
        for(i=0; i<MX; i++)
        {
            v[i].clear();
            level[i] = par[i] = 1<<29;
        }
        src = a = b;
        for(i=1; i<n; i++)
        {
            takei(b);
            v[a].pb(b);
            v[b].pb(a);
            sort(all(v[a]));
            sort(all(v[b]));
            a = b;
        }
        dest = b;
        //CLR1(par);
        BFS(src, dest);
        csi;
        PRINT_ANSWER(dest);
        NL;
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



