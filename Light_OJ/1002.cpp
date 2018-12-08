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

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void deb(T1 x)
{
    cout << "Debugging: " << x << endl;
}
template <class T1, class T2> void deb(T1 x, T2 y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 x, T2 y, T3 z, T4 p)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << ", " << p << endl;
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 1e6
class DATA
{
public:
    int u, w;
    DATA(int _u=0, int _w=0)
    {
        u = _u;
        w = _w;
    }
    bool operator < (const DATA a) const
    {
        return w < a.w;
    }
};
vector <DATA> path[505];
int level[505], n;

void DIJKSTRA(int s)
{
    int i, j, u, v, w;
    DATA t, t1;
    queue<DATA> pq;
    level[s] = 0;
    pq.push(DATA(s, 0));
    while(pq.size())
    {
        t = pq.front();
        pq.pop();
        u = t.u;
        w = t.w;
        for(i=0; i<path[u].size(); i++)
        {
            t1 = path[u][i];// pf(" - t1.u = %d , t1.w = %d , level[u] = %d , t1.w = %d, level[t1.u] = %d\n", t1.u, t1.w, level[u],t1.w, level[t1.u]);
            //    deb("t1.w = ", t1.w, "t1.u", t1.u);
            // deb(level[t1.u]);
            if( level[t1.u] > max(t1.w, level[u]) )
            {
                level[t1.u] = max(t1.w, level[u]);
                pq.push(DATA(t1.u, 0));
            }
        }
    }
    return;
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
    int test, m, keis=0, temp1, temp2, temp3, start, i, j;
    takei(test);
    while(test--)
    {
        takei(n);
        takei(m);
        for(i=0; i<n; i++) path[i].clear();
        for(i=0; i<m; i++)
        {
            takei(temp1);
            takei(temp2);
            takei(temp3);
            path[temp1].pb(DATA(temp2, temp3));
            path[temp2].pb(DATA(temp1, temp3));
        }
        takei(start);
        for(i=0; i<n; i++)
            level[i] = 1<<28;
        DIJKSTRA(start);

        pf("Case %d:\n", ++keis);
        for(i=0; i<n; i++)
        {
            if(level[i]==1<<28) pf("Impossible\n");
            else pf("%d\n",level[i]);
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

