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

int temp[505], dis[505], fi[105];
int cost[505][505];
bool flag[505];

void DHISHUM(int s)
{
    int i, j, k, l, cost;
    level[s] = 0;

}


int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10278.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, l, in, fire, t, u, v, w;
    char li[100];
    sf("%d", &t);
    while(t--)
    {
        sf("%d %d", &f, &in);
        memset(flag, false, sizeof(flag));
        memset(level, SIZE, sizeof(level));
        for(i=0; i<f; i++)
            sf("%d ", &fi[i]);
        for(i=0; i<in; i++)
        {
            for(j=0; i<in; j++)
                cost[i][j] = SIZE;
        }
        while(gets(li))
        {
            if(strcmp(li, "")==0) break;
            sscanf("%d %d %d", &u, &v, &w);
            if(w < cost[u][v])
                cost[u][v] = cost[v][u] = w;
        }
        for(i=0; i<f; i++)
            DHISHUM(i+1);

    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
