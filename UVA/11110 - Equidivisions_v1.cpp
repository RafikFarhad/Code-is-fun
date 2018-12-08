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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs

int cow, ad[110][110], n;
bool flag[110][110];
char line[1000];

void DFS(int x, int y, int p)
{
    if(x==0 || y==0 || x>n || y>n || flag[x][y] || ad[x][y]!=p) return;
    flag[x][y] = 1;
    cow++;
    for(int po=0; po<4; po++)
    {
        DFS(x+xx[po], y+yy[po], p);
    }
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11110.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, l, a, b;
    while(sf("%d ", &n)==1 && n)
    {
        memset(flag, 0, sizeof flag);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                ad[i][j] = n;
        for(i=1;i<n; i++)
        {
            gets(line);
            char *ch;
            ch = strtok(line, " ");
            while(ch!=NULL)
            {
                a = atoi(ch);
                ch = strtok(NULL, " ");
                b = atoi(ch);
                ch = strtok(NULL, " ");
                ad[a][b] = i;
            }
        }
        bool result = true;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                {
                    if(!flag[i][j])
                    {
                        cow = 0;
                        DFS(i, j, ad[i][j]);
                        //cout << "cow " << cow << endl;
                        if(cow!=n)
                        {
                            result = false;
                            //MyDebug(i, j);
                            i = j = n+n;
                        }
                    }
                }
        if(result) pf("good\n");
        else pf("wrong\n");
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
