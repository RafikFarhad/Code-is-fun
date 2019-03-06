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

int GCD(int a, int b)
{
    if(a%b==0) return b;
    return GCD(b, a%b);
}

int main()
{
    //time_t t1=clock();
    //freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN
    int ma[1010], d[1010], cow, i, j;
    while(sf("%d", &ma[0]) && ma[0])
    {
        for(i=0; ma[i]!=0 ; i++)
            sf("%d", &ma[i+1]);
        sort(ma, ma+i);
        int mini=0;
        for(j=0; j<i-1; j++)
            {
                d[j] = ma[j+1] - ma[j];
                if(mini < d[j]) mini = d[j];
            }
       // cout << j << endl;
        if(d[0]!=0 && d[i-2]!=0)
            {
                cow = GCD(d[0], d[i-2]);
                //pf("%d %d -> %d\n", d[0], d[i-2], cow);
                if(mini>cow) mini = cow;
            }
        for(j=0; j<i-2; j++)
        {
            if(d[j]==0 || d[j+1]==0) continue;
            cow = GCD(d[j], d[j+1]);
            //pf("%d %d -> %d\n", d[j], d[j+1], cow);
            if(mini>cow) mini = cow;
        }
        cout << mini << endl;
    }

    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
