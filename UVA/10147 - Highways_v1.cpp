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
int par[800];
class DATA
{
public:
    int c1, c2;
    double d;
    DATA(int c11, int c22, double di)
    {
        c1 = c11;
        c2 = c22;
        d = di;
    }
    bool operator < (const DATA &k) const
    {
        return d<k.d;
    }
};
vector <DATA> v;
double DIS(int i, int j, int k, int l)
{
    return sqrt((i-k)*(i-k)+(j-l)*(j-l));
}

int FIND(int n)
{
    if(par[n]==n) return n;
    return par[n]=FIND(par[n]);
}

void UNION(int a, int b)
{
    par[a] = b;
}

vector < DATA> last;
void MST(vector <DATA> &v, int node)
{
    last.clear();
    sort(v.begin(), v.end());
    int s = v.size(), cow=0;
    for(int i=0; i<s; i++)
    {ok
        //cout << v[i].d << endl;
        int pu = FIND(v[i].c1);
        int pv = FIND(v[i].c2);
        if(pu!=pv)
        {
            UNION(v[i].c1, v[i].c2);
            last.pb(DATA(v[i].c1, v[i].c2, 0.0));
            cow++;
        }
        if(cow==node) return;
    }
}
int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10147.inp","r",stdin);
#endif
    ///                                    MAIN
    int n, i, j, k, x[800], y[800], t, a, b;
    sf("%d", &t);
    while(t--)
    {
        v.clear();
        sf("%d", &n);
        for(i=1; i<=n; i++)
            {
                par[i] = i;
                sf("%d %d", &x[i], &y[i]);
            }
        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++)
                {
                    v.pb(DATA(i, j, DIS(x[i], y[i], x[j], y[j])));
                    //cout << i << " " << j << " " << DIS(x[i], y[i], x[j], y[j])<< endl;
                }
        sf("%d", &k);
        for(i=0; i<k; i++)
        {
            sf("%d %d", &a, &b);
            par[FIND(a)] = b;
            //par[FIND(b)] = a;
            //par[b] = a; MyDebug(a, par[b]);
            //par[a] = b;
        }
        MST(v, n-k-1);
        if(last.size()==0) pf("No new highways need\n");
        else
        {
            for(i=0; i<last.size(); i++)
            cout << last[i].c1 << " " << last[i].c2 << endl;
        }
        if(t) pf("\n");
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
