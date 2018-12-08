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
int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
const int MOD=1000000007;
const int my[] = {0, 9,99,999,9999,99999,999999,9999999,99999999,999999999};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, k, l, t, keis=0, p, q, r, hi, low;
    long long  ans, n, a[100005], b[100005];
    while(sf("%lld", &n)!=EOF)
    {
        takell(k);
        l = n/k;
        for(i=0; i<l; i++)
        {
            takell(a[i]);
        }
        for(i=0; i<l; i++)
        {
            takell(b[i]);
        }
        ans = 1;
        for(i=0; i<l; i++)
        {
            if(0)
            {
                p = my[9]/a[i];
                //deb(a[i]);
                low = b[i]*POOW(10, 9-1);
                hi = low + my[9-1];
                if(b[i]) low--;
                //deb(low, hi, my[8]);
                q = hi/a[i] - low/a[i];
                if(b[i]) p++;
                //deb(p, q);
                p-=q;
                ans = ((ans%MOD)*(p%MOD))%MOD;
            }
            else
            {
                //deb("n", n, k);

                p = my[k]/a[i];
                //deb(my[k], a[i]);
                low = b[i]*POOW(10, k-1);
                hi = low + my[k-1] ;
                if(b[i]) low--;
                q = hi/a[i] - low/a[i];
                //ok deb(low, hi, my[k-1]);
                //deb(p, q);
                if(b[i]) p++;
                p-=q;
                //deb(p);
                ans = ((ans%MOD)*(p%MOD))%MOD;
                //NL;NL;
            }
        }
        cout << ans << endl;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


