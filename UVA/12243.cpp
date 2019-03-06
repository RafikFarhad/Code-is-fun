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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //time_t t1=clock();
    freopen("12243.txt", "r", stdin);

    ///                                    MAIN
    char line[1009];
    while(gets(line))
    {
        int k = strlen(line), i, t=0;
        char c;
        if(line[0]=='*') return 0;
        c = tolower(line[0]);

        for(i=1; i+1<k; i++)
        {
            line[i+1] = tolower(line[i+1]);
            if(line[i]==' ') t++;
            if(line[i]==' ' && line[i+1]==c) t--;
        }
        if(t==0) pf("Y\n");
        else pf("N\n");
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
