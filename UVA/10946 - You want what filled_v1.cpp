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
int xx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy[] = {0, -1, 1, 0, -1, 1, 1, -1};
char adj[55][55];
int r, c, cow;

void DFS(int i, int j, char k)
{
    if(i<0 || j<0 || i==r || j==c || adj[i][j]!=k) return;
    cow++;
    adj[i][j] = '.';
    for(int po=0; po<4; po++)
        DFS(i+xx[po], j+yy[po], k);
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10946.inp","r",stdin);
#endif
    ///                                    MAIN
    int t, i, j, k, keis=0;
    while(sf("%d %d ", &r, &c)==2 && r+c)
    {
        for(i=0; i<r; i++)
            gets(adj[i]);
        vector <int> v[500];
        for(i=0; i<500; i++) v[i].clear();
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(adj[i][j]>='A' && adj[i][j] <='Z')
                {
                    char ko = adj[i][j];
                    cow = 0;
                    DFS(i, j, adj[i][j]); //MyDebug(cow, i);
                    v[cow].pb(ko);
                }
            }
        }
        pf("Problem %d:\n", ++keis);
        for(i=499; i>0; i--)
        {
            if((int)v[i].size()==0) continue;
            sort(v[i].begin(), v[i].end());
            for(j=0; j<v[i].size(); j++)
                pf("%c %d\n", v[i][j], i);
        }
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
