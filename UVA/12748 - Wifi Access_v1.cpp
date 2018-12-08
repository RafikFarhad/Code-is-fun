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
    freopen("12748.inp","r",stdin);
#endif
    ///                                    MAIN
    int wifi[101][3], my[2], n, m, i, j, r, flag, t, k;
    sf("%d", &t);
    for(i=0; i<t; i++)
    {
        pf("Case %d:\n", i+1);
        sf("%d %d", &n, &m);
        for(j=0; j<n; j++)
            sf("%d %d %d", &wifi[j][0], &wifi[j][1], &wifi[j][2]);
        for(j=0; j<m; j++)
        {
            sf("%d %d", &my[0], &my[1]);
            for(k=flag=0; k<n; k++)
            {
                if((wifi[k][0]-my[0])*(wifi[k][0]-my[0])+(wifi[k][1]-my[1])*(wifi[k][1]-my[1]) <= (wifi[k][2]*wifi[k][2]))
                    flag=1;
            }
            if(flag) pf("Yes\n");
            else pf("No\n");
        }
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
