/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define PI 2*acos(0)
using namespace std;

//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //freopen("541.txt", "r", stdin);
    long int step, sid, mod;
    bool any[100005];
    while(scanf("%ld %ld", &step, &mod)!=EOF)
    {
        memset(any, false, sizeof(any));
        long int cow=sid=0;
        while(cow<mod)
        {
            sid = (sid+step)%mod;
            if(any[sid]) break;
            any[sid] = true;
            cow++;
        }
        if(cow==mod) printf("%10ld%10ld    Good Choice\n\n", step, mod);
        else printf("%10ld%10ld    Bad Choice\n\n", step, mod);
    }
    return 0;
}

