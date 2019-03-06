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
    freopen("10281.txt", "r", stdin);
    char line[20];
    int h, m, s, speed=0, ns;
    double now, prev=0, ans=0;
    while(gets(line))
    {
        int n = sscanf(line, "%d:%d:%d %d", &h, &m, &s, &ns);
        now = (h*3600)+(m*60) + s;
        ans = ans + (now-prev)*speed;
        //cout << now << " -> " << prev << "  ans  " << ans << endl << endl;
        prev = now;
        if(n==3)
            printf("%02d:%02d:%02d %.2lf km\n", h, m, s, ans/3600);
        else if(n==4)
            speed = ns;//speed = n;
    }
    return 0;
}


