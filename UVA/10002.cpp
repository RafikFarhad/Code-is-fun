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

class POINT
{
public:
    double x, y;
    POINT();
    POINT(double _x, double _y): x(_x), y(_y){};
};
vector <POINT> point;
vector <POINT> answer;//(1000);
int n;

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

int CONVEX_HULL()
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
    answer[0] = point[0];
    answer[1] = point[1];
    answer[2] = point[2];
    l = 3;
    for(i=3; i<n; i++)
    {
        while(AREA(answer[l-2], answer[l-1], point[i])<=0.00000001)
        {
            l--;
        }
        answer[l++] = point[i];
    }
    //for(i=0; i<n; i++)
      //  deb(answer[i].x, answer[i].y);
    return l;
}
double xx, yy;
void GET_CENTRE(int n)
{
    double a = 0.0, area = 0.0, xsum=0.0, ysum=0.0, temp;
    int i;
    answer[n] = answer[0];
    n++;
    xx = 0.0;
    yy = 0.0;
    for(i=0; i<n-1; i++)
    {
        temp = answer[i].x*answer[i+1].y - answer[i].y*answer[i+1].x;
        xx += (answer[i].x+answer[i+1].x)*temp;
        yy += (answer[i].y+answer[i+1].y)*temp;
        area+=temp;
    }
    area/=2.0;
    xx= xx/(double)area/6.0;
    yy= yy/(double)area/6.0;
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l, keis=0, a, b, c, d;
    double q, x, y, area1, area2;
    for(i=0; i<500; i++)
        answer.pb(POINT(0,0));
    while(sf("%d", &n)==1 and n>2)
    {
        point.clear();
        for(i=0; i<n; i++)
        {
            sf("%lf %lf", &x, &y);
            point.pb(POINT(x, y));
        }

        l = CONVEX_HULL();
        //deb(l);
        GET_CENTRE(l);
        pf("%.3lf %.3lf\n", xx, yy);

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



