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
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second

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
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN

#define SIZE 20004
int ans, disk[SIZE], low[SIZE], flag[SIZE], n, times, sccno[SIZE], totalscc, match[SIZE], in[SIZE], out[SIZE];
stack <int> st;
vector <int> v[SIZE], scc[SIZE], new_graph[SIZE];
void SCC(int u)
{
    disk[u] = low[u] = ++times;
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
void RESET()
{
    CLR(sccno);
    for(int i=0; i<n; i++)
    {
        v[i].clear();
        disk[i] = 0;
        flag[i] = 0;
        scc[i].clear();
        new_graph[i].clear();
    }
    while(st.size()) st.pop();
    ans = 0;
    times = 0;
    totalscc = 0;
    return;
}
void DFS(int x)
{
    flag[x] = 1;
    //in[x]++;
    // deb(x);
    for(int i=0; i<new_graph[x].size(); i++)
    {
        in[new_graph[x][i]]++;
        //deb("->", x, new_graph[x][i], flag[new_graph[x][i]]);
        if(flag[new_graph[x][i]] == 1) ;
        else
        {
            //flag[new_graph[x][i]] = 1;

            DFS(new_graph[x][i]);
        }
    }
    return;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y, track[100005], m;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        RESET();
        CLR(in);
        CLR(out);
        while(m--)
        {
            takei(a);
            takei(b);
            --a;
            --b;
            v[a].pb(b);
        }
/// SCC
        for(i=0; i<n; i++)
        {
            if(disk[i]==0)
            {
                SCC(i);
            }
        }
        //deb(totalscc);
/// Let, SCC is one node, the create the new graph... and store it to new_graph[][]...
        for(i=0; i<n; i++)
        {
            for(j=0; j<v[i].size(); j++)
            {
                a = i;
                b = v[i][j];
                if(sccno[a]!=sccno[b])
                {
                    out[sccno[a]]++;
                    in[sccno[b]]++;
                }
            }

        }
        //deb(totalscc);
        x = 0;
        y = 0;
        csi;
        if(totalscc==1)
        {
            _(0);
            continue;
        }
        CLR(flag);
        for(i=0; i<totalscc; i++)
        {
            if(flag[i]);
            else
                DFS(i);
        }
        //pf("%d\n", totalscc-1);
        for(i=0; i<totalscc; i++)
        {
            if(out[i]==0)
            {
                x++;
            }
            if(in[i]==0)
            {
                //deb(i, in[i]);
                y++;
            }

        }
        //deb(x, y);
        _(max(x,y));
    }
    return 0;
}
/*
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;

     Coding is FUN
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


*/
