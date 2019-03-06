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
int n, ar[100010], ulta[100010], x[100010], y[100010];

void LIS_IN_NLOGN(int pp[], int qq[])
{
    int i, j, temp[100010], lis_so_far=0;
    temp[0] = -(2000000000);
    for(i=1; i<=n; i++)
        temp[i] = 2000000000;
    for(i=0; i<n; i++)
    {
        j = lower_bound(temp, temp+(n+1), pp[i]) - temp;
        temp[j] = pp[i];
        lis_so_far = max(lis_so_far, j);
        qq[i] = lis_so_far;
    }
    return;
    for(i=0; i<n; i++)
    {
        cout << qq[i] << " ";
    }
    NL;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t,  keis=0, a, b, c, d;
    //takei(t);
    while(sf("%d", &n)==1)
    {
        //takei(n);
        for(i=0; i<n; i++)
        {
            takei(a);
            ar[i] = ulta[n-i-1] = a;
        }
        LIS_IN_NLOGN(ar, x);
        LIS_IN_NLOGN(ulta, y);
        reverse(y, y+n);
        a = 0;
        for(i=0; i<n; i++)
        {
            //deb(x[i], y[i]);
            a = max(min(x[i], y[i]), a);
        }
       // csi;
        __(2*a-1);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



