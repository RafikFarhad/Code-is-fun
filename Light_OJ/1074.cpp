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
#define csi                                     pf("Case %d:", ++keis)
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
#define SIZE INT_MAX
ll ar[201];
int n;
bool flag[201];
ll level[201];
class DATA
{
public:
    int v;
    ll w;
    DATA(int a, ll o) : v(a), w(o){};
};

vector <DATA> v[201];

ll SPFA(int theke, int porjonto)
{
    int i, j, k, u, vv;
    for(i=1; i<=n; i++)
    {
        level[i] = 1e12;
        flag[i] = 0;
    }
    flag[theke] = 1;
    level[theke] = 0ll;
    queue <int> qu;
    qu.push(theke);
    while(qu.size())
    {
        u = qu.front();
        qu.pop();
        flag[u] = 0;
        for(i=0; i<v[u].size(); i++)
        {
            vv = v[u][i].v;
            //if(flag[vv]) continue;
            if(level[vv]>level[u]+v[u][i].w and level[vv]>-8000)
            {
                level[vv] = level[u]+v[u][i].w;
                flag[vv] = 0;
                qu.push(vv);
            }
        }
    }
    if(level[porjonto]==1e12) return -1;
    else return level[porjonto];
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    int t;
    ll x, y, z, br[205];
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=1; i<=n; i++)
        {
            br[i] = -2;
            takell(ar[i]);
            v[i].clear();
        }
        takei(l);
        while(l--)
        {
            takell(x);
            takell(y);
            //deb(x, y, z);
            z = (ar[y]-ar[x]);
            z = z*z*z;
            v[x].pb(DATA(y, z));
            //if(x==1 and y==6) deb(z);
        }

        csi;NL;
        takei(l);
        while(l--)
        {
            takei(a);
            if(br[a]==-2) x = SPFA(1,a);
            else x = br[a];
            x<3ll?pf("?\n"):pf("%lld\n", x);

        }

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


