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
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

class Graph
{
    int V;
    list<int> *adj;
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int Articulation_Point();
};

void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
            low[u]  = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)
               ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
               ap[u] = true;
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
int Graph::Articulation_Point()
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        visited[i] = false;
        ap[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
    int a=0;
    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            a++;
    return a;
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/RafikFarhad/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    map <pair<int, int>, bool > mmp;
    int n;
    char pp[1000];
    while(sf("%d", &n)==1 and n)
    {
        Graph v(n);
        mmp.clear();
        getchar();
        while(gets(pp) and strcmp(pp, "0"))
        {
            l = strlen(pp);
            //deb(l);
            b = 0;
            for(j=0; ; j++)
            {
                if(pp[j]==' ')
                {
                    a = b;
                    j++;
                    break;
                }
                b = 10*b + pp[j] - '0';
            }
            b = 0;
            for(; j<l; j++)
            {
                //deb(j, pp[j]);ok
                if(pp[j]==' ')
                {
                    //deb("*", a, b);
                    if(mmp[make_pair(a, b)])
                    {
                        b = 0;
                        continue;
                    }
                    else
                    {
                        mmp[make_pair(a, b)] = 1;
                        mmp[make_pair(b, a)] = 1;
                    }
                    v.addEdge(a-1, b-1);
                    v.addEdge(b-1, a-1);
                    b = 0;
                    //deb(b, pp[j]);
                }
                else
                {
                    b = 10*b + pp[j] - '0';
                }
                //deb(j, b, pp[j]);
            }
            if(mmp[make_pair(a, b)])
            {
                b = 0;
                continue;
            }
            else
            {
                mmp[make_pair(a, b)] = 1;
                mmp[make_pair(b, a)] = 1;
            }
            v.addEdge(b-1, a-1);
            v.addEdge(a-1, b-1);
        }
        a = v.Articulation_Point();
        __(a);
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}
