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
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //time_t t1=clock();
    freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN

    int n;
    while(sf("%d ", &n) && n)
    {
        char line[30];
        int countt[14], i, j, maxi;
        for(int k=0; k<n; k++)
        {
            gets(line);
            j = strlen(line);
            for(i=maxi=0; i<j; i++)
                if(line[i]=='X') maxi++;
                countt[k] = maxi;
                //cout << k << " " << countt[k] << endl;
        }
        int *maxii = max_element(countt, countt+n);
        int cow = 0;
        for(int k=0; k<n; k++)
            cow = cow + *maxii - countt[k];
        pf("%d\n", cow);
    }
//        delete(big);
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
