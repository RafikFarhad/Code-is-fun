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
    //freopen("424.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN
    int t, i, j, p[101], day, nom, cow, k;
    bool hartal[3655];
    sf("%d", &t);
    while(t--)
    {
        sf("%d %d", &day, &nom);
        cow = 0;
        memset(hartal, false, sizeof(hartal));
        for(i=0; i<nom; i++)
        {
            sf("%d", &k);
            for(j=0; ; )
            {
                j = j + k;
                //cout << "j " << j << endl;
                if(j>day) break;
                hartal[j] = true;
            }
        }
        for(j=0; j<=day; j++)
            if(hartal[j])
                if(j%7!=6 && j%7!=0)
                    cow++;
        pf("%d\n", cow);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

