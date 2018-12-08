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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
char ad[55][55];
bool trap[50][50], flag[50][50];
int cow, r, c;

void BFS(int i, int j)
{
    queue <int> qu;
    qu.push(i);
    qu.push(j);
    flag[i][j] = 1;
    int a, b, c1, d;
    while(qu.size())
    {
        a = qu.front(); qu.pop();
        b = qu.front(); qu.pop();
        if(trap[a][b]) continue;
        for(int po=0; po<4; po++)
        {
            c1 = a+xx[po];
            d = b+yy[po];
            if(c1>-1 && d>-1 && c1<r && d<c && !flag[c1][d] && ad[c1][d]!='#')
            {
                flag[c1][d] = 1;
                if(ad[c1][d]=='G' ) cow++;
                qu.push(c1);
                qu.push(d);
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
    freopen("11561.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, sx, sy;
    while(sf("%d %d ", &c, &r)!=EOF)
    {
        CLR(flag);
        CLR(trap);
        for(i=0; i<r; i++)
            gets(ad[i]);
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                if(ad[i][j]=='T')
                {
                    trap[i][j] = 1;
                    for(int po=0; po<4; po++)
                    {
                        if(i+xx[po]>-1 && j+yy[po]>-1)
                            trap[i+xx[po]][j+yy[po]] = 1;
                    }
                }
                else if(ad[i][j]=='P')
                {
                    sx = i;
                    sy = j;
                }
            }
            cow = 0;
            BFS(sx, sy);
            cout << cow << endl;
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
