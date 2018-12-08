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
#include <sstream>
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
int xx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy[] = {0, -1, 1, 0, -1, 1, 1, -1};   // diagonal -> 8 horizontal/vertical->4

int GCD(long a, long b)
{
    if(a%b==0) return b;
    return GCD(b, a%b);
}

int POW(int b, int p)
{
    if(p==0) return 1;
    if(p==1) return b;
    return POW(b, p-1)*b;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("332.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, keis=0;
    int a, b;
    double X;
    char line[1000];
    while( 1 )
    {
        cin >> j;
        if(j==-1) break;
        sf("%s", line);
        if(line[0]=='1')
        {
            pf("Case %d: 1/1\n", ++keis);
            continue;
        }
        int l = strlen(line), k = l-2-j;
        int p = 0;
        for(i=2; i<l; i++)
        {
            p*=10;
            p+=(line[i]-'0');
        }
       // cout << p << endl;
        if(j==0)
        {
            a = p;
            b = POW(10, k);
        }
        else
        {
            a = p - p/POW(10, j); //MyDebug(POW())
            b = POW(10, k+j) - POW(10, k); //MyDebug(b, b);
        }
        int gcd = GCD(a, b);
        pf("Case %d: %d/", ++keis, a/gcd);
        pf("%d\n", b/gcd);
    }
    //cout << POW(10, 9) << endl;
        ///                                    ENDD
        // time_t t2=clock();
        // cout << " My time: " <<(t2-t1) << endl;;
        return 0;
    }
