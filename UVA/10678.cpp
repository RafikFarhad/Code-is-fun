
/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define PI 2*acos(0)
using namespace std;

//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //freopen("567.txt", "r", stdin);
    double a, b, c, d, e;
    int t;
   // printf("Pi = %lf\n", PI);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf", &a, &b);
        c = (b*b/4) - (a*a/4);
        a = a + (b-a);
        c = PI * a * sqrt(c)/2;
        printf("%.3lf\n", c);
    }
}

