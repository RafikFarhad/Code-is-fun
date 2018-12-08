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
#define SIZE 100005
int n, m, par[SIZE], level[SIZE], lca[SIZE][20], ans[SIZE][20], ans2[SIZE][20];
bool vis[SIZE];

class DATA
{
public:
    int v, w;
    DATA(int a=0, int b=0):v(a), w(b){};
    bool operator < (const DATA &p) const
    {
        return w<p.w;
    }
};

vector <DATA> mat[SIZE];

int highest_level;

void DFS(int cur, int prev)
{
    int i, vv;
    for(i=0; i<mat[cur].size(); i++)
    {
        vv = mat[cur][i].v;
        if(vv==prev or vis[vv]) continue;
        level[vv] = level[cur] + 1;
        vis[vv] = 1;
        highest_level = max(highest_level, level[vv]);
        DFS(vv, cur);
        lca[vv][0] = cur;
        ans[vv][0] = mat[cur][i].w;
        ans2[vv][0] = mat[cur][i].w;
    }
    return;
}

void MAKE_A_TREE()
{
    for(int i=0; i<n; i++)
    {
        vis[i] = 0;
    }
    level[0] = 0;
    vis[0] = 1;
    lca[0][0] = -1;
    ans[0][0] = -1;
    ans2[0][0] = 1<<29;
    DFS(0, -1);
    //pf("Tree Made \n\n\n");
    //for(int i=0; i<n; i++)
        //deb(i+1, lca[i][0]+1, level[i]);
    return;
}

void BUILD_LCA()
{
    int i, j, lg = 17;
    for(i=0; i<n; i++)
    {
        for(j=1; j<=lg; j++)
        {
            lca[i][j] = -1;
            ans[i][j] = 0;
            ans2[i][j] = 1<<29;
        }
    }
    for(j=1; j<=lg; j++)
    {
        for(i=0; i<n; i++)
        {
            if(lca[i][j-1]!=-1)
            {
                lca[i][j] = lca[lca[i][j-1]][j-1];
                ans2[i][j] = min(ans2[lca[i][j-1]][j-1], ans2[i][j-1]);
                ans[i][j] = max(ans[lca[i][j-1]][j-1], ans[i][j-1]);
            }
        }
    }
    return;
}

void QUIERY(int a, int b)
{
    int i, j, res = 0, lg = 17, res2 = 1<<29;
    if(level[b]>level[a])
        swap(a, b);
    for(i=lg; i>=0; i--)
    {
        if(level[a]-(1<<i) >= level[b])
        {
            res = max(res, ans[a][i]);
            res2 = min(res2, ans2[a][i]);
            a = lca[a][i];
        }
    }
    if(a==b)
    {
        pf("%d %d\n", res2, res);
        return;
    }
    for(i=lg; i>=0; i--)
    {
        if(lca[a][i]!=lca[b][i])
        {
            res = max(res, ans[a][i]);
            res = max(res, ans[b][i]);

            res2 = min(res2, ans2[a][i]);
            res2 = min(res2, ans2[b][i]);

            a = lca[a][i];
            b = lca[b][i];
        }
    }
    res = max(res, ans[a][0]);
    res = max(res, ans[b][0]);

    res2 = min(res2, ans2[a][0]);
    res2 = min(res2, ans2[b][0]);

    pf("%d %d\n", res2, res);
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    int t;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n;i++)
            mat[i].clear();
        for(i=0; i<n-1; i++)
        {
            takei(a);
            takei(b);
            takei(c);
            a--;
            b--;
            mat[a].pb(DATA(b, c));
            mat[b].pb(DATA(a, c));
        }
        MAKE_A_TREE();
        BUILD_LCA();
        pf("Case %d:\n", ++keis);
        takei(k);
        while(k--)
        {
            takei(a);
            takei(b);
            QUIERY(--a, --b);
        }

    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

