/// #define_SUST
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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define SIZE 1000005
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long unsigned a, b, c;
    vector <long long unsigned> v;
    long long unsigned i, j, t, ti, k;
    sf("%llu", &t);
    for(ti=0; ti<t; ti++)
    {
        sf("%llu %llu", &a, &b);
        pf("Case %llu:", ti+1);
        c = sqrt(a)+1;
        a-=b;
        v.clear();
        for(i=1; i<c; i++)
        {
            if(a%i==0)
            {
                v.pb(i);
                if(i*i!=a) v.pb(a/i);
            }
        }
        sort(v.begin(), v.end());
            for(i=0; i<v.size(); i++)
        if(v[i]>b)
        {
            pf(" %llu", v[i]);
            c = 0;
        }
        if(!c) pf("\n");
        else pf(" impossible\n");
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

