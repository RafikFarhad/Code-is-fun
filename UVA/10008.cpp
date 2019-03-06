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
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int GCD(int a, int b)
{
    if(a%b==0) return b;
    return GCD(b, a%b);
}

int main()
{
    //time_t t1=clock();
    //freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN
    char line[500];
    int n, len, i, j, p[27];
    memset(p, 0, sizeof(p));
    sf("%d ", &n);
    while(n--)
    {
        len = strlen(gets(line));
        for(i=0; i<len; i++)
        {
            if(isalpha(line[i]))
            {
                line[i] = tolower(line[i]);
                p[line[i]-'a']++;
            }
        }
    }
    len = 0;
    for(i=0; i<26; i++)
    {
        if(len<p[i]) len = p[i];
    }
    for(i=len; i>0; i--)
    {
        for(j=0; j<26; j++)
            if(i==p[j]) pf("%c %d\n", j+'A', i);
    }

    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

