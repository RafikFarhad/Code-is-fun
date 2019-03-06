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
//#define mp                                      make_pair
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
int ans, disk[20005], low[20005], flag[20005], n, times, totalscc;//, sccno[100005], totalscc;
stack <int> st;
vector <int> v[20005];//, scc[100005];

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
            //scc[totalscc].pb(st.top());
            //sccno[st.top()] = totalscc;
            flag[st.top()] = 0;
            st.pop();
        }
        //scc[totalscc].pb(st.top());
        //sccno[st.top()] = totalscc;
        flag[u] = false;
        st.pop();
        totalscc++;
    }
    return;
}

map <string, int> mp;

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    string ab, bc;
    while(t--)
    {
        mp.clear();
        for(i=0; i<20000; i++)
        {
            v[i].clear();
            disk[i] = 0;
            flag[i] = 0;
        }
        times=0;
        totalscc = 0;
        l = 0;
        takei(n);
        getchar();
        for(i=0; i<n; i++)
        {
            cin >> ab >> bc;
            //deb(ab, "#", bc);
            //deb(ab.size(), bc.size());
            if(mp.count(ab))
                ;
            else
                mp[ab] = l
                ++;
            if(mp.count(bc))
                ;
            else
                mp[bc] = l
                ++;
            a = mp[ab];
            b = mp[bc];
            //deb(a, b);
            v[a].pb(b);
        }
        for(i=0; i<l; i++)
        {
            if(disk[i]==0)
                SCC(i);
        }
        //deb(l);
        csi;
        if(l==totalscc)
            pf("Yes\n");
        else
            pf("No\n");
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



