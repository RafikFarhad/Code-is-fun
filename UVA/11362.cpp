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

bool PE(string a, string b)
{
    //if(b.size())
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int main()
{
    freopen("11362.txt", "r", stdin);
    int t, n, i, j, a;
    string line[10010];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        j = 0;
        for(i=0; i<n; i++)
            cin >> line[i];
        sort(line, line+n);
        for(i=1; i<n; i++)
        {
            if(PE(line[i-1], line[i])) j=1;
        }
        if(!j) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}



