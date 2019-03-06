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


int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    int ar[100005], n;
    while(cin>>n >> a)
    {
        for(i=0; i<n; i++)
            takei(ar[i]);
        sort(ar, ar+n);
        //for(i=0; i<n; i++)
          //  deb(i, ar[i]);
        if(n<3)
        {
            if(n==1)
                cout << 0 << endl;
            else
                cout << min(abs(a-ar[0]), abs(a-ar[1]));
            continue;
        }
        //if(abs(ar[0]-a) > abs(ar[n-1]-a))
        {
            if(a>ar[n-1])
            {
                x = abs(a-ar[1]);
            }
            else if(a<ar[1])
            {
                x = abs(a-ar[n-1]);
            }
            else
            {
                b = abs(a-ar[1]);
                c = abs(ar[n-1]-a);
                if(b>c)
                    x = 2*c + b;
                else
                    x = 2*b + c;
            }
        }
        //else
        {
            if(a<ar[0])
            {
                y = abs(a-ar[n-2]);
            }
            else if(a>ar[n-2])
            {
                y = abs(a-ar[0]);
            }
            else
            {
                b = abs(a-ar[0]);
                c = abs(ar[n-2]-a);
                //deb(b, c, ar[n-2]);
                if(b>c)
                    y = 2*c + b;
                else
                    y = 2*b + c;
            }
        }
        cout << min(x, y) << endl;

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



