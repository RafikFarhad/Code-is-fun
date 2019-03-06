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
#define SIZE INT_MAX
int x, ar[25];
ll pre[65];

ll GO(int pos, bool issmall)
{
    if(pos==(x+1)/2)
    {
        return issmall;
    }
    if(issmall)
    {
        return 10ll*GO(pos+1, 1);
    }
    ll x1 = 0, x2 = 0;
    if(ar[pos]>ar[x-pos-1])
    {
        if(pos!=0)
        {
            x1 = GO(pos+1, 0);
            x2 = (ar[pos]) * GO(pos+1, 1);
        }
        else
        {
            x1 = GO(pos+1, 0);
            x2 = (ar[pos]-1) * GO(pos+1, 1);
        }
    }
    else if (ar[pos]==ar[x-pos-1])
    {
        //deb("#", ar[pos], ar[x-pos-1]);
        if(pos!=0)
        {
            x1 = GO(pos+1, 0);
            x2 = GO(pos+1, 1) * (ar[pos]);
        }
        else
        {
            x1 = GO(pos+1, 0);
            x2 = (ar[pos]-1)*GO(pos+1, 1);
        }
    }
    else
    {
        if(pos!=0)
        {
            x1 = GO(pos+1, 0);
            x2 = (ar[pos]) * GO(pos+1, 1);
        }
        else
        {
            x1 = GO(pos+1, 0);
            x2 = (ar[pos]-1) * GO(pos+1, 1);
        }
        //deb(x1, x2);
        //deb("#", ar[pos], ar[x-pos-1]);
    }
    //deb("->", pos, x1, x2);
    return x1+x2;
}

ll CALL(ll n)
{
    int br[70], i;
    ll n2, ans;
    CLR(ar);
    n2 = n;
    for(i=0; n2; i++)
    {
        br[i] = n2%10;
        n2/=10;
    }
    x = i;
    CLR(ar);
    for(i=0; i<x; i++)
        ar[i] = br[x-i-1];
    ans = pre[i-1];

    n2 = GO(0,0);
    return ans+n2;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, y;
    ll n, n2;
    ll ans;
    pre[0] = 1;
    pre[1] = pre[2] = 9ll;
    for(i=3; i<20; i++)
    {
        pre[i] = pre[i-2]*10ll;
        //deb(i, pre[i]);
    }
    for(i=1; i<20; i++)
    {
        pre[i] += pre[i-1];
        //deb(i, pre[i]);
    }

    takei(t);
    while(t--)
    {
        takell(n);
        takell(n2);
        if(n>n2)
        {
            ll t = n2;
            n2 = n;
            n = t;
        }
        //deb(n,n2);
        csi;
        n2 = CALL(n2);
        n = CALL(n);
        pf("%lld %lld %lld\n", n2, n, n2-n);
    }

        /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



