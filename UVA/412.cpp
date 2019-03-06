/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
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

int GCD(int a, int b)
{
    if(a%b==0) return b;
    return GCD(b, a%b);
}

int main()
{
    //time_t t1=clock();
    //freopen("10176.txt", "r", stdin);
    int ar[55], i, j, n, cow, pairo;
    double pi;
    while(scanf("%d", &n)==1 && n)
    {
        for(i=cow=pairo=0; i<n; i++)
            scanf("%d", &ar[i]);
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                {
                    pairo++;
                    if(GCD(ar[i], ar[j])==1)
                    cow++;
                }
        //cout << 6*pairo/(double)cow << endl;
        if(cow==0) printf("No estimate for this data set.\n");
        else printf("%lf\n", sqrt(6*pairo/(double)cow));
    }

    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
