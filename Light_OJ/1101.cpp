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
#define csi                                     pf("Case %d:\n", ++keis)
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
#define SIZE 50004

class DATA
{
public:
    int u, v, w;
    DATA(int uu=0, int vv=0, int ww=0) : u(uu), v(vv), w(ww){};
    bool operator < (const DATA &p) const
    {
        return w<p.w;
    }
}edge[100005];

class DATA2
{
public:
    int  v, w;
    DATA2(int vv=0, int ww=0) : v(vv), w(ww){};

};
vector <DATA2> adj[50054];

int par[SIZE], lca[SIZE][20], maxi[SIZE][20], n, highest, level[SIZE];
bool vis[SIZE];
int FIND_PARENTS(int a);
void BUILD_LCA();
void DFS(int cur, int prev, int lev);
int QUIERY(int a, int b);
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    int t, m;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        for(i=0, j=0; i<m; i++)
        {
            takei(a);
            takei(b);
            takei(c);
            edge[j++] = DATA(a, b, c);
        }
        sort(edge, edge+j);
        for(i=1; i<=n; i++)
        {
            par[i] = i;
            adj[i].clear();
        }
        for(i=0, k=0; i<j and k<n-1; i++)
        {
            a = edge[i].u;
            b = edge[i].v;
            c = edge[i].w;
            //deb(a, b, c);
            //deb(FIND_PARENTS(a), FIND_PARENTS(b));
            if(FIND_PARENTS(a)!=FIND_PARENTS(b))
            {
                //deb(a, b, c);
                par[FIND_PARENTS(a)] = FIND_PARENTS(b);
                k++;
                adj[a].pb(DATA2(b, c));
                adj[b].pb(DATA2(a, c));
            }
        }
        //deb(par[7]);
        BUILD_LCA();
        //deb("#", lca[2][0], maxi[2][0]);
        takei(l);
        csi;
        while(l--)
        {
            takei(a);
            takei(b);
           // ok
            j = QUIERY(a, b);
            pf("%d\n", j);
        }

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

int FIND_PARENTS(int a)
{
    if(par[a]==a) return a;
    return par[a] = FIND_PARENTS(par[a]);
}
void DFS(int cur, int prev, int lev)
{
    //par[cur] = prev;
    vis[cur] = 1;
    highest = max(highest, lev);
    level[cur] = lev;
    int i;
    for(i=0; i<adj[cur].size(); i++)
    {
        int vv = adj[cur][i].v;
        //deb(cur, vv);
        //if(vv==prev) continue;
        if(vis[vv]) continue;
        DFS(vv, cur, lev+1);
        lca[vv][0] = cur;
        maxi[vv][0] = adj[cur][i].w;
    }
    return;
}
void BUILD_LCA()
{
    highest = 0;
    CLR(vis);
    DFS(1, -1, 0);
   // deb(level[4], level[7], par[7]);
    //deb(lca[26][0]);
    int i, j, lg = log(highest)+1;
    lca[1][0] = -1;
    maxi[1][0] = 0;
    for(i=1; i<=n; i++)
        for(j=1; j<=lg; j++)
        {
            lca[i][j] = -1;
            maxi[i][j] = 0;
        }
    //deb(lg, highest);
    //deb(lca[26][0]);
        for(j=1; j<=lg; j++)
    for(i=1; i<=n; i++)
        {
            if(lca[i][j-1]!=-1)
            {
                //deb(i, j, lg);
                lca[i][j] = lca[lca[i][j-1]][j-1];
                //deb(lca[i][j-1], lca[i][j]);
                maxi[i][j] = max(maxi[lca[i][j-1]][j-1], maxi[i][j-1]);
            }
        }
    return;
}
int QUIERY(int a, int b)
{
    int i, j, k, lg = floor(log(highest))+1, ans = 0;
    if(level[a]>level[b]) swap(a, b);
   // ok
  // deb(highest, lg);
   // deb(a, b, level[a], level[b]);
    //deb("lg", lca[20][2], lca[20][1], lca[lca[20][1]][1]);
    //deb(level[18]);
    for(i=lg; i>=0; i--)
    {
        //ok
        //deb(level[b], i, level[b]- (1<<i) , level[a]);
        if( (level[b]- (1<<i)) >= level[a])
        {
            //deb("*", lg, lca[b][i], maxi[b][i]);
            ans = max(ans, maxi[b][i]);
            b = lca[b][i];
        }
    }
    //deb(a, b, level[a], level[b]);
   // deb(ans);
    if(a==b) return ans;
    for(i=lg; i>=0; i--)
    {
        if(lca[a][i]!=-1 and lca[a][i]!=lca[b][i])
        {
            ans = max(ans, max(maxi[a][i], maxi[b][i]));
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    //deb(a, b, level[a], level[b]);
    //deb(maxi[a][0], maxi[b][0]);
    //deb(ans);
    ans = max(ans, max(maxi[a][0], maxi[b][0]));
    return ans;
 }
