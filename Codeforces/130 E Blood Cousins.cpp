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
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
#define SIZE 100005
class DATA
{
public:
    int v, w;
    DATA(int _u=0, int _v=0) : v(_u), w(_v) {};
};

vector <DATA> mat[SIZE];
vector <int> nodes[SIZE];
int n, par[SIZE][20], level[SIZE], lef[SIZE], ri[SIZE], t;
bool visit[SIZE];

void DFS(int prev, int cur=0, int lev=0)
{
    visit[cur] = 1;
    level[cur] = lev;
    lef[cur] = t;
    nodes[lev].pb(t);
    t++;
    for(int i=0; i<mat[cur].size(); i++)
    {
        int vv = mat[cur][i].v;
        if(vv==prev or visit[vv]) continue;
        //par[vv][0] = cur;
        DFS(cur, vv, lev+1);
    }
    ri[cur] = t;
    return;
}

void INIT_LCA()
{
    int i, j, k, lg=18;
//    for(i=0; i<=n; i++)
//        for(j=1; j<=lg; j++)
//        {
//            par[i][j] = -1;
//            //dis[i][j] = 0ll;
//        }
    for(j=1; j<=lg; j++)
    {
        for(i=0; i<=n; i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j] = par[par[i][j-1]][j-1];
                //dis[i][j] = dis[par[i][j-1]][j-1] + dis[i][j-1];
            }
        }
    }
    return;
}

int FIND_LCA(int a, int b)
{
    int i, j, k=a, lg=18;
    if(level[a]<b) return -1;
    //ok
    //deb(a, b);
    for(j=18; j>=0 and b; j--)
    {
//        deb(j, a, level[a], par[a][j]);
//        deb(1<<j, b);
        if(par[a][j]!=-1 and (1<<j) <= b)
        {
            a = par[a][j];
            b -= (1<<j);
        }
    }
    if(k==a or b) return -1;
    return a;
}

int COUNT(int a, int b)
{
    if(a==-1) return 0;
    int k = level[a] + b;
//    deb(k, a, level[a], b);
//    deb(lef[a], ri[a]);
//    for( auto i:nodes[k])
//        deb("*", i);
    auto ita = lower_bound(nodes[k].begin(), nodes[k].end(), lef[a]);
    auto itb = lower_bound(nodes[k].begin(), nodes[k].end(), ri[a]);
    int tot = itb-ita-1;
    //if(tot<0) tot=0;
    //deb(tot);
    return tot;
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
    int i, j, k, l,  keis(0), c, d, x, y, a, b, v, p, q;
    CLR1(par);
    takei(n);
    for(i=1; i<=n; i++)
    {
        takei(a);
        if(a==0) continue;
        mat[a].pb(i);
        par[i][0] = a;
    }
    t = 1;
    for(i=1; i<=n; i++)
    {
        if(par[i][0]==-1)
        {
            //lef[i] = t;
            DFS(-1, i, 0);
            t++;
            //ri[i] = t;
//            t = t+1;
        }
    }
//    for(i=0; i<=n; i++)
//    {
//        deb(i, level[i]);
//    }
    INIT_LCA();
//    deb(par[2][0], par[7][1]);
//    for(i=0; i<nodes[1].size(); i++)
//        deb(i, nodes[1][i]);
//    deb(lef[1], ri[1]);
    takei(q);
    while(q--)
    {
        takei(v);
        takei(p);
        a = FIND_LCA(v, p);
        //deb("LCA-> ", a);
//        deb(v, p, a);
        _(COUNT(a, p));
        //deb(v, p, a);
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



