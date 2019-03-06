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
    ll i, t, j, k, l,  keis=0, a, b, c, d, x, y, n, ar[600][600], row[600], col[600];
    set <ll> aa, bb;

    while(cin>>n)
    {
        if(n==1)
        {
            cin >> k;
            cout << "5\n";
            continue;
        }
        b = 0;
        c = d = 0;
        aa.clear();
        bb.clear();
        for(i=0; i<n; i++)
        {
            a = 0;
            for(j=0; j<n; j++)
            {
                takell(k);
                a+=k;
                if(!k)
                {
                    x = i;
                    y = j;
                }
                ar[i][j] = k;
            }
            row[i] = a;
            aa.insert(a);
            c = max(a, c);
        }
        for(i=0; i<n; i++)
        {
            a = 0;
            for(j=0; j<n; j++)
            {
                k = ar[j][i];
                a+=k;
            }
            col[i] = a;
            bb.insert(a);
            d = max(a, d);
        }

        if(aa.size()!=2 or bb.size()!=2 or c-row[x]!=d-col[y])
        {
            cout << -1 << endl;
        }
        else
        {
            t = c-row[x];
            ar[x][y] = t;
            a = 0;
            for(i=0; i<n; i++)
                a+=ar[i][i];
            b = 0;
            for(i=0; i<n; i++)
                b+=ar[i][n-i-1];
            if(a!=b or a!=c or a!=d)
                cout << -1 << endl;
            else
                cout << t << endl;

        }

    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



