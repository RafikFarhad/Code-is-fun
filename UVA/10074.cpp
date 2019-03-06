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
int n, m, ar[105][105];

int CALCULATE(int x, int y)
{
    int now[105], i, j, k, pp, qq, ans = 0;
    for(i=1; i<=m; i++)
    {
        now[i] = ar[y][i]-ar[x-1][i];
        //deb(i, now[i]);
        now[i]<0?now[i]=0:1;
    }
    now[0] = 0;
    pp = 1;
    qq = 0;
    for(i=1; i<=m; i++)
    {
        if(now[i]!=now[i-1])
        {
            qq = now[i];
            ans = max(ans, qq);
        }
        else
        {
            //qq = min(qq, now[i]);
            qq+=now[i];
            ans = max(ans, qq);
        }
    }
    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    while(1)
    {
        takei(n);
        takei(m);
        if(!n or !m) break;
        CLR(ar);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                takei(a);
                if(a) ar[i][j] = 0;
                else ar[i][j] = 1+ar[i-1][j];
                //ar[i][j] = (ar[i][j]!=0)?ar[i][j]+ar[i-1][j]:0;
                //deb(i, j, ar[i][j]);
            }
        }

        a = 0;
        //deb(2, 5, CALCULATE(2, 5));
        //return 0;
        for(i=1; i<=n; i++)
        {
            for(j=i; j<=n; j++)
            {
               // deb(i, j, CALCULATE(i, j));
                a = max(a, CALCULATE(i, j));
                //return 0;
            }
        }
        __(a);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


