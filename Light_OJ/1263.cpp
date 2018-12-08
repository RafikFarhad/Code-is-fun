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

vector <int> ad[10005];
int n, cost, flag[10005], my, ar[10005], cc;

int DFS(int x)
{
    flag[x] = 1;
    int i, c = 0;
    for(i=0; i<ad[x].size(); i++)
    {
        if(flag[ad[x][i]]) continue;
        my+=ar[ad[x][i]];
        cc++;
        c = 1 + DFS(ad[x][i]);
    }
    return c;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    for(k=0; k<t; k++)
    {
        takei(n);
        takei(l);
        cost = 0;
        for(i=0; i<n; i++)
        {
            takei(ar[i]);
            cost+=ar[i];
            ad[i].clear();
            flag[i] = 0;
        }
        for(i=0; i<l; i++)
        {
            takei(a);
            takei(b);
            a--;
            b--;
            ad[a].pb(b);
            ad[b].pb(a);
        }
        x = 1;
        if(cost%n!=0)
        {
            x = 0;
        }
        else
        {
            for(i=0; i<n and x; i++)
            {
                if(flag[i]==0)
                {
                    //deb(i);
                    cc = 1;
                    my = ar[i];
                    a = 1+DFS(i);
                    //deb(my, cc, cost, n);
                    //deb(my%cc, my/cc, cost/n);
                    if(my%cc==0 and (my/cc)==(cost/n))
                        x = 1;
                    else
                    {
                        x = 0;
                        //break;
                    }
                    //deb(x);
                }
            }
        }
        csi;
        (x==1)?pf("Yes\n"):pf("No\n");
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}





