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
//#define mp                                      make_pair
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
map <string, int> mp;
int graph[65][65], source, sink, ans, par[65], flag[65];

bool BFS()
{
    CLR1(par);
    CLR(flag);
    queue <int> qu;
    qu.push(source);
    int i, j, k;
    par[source] = source;
    flag[source] = 1;
    while(qu.size())
    {
        k = qu.front(); qu.pop();
        for(i=1; i<=58; i++)
        {
            if(flag[i]==0 and graph[k][i]>0)
            {
                par[i] = k;
                flag[i] = 1;
                qu.push(i);
                //deb(i);
                if(i==sink)
                    return true;
            }
        }
    }
    return false;
}

int MAX_FLOW()
{
    int min_flow = 10e8, u, v, k;
    while(BFS())
    {
        u = par[sink];
        v = sink;
        while(u!=v)
        {
            min_flow = min(min_flow, graph[u][v]);
            v = u;
            u = par[v];
        }
        u = par[sink];
        v = sink;
        while(u!=v)
        {
            graph[u][v]-=min_flow;
            graph[v][u]+=min_flow;
            v = u;
            u = par[v];
        }
        ans+=min_flow;
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
    int i, j, k, l, t, keis=0, n, m;
    mp["XL"] = 51;
    mp["L"] = 52;
    mp["S"] = 53;
    mp["M"] = 54;
    mp["XXL"] = 55;
    mp["XS"] = 56;
    string a;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        CLR(graph);
        for(i=1; i<=m; i++)
        {
            cin >> a;
            graph[i][mp[a]] = 1;
            //deb("OK", i, mp[a]);
            cin >> a;
            graph[i][mp[a]] = 1;
        }
        for(i=51; i<57; i++)
            graph[i][58] = n;
        for(i=1;i<=m; i++)
            graph[0][i] = 1;
        source = 0;
        sink = 58;
        ans = 0;
        ans = MAX_FLOW();
        //deb(ans);NL;NL;NL;
        if(ans<m)
            pf("Case %d: NO\n", ++keis);
        else
            pf("Case %d: YES\n", ++keis);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


