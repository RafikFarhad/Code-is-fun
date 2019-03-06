/*De La Grandi Mephistopheles*/


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
#include <list>
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : $ _ $       */
/****************************************************/
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
#define csii                                     pf("Case %d:\n", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN

class Graph
{
    int V;
    list<int> *adj;
    void bridgeUtil(int v, bool visited[], int disc[], int low[],
                    int parent[]);
public:
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void bridge();
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
};

vector <pair<int, int> > ans;

void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
            low[u]  = min(low[u], low[v]);

            if (low[v] > disc[u])
            {
                ans.pb(make_pair(min(u,v), max(u,v)));
            }
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

void Graph::bridge()
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("/home/looser/Desktop/000.txt","r",stdin);
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
    int n;
    map <int, int> mmp, mmp2;
    while(sf("%d", &n)!=EOF)
    {
        Graph v(n);
        ans.clear();
        for(i=0; i<n; i++)
        {
            sf("%d (%d)", &a, &j);
            for(k=0; k<j; k++)
            {
                takei(b);
                v.addEdge(a, b);
                v.addEdge(b, a);
            }
        }
        v.bridge();
        sort(all(ans));
        pf("%d critical links\n", ans.size());
        for(i=0; i<ans.size(); i++)
        {
            pf("%d - %d\n", ans[i].xx, ans[i].yy);
        }
        NL;
    }

//    char pp[100];
//    fgets(pp, 100, stdin);


    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}

