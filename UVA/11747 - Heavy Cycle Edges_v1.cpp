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

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T> void MyDebug(T x, T y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
template <class T> void MyDebug(T x, T y, T z)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << endl;
}
int xx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy[] = {0, -1, 1, 0, -1, 1, 1, -1};   // diagonal -> 8 horizontal/vertical->4
int par[1010];
vector <int> sub;
class DATA
{
public:
    int u, v, cost;
    DATA(int a=0, int b=0, int c=0)
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
int FIND(int r)
{
    if(par[r]==r) return r;
    return par[r]=FIND(par[r]);
}
void UNION(int pa, int pv)
{
    par[pa] = pv;
}

void MST(vector <DATA> &v)
{
    int po = v.size(); //cout <<  "po -> " << po << endl;
    sort(v.begin(), v.end());
    int cow = 0;
    for(int i=0; i<po; i++)
    {
        int u = v[i].u;
        int va = v[i].v;
        int pu = FIND(u);
        int pv = FIND(va);
        //MyDebug(pu, pv);
        if(pu!=pv)
        {
            UNION(pu, pv);
            v[i].cost = -1;
            cow++;
        }
        else sub.pb(v[i].cost);
    }
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11747.inp","r",stdin);
#endif
    ///                                    MAIN
    int m, n, i, j, k, l;
    vector <DATA> va;
    while(sf("%d %d", &n, &m)==2 && m+n)
    {
        for(i=0; i<n; i++)
            par[i] = i;
        va.clear();
        sub.clear();
        int a, b, c;
        for(i=0; i<m; i++)
        {
            sf("%d %d %d", &a, &b, &c);
            va.pb(DATA(a, b, c));
        }
        MST(va);
        k = 0;
        for(i=0; i<sub.size(); i++)
            {
                if(k) pf(" %d", sub[i]);
                else pf("%d", sub[i]);
                k++;
            }

        if(k==0) pf("forest");
        pf("\n");
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
