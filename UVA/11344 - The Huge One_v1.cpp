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

char k[2200];
bool DIV(int t)
{
    int i, j, r = 0, len=strlen(k);
    for(i=0; i<len;i++)
    {
        r = (r*10+(k[i]-'0'))%t;
    }
    if(r) return 0;
    return 1;
}
int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11344.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, t, ar[13], j, n, d;
    sf("%d ", &t);
    while(t--)
    {
        int flag=0;
        gets(k); //puts(k);
        sf("%d", &j);
        for(n=0; n<j; n++)
        {
            sf("%d ", &d);
            if(DIV(d)) flag++;
            else flag--;
        }
        pf("%s - ", k);
        if(flag==j) pf("Wonderful.\n");
        else pf("Simple.\n");
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
