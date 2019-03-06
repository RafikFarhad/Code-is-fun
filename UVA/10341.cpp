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
double p, q, r, s, t, u;
double DO(double mid)
{
   // deb( t*mid*mid + u);
    //deb(t,mid, u);
    return p*pow(2.7182818, (-mid)) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t*mid*mid + u;
}
#define EPS 10e-9
int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    //int i, j, k, l, t, keis=0;
    double hi, mid, lo, ans, pp;
    bool f;
    while(sf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u)!=EOF)
    {
        lo = 0.0;
        hi = 1.0;
        mid = (hi+lo)/2.0;
        ans = -1.0;
        f = 0;
        //deb(EPS);
        if(DO(0.0)*DO(1.00)>0.0)
        {
            pf("No solution\n");
            continue;
        }
        while(hi > EPS+lo)
        {
            pp = DO(mid);

            if(pp>0.0)
                lo = mid;
            else
                hi = mid;
            mid = (hi+lo)/2.0;
        }

            pf("%.4lf\n", mid);

    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


