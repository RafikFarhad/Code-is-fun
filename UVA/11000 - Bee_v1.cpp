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
int xx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int yy[] = {1, -1, -2, -2, -1, 1, 2, 2};
int xx1[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy1[] = {0, -1, 1, 0, -1, 1, 1, -1};
#define MaX 1000

int main()
{
   // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    //freopen(".inp","r",stdin);
#endif
    ///                                    MAIN
    long long i, j, k, n, fib[1000], sum[10000];
    //memset(fib, -1, sizeof fib);
    while(sf("%lld", &n)==1 && n>=0)
    {
        fib[0] = 0;
        fib[1] = 1;
        sum[0] = 1;
        for(i=2; i<=n+1; i++)
                fib[i] = fib[i-1] + fib[i-2];
        for(i=1; i<=n; i++)
            sum[i] = sum[i-1] + fib[i+1];
            //out << sum[2] << endl;
        pf("%lld %lld\n", sum[n]-fib[n+1], sum[n]);
    }

    ///                                    ENDD
   // time_t t2=clock();
   // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
