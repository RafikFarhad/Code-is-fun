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
#define CLR(a, b) for(int o=0; o<b; o++) a[o] = 0
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
    //freopen(".inp","r",stdin);
#endif
    ///                                    MAIN
    long long n;
    int ar[20], i, keis=0;
    while(sf("%lld", &n)!=EOF)
    {
        i = 0;
        if(n<10) {pf("%4d. %lld\n", ++keis, n); continue;}
        pf("%4d.", ++keis);
        CLR(ar, 10);
        bool t = true;
        while(n)
        {

            if(i==1 || i==5) t = false;
            if(!t)
            {
                ar[i++] = n%10;
                t = true;
                n/=10;
                continue;
            }
            ar[i++] = n%100;
            n/=100; //MyDebug((int)n, i, ar[i-1]);
        } //cout << i << endl;
    if(i==10) ar[8] = ar[9]*100+ar[8];
    t = true;

    if(ar[8]) {pf(" %d kuti", ar[8]); t = false;}
    if(ar[7]) {pf(" %d lakh", ar[7]); t = false;}
    if(ar[6]) {pf(" %d hajar", ar[6]); t = false;}
    if(ar[5]) {pf(" %d shata", ar[5]);t = false;}
    if(ar[4]) {pf(" %d kuti", ar[4]); t = false;}
    if(!t && !ar[4]) pf(" kuti");
    if(ar[3]) {pf(" %d lakh", ar[3]); t = false;}
    if(ar[2]) {pf(" %d hajar", ar[2]); t = false;}
    if(ar[1]) {pf(" %d shata", ar[1]);t = false;}
    if(ar[0]) {pf(" %d", ar[0]);t = true;}
        pf("\n");
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
