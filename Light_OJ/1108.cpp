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
template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void __(T1 p)
{
    cout << p << endl;
}
template <class T1> void deb(T1 p)
{
    cout << "Debugging: " << p << endl;
}
template <class T1, class T2> void deb(T1 p, T2 q)
{
    cout << "Debugging: " << p << "\t" << q  << endl;
}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;
}
long long int POOW(long long b, long long p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int n, ans, level[1010];
bool inqueue[1001], got[1001], mark;
int counter[1010];
class DATA
{
public:
    int v, w;
    DATA(int a, int o) : v(a), w(o) {};
};

vector <DATA> v[1001];

void DFS(int vv)
{
    got[vv] = 1;
    mark = 1;
    deb("*", vv);
    for(int i=0; i<v[vv].size(); i++)
        if(got[v[vv][i].v]==0)
            DFS(v[vv][i].v);
    return;
}

void SPFA()
{
    int i, u, vv;
    queue <int> qu;
    for(i=0; i<n; i++) qu.push(i);
    while(qu.size())
    {
        u = qu.front();
        qu.pop();
        inqueue[u] = 0;


        for(i=0; i<v[u].size(); i++)
        {
            vv = v[u][i].v;
            //deb(u, vv);
            if(got[vv]) continue;
            if(level[vv]>level[u]+v[u][i].w)
            {
                level[vv] = level[u]+v[u][i].w;
                if(inqueue[vv]==0)
                {
                    qu.push(vv);
                    inqueue[vv] = 1;
                    //deb(vv, counter[vv]);
                    counter[vv]++;
                    if(counter[vv]>=n)
                    {
                        DFS(vv);
                        //continue;
                    }
                }
            }
        }
    }
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
        takei(l);
        for(i=0; i<n; i++)
        {
            level[i]=0;;
            inqueue[i] = 1;
            got[i] = 0;
            counter[i] = 0;
        }
        while(l--)
        {
            takei(a);
            takei(b);
            takei(c);
            v[a].pb(DATA(b, c));
        }

        vector <int> ar;
        SPFA();

        for(i=0; i<n; i++)
            if(got[i]) pf("%d ", i);
        if(i==0)
            pf("Impossible\n");
        ok;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

