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
    int tot, id;
    DATA(int _tot=0, int _id=0) : tot(_tot), id(_id){};
    bool operator < (const DATA &a) const
    {
        return a.tot<tot;
    }
};
map <pair<int, int>, int > mp;
int value[MX], par[MX][20], n;
DATA level[MX];
vector <int> v[MX];
bool vis[MX];

void DFS(int now, int prev)
{
    vis[now] = 1;
    par[now][0] = prev;
    for(auto i:v[now])
    {
        if(vis[i]) continue;
//        deb(i, now);
        level[i].tot = level[now].tot + 1;
        DFS(i, now);
    }
    return;
}

void INIT_LCA()
{
    int i, j, k, lg=18;
    for(j=1; j<=lg; j++)
    {
        for(i=0; i<=n; i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }
    return;
}

void UPDATE_LCA(int a, int b)
{
    int i, j, k, lg=18;
    if(level[a].tot<level[b].tot)
        swap(a, b);
    int t = level[a].tot;
    for(j=18; j>=0; j--)
    {
        if(t-(1<<j)>=level[b].tot)
        {
            a = par[a][j];
            t-=(1<<j);
        }
    }
    if(a==b)
    {
        value[a]--;
        value[a]--;
        return;
    }
    for(j=18; j>=0; j--)
    {
        if(par[a][j]!=par[b][j])
        {
            a = par[a][j];
            b = par[b][j];
        }
    }
    value[par[a][0]]--;
    value[par[a][0]]--;
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
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b, m;

    takei(n);
    for(i=1; i<n; i++)
    {
        takei(a);
        takei(b);
        mp[{a,b}] = i;
        mp[{b,a}] = i;
        v[a].pb(b);
        v[b].pb(a);
    }
    CLR1(par);
    level[1].tot = 1;
    DFS(1, -1);
    INIT_LCA();
    takei(m);
    while(m--)
    {
        takei(a);
        takei(b);
        value[a]++;
        value[b]++;
        UPDATE_LCA(a, b);
    }
    for(i=1; i<=n; i++)
    {
        level[i].id = i;
    }
    sort(level+1, level+(n+1));
    int ans[MX];
    CLR(ans);
    for(i=1; i<=n; i++)
    {
//        deb(level[i].tot, level[i].id);
        a = level[i].id;
        b = par[a][0];
//        deb("->", b, a, value[a]);
        ans[mp[{a,b}]] += value[a];
        //ans[mp[{b,a}]] = value[a];
        value[b]+=value[a];
    }
    for(i=1; i<n-1; i++)
    {
        pf("%d ", ans[i]);
    }
    pf("%d\n", ans[i]);
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



