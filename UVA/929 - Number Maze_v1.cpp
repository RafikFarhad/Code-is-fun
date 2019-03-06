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
template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}
int row, col, cost[1000][1000];
int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, 1, -1};
int d[1000][1000];

struct DATA
{
    int r, c, val;
    DATA(int a, int b, int t)
    {
        r = a;
        c = b;
        val = t;
    }
};

class COMPA
{
public:
    bool operator()(DATA a, DATA b)
    {
        if(a.val>b.val) return true;
        return false;
    }
};

void DHISHUM()
{
    priority_queue<DATA, vector<DATA>, COMPA> pq;
    int i, j;
    while(pq.size()) pq.pop();

    d[0][0] = cost[0][0];
    pq.push(DATA(0, 0, cost[0][0]));

    while(pq.size())
    {
        DATA working = pq.top(); pq.pop();
        int u = working.r, v = working.c, co = cost[u][v];
        if(u==row-1 && col-1 == v) return;
        //MyDebug(u, v, working.val);
        //if(d[u][v] == working.val)
        for(i=0; i<4; i++)
        {
            int new_row = u + xx[i], new_col = v + yy[i];
        //cout <<" u " << xx[i] <<"  v " << yy[i] << endl;
            if(new_col<col && new_col>=0 && new_row>=0 && new_row<row)
                if( d[u][v] + cost[new_row][new_col] < d[new_row][new_col])
                {
        //cout <<"** u " << new_row <<"  v " << new_col << endl;
                    d[new_row][new_col] = d[u][v] + cost[new_row][new_col];
                    pq.push(DATA(new_row, new_col, d[new_row][new_col]));
                    //cout << d[new_row][new_col] << endl;
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
    freopen("929.inp","r",stdin);
#endif
    ///                                    MAIN
     int i, j, k, t;
     sf("%d", &t);
     while(t--)
     {
         sf("%d %d", &row, &col);
         for(i=0; i<row; i++)
         {
             for(j=0; j<col; j++)
             {
                 sf("%d", &cost[i][j]);
                 d[i][j] = SIZE;
             }
         }
        DHISHUM();
        pf("%d\n", d[row-1][col-1]);
     }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
