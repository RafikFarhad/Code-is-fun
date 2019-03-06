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
    long long unsigned b, s, b1, s1;
    double x, y, one = 1.0;
    int keis=1;
    while(scanf("%llu %llu", &b, &s)==2 && b && s)
    {
        printf("Case %d: ", keis++);
        if(b==1) printf(":-\\\n");
        else if(s==b) printf(":-|\n");
        else
        {
            x = s/(double)b;
            x = x>one?one:x;
            y = (s-1)/(double)(b-1);
            if(y>one) y = one;
            if(x<y) printf(":-)\n");
            else if(x>y) printf(":-(\n");
            else printf(":-|\n");
        }
    }
        return 0;
}



