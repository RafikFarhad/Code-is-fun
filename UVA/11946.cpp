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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}


int main()
{
    //time_t t1=clock();
    freopen("11946.txt", "r", stdin);

    ///                                    MAIN
    int t, len, a;
    char line[100];
    scanf("%d ", &t);
    while(t--)
    {
        //cout << t << endl;
        while(gets(line))
        {
            len = strlen(line);
            //  cout << len << endl;
            if(len==0) break;
            for(int i=0; i<len; i++)
            {
                if(line[i] == '1') putchar('I');
                else if(line[i] == '2') putchar('Z');
                else if(line[i] == '3') putchar('E');
                else if(line[i] == '4') putchar('A');
                else if(line[i] == '5') putchar('S');
                else if(line[i] == '6') putchar('G');
                else if(line[i] == '7') putchar('T');
                else if(line[i] == '8') putchar('B');
                else if(line[i] == '9') putchar('P');
                else if(line[i] == '0') putchar('O');
                else putchar(line[i]);
            }
            pf("\n");
        }
        if(t!=0)
            pf("\n");
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

