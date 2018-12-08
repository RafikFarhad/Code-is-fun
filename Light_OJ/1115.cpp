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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen(b, "w", stdout);
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << ", " << q << ", " << r << ", " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
int n, m, val[55][55];
bool flag[55][55];
char ad[55][55];

void DFS(int i, int j, char c)
{
    if(i<0 || i==m || j<0 || j==n || flag[i][j] ||ad[i][j]!=c) return;
    flag[i][j]=1;
    for(int ii=0; ii<4; ii++)
    {
        DFS(i+xx[ii], j+yy[ii], c);
    }
    return;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k, l;
    takei(t);
    while(t--)
    {
        sf("%d %d\n", &m, &n);
        for(i=0; i<m; i++)
            gets(ad[i]);
        CLR(flag);
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(flag[i][j]) continue;
                if(ad[i][j]!='.')
                {
                    DFS(i, j, ad[i][j]);
                }
            }
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                pf("%d", flag[i][j]);
            }
            cout << endl;
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
