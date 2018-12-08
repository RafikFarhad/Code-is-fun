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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 5000003

char adj[22][22];
bool flag[22][22];
int level[22][22];

int BFS(int s1, int s2)
{
    CLR(flag);
    CLR(level);
    int i, j, ux, uy, vx, vy;
    queue <int> qu;
    qu.push(s1);
    qu.push(s2);
    level[s1][s2] = 0;
    flag[s1][s2] = 1;
    while(qu.size())
    {
        ux = qu.front(); qu.pop();
        uy = qu.front(); qu.pop();
        for(i=0; i<4; i++)
        {
            vx = ux + xx[i];
            vy = uy + yy[i];
            if(adj[vx][vy]!='#' && adj[vx][vy]!='m' && flag[vx][vy]==0)
            {
                flag[vx][vy] = 1;
                level[vx][vy] = level[ux][uy] + 1;
                //deb(adj[vx][vy]);
                if(adj[vx][vy]=='h') return level[vx][vy];
                qu.push(vx);
                qu.push(vy);
            }
        }
    }
    return -1;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int r, c, i, j, mark, p, t, keis=0;
    takei(t);
    while(t--)
    {
        sf("%d %d ", &r, &c);
        for(i=0; i<r; i++)
            gets(adj[i]);
        mark = 0;
        for(i=0; i<r; i++)
            for(j=0; j<c;j++)
        {
            if(adj[i][j]=='a' || adj[i][j]=='b' || adj[i][j]=='c')
            {
                mark = MAX(mark, BFS(i, j));
            }
        }
        pf("Case %d: %d\n", ++keis, mark);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

