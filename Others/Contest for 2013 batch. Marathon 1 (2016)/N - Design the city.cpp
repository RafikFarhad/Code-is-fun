///Only Sakibul Mowla vai is real :P



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
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875

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
#define SIZE 50005
class DATA
{
public:
    int v, w;
    DATA(int _u=0, int _v=0) : v(_u), w(_v) {};
};

vector <DATA> mat[SIZE];
int n, par[SIZE][20], dis[SIZE][20], level[SIZE];
bool visit[SIZE];

void DFS(int prev, int cur=0, int lev=0)
{
    visit[cur] = 1;
    level[cur] = lev;
    for(int i=0; i<mat[cur].size(); i++)
    {
        int vv = mat[cur][i].v;
        if(vv==prev or visit[vv]) continue;
        par[vv][0] = cur;
        dis[vv][0] = mat[cur][i].w;
        DFS(cur, vv, lev+1);
    }
    return;
}

void INIT_LCA()
{
    int i, j, k, lg=18;
    for(i=0; i<n; i++)
        for(j=1; j<=lg; j++)
        {
            par[i][j] = -1;
            dis[i][j] = 0;
        }
    for(j=1; j<=lg; j++)
    {
        for(i=0; i<=n; i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j] = par[par[i][j-1]][j-1];
                dis[i][j] = dis[par[i][j-1]][j-1] + dis[i][j-1];
            }
        }
    }
    return;
}

int FIND_LCA(int a, int b)
{
    int i, j, k, lg=18;
    if(level[a]<level[b])
        swap(a, b);
    for(j=18; j>=0; j--)
    {
        if(level[a]-(1<<j)>=level[b])
            a = par[a][j];
    }
    if(a==b)
        return a;
    for(j=18; j>=0; j--)
    {
        if(par[a][j]!=par[b][j])
        {
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}

int COUNT_DIST(int a, int b)
{
    int j, res = 0;
    if(level[a]<level[b])
        swap(a, b);
    for(j=18; j>=0; j--)
    {
        if(level[a]-(1<<j)>=level[b])
        {
            res+=dis[a][j];
            a = par[a][j];
        }
    }
    return res;
}

int DIS(int a, int b)
{
    //deb(a, b);
    int lca = FIND_LCA(a, b);
    return COUNT_DIST(n-1, a)+ COUNT_DIST(n-1, b) - 2*COUNT_DIST(lca, n-1);
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d, ab, bc, ca;
    int lca, dis1, dis2, dis3;
    while(sf("%d", &n)!=EOF)
    {
        if(keis++) NL;

        for(i=0; i<n; i++)
            mat[i].clear();
        for(i=1; i<n; i++)
        {
            takei(a);
            takei(b);
            takei(c);
            mat[a].pb(DATA(b, c));
            mat[b].pb(DATA(a, c));
        }
        CLR(visit);
        DFS(-1, n-1, 0);
        INIT_LCA();
        /*for(i=0; i<n; i++)
            deb(i, level[i]);*/
        takei(l);
        while(l--)
        {
            takei(a);
            takei(b);
            takei(c);

            ab = FIND_LCA(a, b);
            bc = FIND_LCA(b, c);
            ca = FIND_LCA(c, a);

            dis1 = DIS(a, b) + DIS(ab, c);
            dis2 = DIS(a, c) + DIS(ca, b);
            dis3 = DIS(c, b) + DIS(bc, a);
           // deb(c, b, "**", DIS(c, b));

            d = min(dis1, min(dis2, dis3));
           // deb(dis1, dis2, dis3);
            pf("%d\n", d);
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


