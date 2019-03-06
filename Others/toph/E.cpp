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
//#define mp                                      make_pair
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
#define ull                                       long long
#define exx                                     2.7182818284590452353602875

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long   POOW(long long   b, long long   p) { if(p==0) return 1llu; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX

long long   g, a, b, m, n, g2, g3;
vector <long long> v1, v2;

long long   COUNT(long long a)
{
    long long i, j;
    long long k;
    for(i=0; i<65; i++)
    {
        for(j=0; j<65; j++)
        {
            if((g2+i+1)*(g3+j+1)==a)
            {
               // deb("->", (g2+i+1)*(g3+j+1));
               // deb(i, j, a);
                k = POOW(2, i) * POOW(3, j);
                if(k<1) continue;
                k = g*k;
                v1.pb(k);
            }
        }
    }
    return 0;
}
long long COUNT_b(ll a)
{
    long long i, j;
    ll k;//, l = 1e18;
    for(i=0; i<65; i++)
    {
        for(j=0; j<65; j++)
        {
            if((g2+i+1)*(g3+j+1)==a)
            {
                //deb("->", (g2+i+1)*(g3+j+1));
                //deb(i, j, a);
                k = POOW(2, i) * POOW(3, j);
                k = g*k;
                if(k<1) continue;
                v2.pb(k);
            }
        }
    }
    return 0;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0;
    long long   c, d, x, y;
    takei(t);
    while(t--)
    {

        takell(g);
        takell(a);
        takell(b);
        c = g;
        g2 = 0;
        g3  = 0;
        while(c%3ll==0)
        {
            g3++;
            c/=3ll;
        }

        while(c%2ll==0)
        {
            g2++;
            c/=2ll;
        }
        v1.clear();
        v2.clear();
        //deb(g2, g3);
        c = COUNT(a);
        d = COUNT_b(b);
        k =v1.size();
        l = v2.size();
        c = d = 1e18;

        //deb(c, log10(c));
        //deb(j, k);
        for(i=0; i<k; i++)
            for(j=0; j<l; j++)
            {
                //deb(v1[i], v2[j], __gcd(v1[i], v2[j]));
                if(__gcd(v1[i], v2[j])==g)
                {
                    if(c>v1[i])
                    {
                        c = v1[i];
                        d = v2[j];
                    }
                    else if(c==v1[i] and d>v2[j])
                        d = v2[j];
                }
            }
        pf("%lld %lld\n", c, d);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



