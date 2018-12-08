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
#define sf scanf
#define ssf sscanf
#define pf printf
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
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}
int row, column;
bool flag[1001][1001];

struct m
{
    int r, c;
    m(int a, int b)
    {
        r = a;
        c = b;
    }
};

int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};

int BFS( int a, int b, int c, int d)
{
    int dis[row+1][column+1];
    queue <m> qu;
    qu.push(m(a, b));
    flag[a][b] = true;
    dis[a][b] = 0;
    while(qu.size())
    {
        m working = qu.front();
        qu.pop();
        int new_row, new_col, old_row = working.r, old_col = working.c;
        for(int po=0; po<4; po++)
        {
            new_row = old_row + xx[po];
            new_col = old_col + yy[po];
            if(new_col > -1 && new_col < column && new_row >-1 && new_row < row && !flag[new_row][new_col])
            {
               // cout << new_row << " " << new_col << endl;
                if(new_col == d && new_row == c) return dis[old_row][old_col];
                flag[new_row][new_col] = true;
                dis[new_row][new_col] = dis[old_row][old_col] + 1;
                qu.push(m(new_row, new_col));
            }
        }
    }
}

int main()
{
    // time_t t1=clock();
    //freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    ///                                    MAIN
    int i, j, rr, bomb, cc;
    while(sf("%d %d", &row, &column)==2 && row && column)
    {
        for(i=0; i<row; i++)
            for(j=0; j<column; j++)
                flag[i][j] = false;
        sf("%d", &j);
        for(i=0; i<j; i++)
        {
            sf("%d %d", &rr, &bomb);
            for(int k=0; k<bomb; k++)
            {
                sf("%d", &cc);
                flag[rr][cc] = true;
            }
        }
        int a, b, c, d;
        sf("%d %d", &a, &b);
        sf("%d %d", &c, &d);
        i = BFS(a, b, c, d);
        cout << i+1 << endl;
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


