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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int ans, disk[100005], low[100005], flag[100005], n, times, sccno[100005], totalscc;
stack <int> st;
vector <int> v[100005], scc[100005];

void SCC(int u = 0)
{
    disk[u] = low[u] = ++times;
    //deb(u, times);
    st.push(u);
    flag[u] = 1;
    for(int i=0; i<v[u].size(); i++)
    {
        int vv = u[v][i];
        if(disk[vv]==0)
        {
            SCC(vv);
            low[u] = min(low[u], low[vv]);
        }
        else if(flag[vv])
            low[u] = min(low[u], disk[vv]);
    }
    if(disk[u]==low[u])
    {
        //deb(u);
        //ans++;
        while(st.top()!=u)
        {
            scc[totalscc].pb(st.top());
            sccno[st.top()] = totalscc;
            flag[st.top()] = 0;
            st.pop();
        }
        scc[totalscc].pb(st.top());
        sccno[st.top()] = totalscc;
        flag[u] = false;
        st.pop();
        totalscc++;
    }
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
 freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y, track[100005], indegree[100005];
    takei(t);
    while(t--)
    {
        takei(n);
        takei(l);
        CLR(sccno);
        for(i=0; i<n; i++)
        {
            v[i].clear();
            disk[i] = 0;
            flag[i] = 0;
            scc[i].clear();
        }ok
        while(l--)
        {
            takei(a);
            takei(b);
            --a;
            --b;
            v[a].pb(b);
        }
        while(st.size()) st.pop();
        ans = 0;
        times = 0;
        totalscc = 0;
        CLR(indegree);
        for(i=0; i<n; i++)
        {
            if(disk[i]==0)
            {
                SCC(i);
            }
        }
        //deb(totalscc);
        for(i=totalscc-1; i>=0; i--)
        {
            CLR(track);
            for(j=0; j<scc[i].size(); j++)
            {
                track[scc[i][j]] = 1;
            }
            for(j=0; j<scc[i].size(); j++)
            {
                for(k=0; k<v[scc[i][j]].size(); k++)
                {
                    if(track[v[scc[i][j]][k]]) continue;
                    indegree[sccno[v[scc[i][j]][k]]]++;
                }
            }
        }
        for(i=0; i<totalscc; i++)
            if(indegree[i]==0)
                ans++;
        _(ans);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



