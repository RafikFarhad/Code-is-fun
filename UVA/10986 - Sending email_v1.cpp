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
#define CLR(a, b) for(int o=0; o<b; o++) a[o] = 0
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
#define MAX 20000
class DATA
{
public:
    int v, cost;
    //DATA();
    DATA(int _v=0, int _cost=0)
    {
        v = _v;
        cost = _cost;
    }
    bool operator < (DATA a) const
    {
        return cost > a.cost;
    }
};
vector <DATA> va[MAX+5];
bool flag[MAX];
int dis[MAX+5];

void DHISHUM(int n, int s)
{
    int i, j, k, l;
    for(i=0; i<n; i++) dis[i] = SIZE;
    dis[s] = 0;
    priority_queue<DATA> pq;
    pq.push(DATA(s, 0));
    while(pq.size())
    {
        DATA working = pq.top(); pq.pop();
       // MyDebug(working.v, working.cost);
        for(k=0; k<va[working.v].size(); k++)
        {
            DATA p = va[working.v][k];
            //MyDebug(p.v, p.cost, working.cost); ok
            if(dis[p.v]> working.cost + p.cost)
            {
                dis[p.v] = working.cost + p.cost;
                pq.push(DATA(p.v, dis[p.v])); //MyDebug(p.v, dis[p.v]);
            }
        }
    }
}
int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10986.inp","r",stdin);
#endif
    ///                                    MAIN
    int n, m, s, t, cas, i, j, k, p, q, w;
    sf("%d", &cas);
    for(i=0; i<cas; i++)
    {
        sf("%d %d %d %d", &n, &m, &s, &t);
        for(j=0; j<n; j++) va[j].clear();
        for(j=0; j<m; j++)
        {
            sf("%d %d %d", &p, &q, &w);
            va[p].pb(DATA(q, w));
            va[q].pb(DATA(p, w));
        }
        DHISHUM(n, s);
        //MyDebug(s, t);
        if(dis[t]==SIZE) pf("Case #%d: unreachable\n", i+1);
        else pf("Case #%d: %d\n", i+1, dis[t]);
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
