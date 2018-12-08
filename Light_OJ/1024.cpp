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
long long POWER(int b, int p){if(p==0) return 1; return b*POWER(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs

int SUPERMAN(int a[], int p, int len)
{
    int i, j, k;
    for(i=0; i<len; i++)
        a[i]*=p;
    for(i=0; i<len; i++)
        if(a[i]>9)
        {
            a[i+1]+=(a[i]/10);
            a[i]%=10;
            if(i==len-1) len++;
        }
        return len;
}


int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("inp.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, n, i, j, k, cow, p, len, prime[10005], pro[10000];
    sf("%d", &t);
    for(j=0; j<t; j++)
    {
        sf("%d", &n);
        CLR(pro);
        CLR(prime);
        len = 1;
        pro[0] = 1;;
        while(n--)
        {
            sf("%d", &p);
            for(i=2; p!=1; i++)
            {
                cow = 0;
                while(p%i==0)
                {
                    p/=i;
                    cow++;
                }
                prime[i] = MAX(prime[i], cow);
            }
        }

        for(i=2; i<10001; i++)
            if(prime[i])
                len = SUPERMAN(pro, POWER(i, prime[i]), len);
        pf("Case %d: ", j+1);
        for(i=len-1; i>=0; i--)
            cout << pro[i];
        cout << endl;
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

