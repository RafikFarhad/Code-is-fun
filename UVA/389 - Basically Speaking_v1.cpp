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

string b;
char a[15], c[20];

int POWER(int ba, int po)
{
    int i, r = 1;
    for(i=0; i<po; i++)
        r*=ba;
    return r;
}

int toDEC(char p[], int base)
{
    //cout << p << endl;
    int i, j, len, sum = 0, temp;
    len = strlen(p);
    for(i=len-1, j=0; i>-1; i--)
    {
        if(p[i]==' ') continue;
        if(p[i]>='A') temp = p[i] - 'A' + 10;
        else temp = p[i] - '0';
        sum += (temp * POWER(base, j++));
    }
    return sum;
}

void toBASE(int n, int base)
{
    //int n = atoi(p);
    //cout << p << " = " << n+1 << endl;
    b = "";
    while(n)
    {
        int temp = n%base;
        char t;
        if(temp>9) t = temp - 10 + 'A';
        else t = temp + '0';
        b = t + b;
        n/=base;
        if(b.size()>7) { b = "ERROR"; return;}
    }
    if(b=="") b = "0";
    return ;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("389.inp","r",stdin);
#endif
    ///                                    MAIN
    int n, from, to;
    while(sf("%s %d %d", a, &from, &to)!=EOF)
    {
        n = toDEC(a, from);
        toBASE(n, to);
        cout.width(7); cout << b << endl;
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
