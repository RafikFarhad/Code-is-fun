/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause");
#define ppp system("pause");
#define ok cout << "OK" <<endl;
#define pf printf
#define CLR(a) memset(a, 0, sizeof(a))
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
int xx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy[] = {0, -1, 1, 0, -1, 1, 1, -1};   // diagonal -> 8 horizontal/vertical->4

double DIS(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int par[105];

int FIND(int r)
{
    if(par[r]==r) return r;
    return par[r]=FIND(par[r]);
}

class DATA
{
public:
    int u, v;
    double cost;
    DATA();
    DATA(int a=0, int b=0, double c=0)
    {
        u = a;
        v = b;
        cost = c;
    }
    bool operator < (const DATA &p) const
    {
        return cost < p.cost;
    }
};

void UNION(int pa, int pv)
{
    par[pa] = pv;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10034.inp","r",stdin);
#endif
    ///                                    MAIN
    int t, i, j, k, n;
    double x[105], y[105], p, q, r;
    vector <DATA> v;
    sf("%d", &t);
    while(t--)
    {
        sf("%d", &n); v.clear();
        for(i=0; i<n; i++)
        {
            par[i] = i;
            sf("%lf %lf", &x[i], &y[i]);
        }
        int po=0;
        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
        {
            v.pb(DATA(i, j, DIS(x[i], y[i], x[j], y[j])));
            po++;
        }
        //cout << po << endl;
        sort(v.begin(), v.end());
        int cow = 0;
        double total = 0.0;
        for(i=0; i<po; i++)
        {
            int u = v[i].u;
            int va = v[i].v;
            double cost = v[i].cost;
            int pu = FIND(u);
            int pv = FIND(va);
            //MyDebug(pu, pv);
            if(pu!=pv)
            {
                UNION(pu, pv);
                total+=cost;
                cow++;
            }
            if(cow==po-1) break;
        }

        pf("%.2lf\n", total);
        if(t) pf("\n");

        /*for(i=0; i<po; i++)
        {
            cout << v[i].u << " " << v[i].v << " " << v[i].cost << endl;
        }*/
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
