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
int xx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int yy[] = {1, -1, 0, 0,  1, -1, 1, -1};
int color[105][105];
int adj[105][105];

void DFS(int i, int j)
{
    color[i][j] = 1;
    for(int po=0; po<8; po++)
    {
        int x = i+xx[po];
        int y = j+yy[po]; //MyDebug(x, y);
        if(x>=0 && y>=0)
        {
            if(adj[x][y] && color[x][y]==0)
            DFS(x, y);
            color[x][y] = 1;
        }
    }
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("572.inp","r",stdin);
#endif
    ///                                    MAIN
    char a[105];
    int i, j, k, l, p, q, m, n;
    while(sf("%d", &m) && m)
    {
        sf("%d ", &n);
        memset(adj, 0, sizeof(adj));
        memset(color, 0, sizeof(color));

        for(i=0; i<m; i++)
        {
            gets(a);
            for(j=0; j<n; j++)
                if(a[j]=='@')
                    adj[i][j] = 1;
        }
        int cow = 0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
                {
                    if(adj[i][j] && color[i][j]==0)
                    {
                        DFS(i, j);
                        cow++;
                    }
                }
        }

        cout << cow << endl;

/*
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
                cout << adj[i][j] << "   ";
                cout << endl;
        }*/
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
