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
#define SIZE INT_MAX
int n, mil[105];
double target, risk[105];
double dp[10005], ans;

int GO(int pos, int teka, double prob)
{
    int i, j, k;
    for(i=1; i<=ans; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1.0;
    for(j=1; j<=n; j++)
    {
        for(i=ans; i>=mil[j]; i--)
        {
            //deb(dp[i-mil[j]], i, j);
            //deb(j, i, i-mil[j], (1.0-risk[j]));
            dp[i] = max(dp[i], dp[i-mil[j]]*(1.0-risk[j]));
        }
    }

    for(i=ans; i>=0; i--)
    {
        //dp[i] = 0;
        //deb(i, dp[i], dp[i]+target);
        if(dp[i]+target>=1.0)
            break;
    }

    return i;
}
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d, t;
    takei(t);
    while(t--)
    {
        sf("%lf %d", &target, &n);
        ans = 0;
        memset(dp, 0, sizeof dp);
        for(i=1; i<=n; i++)
        {
            sf("%d %lf", &mil[i], &risk[i]);
            ans+=mil[i];
        }
        //CLR(dp);
        //ans = 0.0;
        csi;

        pf("%d",GO(0,0,0.0));
        NL;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


