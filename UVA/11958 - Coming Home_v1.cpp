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
#define CLR(a) memset(a, 0, sizeof(a))
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
int xx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy[] = {0, -1, 1, 0, -1, 1, 1, -1};   // diagonal -> 8 horizontal/vertical->4

int HOUR(int a, int b, int c, int d)
{
    a = a==0?24:a;
    c= c==0?24:c;
    if(d<b)
    {
        d+=60;
        c--;
    }
    if(c<a)
    {
        c+=24;
    }
    return (d-b)+60*(c-a);
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11958.inp","r",stdin);
#endif
    ///                                    MAIN
    int test, ti, h, m, k, h1, m1, mini, i, j;
    sf("%d", &test);
    for(ti=0; ti<test; ti++)
    {
        sf("%d %d:%d", &k, &h, &m);
        mini = SIZE;
        for(j=0; j<k; j++)
        {
            sf("%d:%d %d", &h1, &m1, &i);
            mini = MIN(mini, HOUR(h, m, h1, m1)+i);
        }
        pf("Case %d: %d\n", ti+1, mini);
    }
    //cout << HOUR(00, 0, 11, 59) << endl;
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
