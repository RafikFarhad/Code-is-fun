
/*Winter is coming*/


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
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-03-21-23.09 _ Tuesday       */
/****************************************************/
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
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

class POINT
{
public:
    double x, y;
//POINT();
    POINT(double _x=0.0, double _y=0.0): x(_x), y(_y) {};
};

double DIST(POINT a, POINT b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

class LINE
{
public:
    double a, b, c;
    LINE(double _a=0, double _b=0, double _c=0):a(_a), b(_b), c(_c) {};
    LINE(POINT a, POINT b)
    {
//        int aa =
//        int bb =
//        int cc = ;
//        int p = __gcd(aa, bb);
//        p = __gcd(p, cc);
//        aa/=p;
//        bb/=p;
//        cc/=p;
        this->a = a.y - b.y;;//aa;
        this->b = -a.x + b.x;//bb;
        this->c = a.x*b.y - a.y*b.x;//cc;
    }
    LINE PERPENDICULAR_THORUGH_THIS_POINT(POINT p)
    {
        LINE temp;
        temp.a = -this->b;
        temp.b = this->a;
        temp.c = this->b*p.x-this->a*p.y;
        return temp;
    }
    POINT CROSS_POINT(LINE qq)
    {
        POINT tem;
        tem.y = (qq.a*this->c - this->a*qq.c) / (this->a*qq.b - qq.a*this->b);
        tem.x = (this->b*qq.c - qq.b*this->c) / (this->a*qq.b - qq.a*this->b);
        return tem;
    }
    double DIST_FROM_THIS(POINT p)
    {
        return (((p.x*this->a)+ (p.y*this->b) + this->c)/sqrt(a*a+b*b));
    }
};
double AREA(POINT a, POINT b, POINT c)
{
    return fabs(a.x*(b.y-c.y) + a.y*(c.x-b.x) + (b.x*c.y-b.y*c.x));
}
#define eps 1e-9
int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0);
    POINT c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    int n;
    LINE p, q;
    double ans, dis;
    while(sf("%lf%lf", &c.x, &c.y)!=EOF)
    {
        takei(n);
        sf("%lf%lf", &a.x, &a.y);
        ans = 1e25;
        double d1, d2, d3;
        for(i=0; i<n; i++)
        {
            sf("%lf%lf", &b.x, &b.y);
            p = LINE(a, b);

            if(AREA(a, b, c)<eps)
            {
                d1 = DIST(a, c), d2 = DIST(b, c), d3 = DIST(a, b);
                if(fabs(d1+d2-d3)<eps)
                {
                    x.x = c.x;
                    x.y = c.y;
                    ans = 0;
                    a.x = b.x;
                a.y = b.y;
                continue;
                }
                if(ans-DIST(a,c)>eps)
                {
                    x.x = a.x;
                    x.y = a.y;
                    ans = DIST(a,c);
                }
                if(ans-DIST(b,c)>eps)
                {
                    x.x = b.x;
                    x.y = b.y;
                    ans = DIST(b,c);
                }
                a.x = b.x;
                a.y = b.y;
                continue;
            }
            q = p.PERPENDICULAR_THORUGH_THIS_POINT(c);
            d = p.CROSS_POINT(q);
            d1 = DIST(a, d), d2 = DIST(b, d), d3 = DIST(a, b);
//            deb(d.x, d.y, "--------------");
//            deb(d1, d2, d3);
            if(fabs(d1+d2-d3)<eps)
            {
                dis = DIST(c,d);
                //deb(ans, dis);
                if(ans-dis>eps)
                {
                    x.x = d.x;
                    x.y = d.y;
                    ans = dis;
                }
                a.x = b.x;
                a.y = b.y;
                continue;
            }
            if(ans-DIST(a,c)>eps)
            {
                //deb(ans, DIST(a,c), DIST(b,c));
                x.x = a.x;
                x.y = a.y;
                ans = DIST(a,c);
            }
            if(ans-DIST(b,c)>eps)
            {
                //deb(ans, DIST(b,c));
                x.x = b.x;
                x.y = b.y;
                ans = DIST(b,c);
            }


            a.x = b.x;
            a.y = b.y;
        }
        //deb(ans);
        pf("%.4lf\n", x.x);
        pf("%.4lf\n", x.y);
        //pf("%.4lf\n", ans);
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



