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
template <class T> bool MAX(T a, T b) { return a>b?a:b;}
template <class T> bool MIN(T a, T b) { return a<b?a:b;}
template <class T1, class T2> void MyDebug(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void MyDebug(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
template <class T1, class T2, class T3, class T4> void MyDebug(T1 x, T2 y, T3 z, T4 xx) { cout << "Debugging: " << x << ", " << y << ", " << z << ", " << xx << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
char ad[21][21];
int level[21][21], r, c;
queue <int> qu;
void BFS(int x, int y)
{
    queue <int> qu;
    int ux, uy, vx, vy, i;
    qu.push(x);
    qu.push(y);
    CLR(level);
    level[x][y] = 0;
    while(qu.size())
    {
        ux = qu.front(); qu.pop();
        uy = qu.front(); qu.pop();
        for(i=0; i<4; i++)
        {
            vx = ux+xx[i];
            vy = uy+yy[i];
            if(vx>=0 && vy>=0 && vx<r && vy<c && ad[vx][vy]=='.')
            {
                ad[vx][vy] = '#';
                level[vx][vy] = level[ux][uy] +1;  // MyDebug(level[ux][uy], level[vx][vy]);
                qu.push(vx);
                qu.push(vy);
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
    freopen("inp.txt","r",stdin);
#endif
    ///                                    MAIN
    int t, ti = 0, i, j, k, l, maxi;
    sf("%d", &t);
    while(t--)
    {
        sf("%d %d ", &c, &r);
        for(i=0; i<r; i++)
            gets(ad[i]);
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(ad[i][j]=='@')
        {
            //MyDebug(i, j);
            BFS(i, j);
            break;
        }
        k = 1;
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                {
                    if(level[i][j]) k++;
                //cout << level[i][j] << "  ";
                }
        pf("Case %d: %d\n",++ti, k);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
