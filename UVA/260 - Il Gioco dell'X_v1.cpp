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
int xx[] = {0, 0, 1, -1, -1,  1};
int yy[] = {1, -1, 0, 0, -1, 1};

char adj[210][210];
bool flag[210][210];
const char b = 'b', w = 'w';
char result;
int n;
void DFS(int i, int j, char curr)
{
    //MyDebug(i, j);
    if( i<0 || j<0 || i==n || j==n || flag[i][j] || adj[i][j]!=curr) return;
    if(j==n-1 && adj[i][j]==w) {result = 'W'; return;}
    if(i==n-1 && adj[i][j]==b) {result = 'B'; return;}
    flag[i][j] = 1;
    for(int k=0; k<6; k++)
        DFS(i+xx[k], j+yy[k], curr);
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("260.inp","r",stdin);
#endif
    ///                                    MAIN
    int t, i, j, k, keis=0;
    while(sf("%d ", &n)==1 && n)
    {
        for(i=0; i<n; i++)
            gets(adj[i]);
        memset(flag, 0, sizeof(flag));
        for(i=0; i<n; i++)
        { //cout << adj[0][i] << endl;
            if(!flag[0][i] && adj[0][i]==b)
                DFS(0, i, b);
        }
        for(i=0; i<n; i++)
        {
            if(!flag[i][0] && adj[i][0]==w)
                DFS(i, 0, w);
        }
        pf("%d %c\n", ++keis, result);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
