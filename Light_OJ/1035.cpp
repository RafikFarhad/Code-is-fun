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
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs


int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int fre[101][100], n, i, j, k, cow, temp;
    CLR(fre);
    for(i=2; i<101; i++)
    {
        temp = i; //cout << temp << endl;

        for(j=2; j<100; j++)
            fre[i][j] = fre[i-1][j];    /// COPYING PREVIOS FACTORIZATION

        for(j=2; temp>1; j++)
        {
            if(temp%j==0)
            {
                while(temp%j==0)
                {
                    fre[i][j]++;
                    temp/=j; //deb(i, j);
                }
            }
        }
    }
    sf("%d", &temp);
    j = 0;
    while(temp--)
    {
        sf("%d", &n);
        k = 0;
        pf("Case %d: %d =", ++j, n);
        for(i=2; i<100; i++)
        {
            if(fre[n][i])
            {
                if(!k++) pf(" %d (%d)", i, fre[n][i]);
                else pf(" * %d (%d)", i, fre[n][i]);
            }
        }
        pf("\n");
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
