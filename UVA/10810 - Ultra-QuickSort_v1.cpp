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

long ar[500100], n, cow, lef[501000], ri[501000];

void MERGING(long i, long mid, long j)
{
    long a, b, c, in1, in2;
    for(in1=1, a=i; a<=mid; a++)
    {
        lef[in1++] = ar[a];
    }

    for(in2=1, a=mid+1; a<=j; a++)
    {
        ri[in2++] = ar[a];
    }

    lef[in1] = ri[in2] = SIZE;

    a = b = 1;
    for(c=i; c<=j; c++)
    {
        if(lef[a]>ri[b])
        {
            cow += (in1-a);
            ar[c] = ri[b];
            b++;
        }
        else
        {
            ar[c] = lef[a];
            a++;
        }
    }
}
void MERGE_SORT(long i, long j) ///                 breaking into pieces
{
    //MyDebug(i, j);
    if(i<j)
    {
        long mid = (i+j)/2;
        MERGE_SORT(i, mid);
        MERGE_SORT(mid+1, j);
        MERGING(i, mid, j);
    }
}


int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10810.inp","r",stdin);
#endif
    ///                                    MAIN
    long i, j;
    while(sf("%ld", &n)==1 && n)
    {
        cow = 0;
        for(i=1; i<=n; i++)
            sf("%ld", &ar[i]);
            cow = 0;
        MERGE_SORT(1, n);

        pf("%ld\n", cow);
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
