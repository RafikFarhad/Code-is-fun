/*
ID: rafikfa1
PROG: beads
LANG: C++
*/
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
#define CLR(a) memset(a, 0, sizeof(a))
#define PI 2*acos(0)
using namespace std;

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    string s, a;
    char c;
    int len, cow = 0, temp, i, j, k, x, y;
    bool b1 = false, b2 = false;
    cin >> len >> a;
    a = a+a;
    //cout << a << endl;
    len=a.size();
    temp = 0;
    for(i=0; i<len; i++)
    {
        x = y = 0;
        for(j=i; j>=0; j--)
        {
            if(a[j]=='w')
            {
                x++;
                continue;
            }
            if(a[i]!=a[j]) break;
            x++;
        }
        if(a[i+1]=='w')
        {
            k = i+1;
            while(k-- && a[k]!='w') ;
            c = a[k-1];
        }
        else c = a[i+1];
        for(j=i+1; j<len; j++)
        {
            if(a[j]=='w')
            {
                y++;
                continue;
            }
            if(c!=a[j]) break;
            y++;
        }
        cow = max(cow, x+y);
        //pf("%d\t%d\n", i+1, y);
    }
    if(cow>len/2) cow = len>>1;
    cout << cow << endl;;

    return 0;
}


