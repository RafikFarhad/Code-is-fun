/**         HODOR          **/



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
//int SET(int mask, int pos){return mask singlebar (1<<pos);}
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
vector <POINT> point;
vector <POINT> answer;

int n;

double DIST(POINT a, POINT b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double DIST_SQUARE(POINT a, POINT b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

double TRIANGLE_AREA(POINT a, POINT b, POINT c)
{
    return (a.x*(b.y-c.y) + a.y*(c.x-b.x) + (b.x*c.y-b.y*c.x));
}

double AREA(vector<POINT> &a)
{
    double area = 0.0;
    int i, j;
    for(i=0; i<a.size(); i++)
    {
        area += (a[i].x * a[(i+1)%a.size()].y);
        area -= (a[i].y * a[(i+1)%a.size()].x);
    }
    return area;
}

class LINE
{
public:
    double a, b, c;
    /// Default Constructor
    LINE(double _a=0, double _b=0, double _c=0):a(_a), b(_b), c(_c) {};
    /// Constructor from point
    LINE(POINT a, POINT b)
    {
        this->a = a.y - b.y;
        this->b = -a.x + b.x;
        this->c = a.x*b.y - a.y*b.x;
    }
    LINE PERPENDICULAR_THORUGH_THIS_POINT(POINT p) /// Return Perpendicular line
    {
        LINE temp;
        temp.a = -this->b;
        temp.b = this->a;
        temp.c = this->b*p.x-this->a*p.y;
        return temp;
    }
    bool IS_PARELLEL(LINE qq)
    {
        if(fabs((this->a*qq.b - qq.a*this->b))<.00000000001) return true;
        return false;
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
        return fabs(((p.x*this->a)+ (p.y*this->b) + this->c)/sqrt(a*a+b*b));
    }
};


double ANGLE_OF_THREE(POINT a, POINT b, POINT c) /// Finds the angle abc
{
    double aa = DIST_SQUARE(b, c),
    cc =  DIST_SQUARE(b, a),
    bb =  DIST_SQUARE(a, c),
    t = 2*sqrt(aa)*sqrt(cc);
    return acos((aa+cc-bb)/t)/(PI/180);
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);

    deb((acos(0))/(PI/180));
    deb(PI);

    POINT p = POINT(0,1);
    POINT q = POINT(1,1);
    POINT pp = POINT(0,2);
    POINT qq = POINT(2,5);

    LINE p1 = LINE(p, q);
    LINE p2 = LINE(pp, qq);

    deb(p1.IS_PARELLEL(p2));

    POINT p3 = p1.CROSS_POINT(p2);
    deb(p3.x, p3.y);

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


