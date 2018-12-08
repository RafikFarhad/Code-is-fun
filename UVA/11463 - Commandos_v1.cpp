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
#define SIZE 100000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
int adj[101][101];

void F_W(int n)
{
    int i, j, k;
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                adj[i][j] = MIN(adj[i][j], adj[i][k]+adj[k][j]);
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11463.inp","r",stdin);
#endif
    ///                                    MAIN
    int t, i, j, p, q, a, b;
    sf("%d", &t);
    for(i=0; i<t; i++)
    {
        sf("%d %d", &p, &q);
        for(j=0; j<p+1; j++)
        {
            for(a=0; a<p+1; a++)
                adj[j][a] = SIZE;
            //adj[j][j] = 0;
        }
        for(j=0; j<p+1; j++)
        {
            adj[j][j] = 0;
        }
        while(q--)
        {
            sf("%d %d", &a, &b);
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        F_W(p);
        sf("%d %d", &a, &b);
        int mini = -1; //cout << mini;
        for(j=0; j<p; j++)
        {
            mini = max(mini, adj[a][j]+adj[j][b]);
        }
        pf("Case %d: %d\n", i+1, mini);
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
