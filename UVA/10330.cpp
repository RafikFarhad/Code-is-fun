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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int residual[210][210], source, sink, ans, par[210], n;
bool flag[205];

bool BFS()
{
    int i, j, u;
    CLR(flag);
    par[source] = source;
    flag[source] = 1;
    queue<int> qu;
    qu.push(source);
    while(qu.size())
    {
        u = qu.front();
        qu.pop();
        for(i=1; i<203; i++)
        {
            if(flag[i]==0 and residual[u][i]>0)
            {
                par[i] = u;
                if(i==sink) return true;
                qu.push(i);
                flag[i] = 1;
            }
        }
    }
    return false;
}

void MAX_FLOW()
{
    int min_flow, i, j, u, v;
    while(BFS())
    {
        min_flow = 10e8+500;
        u = par[sink];
        v = sink;
        while(u!=v)
        {
            min_flow = min(min_flow, residual[u][v]);
            v = u;
            u = par[v];
        }

        u = par[sink];
        v = sink;
        while(u!=v)
        {
            residual[u][v] -= min_flow;
            residual[v][u] += min_flow;
            v = u;
            u = par[v];
        }
        //deb("min_flow = ", min_flow);
        ans+=min_flow;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, i, keis=0, w, x, y, u, v;
    //takei(t);
    while(sf("%d", &n)!=EOF)
    {
        CLR(residual);
        ans = 0;
        //takei(n);
        for(i=1; i<=n; i++)
        {
            takei(x);
            residual[i][i+101] = x;
        }
        takei(x);
        while(x--)
        {
            takei(u);
            takei(v);
            takei(w);
            residual[u+101][v] = w;
        }
        takei(x);
        takei(y);
        while(x--)
        {
            takei(u);
            residual[0][u] = 10e8;
        }
        while(y--)
        {
            takei(u);
            residual[u+101][202] = 10e8;
        }
        source = 0;
        sink = 202;
        MAX_FLOW();
        pf("%d\n", ans);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



