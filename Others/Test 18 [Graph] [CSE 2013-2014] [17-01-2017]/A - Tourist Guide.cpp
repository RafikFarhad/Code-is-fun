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
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-01-18-23.46 _ Wednesday      */
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
#define MX 150
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

int n, disc[MX], low[MX], parent[MX];
vector <int> mat[MX];
bool visited[MX], ap[MX];

void INIT()
{
    for(int i=0; i<=n; i++)
    {
        mat[i].clear();
    }
    CLR(disc);
    CLR(low);
    CLR1(parent);
    CLR(visited);
    CLR(ap);
    return;
}

void DFS(int u)
{
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int i, v;
    for (i = 0; i<mat[u].size(); ++i)
    {
        v = mat[u][i];
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            DFS(v);
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
            // u is an articulation point in following cases
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == -1 && children > 1)
               ap[u] = true;
            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != -1 && low[v] >= disc[u])
               ap[u] = true;
        }
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
void Articulation_Point()
{
    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            DFS(i);

    // Now ap[] contains articulation points, print them
//    for (int i = 0; i < n; i++)
//        if (ap[i] == true)
//            cout << i << " ";
//    NL;
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/RafikFarhad/Desktop/000.txt","r",stdin);
    //freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    string aa, bb;
    map <string, int> mmp;
    map <int, string> mmp2;
    while(takei(n)==1 and n)
    {
        if(keis) NL;
        getchar();
        INIT();
        mmp.clear();
        mmp2.clear();
        k = 0;
        for(i=0; i<n; i++)
        {
            cin >> aa;
            mmp[aa] = k;
            mmp2[k] = aa;
            ++k;
        }
        takei(k);
        while(k--)
        {
            cin >> aa >> bb;
            a = mmp[aa];
            b = mmp[bb];
            mat[a].pb(b);
            mat[b].pb(a);
        }
        Articulation_Point();
        a = 0;
        vector <string> ans;
        for(i=0; i<n; i++)
        {
            if(ap[i]==1)
            {
                a++;
                ans.pb(mmp2[i]);
            }
        }
        sort(all(ans));
        pf("City map #%d: %d camera(s) found\n", ++keis, a);
        for(i=0; i<a; i++)
        {
            cout << ans[i] << endl;
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}

