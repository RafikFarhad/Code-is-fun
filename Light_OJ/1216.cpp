/// #define_SUST
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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen(b, "w", stdout);
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << ", " << q << ", " << r << ", " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int t, keis=0;
    double r1, r2, r, rp, h, p, l;
    takei(t);
    while(t--)
    {
        sf("%lf %lf %lf %lf", &r1, &r2, &h, &p);
        rp = (r1-r2)*p/h + r2;
        //l = sqrt((p*p)+(rp-r2)*(rp-r2));
        r = PI*p*(rp*rp + rp*r2 + r2*r2)/3;
        //deb(rp, l, rp, rp-r2);
        pf("Case %d: %lf\n", ++keis, r);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

