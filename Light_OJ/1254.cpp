/// #define_SUST
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 105
int fuel[SIZE], level[SIZE], n, capacity, par[SIZE], rem;
class DATA
{
public:
    int u, w;
    DATA();
    DATA(int _u, int _w)
    {
        u = _u;
        //v = _v;
        w = _w;
    }
    bool operator < (const DATA a) const
    {
        return w < a.w;
    }
};
vector <DATA> v[SIZE];

int COST(int start, int to, int dis)
{
    if(rem>dis) return 0;
    if(fuel[to] < fuel[start]) return dis*fuel[start];
    return fuel[start]*capacity;
}

int DIJK(int start, int endd)
{
    int i, j, k, w, cost, u;
    rem = 0;
    for(i=0; i<n; i++)
    {
        par[i] = i;
        level[i] = 1<<29;
    }
    priority_queue <DATA> qu;
    qu.push(DATA(start, 0));
    level[start] = 0;
    while(qu.size())
    {
        DATA temp = qu.top(); qu.pop();
        u = temp.u;
        cost = temp.w; deb(u, cost);
        for(i=0; i<v[u].size(); i++)
        {
            j = COST(u, v[u][i].u, v[u][i].w);
            if(cost+j < level[v[u][i].u])
            {
                par[v[u][i].u] = u;
                level[v[u][i].u] = level[u] + j;
                qu.push(DATA(v[u][i].u, level[v[u][i].u]));
            }
            //if(v[u][i].u==endd)
        }
    }
    return level[endd];
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, m, i, j, u, va, w, k, l, q;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        for(i=0; i<n; i++)
        {
            takei(fuel[i]);
            v[i].clear();
        }
        for(i=0; i<m; i++)
        {
            takei(u);
            takei(va);
            takei(w);
            v[u].pb(DATA(va, w));
            v[va].pb(DATA(va, w));
        }
        takei(q);
        pf("Case %d:\n", ++keis);
        while(q--)
        {
            takei(capacity);
            takei(u);
            takei(va);
            l = DIJK(u, va);
            if(l==1<<29) pf("impossible\n");
            else pf("%d\n", l);
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

