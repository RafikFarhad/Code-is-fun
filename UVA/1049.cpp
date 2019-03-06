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
/** Author      : Rafik Farhad            */
/** Mail to     : rafikfarhad@gmail.com   */
/******************************************/
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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN
class DATA
{
public:
    int x, dir, c;
    DATA(int _x=0, int _c=0, int _dir=0)
    {
        x = _x;
        dir = _dir;
        c = _c;
    }
};
vector <DATA> ad[105];
int n, cost, flag[105];

int DFS(int x, int prev)
{
    if(x) flag[x] = 1;
    int i, c = 0;
    for(i=0; i<ad[x].size(); i++)
    {
        if(ad[x][i].x==prev or flag[ad[x][i].x]) continue;
        if(ad[x][i].dir==1) c = ad[x][i].c;
        //deb(ad[x][i].x+1, c);
        c+= DFS(ad[x][i].x, x);
    }
    return c;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
        {
            ad[i].clear();
            flag[i] = 0;
        }
        for(i=0; i<n; i++)
        {
            takei(a);
            takei(b);
            takei(c);
            a--;
            b--;
            ad[a].pb(DATA(b, c, 0));
            ad[b].pb(DATA(a, c, 1));
        }
        b = -41;
        c = n+1;
        for(i=0; i<ad[0].size(); i++)
        {
            b = max(ad[0][i].x, b);
            c = min(ad[0][i].x, c);
        }
        //deb(b+1, c+1);
        a = DFS(0, b);
        CLR(flag);
        //ok
        b = DFS(0, c);
        //deb(a, b);
        csi;
        pf("%d\n", min(a,b));
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



