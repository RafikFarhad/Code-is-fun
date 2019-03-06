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
    freopen("10420.txt", "r", stdin);

    ///                                    MAIN
    string a, b;
    char line[80];
    int n;
    map <string, int> di;
    set <string> sett;

    sf("%d ", &n);
    while(n--)
    {
        gets(line);
        char *t;
        t = strtok(line, " ");
        a = t;
        di[a]++;
        sett.insert(a);
    }
    for(typeof(sett.begin()) it = sett.begin(); it != sett.end(); it++)
        cout << *it << " " << di[*it] << endl;
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}



