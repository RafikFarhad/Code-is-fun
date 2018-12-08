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
#define CLR(a, b) for(int o=0; o<b; o++) a[o] = 0
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
int r, c, cnt;
char mat[30][30];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int i, int j)
{
    if(i<0||j<0||i>=r||j>=c||mat[i][j]=='0') return;
    cnt++;
    //printf("Yes %d\n", cnt);
    mat[i][j] = '0';
    for (int k=0; k<8; k++)
        DFS(i+dx[k],j+dy[k]);
    return;
}


int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("871.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, mx, t;
    scanf("%d ", &t);
    getchar();
    getchar();
    while(t--)
    {
        i= 0;
        scanf("\n");
        while(gets(mat[i]))
        {
            if(mat[i][0] == '\0') break;
            c = strlen(mat[i]);
            i++;
        }
        r = i, mx = 0;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(mat[i][j] =='1')
                {
                    cnt = 0;
                    DFS(i,j); //cout << cnt << endl;
                    mx = max(mx, cnt);
                }
            }
        }
        printf("%d\n",mx);
        if(t) printf("\n");
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
