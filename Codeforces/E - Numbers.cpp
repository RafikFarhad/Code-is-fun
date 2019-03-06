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
ll mod =  1000000007;
ll C[105][105], n;
void CALL_nCr()
{
    int i, j;
    C[0][0] = 1;
    for(i=1; i<101; i++)
    {
        C[i][0] = C[i][i] = 1ll;
        for(j=1; j<i; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
    }
    return;
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
    CALL_nCr();
    ll ans=0, dp[110][11], ar[11];
    CLR(dp);
    cin >> n;
    for(i=0; i<10; i++)
        cin >> ar[i];
    for(l=0; l<=n; l++)
    {
        for(j=9; j>=0; j--)
        {
            if(j==0)
            {
                for(i=ar[j]; i<=l; i++)
                {
                    if(l) dp[l][j] = (dp[l][j] + (dp[l-i][j+1]*C[l-1][i]))%mod;
                }
            }
            else if(j==9)
            {
                if(l<ar[9]) dp[l][j] = 0ll;
                else dp[l][j] = 1ll;
            }
            else
            {
                for(i=ar[j]; i<=l; i++)
                {
                    dp[l][j] = (dp[l][j] + (dp[l-i][j+1]*C[l][i]))%mod;
                }
            }
        }
    }
    for(l=0; l<=n; l++)
    {

        ans+=dp[l][0];
        ans%=mod;
    }
    cout << ans << endl;
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

