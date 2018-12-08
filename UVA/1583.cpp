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
int SUM(int p)
{
    int sum = 0;
    if(p<10) return p;
    while(p>9)
    {
        sum += p%10;
        p/=10;
    }
    return sum+p;
}

int main()
{
    //freopen("541.txt", "r", stdin);
    int i, j, k;
    long int any[100003];
    memset(any, false, sizeof(any));
    for(i=1; i<100001; i++)
    {
        k = i;
        while(1)
        {
            j = SUM(k);
            //cout << k << " " << j << endl;
            k = k + j;
            if(k>100001 || (any[k]<k-j && any[k]!=0)) break;
            any[k] = k-j;
        }
    }

    long int p, t;
    scanf("%ld", &t);
    while(t--)
    {
        scanf("%ld", &p);
        printf("%ld\n", any[p]);
    }

    return 0;
}


