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
#define CLR(o) memset(o, 0, sizeof o)
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
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 46400
int ad[105][105];

void INIT(int n)
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            ad[i][j] = 1<<29;
    for(i=0; i<n; i++)
        ad[i][i] = 0;
    return;
}

void FLOYD(int n)
{
    int i, j, k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<n; k++)
                ad[j][k] = MIN(ad[j][i]+ad[i][k], ad[j][k]);
    return;
}
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, n, m, i, j, k, u;
    takei(t);
    while(t--)
    {
        takei(n);
        INIT(n);
        takei(m);
        while(m--)
        {
            takei(i);
            takei(j);
            ad[i][j] = 1;
            ad[j][i] = 1;
        }
        FLOYD(n);
     /*   for(i=0; i<n; i++, cout << endl)
            for(j=0; j<n; j++)
        {
            cout << ad[i][j] << "     ";
            k = MAX(u)
       */ takei(i);
        takei(j);
        for(u=0, k=0; u<n; u++)
            k = MAX(ad[i][u]+ad[u][j], k);
        //deb(k);
        pf("Case %d: %d\n", ++keis, k);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

