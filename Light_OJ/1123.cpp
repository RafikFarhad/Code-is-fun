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
#define SIZE 205
int par[SIZE], n, node;

class DATA
{
public:
    int u, v, w;
    DATA(int _u=0, int _v=0, int _w=0)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};


bool COMPA(DATA a, DATA b)
    {
        return a.w<b.w;
    }

DATA all[6002];
void INITIAL()
{
    for(int i=1; i<=n; i++)
        par[i] = i;
    //pf("%d %d \n",par[2], par[3]);
    return;
}

int FIND(int a)
{
    if(a==par[a]) return a;
    return par[a]=FIND(par[a]);
}

void JOIN(int x, int y)
{
    par[x] = y;
    return;
}

int MST()
{
    INITIAL();
    int po = node, i, total=0, cow=0;
    sort(all, all+node, COMPA);

    for(i=0; i<po; i++)
    {
        int x = FIND(all[i].u), y = FIND(all[i].v); //deb(all[i].u, y);
        if(x!=y)
        {
            JOIN(x, y);
            //cow++;
            total+=all[i].w;
            all[cow++] = all[i];
            if(cow==n-1) break;
        }
    }
    node = cow;
    if(cow!=n-1) return -1;
    return total;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, a, b, c, keis=0, i, j, k, m;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(m);
        //all.clear();
        CLR(all);
        edge = node = 0;
        pf("Case %d:\n", ++keis);
        for(i=0; i<m; i++)
        {
            takei(all[node].u);
            takei(all[node].v);
            takei(all[node].w);
            node++;
            if(node<n-1) pf("-1\n");
            else pf("%d\n", MST());
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

