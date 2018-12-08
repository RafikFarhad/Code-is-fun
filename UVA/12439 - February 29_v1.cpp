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
#define SIZE 1000000001
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T> void MyDebug(T x, T y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
template <class T> void MyDebug(T x, T y, T z)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << endl;
}

bool m11(char a[], int d)
{
    if(strcmp(a, "January")==0) return 1;
    if(strcmp(a, "February")==0)
        if(d<=29) return 1;
        else return 0;

    return false;
}
bool m22(char a[], int d)
{
    if(strcmp(a, "February")==0 && d==29) return 1;
    if(strcmp(a, "January")!=0 && strcmp(a, "February")!=0) return 1;
    return false;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("12439.inp","r",stdin);
#endif
    ///                                    MAIN
    long long i, j, cow, d1, m1, year1, d2, m2, year2;
    char a[20], b[20];
    int t, ti;
    sf("%d ", &t);
    for(ti=0; ti<t; ti++)
    {
        sf("%s %d, %lld ",a, &d1, &year1);
        sf("%s %d, %lld ",b, &d2, &year2);
        cow = 0;
        //cout << a << endl << b << endl;
        //cout << a << " " << mp[a] << endl;
        //if( strcmp(a, "January")!=0 && (strcmp(a,"February")!=0 && d1<29)) year1++;
        //if(strcmp(b, "January")==0 || (strcmp(b,"February")==0 && d2<29)) year2--;
        //MyDebug(year1, year2);
        if(year1!=year2)
        {
            j = year2-1;
            cow = (j/4 - year1/4) - (j/100 - year1/100) + (j/400 - year1/400);
            //cout << cow  << endl;
            if( year1 % 400==0 || ( year1%100!=0 && year1%4==0) )
            {
                if(m11(a, d1))
                cow++;
                //cout <<  ((bool) m11(a, d1))   << (bool)(year1%400==0) << (bool)(year1%100!=0)  << (bool) (year1%4==0)  << endl;
            }
            if(year2 % 400==0  || (year2%100!=0 && year2%4==0))
                if(m22(b, d2))
                   cow++;
        }
        else if(year1 % 400==0  || (year1%100!=0 && year1%4==0))
            if(m22(b, d2) && m11(a, d1))
               cow++;
        pf("Case %d: %lld\n", ti+1, cow);
    }
    //delete(leap);
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
