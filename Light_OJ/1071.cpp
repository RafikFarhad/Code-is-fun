

/*Winter is coming*/


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
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
int dp[105][105][105][4], m, n, ar[105][105];


int GO(int i, int j, int k, int moves)
{
    if( (i==m-1 && j==n-1 && k==n-1 && moves==2))
        return 0;
    //if(j==n-1 or k==n or i==m or j==k) return 0;
    //if(k==n) deb(i+1, j+1, k+1);
    if(dp[i][j][k][moves]!=-1)
        return dp[i][j][k][moves];
    int &ret = dp[i][j][k][moves];
    ret = 0;

    if(moves==0)
    {
        if(k+1<n)
            ret = max(ret, GO(i, j, k+1, 0) + ar[i][k+1]);   ///move the right to right until k==n
        if(k>j)
            ret = max(ret, GO(i, j, k, 1));                ///can move down
        if(ret==-10) deb(i, j, k);
    }
    if(moves==1)
    {
        if(j<k && i+1<m)
            ret = max(ret, GO(i+1, j, k, 2) + ar[i+1][j] + ar[i+1][k]);   /// go down and then if possible then right
    }
    if(moves==2)
    {
        if(j+1<k)
            ret = max(ret, GO(i, j+1, k, 2) + ar[i][j+1]);
        ret = max(ret, GO(i, j, k, 0));
    }
    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b, ans;
//    char pp[100];
//    fgets(pp, 100, stdin);
    takei(t);
    while(t--)
    {
        takei(m);
        takei(n);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                takei(ar[i][j]);
        CLR1(dp);
        ans = GO(0,0,0,0) + ar[m-m][n-n];
        //deb(dp[m-1][n-2][n-1]);
        csi;
        pf("%d\n", ans);
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}
/*
for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                dp[0][i][j] = ar[0][i] + ar[j][0];
            }
        }

        for(i=1; i<m; i++)
        {
            /// DOWN COUNT
            for(j=0; j<n-1; j++)
            {
                for(k=j+1; k<n; k++)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]+ar[i][j]+ar[i][k]);
                }
            }
            ///for first one right move count
            for(j=1; j<n-1; j++)
            {
                for(k=j+1; k<n; k++)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]+ar[i][j]);
                }
            }
            ///for second one right count
            for(j=0; j<n-2; j++)
            {
                for(k=j+2; k<n; k++)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]+ar[i][k]);
                }
            }
        }
        int ans = 0;
        a = 0;
        for(i=0; i<n-1; i++)
            a = max(a, dp[m-1][i][n-1]);
        ans += a;
        a = 0;
        for(i=0; i<m-1; i++)
            a = max(a, dp[m-2][n-1][i]);
        ans += a;
        ans += ar[m-1][n-1];
*/
