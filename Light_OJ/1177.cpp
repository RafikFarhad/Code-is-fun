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
int graph[105][105], par[105], n, m, t, flag[105];

bool BFS()
{
    int i, u, v, k, j;
    queue <int> qu;
    qu.push(1);
    par[1] = 1;
    CLR(flag);
    flag[1]=1;
    while(qu.size())
    {
        u = qu.front();
        qu.pop();
        for(i=1; i<=t; i++)
        {
            //deb(u,i,graph[u][i]);
            if(!flag[i] and graph[u][i]>0)
            {
                par[i]=u;
                flag[i] = 1;
                if(i==t) return true;
                qu.push(i);
            }
        }
    }
    return false;
}

int MAX_FLOW()
{
    int mini, ans = 0, i, j, u, v;
    while(BFS())
    {
        mini = 10e8;
        v = t;
        u = par[t];
        while(u!=v)
        {
            mini = min(graph[u][v], mini);
            //deb(u, v);ppp;
            v = u;
            u = par[v];
        }

        v = t;
        u = par[t];

        while(u!=v)
        {
            graph[u][v] -= mini;
            graph[v][u] += mini;
            v = u;
            u = par[v];
        }
        ans+=mini;

    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, keis=0, tt, pp;
    takei(pp);
    while(pp--)
    {
        sf("%d%d", &n, &l);
        csi;
        CLR(graph);
        t = n+n;
        for(i=2; i<n; i++)
        {
            //takei(j);
            takei(k);
            graph[i][i+n] = k;
            //deb(j, j+n, graph[j][j+n], n);
        }
        graph[1][n+1] = graph[n][n+n] = 10e8;
        while(l--)
        {
            takei(j);
            takei(k);
            takei(tt);
            graph[j+n][k] = tt;
            graph[k+n][j] = tt;
        }

        //deb(MAX_FLOW());
        _(MAX_FLOW()); NL;
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



