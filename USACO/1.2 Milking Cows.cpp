/*
ID: rafikfa1
PROG: milk2
LANG: C++
*/
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
#define _(o)                                    pf("%d", o)

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
class DATA
{
public:
    int start, last;
    DATA(int s=0, int l=0) : start(s), last(l) {};
    bool operator < (DATA const &a) const
    {
        if(start==a.start)
            return last<a.last;
        return start<a.start;
    }
};

DATA ar[5005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("milk2.in","r",stdin);
    freopen("milk2.out", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t, keis=0, n, maxi, maxi2, x, xx, y, p, q;

    takei(n);
    for(i=0; i<n; i++)
    {
        takei(x);
        takei(y);
        ar[i].start = x;
        ar[i].last = y;
    }
    sort(ar, ar+n);
    maxi = 0;
    p = x = ar[0].start;

    q = ar[0].last;
    y = 0;
    for(i=0; i<n; i++)
    {
        //deb(ar[i].start, ar[i].last);
        if(i and ar[i].start>p and q>ar[i].last) continue;
        if(ar[i].start>x)
        {
            maxi = max(maxi, ar[i].last-ar[i].start);
            y=ar[i].last-ar[i].start;
        }
        else
        {
            maxi = max(y+ar[i].last-x, maxi);
            y = y+ar[i].last-x;
        }
        //deb(x, y);
        p = ar[i].start;
        q = ar[i].last;
        x = ar[i].last;
    }
    maxi2 = 0;
    x = ar[0].start;
    for(i=0; i<n; i++)
    {
        if(ar[i].start>x)
            maxi2 = max(maxi2, ar[i].start-x);

        x = max(x, ar[i].last);
    }
    pf("%d %d\n", maxi, maxi2);
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


