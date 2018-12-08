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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define CLR(o) memset(o, 0, sizeof o)
#define pb push_back
#define ppp system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1, class T2> void MyDebug(T1 x, T1 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void MyDebug(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
template <class T1, class T2, class T3, class T4> void MyDebug(T1 x, T2 y, T3 z, T4 xx) { cout << "Debugging: " << x << ", " << y << ", " << z << ", " << xx << endl;}
vector <int> v[20010];
int level[20010];

int BFS(int k)
{
    queue <int> qu;
    int i, j, x, y, p=0, q=0;
    level[k] = 0;
    qu.push(k);
    q++;
    while(qu.size())
    {
        x = qu.front(); qu.pop();
        for(i=0; i<v[x].size(); i++)
        {
            y = v[x][i];
            if(level[y]==-1)
            {
                if(level[x]==0)
                {
                    level[y] = 1;
                    p++;
                }
                else
                {
                    level[y] = 0;
                    q++;
                }
                qu.push(y);
            }
        }
    }
    return MAX(p,q);
}
int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, x, y, t, ti = 0, p, n;
    sf("%d", &t);
    while(t--)
    {
        j = 0;
        for(i=0; i<20001; i++) v[i].clear();
        sf("%d", &n);
        while(n--)
        {
            sf("%d %d", &x, &y);
            if(j<x) j=x;
            if(j<y) j = y;
            v[x].pb(y);
            v[y].pb(x);
        }
        x = 0;
        memset(level, -1, sizeof level);
        for(i=1; i<=j; i++)
            if(level[i]==-1 && v[i].size())
                x+=BFS(i);
        pf("Case %d: %d\n", ++ti, x);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

