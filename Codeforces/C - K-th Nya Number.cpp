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
ll dp[22][11][22][22];
int ar[22], four, seven, n;
ll l, r, p, q;

void INIT()
{
    CLR(dp);
    for(int i=0; i<=9; i++)
    {
        if(i==4)
            dp[1][4][1][0] = 1;
        else if(i==7)
            dp[1][7][0][1] = 1;
        else
            dp[1][i][0][0] = 1;
    }
    int i, j, x4, x7, k;
    for(i=2; i<21; i++)
    {
        for(j=0; j<=9; j++)
        {
            for(x4=0; x4<21; x4++)
            {
                for(x7=0; x7<21; x7++)
                {
                    for(k=0; k<=9; k++)
                    {
                        if(j==4)
                        {
                            if(x4>0)
                            {
                                dp[i][j][x4][x7] += dp[i-1][k][x4-1][x7];
                            }
                            else
                                dp[i][j][x4][x7] = 0;
                        }
                        else if(j==7)
                        {
                            if(x7>0)
                            {
                                dp[i][j][x4][x7] += dp[i-1][k][x4][x7-1];
                            }
                            else
                                dp[i][j][x4][x7] = 0;
                        }
                        else
                            dp[i][j][x4][x7] += dp[i-1][k][x4][x7];
                    }
                }
            }
        }
    }
    return ;
}

ll COUNT(int pos, int x4, int x7)
{
    if(pos==-1)
    {
        int i, f=0, s=0;
        for(i=0; i<n; i++)
            if(ar[i]==4) f++;
            else if(ar[i]==7) s++;
        if(four==f and s==seven) return 1;
        else return 0;
    }
    if(x4==-1 or x7==-1) return 0;
    ll ret = 0;
    for(int i=0; i<ar[pos]; i++)
        ret+=dp[pos+1][i][x4][x7];

    if(ar[pos]==4) x4--;
    if(ar[pos]==7) x7--;
    ret+=COUNT(pos-1, x4, x7);
    return ret;
}

ll SOLVE(ll a)
{
    n = 0;
    while(a)
    {
        ar[n++] = a%10;
        a/=10;
    }
    return  COUNT(n-1, four, seven);
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, keis=0, y, qu;
    ll a, b, c, d, x, lo, hi, mid, ans;
    INIT();
    takei(t);
    while(t--)
    {
        takell(p);
        takell(q);
        takei(four);
        takei(seven);

        c = SOLVE(p);
        d = SOLVE(q);
        //deb(c, d);
        takei(qu);
        pf("Case #%d:\n", ++keis);
        while(qu--)
        {
            takell(x);
            if(x>d-c)
            {
                pf("Nya!\n");
                continue;
            }
            ans = q+1;
            lo = p+1;
            hi = q;
            while(lo<=hi)
            {
                mid = (lo+hi)>>1;
                a = SOLVE(mid);
                if(c+x==a)
                {
                    //deb(lo, hi, mid, a);
                    //deb(c, x);
                    ans = min(ans, mid);
                    hi = mid-1;
                }
                else if(c+x<a)
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            pf("%lld\n", ans);
        }

    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


