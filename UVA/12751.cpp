/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //time_t t1=clock();
    //freopen("10176.txt", "r", stdin);

    ///                                    MAIN
    int t, i, sum, n, k, x, a, b;
    sf("%d", &t);
    for(i=0; i<t; )
    {
        sf("%d %d %d", &n, &k, &x);
        sum = n*(n+1)/2;
        a = x*(x-1)/2;
        b = (k+x)*(k+x-1)/2;
        sum = sum -b+a;
        printf("Case %d: %d\n", ++i, sum);
    }

    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


