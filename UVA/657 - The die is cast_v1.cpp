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
int cow, r, c;
char adj[55][55];
bool flag[55][55];
int xx[] = {-1,  0, 0, 1};
int yy[] = {0,  -1, 1, 0};

void AGAIN_DFS(int i, int j)
{
    if(i<0 || j <0 || i==r || j==c || adj[i][j]!='X') return;
    adj[i][j] = '*';
    for(int po=0; po<4; po++)
    {
        AGAIN_DFS(i+xx[po], j+yy[po]);
    }
    return;
}

void DFS(int i, int j)
{
    //cout << adj[i][j] << endl;
    if(i<0 || j <0 || i==r || j==c || adj[i][j]=='.') return;
    if(adj[i][j]=='X')
    {
        cow++;
        AGAIN_DFS(i, j);
    }
    adj[i][j] = '.';
    for(int po=0; po<4; po++)
    {
        DFS(i+xx[po], j+yy[po]);
    }
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("657.inp","r",stdin);
#endif
    ///                                    MAIN
    int test, i, j, k, pos=0;
    while(sf("%d %d ", &c, &r)==2 && r+c)
    {
        CLR(adj);
        CLR(flag);
        for(i=0; i<r ; i++)
        {
            gets(adj[i]);
            //puts(adj[r]);
        }
        //gets(adj[r+1]);
        //int a, b;
        vector <int> my;
        my.clear();
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                //MyDebug(adj[i][j], 'p');
                if(adj[i][j]!='.')
                {
                    cow = 0;
                    DFS(i, j);
                    //cout << cow << endl;
                    my.pb(cow);
                }
            }
            sort(my.begin(), my.end());
            pf("Throw %d\n%d", ++pos, my[0]);
        for(i=1; i<my.size(); i++)
            cout << " " << my[i];
        cout << endl << endl;
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
