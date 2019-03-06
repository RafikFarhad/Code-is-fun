
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
    //freopen("541.txt", "r", stdin);
    //                           PRE CALCULATION
    int res[10002];
    res[1] = 1;
    res[2] = 2;
    for(int i=2; i<10003; i++)
    {
        int p = res[i-1]*i;
        while(p%10 == 0) p/=10;
        res[i] = p%100000;
        res[i-1] = res[i-1]%10;
    }
    //                                  CODE
    int p;
    while(scanf("%d", &p)!=EOF)
        printf("%5d -> %d\n", p, res[p]);
    return 0;
}



