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
#define TOOT 10000002
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

int main()
{
    //time_t t1=clock();
    //freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN
    int cow, i, j, len;
    char line[303];
    while(gets(line))
    {
        if(line[0] == '*') break;
        len = strlen(line);
        cow = 0;
        for(i=1, j=0; i<len; i++)
        {
            if(line[i]=='X') j+=1;
            else if(line[i]=='T') j+=2;
            else if(line[i]=='S') j+=4;
            else if(line[i]=='E') j+=8;
            else if(line[i]=='Q') j+=16;
            else if(line[i]=='H') j+=32;
            else if(line[i]=='W') j+=64;
            else
            {
               // cout << j << endl;
                if(j==64) cow++;
                j = 0;
            }
        }
        pf("%d\n", cow);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


