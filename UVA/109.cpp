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

class POINT
{
public:
    double x, y;
    POINT();
    POINT(double _x, double _y): x(_x), y(_y){};
};
vector <POINT> point;
vector <POINT> answer[25];//(1000);
vector <POINT> missile;
bool REAL[25];
double area[25], xx, yy;

int n, kingdom, l[25];

double DIST(POINT a, POINT b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double AREA(POINT a, POINT b, POINT c)
{
    return (a.x*(b.y-c.y) + a.y*(c.x-b.x) + (b.x*c.y-b.y*c.x));
}

bool COMP(POINT a, POINT b)
{
    if(fabs(AREA(point[0], a, b))<=0.000000001)
    {
        return DIST(point[0], a) < DIST(point[0], b);
    }
    double slope1 = atan2(a.y-point[0].y, a.x-point[0].x);
    double slope2 = atan2(b.y-point[0].y, b.x-point[0].x);
    return slope1-slope2<0.000000001;
}

int CONVEX_HULL(int x)
{
    int i, j, k, l;
    for(i=1; i<n; i++)
    {
        if(point[0].x==point[i].x)
        {
            if(point[0].y>point[i].y)
            {
                swap(point[0].y, point[i].y);
                swap(point[0].x, point[i].x);
            }
        }
        else if(point[0].x>point[i].x)
        {
            swap(point[0].y, point[i].y);
            swap(point[0].x, point[i].x);
        }
    }
    sort(point.begin()+1, point.end(), COMP);
    answer[x][0] = point[0];
    answer[x][1] = point[1];
    //answer[x][2] = point[x][2];
    l = 2;
    for(i=2; i<n; i++)
    {
        while(AREA(answer[x][l-2], answer[x][l-1], point[i])<=0.00000001 and l>1)
        {
            l--;
        }
        answer[x][l++] = point[i];
    }
    //for(i=0; i<n; i++)
      //  deb(answer[i].x, answer[i].y);
    return l;
}

double GET_AREA(vector <POINT> pp, int n)
{
    pp.pb(pp[0]);
    double a = 0.0;
    int i;
    pp[n] = pp[0];
    n++;
    for(i=0; i<n-1; i++)
    {
        a = a + (pp[i].x*pp[i+1].y);
        a = a - (pp[i].y*pp[i+1].x);
    }
    a/=2.0;
    pp.pop_back();
    return fabs(a);
}

bool IS_OK(vector <POINT> pp, int n, int x)
{
    double dummy = 0.0;
    int i, j, k;
    pp.pb(pp[0]);
    pp[n] = pp[0];
    for(i=0; i<n; i++)
    {
        //deb("*", pp[i].x, pp[i+1].x);
        dummy = dummy + fabs(AREA(pp[i], pp[i+1], POINT(xx, yy)))/2.0;
    }
    //dummy/=2.0;
    dummy = fabs(dummy);
    //deb(dummy, area[x], x);
   // deb(fabs(dummy-area[x]), xx, yy, x);
    if(fabs(dummy-area[x])<=0.0000000001)
        return true;
    return false;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, keis=0, a, b, c, d;
    double q, x, y, area1, area2;
    kingdom = -1;
    while(sf("%d", &n)==1 and n!=-1)
    {
        ++kingdom;
        point.clear();
        for(i=0; i<n; i++)
        {
            answer[kingdom].pb(POINT(0.0, 0.0));
            sf("%lf%lf", &x, &y);
            point.pb(POINT(x, y));
        }
        l[kingdom] = CONVEX_HULL(kingdom);
        area[kingdom] = GET_AREA(answer[kingdom], l[kingdom]);

        //deb(kingdom, area[kingdom]);


        /* //answer[kingdom].resize(l);
        for(i=0; i<l[kingdom]; i++)
        {
            deb(answer[kingdom][i].x, answer[kingdom][i].y);
        }
        NL; NL; NL;*/
    }
    CLR(REAL);
    ++kingdom;
    while(sf("%lf%lf", &xx, &yy)!=EOF)
    {
        for(i=0; i<kingdom; i++)
        {
            //deb(i);
            //if(REAL[i]) continue;
            if(IS_OK(answer[i], l[i], i))
            {
                REAL[i] = 1;
                //break;
            }
            //ok
        }
    }
    xx = 0.00;
    for(i=0; i<kingdom; i++)
        if(REAL[i])
            xx+=area[i];

    pf("%.2lf\n", xx);


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



