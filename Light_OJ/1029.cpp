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
#define CLR(o) memset(o, 0, sizeof o)
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
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 105
int par[SIZE], n;

int BAIR_KORO(int r)
{
    if(par[r]==r) return r;
    return par[r] = BAIR_KORO(par[r]);
}

void JORA_LAGAO(int x, int y)
{
    par[x] = y;
    return;
}

void SHURU(int n)
{
    for(int i=0; i<=n; i++)
        par[i] = i;
    return;
}

class TOTTHO
{
public:
    int u, v, w;
    TOTTHO(int _u=0, int _v=0, int _w=0)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

bool TULONA_SHUJA(TOTTHO a, TOTTHO b)
{
    return a.w < b.w;
}

bool TULONA_ULTA(TOTTHO a, TOTTHO b)
{
    return a.w > b.w;
}

int ULTA_MST(vector <TOTTHO> v)
{
    sort(v.begin(), v.end(), TULONA_ULTA);
    int po = v.size(), cow=0, total = 0, i, u, va, cost, par_u, par_v;
    //deb(po);
    for(i=0; i<po; i++)
    {
        u = v[i].u;
        va = v[i].v;
        cost = v[i].w;
        par_u = BAIR_KORO(u);
        par_v = BAIR_KORO(va);
        //deb(u, va, cost);
        if(par_u!=par_v)
        {
            JORA_LAGAO(par_u, par_v);
            total += cost;
            cow++;
        }
        if(cow==n-1) break;
    }
    return total;
}

int SHUJA_MST(vector <TOTTHO> v)
{
    sort(v.begin(), v.end(), TULONA_SHUJA);
    int po = v.size(), cow=0, total = 0, i, u, va, cost, par_u, par_v;
    //deb(po);
    for(i=0; i<po; i++)
    {
        u = v[i].u;
        va = v[i].v;
        cost = v[i].w;
        par_u = BAIR_KORO(u);
        par_v = BAIR_KORO(va);
        //deb(u, va, cost);
        if(par_u!=par_v)
        {
            JORA_LAGAO(par_u, par_v);
            total += cost;
            cow++;
        }
        if(cow==n-1) break;
    }
    return total;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    vector <TOTTHO> v;
    int  i, j, k, u, va, w, t, keis = 0;
    takei(t);
    while(t--)
    {
        takei(n);n++;
        SHURU(n);
        v.clear();
        while(1)
        {
            takei(u); takei(va); takei(w);
            if(u+va+w==0) break;
            v.pb(TOTTHO(u, va, w));
        }
        j = SHUJA_MST(v);
        SHURU(n);
        k = ULTA_MST(v);
        k = j+k;
        if(k&1) pf("Case %d: %d/2\n", ++keis, k);
        else pf("Case %d: %d\n", ++keis, k/2);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

