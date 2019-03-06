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
//const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
long long x[1005], y[1005], p, k, xx, yy, px[100005], py[100005];
bool ans;

bool CAN_REACH(long long xa,long long  xb,long long  ya,long long  yb,long long  a,long long  b)
{
    long long i = ya-xa;
    long long j = yb-xb;
    if( (i>0 and a<0) or (i<0 and a>0) ) return false;
    if( (j>0 and b<0) or (j<0 and b>0) ) return false;
    //deb(xa, xb, ya, yb);
   // deb(a, b);
   if(a==0 and b==0) return (xa==ya and xb==yb);
   if(a==0) return (xa==ya and j%b==0);
   if(b==0) return (i%a==0 and xb==yb);
   return (i%a==0 and j%b==0);
}

bool DFS(long long pp, long long qq, long long pos)
{
    //deb(pp, qq, pos);
    if(pos==p)
    {
        return 1;
    }
    //if(ans) return;
    for(long long i=0; i<k; i++)
    {
        if(CAN_REACH(pp, qq, px[pos], py[pos], x[i], y[i]))
        {
            //cout << "DONE" << endl;
            return DFS(px[pos], py[pos], pos+1);
        }
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i;
    //takell(p);
    //takell(k);
    //takell(x_0);
    //takell(y_0);
    while(sf("%lld%lld%lld%lld", &p, &k, &xx, &yy)==4)
    {
        for(i=0; i<p; i++)
        {
            takell(px[i]);
            takell(py[i]);
        }

        for(i=0; i<k; i++)
        {
            takell(x[i]);
            takell(y[i]);
        }
        ans = 0;
        ;
        if(DFS(xx, yy, 0)) cout << "Yes";
        else cout << "No";
        NL;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}
