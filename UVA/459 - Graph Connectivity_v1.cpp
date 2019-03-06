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
int xx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int yy[] = {1, -1, 0, 0,  1, -1, 1, -1};
int color[30];
vector<int> v[30];

void DFS(int i)
{
    color[i] = 1;
    for(int po=0; po<v[i].size(); po++)
    {
        int x = v[i][po];
        if(color[x]==0)
            DFS(x);
        color[x] = 1;
    }
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("459.inp","r",stdin);
#endif
    ///                                    MAIN
    char a[3];
    int i, j, k, p, t, q, m, n=0;
    bool l = false;
    sf("%d ", &t);
    sf("\n");
    while(t--)
    {
        memset(color, 0, sizeof(color));
        gets(a);
        m = a[0] - 65;
        for(j=0; j<=m; j++) v[j].clear();
        while(gets(a) && a[0])
        {
            p = a[0] - 'A';
            q = a[1] - 'A';
            v[p].pb(q);
            v[q].pb(p);
        }
        int cow = 0; //cout << m << endl;
        for(i=0; i<=m; i++)
        {
            if(color[i]==0)
            {
                DFS(i);
                cow++;
            }
        }
        if(l) pf("\n"); l = true;
        pf("%d\n", cow);
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
