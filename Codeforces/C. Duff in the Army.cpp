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
//#define mp                                      make_pair
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
#define MX 100005
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
class DATA
{
public:
    int par;
    vector <int> id;
    DATA()
    {
        par = -1;
        //CLR(id);
    }
};

vector <int> CUSTOM_MERGE(vector <int> &a, vector <int> &b)
{
    vector <int> c(a.size()+b.size()+5);
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
//    if(a.size()+b.size()>10) c.resize(10);
//    else c.resize(a.size()+b.size());
    vector<int> ::iterator it = unique(c.begin(), c.end());
    c.resize(distance(c.begin(), it-1));
    if(c.size()>10) c.resize(10);
    return c;
}


map <pair<int, int>, int > mp;
int value[MX], level[MX], n;
DATA par[MX][20];
vector <int> v[MX], init[MX];
bool vis[MX];

void DFS(int now, int prev)
{
    vis[now] = 1;
    par[now][0].par = prev;
    for(auto i:v[now])
    {
        if(vis[i]) continue;
//        deb(i, now);
        level[i] = level[now] + 1;
        DFS(i, now);
    }
    return;
}

void INIT_LCA()
{
    int i, j, k, lg=18;
    for(i=1; i<=n; i++)
    {
        par[i][0].id = CUSTOM_MERGE(init[i], init[par[i][0].par]);
    }
    for(j=1; j<=lg; j++)
    {
        for(i=0; i<=n; i++)
        {
            if(par[i][j-1].par!=-1)
            {
                par[i][j].par = par[par[i][j-1].par][j-1].par;
//                vector <int> v;
                par[i][j].id = CUSTOM_MERGE(par[i][j-1].id, par[par[i][j-1].par][j-1].id);
//                par[i][j].id = v;
            }
        }
    }
    return;
}

vector <int> COUNT(int a, int b)
{
    int i, j, k, lg=18;
    if(level[a]<level[b])
        swap(a, b);
//    deb(a, b, level[a], level[b]);
//    deb(par[4][0].id.size());
    vector <int> ans;
    int t = level[a];
//    deb("t", t);
    for(j=18; j>=0; j--)
    {
        if(t-(1<<j)>=level[b])
        {
//            deb("J", j);
            ans = CUSTOM_MERGE(ans, par[a][j].id);
            a = par[a][j].par;
            t-=(1<<j);
        }
    }
//    deb(a, b, ans.size());
    if(a==b)
    {
        //ans = CUSTOM_MERGE(ans, init[b]);
        return CUSTOM_MERGE(ans, init[a]);
    }
//    ok
    for(j=18; j>=0; j--)
    {
        if(par[a][j].par!=par[b][j].par)
        {
            ans = CUSTOM_MERGE(ans, par[a][j].id);
            ans = CUSTOM_MERGE(ans, par[b][j].id);
            a = par[a][j].par;
            b = par[b][j].par;
        }
    }
    ans = CUSTOM_MERGE(ans, par[a][0].id);
    ans = CUSTOM_MERGE(ans, par[b][0].id);
    return ans;
    //ans = CUSTOM_MERGE(ans, init[b]);
    //return CUSTOM_MERGE(ans, init[par[a][0].par]);
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
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b, m, q;

    takei(n);
    takei(m);
    takei(q);
    for(i=1; i<n; i++)
    {
        takei(a);
        takei(b);
        v[a].pb(b);
        v[b].pb(a);
    }
    level[1] = 1;
    DFS(1, -1);
    for(i=1; i<=m; i++)
    {
        takei(a);
//        par[a][0].id.pb(i);
//        sort(all(par[a][0].id));
        init[a].pb(i);
        //sort(all(init[a]));
    }
    for(i = 1; i<=n; i++)
    {
        sort(all(init[i]));
        if(init[i].size()>10) init[i].resize(10);
    }
//    for(i=1; i<=n; i++, NL)
//    {
//        deb(par[i][0].id.size());
//        for(j=0; j<par[i][0].id.size(); i++)
//        {
//            pf("%d %d %d ",i, j, par[i][0].id[j]);
//        }
//        ok;
//    }
//    return 0;
    INIT_LCA();

    for(i=1; i<=q; i++)
    {
        takei(a);
        takei(b);
        takei(x);
//        deb(a, b, x, i);
        vector <int> p = COUNT(a, b);
        c = p.size();
        pf("%d ", min(x, c));
        for(j=0; j<min(x, c); j++)
        {
            pf("%d ", p[j]);
        }
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



