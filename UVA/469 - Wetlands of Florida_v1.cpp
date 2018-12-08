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

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
int cow, r, c;
char adj[105][105];
bool flag[105][105];
int xx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int yy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int i, int j)
{
    //cout << adj[i][j] << endl;
    if(i<0 || j <0 || i>=r || j>=c || flag[i][j] || adj[i][j]!='W') return;
    cow++;
    flag[i][j] = 1;
    for(int po=0; po<8; po++)
    {
        DFS(i+xx[po], j+yy[po]);
    }
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("469.inp","r",stdin);
#endif
    ///                                    MAIN
    int test, i, j, k, pos;
    sf("%d ", &test);
    while(test--)
    {
        sf("\n");
        CLR(adj);
        CLR(flag);
        for(r=0; ; r++)
        {
            gets(adj[r]);
            //puts(adj[r]);
            if(adj[r][0]!='L' && adj[r][0]!='W') break;
        }
        c = strlen(adj[0]);
        //cout << r << endl;
        //gets(adj[r+1]);
        int a, b;
        while(adj[r][0]!='\0')
        {
            ssf(adj[r], "%d %d", &a, &b); //MyDebug(a, b);
            cow = 0;
            CLR(flag);
            DFS(a-1, b-1);
            cout  << cow << endl;
            if(!gets(adj[r])) break;
        }
        if(test) pf("\n");
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
