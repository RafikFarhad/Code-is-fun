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
#define PPP system("pause")
#define ok cout << "OK" <<endl;
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
template <class T> void MyDebug(T x, T y, T z)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << endl;
}

int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};
int flag[2000+9][2000+9];
int level[2000+9][2000+9];
int mm;
queue < pair< int, int> > qu;

bool UNDER(int x, int y)
{
    return (x>=0 && y>=0 && x<2000 && y <2000) ;
}
int BFS()
{
    //cout << x << " " << y;
    while(qu.size())
    {
        pair<int, int> pa = qu.front();
        qu.pop();
        int Nr, Nc;
        for(int po=0; po<4; po++)
        {
            Nr = pa.first+xx[po];
            Nc = pa.second+yy[po];
            if(UNDER(Nr, Nc))
            {
                pair<int, int> p = pair<int, int> (Nr, Nc);
                if(level[Nr][Nc]==-1)
                {
                    level[Nr][Nc]=level[pa.first][pa.second] + 1;
                    if(flag[Nr][Nc]==2) return level[Nr][Nc];
                    qu.push(make_pair(Nr, Nc));
                }
            }
        }
    }
    return 0;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11101.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, a, b, x, y;
    pair <int, int> p;
    while(sf("%d", &i)==1 && i)
    {
        memset(level, -1, sizeof(level));
        memset(flag, 0, sizeof(flag));
        while(qu.size()) qu.pop();
        bool t = false;
        while(i--)
        {
            sf("%d %d", &j, &k);
            p = make_pair(j, k);
            level[j][k] = 0;
            flag[j][k] = 1;
            qu.push(p);
        }
        sf("%d", &i);
        while(i--)
        {
            sf("%d %d", &j, &k);
            flag[j][k] = 2;
        }

        pf("%d\n", BFS());
    }


    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
