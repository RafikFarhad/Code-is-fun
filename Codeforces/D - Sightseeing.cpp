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
#define SIZE (1000000000)
#define MAX 1010

int dis[MAX][2], cow[MAX][2], n;
bool visit[MAX][2];

class DATA
{
public:
    int v, w, flag;
    DATA(int _v=0, int _w=0, int _fl=0):v(_v), w(_w), flag(_fl) {};
    bool operator <(const DATA &p) const
    {
        return dis[v][flag]>dis[p.v][p.flag];
    }
};

vector <DATA> adj[MAX];

int DIJKSTRA(int a, int b)
{
    int i, j, u, v, w, flag, cost_so_far;
    DATA temp;
    for(i=0; i<n; i++)
    {
        dis[i][0] = dis[i][1] = SIZE;
        cow[i][0] = cow[i][1] = 0;
        visit[i][0] = visit[i][1] = 0;
    }
    priority_queue <DATA> pq;
    pq.push(DATA(a, 0, 0));
    dis[a][0] = 0;
    cow[a][0] = 1;
    //deb(a, b);
    while(pq.size())
    {
        temp = pq.top();
        pq.pop();
        u = temp.v;
        flag = temp.flag;
        cost_so_far = dis[u][flag];
        if(visit[u][flag]) continue;
        //deb(u, cost_so_far);
        visit[u][flag] = 1;
        for(i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i].v;
            w = adj[u][i].w + cost_so_far;
            //deb("->", v, w);
            if(w<dis[v][0])
            {
                if(dis[v][0]!=SIZE)
                {
                    dis[v][1] = dis[v][0];
                    cow[v][1] = cow[v][0];
                    pq.push(DATA(v, 0, 1));
                }
                dis[v][0] = w;
                cow[v][0] = cow[u][flag];
                //deb("#", v);
                pq.push(DATA(v, 0, 0));
            }
            else if(w==dis[v][0])
            {
                cow[v][0]+=cow[u][flag];
            }
            else if(w<dis[v][1])
            {
                dis[v][1] = w;
                cow[v][1] = cow[u][flag];
                pq.push(DATA(v, 0, 1));
            }
            else if(w==dis[v][1])
            {
                cow[v][1]+=cow[u][flag];
            }
        }

    }
    //deb(dis[b][0], dis[b][1]);
    if(dis[b][1]-1==dis[b][0]) return cow[b][0]+cow[b][1];
    return cow[b][0];
    return 0;
}


int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, m, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        for(i=0; i<n; i++)
            adj[i].clear();
        for(i=0; i<m; i++)
        {
            takei(a);
            takei(b);
            takei(c);
            --a;
            --b;
            adj[a].pb(DATA(b, c, 0));
        }
        takei(a);
        takei(b);
        --a;
        --b;
        //cout << "ANS: ";
        _(DIJKSTRA(a, b));
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



