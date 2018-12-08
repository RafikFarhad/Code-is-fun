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
#define _(o)                                    pf("%d", o)

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
typedef long long ll;
ll graph[55][55], par[55], temp[55][55];
int n, m;
bool flag[55];
queue <int> qu;

bool BFS()
{
    CLR(flag);
    par[1] = 1;
    while(qu.size()) qu.pop();
    qu.push(1);
    flag[1] = 1;
    int i, j, k;
    while(qu.size())
    {
        k = qu.front();
        qu.pop();
        for(i=2; i<=n; i++)
        {
            if(!flag[i] and graph[k][i]>0)
            {
                par[i] = k;
                flag[i] = 1;
                if(i==2) return true;
                qu.push(i);
            }
        }
    }
    return false;
}

void MAX_FLOW()
{
     ll mini;
     int i, u, v, j, k, x, y;
    while(BFS())
    {
        mini = 10e15;
        v = 2;
        u = par[2];
        while(u!=v)
        {
            mini = min(graph[u][v], mini);
            v = u;
            u = par[v];
        }
        j = 0;
        v = 2;
        u = par[2];
        while(u!=v)
        {
            graph[u][v]-=mini;
            graph[v][u]+=mini;
           /* if(!j and graph[u][v]==mini)
            {
                x = u;
                y = v;
                j = 1;
            }*/
            v = u;
            u = par[v];
        }
        //deb(mini);
        //pf("%d %d\n", x, y);
    }
    return;
}

void DFS(int x=1)
{
    int i, j;
    flag[x] = 1;
    for(i=1; i<=n; i++)
    {
        if(!flag[i] and graph[x][i])
        {
            flag[i] = 1;
            DFS(i);
        }
    }
    return;
}

void MIN_CUT()
{
    CLR(flag);
    DFS();
    int i, j, k;
    for(i=1; i<=n; i++)
        for(j=i; j<=n; j++)
        {
            if( (flag[i] != flag[j]) and (graph[i][j]==0)!=(graph[j][i]==0))
            //if( flag[i] and !flag[j] and (!graph[i][j] or !graph[j][i]))
            {
                pf("%d %d\n", i, j);
            }
        }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int  i, j, k, t;
    while(sf("%d %d", &n, &m)==2 and n+m)
    {
        CLR(graph);
        while(m--)
        {
            takei(i);
            takei(j);
            takei(t);
            temp[i][j] = temp[j][i] = graph[i][j] = graph[j][i] = t;
        }
        //memcpy(temp, graph, sizeof graph);
        MAX_FLOW();
        MIN_CUT();
        NL;
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


