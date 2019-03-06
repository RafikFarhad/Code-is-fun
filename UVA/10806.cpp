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
#define ok                                      cout << "OK" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d: ", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1}; const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
class DATA
{
public:
    int u,  w;
    DATA (int _u=0, int _w=0)
    {
        u = _u;
        w = _w;
    }
    bool operator < (const DATA& a) const
    {
        return a.w<w;
    }
};
vector <DATA> v[105];
int n, par[105], level[105], source, dest, graph[105][105];

int DIJKSTRA()
{
    int i, j, k, u, p;
    DATA temp;
    priority_queue <DATA> pq;
    for(i=0; i<=n; i++)
    {
        level[i] = 10e8;
    }
    //deb("Source", source, "dest ", dest);
    pq.push(DATA(source, 0));
    par[source]= source;
    level[source] = 0;
    while(pq.size())
    {
        temp = pq.top(); pq.pop();
        u = temp.u;
        for(i=0; i<=n; i++)
        {
            p = i;
            if(graph[u][p]!=10e8 and level[p] > level[u] + graph[u][p])
            {
                //deb(graph[u][p]);
                //deb(u, level[p], temp.w+v[u][i].w);
                level[p] = level[u] + graph[u][p];
                par[p] = u;
                pq.push(DATA(p, level[p]));
            }
        }
    }
    if(level[dest]<10e8) return level[dest];
    return 0;
}

int MAX_FLOW()
{
    int u, v, ans = 0, i, j, k, mini, bar = 0;
    while(bar<2)
    {
        j = DIJKSTRA();
        if(j==0) break;
        bar++;
        //deb(j);
        //mini = 10e8;
        /*u = par[dest];
        v = dest;
        /*while(u!=v)
        {
            mini = min(mini, graph[u][v]);
            v = u;
            u = par[v];
        }*/
        u = par[dest];
        v = dest;
        //deb("mini", mini);
        while(u!=v)
        {
           // deb(u, v);

            graph[u][v] = 10e8;
            graph[v][u] *= -1;
            v = u;
            u = par[v];
        }
        //source = n;
        //dest = 1;
        //deb(mini, j);
        //deb("j", j);
        ans+=j;
    }
    if(bar==2) return ans;
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t, keis=0;
    while(sf("%d", &n)==1 and n)
    {
        takei(k);
        CLR(graph);
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                graph[i][j] = 10e8;
        while(k--)
        {
            takei(i);
            takei(j);
            takei(t);
            graph[i][j] = t;
            graph[j][i] = t;
            //deb("OO", t);
            v[i].pb(DATA(j, t));
            v[j].pb(DATA(i, t));
        }
        source = 1;
        dest = n;
        t = MAX_FLOW();
        //deb("t ",t); NL; NL;
        if(t<0) pf("Back to jail\n");
        else pf("%d\n", t);//ok NL;NL;

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


