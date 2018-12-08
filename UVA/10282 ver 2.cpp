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
    freopen("10282.txt", "r", stdin);

    ///                                    MAIN
    string a;
    int i, j;
    map <string, string> dic;
    char in[100];
    while(gets(in))
    {
        char *temp, p[50], q[50];
        if(!strcmp(in, "")) break;
        temp = strtok(in, " ");
        strcpy(p, temp);
        temp = strtok(NULL, " ");
        strcpy(q, temp);
        dic[q] = p;
    }

    while(gets(in))
    {
        a = dic[in];
        if(a.size()==0) pf("eh\n");
        else cout << a << endl;
    }

    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

