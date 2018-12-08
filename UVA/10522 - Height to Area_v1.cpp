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

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10522.inp","r",stdin);
#endif
    ///                                    MAIN
    double a, b, c, res, a1, a2, b2, res1;
    int i, cow=0, error, j;
    sf("%d", &error);
    while(1)
    {
        if(cow==error) return 0;
        sf("%lf %lf %lf", &a, &b, &c);
        if(a==0 || b==0 || c==0 ) {pf("These are invalid inputs!\n"); cow++; continue;}
        res1 = ( 1/a + 1/b + 1/c )*( 1/c + 1/b - 1/a )*( 1/a - 1/b + 1/c )*( 1/a + 1/b - 1/c );
        res = 1/res1;
        if(res<-0.00001) {pf("These are invalid inputs!\n"); cow++;}
        else pf("%.3lf\n", sqrt(res));
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
