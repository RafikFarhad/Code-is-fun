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
    int qu, i, j, k;
    while(scanf("%d", &qu) && qu)
    {
        for(i=1; i<60; i++)
        {
            for(j=0; j<i; j++)
            {
                if((i*i*i-j*j*j)==qu)
                {
                    goto lastt;
                }
            }
        }
        lastt:
            if(i==60) printf("No solution\n");
            else printf("%d %d\n", i, j);
    }
    return 0;
}




