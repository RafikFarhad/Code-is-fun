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
    //freopen("10176.txt", "r", stdin);
    char c;
    int i, sum=0;
    while(scanf("%c", &c)!=EOF)
    {
        if(c == '1') sum++;
        else if(c=='#')
        {
            //cout << "sum " << sum << endl;
            if(sum==0) printf("YES\n");
            else if(sum%17==0) printf("YES\n");
            else printf("NO\n");
            sum = 0;
        }
    }
    return 0;
}



