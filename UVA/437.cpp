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
int SET(int mask, int pos){return mask|(1<<pos);}
bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN
ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

class DATA
{
public:
    int x, y, z;
    DATA(int a=0, int b=0, int c=0) : x(a), y(b), z(c){};
    bool operator < (const DATA &a) const
    {
        if(x==a.x)
        {
            if(y==a.y)
                return z<a.z;
            else
                return y<a.y;
        }
        else
            return x<a.x;
    }
};
DATA ar[1000];
int n, aa;

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
    int sum[1000];
    while(sf("%d", &n) and n)
    {
        aa = 0;
        CLR(sum);
        for(i=0; i<n; i++)
        {
            takei(a);
            takei(b);
            takei(c);
            ar[aa++] = DATA(a, b, c);
            ar[aa++] = DATA(a, c, b);
            ar[aa++] = DATA(b, a, c);
            ar[aa++] = DATA(b, c, a);
            ar[aa++] = DATA(c, b, a);
            ar[aa++] = DATA(c, a, b);
        }
        sort(ar, ar+aa);
        a = 0;
        for(i=0; i<aa; i++)
        {
//            deb(i, ar[i].x, ar[i].y);
            sum[i] = ar[i].z;
            k = i;
            for(j=0; j<i; j++)
            {
//                if(i==5)
//                    deb(ar[i].x, ar[i].y, ar[j].x, ar[j].y);
                if( (ar[k].x>ar[j].x and ar[k].y>ar[j].y) )//or (ar[k].x>ar[j].y and ar[k].y>ar[j].x) )
                {
//                    if(i==5)
//                        deb("--->", ar[j].x, ar[j].y, sum[j]);
                    sum[i] = max(sum[i], sum[j]+ar[i].z);
                    //k = j;
                }
                a = max(a, sum[i]);
            }

        }
        pf("Case %d: maximum height = %d\n",++keis, a);
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



