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
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%lld", &a)
#define takellu(a)                               scanf("%llu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)
#define all(o)                                      o.begin(), o.end()
#define csi                                         pf("Case %d: ", ++keis)
#define csll                                         pf("Case %lld: ", ++keis)

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int ar[150], w, k, n, ans, dp[150][150];

int GO(int start, int rem)
{
    if(start>=n or rem==0)
    {
        return 0;
    }
    if(dp[start][rem] !=-1 )
    {
       //deb(start, rem, dp[start][rem]);
        return dp[start][rem];
    }
    int ret1=0, ret2=0, i,cc=0;
    for(i=start; i<n; i++)
    {
        if(ar[start]+w >= ar[i])
        {
            cc++;
        }
        else
            break;
    }

    ret1 = cc + GO(i, rem-1);

    ret2 = GO(start+1, rem);

    dp[start][rem] = max(ret1, ret2);
    //deb(start, rem, dp[start][rem]);
    return dp[start][rem];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, l, t, keis=0;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(w);
        takei(k);
        for(i=0; i<n; i++)
        {
            takei(l);
            takei(ar[i]);
        }
        sort(ar, ar+n);
        i=0;
        ans = 0;
        CLR1(dp);
        //for(; i<n; i++)
        {
            ans = GO(i, k);
        }
        csi;
        pf("%d\n", ans);
        //deb(ans);
        //NL;NL;
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


