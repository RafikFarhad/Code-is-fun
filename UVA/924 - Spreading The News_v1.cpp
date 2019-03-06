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
#define INF 2500
vector <int> v[INF+5];
bool flag[INF+5];
int level[INF+5], maxi[INF+5];

void BFS(int start)
{
    CLR(flag, INF);
    CLR(level, INF);
    CLR(maxi, INF);
    int u, w;
    queue <int> qu;
    qu.push(start);
    flag[start]=1;
    level[start] = 0;
    while(qu.size())
    {
        u = qu.front(); qu.pop();
        for(w=0; w<v[u].size(); w++)
        {
            //MyDebug(u, v[u][w]);
            if(!flag[v[u][w]])
            {
                flag[v[u][w]] = 1;
                level[v[u][w]] = level[u] + 1;
                maxi[level[v[u][w]]]++;
                qu.push(v[u][w]);
            }
        }
    }
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("924.inp","r",stdin);
#endif
    ///                                    MAIN
    int node, i, j, t, p, q;
    sf("%d", &node);
    for(i=0; i<node; i++) v[i].clear();
    for(i=0; i<node; i++)
    {
        sf("%d", &t);
        for(j=0; j<t; j++)
        {
            sf("%d", &q);
            v[i].pb(q);
        }
    }
    sf("%d", &t);
    while(t--)
    {
        int s, k=0, pos=0;
        //maxi = 0;
        sf("%d", &s);
        BFS(s);
        for(i=0; i<node; i++)
            {
                //MyDebug(i, maxi[i]);
                if(maxi[i]>k)
                    {
                        k = maxi[i];
                        pos = i;
                    }
            }
        if(k==0) pf("0\n");
        else pf("%d %d\n", k, pos);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
