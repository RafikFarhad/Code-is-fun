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
using namespace std;

//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //freopen("567.txt", "r", stdin);
    long long n;
    int t, i, j, d;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(n==1)
        {
                cout << "1" << endl;
                continue;
        }
        int ar[15];
        for(d=9, i=0; d>1; d--)
        {
            while(n%d==0)
            {
                n/=d;
                ar[i++] = d;
            }
        }

        if(n==1)
        {
            for(j=i-1; j>-1; j--)
                cout << ar[j];
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}

