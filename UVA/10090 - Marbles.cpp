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
#define takell(a)                                scanf("%I64d", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)
#define all(o)                                      o.begin(), o.end()

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
long long g;
typedef pair<long long, long long> pii;

#define x first
#define y second
long long GCD(long long a, long long b)
{
    if(b==0) return a;
    return GCD(b, a%b);
}
pii extendedEuclid(long long a, long long b)    // returns x, y | ax + by = gcd(a,b)
{
    if(b == 0)
    {
        g = a;
        return {1,0};
    }
    else
    {
    pii d = extendedEuclid(b, a % b);
    return pii(d.y, d.x - d.y * (a / b));
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, k, l, t, keis=0, n1, c1, n2, c2, n, m01, m02, cost, m1, m2;
    while(sf("%lld", &n)==1 and n)
    {
        takell(c1);
        takell(n1);
        takell(c2);
        takell(n2);
        //g = GCD(n1, n2);
        pii ans = extendedEuclid(n1, n2);
        if(n%g!=0)
        {
            pf("failed\n");
        }
        else
        {

         //   pf("m01 = %lld m02 = %lld\n", ans.x, ans.y);
            m01 = ans.x*n/g;
            m02 = ans.y*n/g;
            //deb(m01, m02, g);
            n1/=g;
            n2/=g;
            i = ceil(-m01/(double)n2);
            j = floor(m02/(double)n1);
//            m01*=(n/g);
//            m02*=(n/g);
            if(i>j)
            {
                pf("failed\n");
                continue;
            }
          //  deb(i, j);
               l = 0;
              cost = (c1*n2-c2*n1);
              if( i*cost  < j*cost )
                l = i;
              else
                l = j;

            m1 = m01 + n2*l;
            m2 = m02 - n1*l;
            pf("%lld %lld\n", m1, m2);
        }
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}
