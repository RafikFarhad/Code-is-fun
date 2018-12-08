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
int xx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int yy[] = {1, -1, -2, -2, -1, 1, 2, 2};
int xx1[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy1[] = {0, -1, 1, 0, -1, 1, 1, -1};
char adj[200][200];
int flag[200][200], level[200][200], m, n;

bool VALID(int x, int y)
{
    if(x>-1 && y>-1 && x<m && y<n) return true;
    return false;
}



void BFS(int x, int y)
{
    //MyDebug(x, y);
    queue <pair <int, int> > qu;
    qu.push(make_pair(x, y));
    //qu.push(y);
    level[x][y] = 0;
    flag[x][y] = 1;
    while(qu.size())
    {
        pair<int, int> u = qu.front();
        qu.pop();
        int x1 = u.first;
        int y1 = u.second;
        //MyDebug(x1, y1);
        int i, x2, y2;
        for(i=0; i<8; i++)
        {
            x2 = x1+xx1[i];
            y2 = y1+yy1[i];
            if(VALID(x2, y2))
            {
                if(flag[x2][y2]==0)
                {
                    flag[x2][y2] = 1;
                    level[x2][y2] = level[x1][y1] + 1;
                    qu.push(make_pair(x2, y2));
                    if(adj[x2][y2]=='B') return;
                }
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
    freopen("11352.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, l, t, a, b;
    sf("%d", &t);
    pair <int, int> s, e;
    while(t--)
    {
        memset(flag, 0, sizeof(flag));
        memset(level, -1, sizeof(level));
        sf("%d %d ", &m, &n);
        for(i=0; i<m; i++)
            gets(adj[i]);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
            {
                if(adj[i][j]=='Z')
                {
                    flag[i][j] = 1;
                    for(l =0; l<8; l++)
                    {
                        if(VALID(i+xx[l], j+yy[l]))
                            flag[i+xx[l]][j+yy[l]] = 1;
                    }
                }
                else if(adj[i][j]=='A')
                    s = make_pair(i, j);
                else if(adj[i][j]=='B')
                    e = make_pair(i, j);
            }
        flag[s.first][s.second] = 0;
        flag[e.first][e.second] = 0;
        BFS(s.first, s.second);
        if(level[e.first][e.second]==-1) pf("King Peter, you can't go now!\n");
        else pf("Minimal possible length of a trip is %d\n", level[e.first][e.second]);
    }
    ///                                    ENDD
   // time_t t2=clock();
   // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
