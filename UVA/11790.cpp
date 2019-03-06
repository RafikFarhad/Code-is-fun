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
int h[10000];
int w[10000], n, ans;
int dp[10000];
bool flag[10000];

int LIS(int x)
{
    if(x==n) return 0;
    if(flag[x]) return dp[x];
    int i, ans=0, maxi, a, temp;
    maxi = 0;
    flag[x] = 1;
    for(i=x+1; i<n; i++)
    {
        if(h[x]<h[i])
        {
            temp = LIS(i);
            if(ans<temp)
            {
                ans = temp;
            }
        }
    }
    dp[x] = ans + w[x];
    //deb(maxi, ans);
    return dp[x];
}

int LDS(int x)
{
    if(x==n) return 0;
    if(flag[x]) return dp[x];
    int i, ans=0, maxi, a, temp;
    maxi = 0;
    flag[x] = 1;
    for(i=x+1; i<n; i++)
    {
        if(h[x]>h[i])
        {
            temp = LDS(i);
            if(ans<temp)
            {
                ans = temp;
            }
        }
    }
    dp[x] = ans + w[x];
    //deb(maxi, ans);
    return dp[x];
}


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
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
            takei(h[i]);
        for(i=0; i<n; i++)
            takei(w[i]);
        CLR(flag);
        a = 0;
        for(i=0;i<n; i++)
        {
            a = max(a, LIS(i));
        }
        //puts("INCREASING");
        //deb(temp.first, temp.second);
        CLR(flag);
        b = 0;
        for(i=0;i<n; i++)
        {
            b = max(b, LDS(i));
        }
        //puts("DECREASING");
        //deb(temp.first, temp.second);

        if(a>=b)
            pf("Case %d. Increasing (%d). Decreasing (%d).\n", ++keis, a, b);
        else
            pf("Case %d. Decreasing (%d). Increasing (%d).\n", ++keis, b, a);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



