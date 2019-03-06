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

long long POWER(int ba, int po)
{
    int i;
    long long r = 1;
    for(i=0; i<po; i++)
        r*=ba;
        //cout << "r = " << r << endl;
    return r;
}

long long toDEC(char p[], int base)
{
    //cout << p << endl;
    //if(base==10) return atol(p);
    int i, j, len,temp;
    long long sum = 0;
    len = strlen(p);
    for(i=len-1, j=0; i>-1; i--)
    {
        if(p[i]==' ') continue;
        if(p[i]>='A') temp = p[i] - 'A' + 10;
        else temp = p[i] - '0';
        if(temp>=base) { return -1;}
        sum += (temp * POWER(base, j++));
        //cout << temp << " -> " << (temp * POWER(base, j-1)) << endl;
    }
    //cout << " p = " << sum << endl;
    return sum;
}

void toBASE(long long n, int base)
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
    freopen("355.inp","r",stdin);
#endif
    ///                                    MAIN
    int from, to;
    long long n;
    while(sf("%d %d %s",&from, &to, a)!=EOF)
    {
        n = toDEC(a, from);
        if(n==-1) { pf("%s is an illegal base %d number\n", a, from); continue;}
        toBASE(n, to);
        pf("%s base %d = ", a, from);
        cout << b << " base " << to << endl;
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
