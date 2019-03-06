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

class BIRTH
{
public:
    int d, m, y;
    char name[20];

}b[105];


    bool COMPA(BIRTH a, BIRTH b)
    {
        if(a.y==b.y)
        {
            if(a.m==b.m)
                return a.d>b.d;
            else
                return a.m>b.m;
        }
    else return a.y>b.y;
    }

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("12541.inp","r",stdin);
#endif
    ///                                    MAIN
    int n, i, j, k, d1, m1, y1;
    //vector<BIRTH> v[101];
    string a1;
    BIRTH p, q;
    sf("%d", &n);
    for(i=0; i<n; i++)
    {
        sf("%s %d %d %d ", b[i].name, &b[i].d, &b[i].m, &b[i].y);
        //v[i].pb(p);
    }
    sort(b, b+n, COMPA);
        pf("%s\n%s\n", b[0].name, b[n-1].name);
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
