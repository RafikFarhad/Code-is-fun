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
int yy[] = {0, -1, 1, 0, -1, 1, 1, -1};   // diagonal -> 8 horizontal/vertical->4
int row, col;
char ch[51][51];
map < pair<int, int> , int> dis;

class DATA
{
public:
    int x1, y1, x2, y2, c;
    DATA(int a, int b,int d,int e,int f)
    {
        x1 = a;
        y1 = b;
        x2 = d;
        y2 = e;
        c = f;
    }
    bool operator < (const DATA &t) const
    {
        return c <t.c;
    }
};
vector <DATA> va;
void BFS(int x, int y)
{
    queue < pair <int, int> > qu;
    pair <int, int> u, v;
    bool flag[51][51];
    CLR(flag);
    int level[51][51];
    CLR(level);
    qu.push(make_pair(x, y));
    flag[x][y] = 1;
    level[x][y] = 0;
    while(qu.size())
    {
        u = qu.front(); qu.pop();
        for(int po=0; po<4; po++)
        {
            v.first = u.first + xx[po];
            v.second = u.second + yy[po];
            if(v.first>-1 && v.second>-1 && ch[v.first][v.second] != '#' && !flag[v.first][v.second])
            {
                level[v.first][v.second] = level[u.first][u.second] + 1;
                if(ch[v.first][v.second] == 'A')
                {
                    va.pb(DATA(x, y, v.first, v.second, level[v.first][v.second]));
                    BFS(v.first, v.second);
                    //flag[v.first][v.second] = 1;
                    //break;
                    /*if(dis[make_pair(v.first, v.second)] > level[v.first][v.second])
                    {
                        dis[make_pair(v.first, v.second)] = level[v.first][v.second];
                    }*/
                }
                flag[v.first][v.second] = 1;
                qu.push(make_pair(v.first, v.second));
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
    freopen("10307.inp","r",stdin);
#endif
    ///                                    MAIN
    int test, i, j, k, l, t, b;
    sf("%d", &t);
    while(t--)
    {
        va.clear();
        sf("%d %d ", &col, &row);
        for(i=0; i<row; i++)
        {
            gets(ch[i]);
        }
        dis.clear();

        //MyDebug(row, col);
       // CLR(flag);
       // CLR(level);
        for(i=0; i<row; i++)
            for(j=0; j<col; j++)
        {
            if(ch[i][j]=='S')
            {
                BFS(i, j);
            }
        } j = 0;
        for(i=0; i<va.size(); i++, cout << endl)
            {
                j+=va[i].c;
                cout << va[i].x1 << " "<< va[i].y1 << " "<< va[i].x2 << " "<< va[i].y2 << " " << va[i].c;
            }
            //cout << "Total " << j << endl;
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
