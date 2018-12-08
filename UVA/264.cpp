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
#define TOOT 10000002
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
    //freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN
    vector <int> row, column;
    long long i, j, u, v, cow = 0, x=1, y=1;
    //                                                    Pre Calculation
    row.push_back(1);
    column.push_back(y++);
    for(i=1; i<TOOT; )
    {
        x = 1;
        //y++;
        while(x>0 && y>0)
        {
            row.push_back(x);
            column.push_back(y);
            x++;
            --y;
            if(++i>TOOT) goto lastt;
        }

        y = 1;
        while(x && y)
        {
            row.push_back(x);
            column.push_back(y);
            --x;
            y++;
            if(++i>TOOT) goto lastt;
        }

    }
lastt:
    while(sf("%lld", &i)!=EOF)
        pf("TERM %lld IS %d/%d\n", i, row[i-1], column[i-1]);

    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

